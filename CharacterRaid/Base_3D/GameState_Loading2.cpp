#include "stdafx.h"
#include "GameState_Loading2.h"


GameState_Loading2::GameState_Loading2()
{
}


GameState_Loading2::~GameState_Loading2()
{
}


void GameState_Loading2::Initialize(){
	_loading = new loading;
	_loading->Initialize();
	_loading->loadTexture("./UI/atifact/Àü±¤¼®È­.png");
}
void GameState_Loading2::Destroy(){


}
void GameState_Loading2::Update(){
	_loading->Update();

	if (!_loading->loadNext())
	{
		GameStateManager::Get().ChangeGameState(GameStateType::STATE_STAGE2);
	}
}
void GameState_Loading2::Render(){
	_loading->Render();

}

HRESULT GameState_Loading2::OnEnterState(){
	Initialize();

	return S_OK;
}

void GameState_Loading2::OnLeaveState(){

}

LRESULT GameState_Loading2::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	LRESULT result = 0;
	return result;
}

void GameState_Loading2::Reset(){

}