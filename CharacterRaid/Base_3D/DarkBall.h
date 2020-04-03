#pragma once
#include "SkillObject.h"

class DarkBall : public SkillObject
{
public:
	DarkBall();
	~DarkBall();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	void Reset();
private:
	float timer = 0.0f;
	float startTimer = 0.0f;
	float currentTimer = 0.0f;

	bool fire = false;
	D3DXVECTOR3 enemyPos = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 kelthasPos = D3DXVECTOR3(0, 0, 0);
public:
	void SetTimer(float _timer){ timer = _timer; }
	void SetStartTimer(float _startTimer){ startTimer = _startTimer; }

	void SetEnemyPos(D3DXVECTOR3 _enemyPos){ enemyPos = _enemyPos; }
	void SetKelthasPos(D3DXVECTOR3 _kelthasPos){ kelthasPos = _kelthasPos; }
};

