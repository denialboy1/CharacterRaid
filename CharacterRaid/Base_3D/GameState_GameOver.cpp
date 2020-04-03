#include "stdafx.h"
#include "GameState_GameOver.h"


GameState_GameOver::GameState_GameOver()
{
}


GameState_GameOver::~GameState_GameOver()
{
}

void GameState_GameOver::Initialize()
{
	Score_UI* score = new Score_UI;
	score->Initialize();
	score->SetPosition(0, 0, 1);
	score->SetTitle("Score");
	score->SetShow(true);
	score->SetDescription("");
	UI_Manager::Get().SetRoot(score);


}
void GameState_GameOver::Destroy()
{

}
void GameState_GameOver::Reset()
{

}
void GameState_GameOver::Update()
{
	
	
}
void GameState_GameOver::Render()
{
	
}

HRESULT GameState_GameOver::OnEnterState()
{
	Initialize();

	return S_OK;
}
void GameState_GameOver::OnLeaveState()
{
	Destroy();
}
LRESULT GameState_GameOver::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	return result;
}