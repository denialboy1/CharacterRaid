#include "stdafx.h"
#include "FireBallFire.h"


FireBallFire::FireBallFire()
{
}


FireBallFire::~FireBallFire()
{
}

void FireBallFire::Initialize(){
	mFireBallUnUsed.clear();
	//안쓰는 총알 초기화
	fireBallAll = new FireBall[FIREBALL_COUNT];
	for (int i = 0; i < FIREBALL_COUNT; i++){
		FireBall *fireBall = &fireBallAll[i];
		fireBall->Initialize();
		mFireBallUnUsed.push_back(fireBall);
	}

	mFireBallUsed.clear();

	soundManager::Get().addSound("explosion", "Data/Sound/Kealthas/explosion.wav", false, false);
}

void FireBallFire::Fire(D3DXVECTOR3 position, D3DXVECTOR3 enemyPosition, float angle, float timer){
	if (mFireBallUnUsed.size() == 0){
		return;
	}

	for (auto iter = mFireBallUnUsed.begin(); iter != mFireBallUnUsed.end(); iter++){
		(*iter)->Reset();
		(*iter)->SetAngle(angle);
		(*iter)->Update();
		D3DXVECTOR3 newPos = position - (*iter)->GetDirection() * 3;
		newPos.y += 4.5;
		(*iter)->SetPosition(newPos);
		(*iter)->SetEnemyPos(enemyPosition);
		(*iter)->SetKelthasPos(newPos);
		(*iter)->SetTimer(timer);
		(*iter)->SetStartTimer(timeGetTime());
		
		mFireBallUsed.push_back((*iter));
		mFireBallUnUsed.erase(iter);
		break;
	}
}

void FireBallFire::Destroy(){

	for (auto iter = mFireBallUsed.begin(); iter != mFireBallUsed.end(); iter++){
		(*iter)->Destroy();
	}

	for (auto iter = mFireBallUnUsed.begin(); iter != mFireBallUnUsed.end(); iter++){
		(*iter)->Destroy();
	}

	mFireBallUsed.clear();
	mFireBallUnUsed.clear();
}

void FireBallFire::Update(){
	for (auto iter = mFireBallUsed.begin(); iter != mFireBallUsed.end(); ){
		(*iter)->Update();

		if ((*iter)->GetPosition().y < 0){
			//스킬 이펙트
			FireCircleExplosion* fireCircleExplosion = new FireCircleExplosion;
			fireCircleExplosion->Initialize((*iter)->GetPosition()+D3DXVECTOR3(1,3,1), D3DXVECTOR3(2, 2, 2));
			mFireCircleExplosion.push_back(fireCircleExplosion);
			
			mFireBallUnUsed.push_back((*iter));
			iter = mFireBallUsed.erase(iter);
			soundManager::Get().play("explosion", 0.3f);
		}
		else{
			iter++;
		}
	}

	for (auto iter = mFireCircleExplosion.begin(); iter != mFireCircleExplosion.end(); iter++){
		(*iter)->Update(GameManager::Get().GetCamera()->GetEyePosition());
	}

	for (auto iter = mFireCircleExplosion.begin(); iter != mFireCircleExplosion.end();){
		if (!(*iter)->GetIsPlay()) iter =mFireCircleExplosion.erase(iter);
		else iter++;
	}
}

void FireBallFire::Render(){
	for (auto iter = mFireBallUsed.begin(); iter != mFireBallUsed.end(); iter++){
		(*iter)->Render();
	}

	for (auto iter = mFireCircleExplosion.begin(); iter != mFireCircleExplosion.end(); iter++){
		(*iter)->Render();
	}
}

void FireBallFire::Battle(unit* enemy){
	for (auto iter = mFireBallUsed.begin(); iter != mFireBallUsed.end();){
		if (Collision::IsBoxToSphere(enemy->GetSkinedMesh()->GetCollisionBox()->GetBoundingBox(),(*iter)->GetMesh()->GetCollisionSphere()->GetBoundingSphere())){
			enemy->SetHp(enemy->GetHp() - 10);
			//스킬 이펙트
			FireCircleExplosion* fireCircleExplosion = new FireCircleExplosion;
			fireCircleExplosion->Initialize((*iter)->GetPosition() + D3DXVECTOR3(0,2,0), D3DXVECTOR3(2, 2, 2));
			mFireCircleExplosion.push_back(fireCircleExplosion);

			mFireBallUnUsed.push_back((*iter));
			iter = mFireBallUsed.erase(iter);
			soundManager::Get().play("explosion", 0.3f);
		}
		else{
			iter++;
		}
	}
}