#include "stdafx.h"
#include "GameState_Opening.h"


GameState_Opening::GameState_Opening()
{
}


GameState_Opening::~GameState_Opening()
{
}

void GameState_Opening::Initialize()
{
	title = new Opening_UI;
	title->Initialize();
	title->SetPosition(0, 0, 0);
	title->SetShow(true);
	UI_Manager::Get().SetRoot(title);

	soundManager::Get().addSound("openingbgm", "Data/Sound/¿ÀÇÁ´×.mp3", true, true);
	soundManager::Get().play("openingbgm", 0.5f);
}
void GameState_Opening::Destroy()
{
	SAFE_DELETE(title);
	UI_Manager::Get().SetRoot(nullptr);
	
}
void GameState_Opening::Reset()
{

}
void GameState_Opening::Update()
{


}
void GameState_Opening::Render()
{

}

HRESULT GameState_Opening::OnEnterState()
{
	Initialize();
	return S_OK; 
}
void GameState_Opening::OnLeaveState()
{
	Destroy();
}
LRESULT GameState_Opening::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	return result;
}