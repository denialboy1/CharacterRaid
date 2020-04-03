#pragma once
#include "SkillObject.h"

class DarkCircle :public SkillObject
{
	enum DARK_CIRCLE_STATE{ IDLE, COLLISION, COLLISION_AFTER, /*EXPLOSION*/ };
public:
	DarkCircle();
	~DarkCircle();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;

	void Battle(unit* enemy);

	void Reset();


private:
	float timer = 0.0f;
	float startTimer = 0.0f;
	float currentTimer = 0.0f;

	bool fire = false;
	D3DXVECTOR3 enemyPos = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 azmodanPos = D3DXVECTOR3(0, 0, 0);

	DARK_CIRCLE_STATE state = IDLE;
	bool isAfter = false;
	PillarOfFire* pillarOfFire = nullptr;
public:
	void SetTimer(float _timer){ timer = _timer; }
	void SetStartTimer(float _startTimer){ startTimer = _startTimer; }

	void SetEnemyPos(D3DXVECTOR3 _enemyPos){ enemyPos = _enemyPos; }
	void SetAzmodanPos(D3DXVECTOR3 _kelthasPos){ azmodanPos = _kelthasPos; }

	void SetCollision(){ if (state == IDLE) state = COLLISION; }
	bool GetIsAfter(){ return isAfter; }

};

