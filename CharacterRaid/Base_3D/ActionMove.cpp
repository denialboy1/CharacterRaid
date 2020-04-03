#include "stdafx.h"
#include "ActionMove.h"


ActionMove::ActionMove()
{
}


ActionMove::~ActionMove()
{
}

void ActionMove::Start()
{
	//if (abs(start.x - goal.x) < 0.001 && abs(start.y - goal.y) < 0.001 && abs(start.z - start.z) < 0.001) return;
	if ( !target )
		return;

	isStart = true;
	passedTime = 0.0f;
	target->SetPosition(start);	

	D3DXVECTOR3 a(0,0,1);
	D3DXVECTOR3 b = goal - start;

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&b);
	float dot = D3DXVec3Dot(&a, &b);

	// �ð�������� �ݽð�������� �Ǻ�
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &b);
	if (cross.y < 0)	
	{
		dot *= -1;		// �ݽð� �����̴�. �׷��� ������ �ݴ��
	}
	
	float angle = acos(dot / (aLength * bLength));	//acos�� 0~180�� ������ ���� ���´�.

	//���� 180�� �̻����� �Ǻ�
	D3DXVECTOR3 c(1, 0, 0);	//a�� 90�� ��ŭ ���� ����
	bool over180 = false;
	if (D3DXVec3Dot(&b, &c) < 0.0f)	// c,b�� 90�� �̻��̸� a,b�� 180�� �̻��̶�� �Ҹ�
	{
		over180 = true;
	}

	//180�� �̻��̸� 180���� ������
	if (over180)
	{
		angle += D3DX_PI;
	}

	target->SetAngle(angle);
}

void ActionMove::Update()
{
	if ( !target || isStart == false )
		return;

	passedTime += (float)GameManager::GetTick()*speed;

	if (passedTime >= durationTime)
	{
		target->SetPosition(goal);

		isStart = false;
		if ( actionDelegate )
		{
			actionDelegate->OnActionFinish(this);
		}

		return;
	}

	float t = passedTime / (durationTime);

	D3DXVECTOR3 newPosition;
	D3DXVec3Lerp(&newPosition, &start, &goal, t);
	target->SetPosition(newPosition);
}

void ActionMove::Destroy()
{
}