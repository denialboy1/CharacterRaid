#pragma once
class bossBar
{
public:
	bossBar();
	~bossBar();

	void Initialize(float _maxHp, float _currentHp);
	void Destroy();
	void Update(D3DXVECTOR3 cameraPos, D3DXVECTOR3 pos);
	void Render();

private:
	Billboard* hpTop = nullptr;
	Billboard* hpBottom = nullptr;

	Billboard* mpTop = nullptr;
	Billboard* mpBottom = nullptr;

	Billboard* hpBar = nullptr;

	D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0);

	float maxHp = 100;
	float currentHp = 60;

	float maxMp = 100;
	float currentMp = 60;
public:
	float GetCurrentHp(){ return currentHp; }
	void SetCurrentHp(float _currentHp){ currentHp = _currentHp; }

	float GetMaxHp(){ return maxHp; }
	void SetMaxHp(float _maxHp){ maxHp = _maxHp; }

	float GetCurrentMp(){ return currentMp; }
	void SetCurrentMp(float _currentMp){ currentMp = _currentMp; }

	float GetMaxMp(){ return maxMp; }
	void SetMaxMp(float _maxMp){ maxMp = _maxMp; }
};

