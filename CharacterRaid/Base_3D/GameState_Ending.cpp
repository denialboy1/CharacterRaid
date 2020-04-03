#include "stdafx.h"
#include "GameState_Ending.h"


GameState_Ending::GameState_Ending()
{
}


GameState_Ending::~GameState_Ending()
{
}

void GameState_Ending::Initialize()
{
	ending = new Ending_UI;
	ending->Initialize();
	ending->SetPosition(0, 0, 1);
	ending->SetTitle("Total Rank");
	ending->SetShow(true);
	ending->SetDescription("");
	UI_Manager::Get().SetRoot(ending);

	soundManager::Get().addSound("endingBgm", "Data/Sound/¿£µù.mp3", true, true);
	soundManager::Get().play("endingBgm", 0.5f);

}
void GameState_Ending::Destroy()
{
	SAFE_DELETE(ending);
	soundManager::Get().stop("endingBgm");
}
void GameState_Ending::Reset()
{

}
void GameState_Ending::Update()
{


}
void GameState_Ending::Render()
{

}

HRESULT GameState_Ending::OnEnterState()
{
	Initialize();

	return S_OK;
}
void GameState_Ending::OnLeaveState()
{
	Destroy();
}
LRESULT GameState_Ending::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	return result;
}