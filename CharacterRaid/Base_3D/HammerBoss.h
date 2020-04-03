#pragma once
#include "unit.h"
#include "bigMissile.h"
#include "bossBar.h"
class HammerBoss : public unit
{
	enum HAMMERBOSS_STATE
	{
		STAND = 36,
		WALK,
		PATTERN_1,
		PATTERN_2,
		PATTERN_3,
		ULTIMATE_PATTERN
	};
public:
	HammerBoss();
	~HammerBoss();

	void Initialize();
	void Destroy();
	void Update();//float _timer);
	void Render();

	void Battle(unit& enemy);
	void ChangeMotion(HAMMERBOSS_STATE _BossState);
	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2);
	void Action(float _timer);


	void SetGoal(D3DXVECTOR3 _goal){ goal = _goal; }
	D3DXVECTOR3 GetGoal(){ return goal; }

	HAMMERBOSS_STATE HammerBossState = STAND;

	Collider_Sphere* HammerBossBodySphere = nullptr;
	bigMissile* _bigMissile = nullptr;

private:
	float aniTime = 0.0f;
	float startTimer = 0.0f;

	D3DXVECTOR3 goal = D3DXVECTOR3(0, 0, 0);

	//hpBar
	bossBar* hpBar = nullptr;

};

