#include "stdafx.h"
#include "GameStateManager.h"


GameStateManager::GameStateManager()
{
}


GameStateManager::~GameStateManager()
{
}

void GameStateManager::Initialize()
{
	gameStates[GameStateType::STATE_DIRECT_X_BASE] = new GameState_DX_Base;
	gameStates[GameStateType::STATE_STAGE3] = new GameState_Stage3;
	gameStates[GameStateType::STATE_STAGE2] = new GameState_Stage2;
	gameStates[GameStateType::STATE_STAGE1] = new GameState_Stage1;
	gameStates[GameStateType::STATE_SHOP] = new GameState_Shop;
	gameStates[GameStateType::STATE_OPENING] = new GameState_Opening;
	gameStates[GameStateType::STATE_SELECT] = new GameState_Select;
	gameStates[GameStateType::STATE_LOADING1] = new GameState_Loading1;
	gameStates[GameStateType::STATE_LOADING2] = new GameState_Loading2;
	gameStates[GameStateType::STATE_LOADING3] = new GameState_Loading3;
	gameStates[GameStateType::STATE_ENDING] = new GameState_Ending;
	GameStateManager::_currentState = GameStateType::STATE_OPENING;
	gameStates[GameStateManager::_currentState]->OnEnterState();
}

void GameStateManager::Destroy()
{
	for ( int i = 0; i < GameStateType::NUM_OF_STATE; ++i )
	{
		if ( gameStates[i] != nullptr )
		{
			gameStates[i]->OnLeaveState();
			delete gameStates[i];
			gameStates[i] = nullptr;			
		}
		//SAFE_DELETE(gameStates[i]);	// OnLeaveState안에 들어있음
	}
}

void GameStateManager::Update()
{
	gameStates[GameStateManager::_currentState]->Update();
}

void GameStateManager::Render()
{
	gameStates[GameStateManager::_currentState]->Render();
}

LRESULT GameStateManager::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return gameStates[GameStateManager::_currentState]->InputProc(hWnd, message, wParam, lParam);
	return 0;
}

bool GameStateManager::ChangeGameState(GameStateType state)
{
	bool result = false;
	if ( gameStates[state] )
	{
		gameStates[GameStateManager::_currentState]->OnLeaveState();
		GameStateManager::_currentState = state;
		gameStates[GameStateManager::_currentState]->OnEnterState();

		result = true;
	}

	return result;
}

bool GameStateManager::ChangeGameState(GameStateType state, GameStateType loadingScene){
	if (gameStates[state] == nullptr) return E_FAIL;
	bool result = false;
	if (SUCCEEDED(gameStates[state]->OnEnterState()))
	{
		gameStates[GameStateManager::_currentState]->OnLeaveState();
		_loadingScene = gameStates[loadingScene];
		_readyScene = state;
		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &_loadThreadID));
		
	}

	return result;
}


//로딩 쓰레드를 위한 함수
DWORD CALLBACK loadingThread(LPVOID prc)
{
	//교체될 init 함수를 실행한다
	GameStateManager::gameStates[GameStateManager::_readyScene]->Initialize();

	//현재 씬을 교체될 씬으로 바꾼다
	GameStateManager::_currentState = GameStateManager::_readyScene;

	//로딩씬을 해제 한다
	GameStateManager::_loadingScene->OnLeaveState();
	GameStateManager::_loadingScene = NULL;

	return 0;
}

GameState* GameStateManager::_loadingScene = NULL;
GameState* GameStateManager::_currentScene = NULL;
GameState* GameStateManager::gameStates[GameStateType::NUM_OF_STATE];
GameStateType GameStateManager::_currentState = GameStateType::STATE_DIRECT_X_BASE;
GameStateType GameStateManager::_readyScene = GameStateType::STATE_DIRECT_X_BASE;