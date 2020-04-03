#include "stdafx.h"
#include "Phoenix.h"


Phoenix::Phoenix()
{
}


Phoenix::~Phoenix()
{
}

void Phoenix::Initialize(D3DXVECTOR3 _scale){
	unit::Initialize();
	scale = _scale;
	mesh->Initialize("피닉스/", "피닉스.x", scale);
	
	attackRange = 2;
	mesh->GetCollisionSphere()->GetBoundingSphere().radius = attackRange;
	mesh->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(100, 100, 100);
	hp = hpMax = 1200;
	attack = 10;
	moveSpeed = 1.5;

	unit::Update();
	obb = new cOBB;
	obb->Setup(mesh);

	//추적
	if (traceRange == nullptr){
		traceRange = new Collider_Sphere;
		traceRange->Initialize(mesh->GetCollisionSphere()->GetBoundingSphere().center, 10);
	}
	
	if (circle == nullptr){
		circle = new Phoenix_Circle;
		circle->Initialize();
	}

	if (hpBar == nullptr){
		hpBar = new minionHpBar;
		hpBar->Initialize(hp, hp);
	}

	if (burn == nullptr){
		burn = new Burn;
		burn->Initialize(D3DXVECTOR3(0,0,0), D3DXVECTOR3(1, 1, 1));
	}

	soundManager::Get().addSound("pinix_attack", "Data/Sound/Kealthas/피닉스공격.wav", false, false);
	soundManager::Get().addSound("pinix_death", "Data/Sound/Kealthas/피닉스죽음.wav", false, false);
}

void Phoenix::Destroy(){
	unit::Destroy();
	SAFE_DELETE(traceRange);
	if (circle)		SAFE_DELETE(circle);
	SAFE_DELETE(hpBar);
	soundManager::Get().play("pinix_death", 1.0f);
}

void Phoenix::Update(unit* _enemy){
	if (isDeath) return;
	unit::Update();
	obb->Update(&obbWorld);
	mesh->GetCollisionSphere()->GetBoundingSphere().center = position;
	if (circle){
		circle->Update(position);
	}
	D3DXVECTOR3 pos = position;
	pos.y = 5;
	if (hpBar){
		hpBar->SetCurrentHp(hp);
		hpBar->Update(GameManager::Get().GetCamera()->GetEyePosition(), pos);
	}
	
	if (burn)	{
		D3DXVECTOR3 pos = _enemy->GetPosition();
		pos.y = 3;
		burn->Update(GameManager::GetCamera()->GetEyePosition(), pos);
	}

	if (hp < 0){
		isDeath = true;
		soundManager::Get().play("pinix_death", 1.0f);
	}
}

void Phoenix::Render(){
	if (isDeath) return;
	mesh->UpdateAndRender();
	if (circle)		circle->Render();
	if (hpBar) hpBar->Render();
	if (burn) burn->Render();
}

void Phoenix::Battle(unit* _enemy){

	if (!_enemy->GetIsInvincible()){
		if (Collision::IsSphereToSphere(_enemy->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), mesh->GetCollisionSphere()->GetBoundingSphere())){
			_enemy->SetHp(_enemy->GetHp() - 0.1);
			burn->Start(_enemy->GetPosition());
			if (!soundManager::Get().isPlaySound("pinix_attack")){
				soundManager::Get().play("pinix_attack", 1.0f);
			}
		}
	}
}

void Phoenix::Trace(unit* _enemy){
	traceRange->GetBoundingSphere().center = position;
	
	if (Collision::IsSphereToSphere(_enemy->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), traceRange->GetBoundingSphere())){
		removeAction();
		rotationAngle = GetAngle(_enemy->GetPosition(), position) + D3DX_PI;
		position -= direction * 0.1 * moveSpeed;
		state = TRACE;
	}
	else{
		if (state == TRACE){
			state = TRACE_AFTER;
		}
	}
}

float Phoenix::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
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