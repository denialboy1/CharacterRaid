#include "stdafx.h"
#include "ActionRotate.h"


ActionRotate::ActionRotate()
{
}


ActionRotate::~ActionRotate()
{
}


void ActionRotate::Start()
{
	if (!target)
		return;

	startAngle = target->GetAngle();

	isStart = true;
	passedTime = 0.0f;
	target->SetPosition(start);

	D3DXVECTOR3 a(0, 0, 1);
	D3DXVECTOR3 b = goal - start;

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&b);
	float dot = D3DXVec3Dot(&a, &b);

	// 시계방향인지 반시계방향인지 판별
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &b);
	if (cross.y < 0)
	{
		dot *= -1;		// 반시계 방향이다. 그러면 각도가 반대로
	}

	float angle = acos(dot / (aLength * bLength));	//acos는 0~180도 사이의 값만 나온다.

	//따라서 180도 이상인지 판별
	D3DXVECTOR3 c(1, 0, 0);	//a를 90도 만큼 돌린 백터
	bool over180 = false;
	if (D3DXVec3Dot(&b, &c) < 0.0f)	// c,b가 90도 이상이면 a,b가 180도 이상이라는 소리
	{
		over180 = true;
	}

	//180도 이상이면 180도를 더해줌
	if (over180)
	{
		angle += D3DX_PI;
	}

	goalAngle =  angle;
}

void ActionRotate::Update()
{
	if (!target || isStart == false)
		return;

	passedTime += (float)GameManager::GetTick()*speed;

	if (passedTime >= durationTime)
	{
		target->SetAngle(goalAngle);

		isStart = false;
		if (actionDelegate)
		{
			actionDelegate->OnActionFinish(this);
		}

		return;
	}

	float t = passedTime / (durationTime);

	if (startAngle <= goalAngle){
		float angle = startAngle + (goalAngle - startAngle) / t;
		target->SetAngle(angle);
	}
	else{

	}float angle = startAngle + (startAngle - goalAngle) / t;
	target->SetAngle(angle);

	
}

void ActionRotate::Destroy()
{
}