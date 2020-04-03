#include "stdafx.h"
#include "Ice.h"


Ice::Ice()
{
}


Ice::~Ice()
{
}


void Ice::Initialize(){
	SkillObject::Initialize();
	if (mesh == nullptr){
		mesh = new SkinnedMesh;
		scale.x = 0.05f;
		scale.y = 0.05f;
		scale.z = 0.05f;
		mesh->Initialize("IceMissile/","IceMissile.X",scale);  //�������
		mesh->SetAnimationIndex(0);
		
		obbBox->Setup(mesh);
		ChangeMotion(BIRTH);
	}

}
void Ice::Destroy(){
	SkillObject::Destroy();
}
void Ice::Update(){
	
	SkillObject::Update();
	obbBox->Update(&obbWorld);
	switch (state){
	case BIRTH:
		if (aniTime -0.1f< (timeGetTime() - startTimer) * 0.001f) {
			state = STAND;
			ChangeMotion(STAND);
		}
		break;
	case DEATH:
		break;
	case STAND:
		break;
	case FIRE:
		break;
	case FIND_ANGLE:
		FindDirection();
		break;
	case MOVE:
		Move();
		break;
	
	}
}
void Ice::Render(){
	SkillObject::Render();
	if (mesh){
		mesh->UpdateAndRender();
	}
}

void Ice::ChangeMotion(ICE_STATE _state){
	if (action)
		action->SetIsStart(false);
	state = _state;
	mesh->SetAnimationIndex(state);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//�ִϸ��̼� ������ �޾��� ����
	mesh->GetAnimController()->GetAnimationSet(state, &animSet);	//��ϵ� �ִϸ��̼ǿ��� animSet������ ������ ���
	aniTime = animSet->GetPeriod();									//�ִϸ��̼� �ð����� ����
	startTimer = timeGetTime();										//���� �ð� ����
	SAFE_RELEASE(animSet);
}

void Ice::FindAngle(D3DXVECTOR3 _startPos, D3DXVECTOR3 _goal, float _startAngle){
	start = _startPos;
	startAngle = _startAngle;
	goal = _goal;

	passedTime = 0.0f;
	passedTime1 = 0.0f;
	speed = 5;
	D3DXVECTOR3 a(0, 0, 1);
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

	goalAngle = angle;
	state = FIND_ANGLE;
}
void Ice::FindDirection(){
	if (state != FIND_ANGLE)	return;

	passedTime += (float)GameManager::GetTick()*speed;

	if (passedTime >= durationTime)
	{
		rotationAngle = goalAngle;

		state = MOVE;

		return;
	}

	float t = passedTime / (durationTime);

	if (startAngle <= goalAngle){
		float angle = startAngle + (goalAngle - startAngle) / t;
		rotationAngle = angle;
	}
	else{
		float angle = startAngle + (startAngle - goalAngle) / t;
		rotationAngle = angle;
	}
}

void Ice::Move(){
	if (state != MOVE)	return;

	passedTime1 += (float)GameManager::GetTick()*speed;

	if (passedTime1 >= durationTime1)
	{
		position = goal;
		state = STAND;
		return;
	}

	float t = passedTime1 / (durationTime1);

	D3DXVECTOR3 newPosition;
	D3DXVec3Lerp(&newPosition, &start, &goal, t);
	position = newPosition;
}

void Ice::Reset(){
	state = STAND;
	passedTime = 0.0f;
	passedTime1 = 0.0f;
}