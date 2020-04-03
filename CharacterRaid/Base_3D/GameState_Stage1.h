#pragma once
#include "GameState.h"
#include "Nova.h"
#include "Grid.h"
#include "Stage1.h"
#include "Marine.h"
#include "VikingEnemy.h"
#include "HammerBoss.h"
#include "bigMissile.h"
#include "UI_Interface.h"
#include "NuClear.h"
#include "jaina.h"

enum MISSILE_STATE
{
	PAGE_1,
	PAGE_2,
	PAGE_3,
	PAGE_4
};

class GameState_Stage1 : public GameState
{
public:
	GameState_Stage1();
	~GameState_Stage1();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2);
private:

	Grid* grid = nullptr;
	Nova* nova = nullptr;
	//VikingAttack* _VikingAttack = nullptr;
	Stage1* stage1 = nullptr;
	Marine* marine = nullptr;
	VikingEnemy* vikingEnemy1 = nullptr;
	VikingEnemy* vikingEnemy2 = nullptr;
	VikingEnemy* vikingEnemy3 = nullptr;
	VikingEnemy* vikingEnemy4 = nullptr;
	VikingEnemy* vikingEnemy5 = nullptr;
	VikingEnemy* vikingEnemy6 = nullptr;
	player* _player = nullptr;
	HammerBoss* hammerBoss = nullptr;
	bigMissile* _bigMissile = nullptr;
	UI_Interface* UI = nullptr;

	MISSILE_STATE MissileState;
	Jaina* jaina = nullptr;

	//NuClear* BlNuclear = nullptr;

	float HammerBossMove;
	bool IsHammerBossMove;

	std::list<VikingEnemy*> vikingEnemyList;

	
	float startTimer = 0.0f;

};

