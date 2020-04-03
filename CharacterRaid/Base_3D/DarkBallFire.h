#pragma once
#include "DarkBall.h"
#include "DarkCircleExplosion.h"
#define DARKBALL_COUNT 100

class DarkBallFire
{
public:
	DarkBallFire();
	~DarkBallFire();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Fire(D3DXVECTOR3 position, D3DXVECTOR3 enemyPosition, float angle, float timer);

	std::list<DarkBall*>& GetMIce(){ return mDarkBallUsed; }
	std::list<DarkBall*>& GetMIceUnUsed(){ return mDarkBallUnUsed; }

	void Battle(unit* enemy);
private:
	std::list<DarkBall*> mDarkBallUsed;
	std::list<DarkBall*> mDarkBallUnUsed;
	DarkBall *darkBallAll = nullptr;

	std::list<DarkCircleExplosion*> mDarkCircleExplosion;
};

