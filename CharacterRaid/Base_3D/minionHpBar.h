#pragma once
#include "Billboard.h"

class minionHpBar
{
public:
	minionHpBar();
	~minionHpBar();

	void Initialize(float _maxHp, float _currentHp);
	void Destroy();
	void Update(D3DXVECTOR3 cameraPos,D3DXVECTOR3 pos);
	void Render();

private:
	Billboard* hpTop = nullptr;
	Billboard* hpBottom = nullptr;
	Billboard* hpBar = nullptr;

	D3DXVECTOR3 pos = D3DXVECTOR3(0, 15, 0);

	float maxHp = 100;
	float currentHp = 60;
public:
	float GetCurrentHp(){ return currentHp; }
	void SetCurrentHp(float _currentHp){ currentHp = _currentHp; }

	float GetMaxHp(){ return maxHp; }
	void SetMaxHp(float _maxHp){ maxHp = _maxHp; }
};


