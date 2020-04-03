#include "stdafx.h"
#include "DarkBallFire.h"


DarkBallFire::DarkBallFire()
{
}


DarkBallFire::~DarkBallFire()
{
}

void DarkBallFire::Initialize(){
	mDarkBallUnUsed.clear();
	//안쓰는 총알 초기화
	darkBallAll = new DarkBall[DARKBALL_COUNT];
	for (int i = 0; i < DARKBALL_COUNT; i++){
		DarkBall *darkBall = &darkBallAll[i];
		darkBall->Initialize();
		mDarkBallUnUsed.push_back(darkBall);
	}

	mDarkBallUsed.clear();

	soundManager::Get().addSound("Attack", "Data/Sound/Azmodan/Azmodan_AllShallBurn_Cast02.wav", false, false);
}

void DarkBallFire::Fire(D3DXVECTOR3 position, D3DXVECTOR3 enemyPosition, float angle, float timer){
	if (mDarkBallUnUsed.size() == 0){
		return;
	}

	for (auto iter = mDarkBallUnUsed.begin(); iter != mDarkBallUnUsed.end(); iter++){
		(*iter)->Reset();
		(*iter)->SetAngle(angle);
		(*iter)->Update();
		D3DXVECTOR3 newPos = position - (*iter)->GetDirection() * 3;
		newPos.y += 4.5;
		(*iter)->SetPosition(newPos);
		(*iter)->SetEnemyPos(enemyPosition);
		//
		(*iter)->SetKelthasPos(newPos);
		(*iter)->SetTimer(timer);
		(*iter)->SetStartTimer(timeGetTime());

		mDarkBallUsed.push_back((*iter));
		mDarkBallUnUsed.erase(iter);
		break;
	}
}

void DarkBallFire::Destroy(){

	for (auto iter = mDarkBallUsed.begin(); iter != mDarkBallUsed.end(); iter++){
		(*iter)->Destroy();
	}

	for (auto iter = mDarkBallUnUsed.begin(); iter != mDarkBallUnUsed.end(); iter++){
		(*iter)->Destroy();
	}

	mDarkBallUsed.clear();
	mDarkBallUnUsed.clear();
}

void DarkBallFire::Update(){
	for (auto iter = mDarkBallUsed.begin(); iter != mDarkBallUsed.end();){
		(*iter)->Update();

		if ((*iter)->GetPosition().y < 0){
			//스킬 이펙트
			DarkCircleExplosion* darkCircleExplosion = new DarkCircleExplosion;
			darkCircleExplosion->Initialize((*iter)->GetPosition() + D3DXVECTOR3(1, 3, 1), D3DXVECTOR3(2, 2, 2));
			mDarkCircleExplosion.push_back(darkCircleExplosion);

			mDarkBallUnUsed.push_back((*iter));
			iter = mDarkBallUsed.erase(iter);
			soundManager::Get().play("Attack", 1.0f);
		}
		else{
			iter++;
		}
	}

	for (auto iter = mDarkCircleExplosion.begin(); iter != mDarkCircleExplosion.end(); iter++){
		(*iter)->Update(GameManager::Get().GetCamera()->GetEyePosition());
	}

	for (auto iter = mDarkCircleExplosion.begin(); iter != mDarkCircleExplosion.end();){
		if (!(*iter)->GetIsPlay()) iter = mDarkCircleExplosion.erase(iter);
		else iter++;
	}
}

void DarkBallFire::Render(){
	for (auto iter = mDarkBallUsed.begin(); iter != mDarkBallUsed.end(); iter++){
		(*iter)->Render();
	}

	for (auto iter = mDarkCircleExplosion.begin(); iter != mDarkCircleExplosion.end(); iter++){
		(*iter)->Render();
	}
}

void DarkBallFire::Battle(unit* enemy){
	for (auto iter = mDarkBallUsed.begin(); iter != mDarkBallUsed.end();){
		if (Collision::IsBoxToSphere(enemy->GetSkinedMesh()->GetCollisionBox()->GetBoundingBox(), (*iter)->GetMesh()->GetCollisionSphere()->GetBoundingSphere())){
			enemy->SetHp(enemy->GetHp() + enemy->GetArmor() - 10);
			//스킬 이펙트
			DarkCircleExplosion* darkCircleExplosion = new DarkCircleExplosion;
			darkCircleExplosion->Initialize((*iter)->GetPosition() + D3DXVECTOR3(0, 2, 0), D3DXVECTOR3(2, 2, 2));
			mDarkCircleExplosion.push_back(darkCircleExplosion);

			mDarkBallUnUsed.push_back((*iter));
			iter = mDarkBallUsed.erase(iter);
			soundManager::Get().play("Attack", 1.0f);
		}
		else{
			iter++;
		}
	}
}