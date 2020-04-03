#pragma once
#include "SkillObject.h"
#include "unit.h"
class Fire_Shield : public SkillObject
{
public:
	Fire_Shield();
	~Fire_Shield();

	virtual void Initialize() override;
	virtual void Destroy() override;
	void Update(D3DXVECTOR3 pos);
	virtual void Render();

	void Start();
	void Reset();

private:
	float timer = 0.0f;
	float startTimer = 0.0f;
	float currentTimer = 0.0f;

	bool start = false;
	D3DXVECTOR3 enemyPos = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 kelthasPos = D3DXVECTOR3(0, 0, 0);
public:
	void SetTimer(float _timer){ timer = _timer; }
	void SetStartTimer(float _startTimer){ startTimer = _startTimer; }

	void SetEnemyPos(D3DXVECTOR3 _enemyPos){ enemyPos = _enemyPos; }
	void SetKelthasPos(D3DXVECTOR3 _kelthasPos){ kelthasPos = _kelthasPos; }

	bool GetStart(){ return start; }
};

