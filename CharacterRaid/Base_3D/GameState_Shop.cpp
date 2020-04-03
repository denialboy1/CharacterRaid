#include "stdafx.h"
#include "GameState_Shop.h"


GameState_Shop::GameState_Shop()
{
}


GameState_Shop::~GameState_Shop()
{
}

void GameState_Shop::Initialize(){
	if (shop == nullptr){
		shop = new Shop;
		shop->Initialize();
		UI_Manager::Get().SetRoot(shop);
	}
	soundManager::Get().addSound("shopbgm", "Data/Sound/»óÁ¡.mp3", true, true);
	soundManager::Get().play("shopbgm", 0.5f);

}
void GameState_Shop::Destroy(){
	SAFE_DELETE(shop);
	UI_Manager::Get().SetRoot(nullptr);
	soundManager::Get().stop("shopbgm");
}
void GameState_Shop::Reset(){

}
void GameState_Shop::Update() {
	if (shop){
		shop->Update();
	}
}
void GameState_Shop::Render() {
	if (shop){
		shop->Render();
	}
}

HRESULT GameState_Shop::OnEnterState(){
	Initialize();
	return S_OK;
}

void GameState_Shop::OnLeaveState(){
	Destroy();
}

LRESULT GameState_Shop::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;
	if (shop){
		shop->InputProc(hWnd, message, wParam, lParam);
	}
	return result;
}