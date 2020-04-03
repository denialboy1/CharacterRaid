#include "stdafx.h"
#include "GameState_Loading3.h"


GameState_Loading3::GameState_Loading3()
{
}


GameState_Loading3::~GameState_Loading3()
{
}

void GameState_Loading3::Initialize(){
	_loading = new loading;
	_loading->Initialize();
	_loading->loadTexture("./UI/atifact/Àü±¤¼®È­.png");
}
void GameState_Loading3::Destroy(){


}
void GameState_Loading3::Update(){
	_loading->Update();

	if (!_loading->loadNext())
	{
		GameStateManager::Get().ChangeGameState(GameStateType::STATE_STAGE3);
	}
}
void GameState_Loading3::Render(){
	_loading->Render();

}

HRESULT GameState_Loading3::OnEnterState(){
	Initialize();

	return S_OK;
}

void GameState_Loading3::OnLeaveState(){

}

LRESULT GameState_Loading3::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	LRESULT result = 0;
	return result;
}

void GameState_Loading3::Reset(){

}