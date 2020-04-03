#include "stdafx.h"
#include "GameState_Select.h"


GameState_Select::GameState_Select()
{
}


GameState_Select::~GameState_Select()
{
}

void GameState_Select::Initialize()
{
	select = new Select_UI;
	select->Initialize();
	select->SetPosition(0, 0, 0);
	select->SetShow(true);
	
	UI_Manager::Get().SetRoot(select);
}
void GameState_Select::Destroy()
{
	 SAFE_DELETE(select);
	 UI_Manager::Get().SetRoot(nullptr);
	 soundManager::Get().stop("openingbgm");
}
void GameState_Select::Reset()
{

}
void GameState_Select::Update()
{
	select->Update();
}
void GameState_Select::Render()
{
	select->Render();
}

HRESULT GameState_Select::OnEnterState()
{
	Initialize();
	return S_OK;
}
void GameState_Select::OnLeaveState()
{
	Destroy();
}
LRESULT GameState_Select::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	return result;
}