#pragma once
#include "GameState.h"
#include "jaina.h"
#include "Grid.h"
#include "Billboard.h"
#include "Marine.h"
#include "Stage3.h"
#include "Phoenix.h"
#include "Kealthas.h"
#include <list>
#include "UI_Interface.h"
#include "BossDeath.h"
#include "characterDeath.h"

class GameState_Stage3 : public GameState
{
	//10�ʵ��� �������� ���
	//30�ʵ��� ���� ���
	//��������
	//���������� 10�ʵ� ����
	enum STATE { IDLE, MINION, BOSS, BOSS_AFTER };

public:
	GameState_Stage3();
	~GameState_Stage3();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void WalkRoute(Phoenix& _phoenix, D3DXVECTOR3 _goal,bool _loop);
	void WalkHome(Phoenix& _phoenix, D3DXVECTOR3 _goal);
	void CreateMonster(float timer);
private:
	Jaina* jaina = nullptr;
	Grid* grid = nullptr;
	Stage3* stage = nullptr;
	Billboard* billboard = nullptr;
	Kealthas* kealthas = nullptr;
	UI_Interface* ui_interface = nullptr;
	D3DXVECTOR3 scale = D3DXVECTOR3(0, 0, 0);
	BossDeath* deathEffect = nullptr;
	characterDeath* playerDeathEffect = nullptr;
	//����
	std::list<Phoenix*> vPheonix;
	std::list<Phoenix*>::iterator viPheonix;
	//�������� ���°�
	STATE state = IDLE;

	player* _player = nullptr;
	
	float timer = 0.0f;
	float startTimer = 0.0f;

	bool isReborn = false;
	float rebornTimer = 0.0f;
};

