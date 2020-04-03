#pragma once
#include "Billboard.h"
#include "johanna.h"
#include "GameState.h"
#include "Grid.h"
#include "Marine.h"
#include "Stage2.h"
#include "Azmodan.h"
#include <list>
#include "UI_Interface.h"
#include "BossDeathEffect.h"
#include "jaina.h"
enum STAGE_STATE
{
	IDLE,
	MINION,
	BOSS,
	BOSS_AFTER
};
class GameState_Stage2 : public GameState
{
public:
	GameState_Stage2();
	~GameState_Stage2();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void WalkRoute(Phoenix& _phoenix, D3DXVECTOR3 _goal, bool _loop);
	void WalkHome(Phoenix& _phoenix, D3DXVECTOR3 _goal);
	void CreateMonster(float timer);
private:
	Stage2* stage = nullptr;
	johanna* Johanna = nullptr;
	Azmodan* azmodan = nullptr;
	Billboard* billboard = nullptr;
	UI_Interface* ui_interface = nullptr;
	BossDeathEffect* effect = nullptr;
	Jaina* jaina = nullptr;

	STAGE_STATE state = BOSS;

	D3DXVECTOR3 scale = D3DXVECTOR3(0, 0, 0);

	player* _player = nullptr;

	float timer = 0.0f;
	float startTimer = 0.0f;
};

