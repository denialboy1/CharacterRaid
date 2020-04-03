#pragma once
#include "GameState.h"
#include "GameState_DX_Base.h"
#include "GameState_Stage3.h"
#include "GameState_Stage2.h"
#include "GameState_Stage1.h"
#include "GameState_Shop.h"
#include "GameState_Opening.h"
#include "GameState_Select.h"
#include "GameState_Loading1.h"
#include "GameState_Loading2.h"
#include "GameState_Loading3.h"
#include "GameState_Ending.h"
enum GameStateType
{
	STATE_DIRECT_X_BASE = 0,	//기본 윈도우 프레임워크. DirectX초기화
	STATE_OPENING,
	STATE_SELECT,
	STATE_SHOP,
	STATE_STAGE1,
	STATE_STAGE2,
	STATE_STAGE3,
	STATE_ENDING,
	STATE_GAMEOVER,
	STATE_LOADING1,
	STATE_LOADING2,
	STATE_LOADING3,
	NUM_OF_STATE
};

class GameStateManager
{
private:
	GameStateManager();
	GameStateManager(const GameStateManager& other);
	~GameStateManager();

	static GameState* _loadingScene;
	
	static GameState* _currentScene;

	static GameStateType _currentState;
	static GameStateType _readyScene;
	static GameState* gameStates[GameStateType::NUM_OF_STATE];
	DWORD _loadThreadID;
public:
	static GameStateManager& Get()
	{
		static GameStateManager instance;
		return instance;
	}

	void Initialize();
	void Destroy();
	void Update();
	void Render();
	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	bool ChangeGameState(GameStateType state);
	bool ChangeGameState(GameStateType state,GameStateType loadingScene);

	friend DWORD CALLBACK loadingThread(LPVOID prc);
protected:
	//GameStateType currentState = GameStateType::STATE_DIRECT_X_BASE;
	
};

