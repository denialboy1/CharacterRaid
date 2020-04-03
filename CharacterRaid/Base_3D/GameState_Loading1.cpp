#include "stdafx.h"
#include "GameState_Loading1.h"


GameState_Loading1::GameState_Loading1()
{
}


GameState_Loading1::~GameState_Loading1()
{
}

void GameState_Loading1::Initialize(){
	_loading = new loading;
	_loading->Initialize();

	_loading->loadTexture("stage1-3.jpg");
	_loading->loadMesh("","노바.x");
	_loading->loadMesh("", "Nuke.x");
	_loading->loadMesh("", "Battlecruiser.x");
	_loading->loadMesh("HammerBoss/", "해머상사.X");
	_loading->loadMesh("HammerBoss/", "BansheeMissile.X");
	_loading->loadTexture("./UI/hpmp/hpbar-1.png");
	_loading->loadTexture("./UI/hpmp/mpbar.png");
	_loading->loadTexture("./UI/hpmp/경험치바-3.png");
	_loading->loadTexture("./UI/bossRaidUI-3.png");
	_loading->loadTexture("./UI/skill/평타.png");
	_loading->loadTexture("./UI/skill/무브.png");
	_loading->loadTexture("./UI/skill/중지.png");
	_loading->loadTexture("./UI/skill/저격-1.png");
	_loading->loadTexture("./UI/skill/히페리온 지원사격.png");
	_loading->loadTexture("./UI/skill/강인한문양.png");
	_loading->loadTexture("./UI/skill/핵수정본-1.png");
	_loading->loadTexture("./UI/skill/제이나 얼음 발사.png");
	_loading->loadTexture("./UI/skill/제이나 얼음소환.png");
	_loading->loadTexture("./UI/skill/제이나 마나재생.png");
	_loading->loadTexture("./UI/skill/제이나 120개얼음.png");
	_loading->loadTexture("./UI/skill/징벌.png");
	_loading->loadTexture("./UI/skill/규탄.png");
	_loading->loadTexture("./UI/skill/강철피부.png");
	_loading->loadTexture("./UI/skill/빛나는방패.png");
	_loading->loadTexture("./UI/item/HP물약.png");
	_loading->loadTexture("./UI/item/MP물약.png");
	_loading->loadTexture("./UI/item/파워허브.png");
	_loading->loadTexture("./UI/item/아머포션.png");
	_loading->loadTexture("./UI/item/스턴용 단검.png");
	_loading->loadTexture("./UI/item/무적주문서.png");
	_loading->loadTexture("./UI/atifact/블리읔.png");
	_loading->loadTexture("./UI/atifact/무적반지.png");
	_loading->loadTexture("./UI/atifact/전광석화.png");
	_loading->loadMesh ("Stage1Enemy/", "VikingAssert.x");
	_loading->loadTexture("핵-2.png");
}
void GameState_Loading1::Destroy(){


}
void GameState_Loading1::Update(){
	_loading->Update();

	if (!_loading->loadNext())
	{
		GameStateManager::Get().ChangeGameState(GameStateType::STATE_STAGE1);
	}
}
void GameState_Loading1::Render(){
	_loading->Render();

}

HRESULT GameState_Loading1::OnEnterState(){
	Initialize();

	return S_OK;
}

void GameState_Loading1::OnLeaveState(){

}

LRESULT GameState_Loading1::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	LRESULT result = 0;
	return result;
}

void GameState_Loading1::Reset(){
	
}