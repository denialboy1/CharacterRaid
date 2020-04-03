#include "stdafx.h"
#include "FireArrowWorld.h"


FireArrowWorld::FireArrowWorld()
{
}


FireArrowWorld::~FireArrowWorld()
{
}

void FireArrowWorld::Update(){
	for (auto iter = mFireArrowUsed.begin(); iter != mFireArrowUsed.end(); iter++){
			(*iter)->Update();
	}

	if (fireArrowEffect){
		fireArrowEffect->Update();
	}
}

void FireArrowWorld::Battle(unit* enemy){
	for (auto iter = mFireArrowUsed.begin(); iter != mFireArrowUsed.end(); ){
		if (cOBB::IsCollision(enemy->GetObbBox(), (*iter)->GetObbBox())){
			(*iter)->SetStand();
			fireArrowEffect->Start((*iter)->GetPosition());
			mFireArrowUnUsed.push_back((*iter));
			iter = mFireArrowUsed.erase(iter);
			enemy->SetHp(enemy->GetHp() - 10);
			soundManager::Get().play("arrow_attack", 1.0f);
		}
		else{
			iter++;
		}
	}
}

void FireArrowWorld::Fire(D3DXVECTOR3 _pos){
	for (auto iter = mFireArrowUsed.begin(); iter != mFireArrowUsed.end(); iter++){
		(*iter)->FindAngle((*iter)->GetPosition(), _pos, (*iter)->GetAngle()); 
		(*iter)->SetFindAngle();
		(*iter)->SetMove();
	}
}

void FireArrowWorld::Destroy(){
	for (auto iter = mFireArrowUsed.begin(); iter != mFireArrowUsed.end(); iter++){
		(*iter)->Destroy();
	}

	for (auto iter = mFireArrowUnUsed.begin(); iter != mFireArrowUnUsed.end(); iter++){
		(*iter)->Destroy();
	}

	SAFE_DELETE(fireArrowEffect);
}

void FireArrowWorld::Make(D3DXVECTOR3 _pos){
	isStart = true;
	startTime = timeGetTime();

	for (auto iter = mFireArrowUnUsed.begin(); iter != mFireArrowUnUsed.end();){
		(*iter)->SetPosition(D3DXVECTOR3(RandomUtil::GetInteger(30, -45), 1.5, RandomUtil::GetInteger(20, -25)));
		(*iter)->SetAngle(GetAngle(_pos,(*iter)->GetPosition())+D3DX_PI);
		mFireArrowUsed.push_back(*iter);
		iter = mFireArrowUnUsed.erase(iter);

	}
}

void FireArrowWorld::Initialize(){
	mFireArrowUnUsed.clear();
		//안쓰는 총알 초기화
	fireArrowAll = new FireArrow[FIREARROW_COUNT];
	for (int i = 0; i < FIREARROW_COUNT; i++){
		FireArrow *fireArrow = &fireArrowAll[i];
		fireArrow->Initialize();
		mFireArrowUnUsed.push_back(fireArrow);
	}

	mFireArrowUsed.clear();
	fireArrowEffect = new FireArrowEffect;
	fireArrowEffect->Initialize();

	soundManager::Get().addSound("arrow_attack", "Data/Sound/Kealthas/arrow.wav", false, false);
}

void FireArrowWorld::Reset(){
	isStart = false;
}

void FireArrowWorld::Render(){
	for (auto iter = mFireArrowUsed.begin(); iter != mFireArrowUsed.end(); iter++){
		(*iter)->Render();
	}

	if (fireArrowEffect){
		fireArrowEffect->Render();
	}
}


float FireArrowWorld::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
	D3DXVECTOR3 a(0, 0, 1);
	D3DXVECTOR3 b = v2 - v1;

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

	return angle;
}