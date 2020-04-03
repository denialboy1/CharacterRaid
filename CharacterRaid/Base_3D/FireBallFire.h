#pragma once
#include "FireBall.h"
#include "FireCircleExplosion.h"
#define FIREBALL_COUNT 100

class FireBallFire
{
public:
	FireBallFire();
	~FireBallFire();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Fire(D3DXVECTOR3 position, D3DXVECTOR3 enemyPosition,float angle, float timer);

	std::list<FireBall*>& GetMIce(){ return mFireBallUsed; }
	std::list<FireBall*>& GetMIceUnUsed(){ return mFireBallUnUsed; }

	void Battle(unit* enemy);
private:
	std::list<FireBall*> mFireBallUsed;
	std::list<FireBall*> mFireBallUnUsed;
	FireBall *fireBallAll = nullptr;

	std::list<FireCircleExplosion*> mFireCircleExplosion;
	
};

