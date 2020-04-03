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
	_loading->loadMesh("","���.x");
	_loading->loadMesh("", "Nuke.x");
	_loading->loadMesh("", "Battlecruiser.x");
	_loading->loadMesh("HammerBoss/", "�ظӻ��.X");
	_loading->loadMesh("HammerBoss/", "BansheeMissile.X");
	_loading->loadTexture("./UI/hpmp/hpbar-1.png");
	_loading->loadTexture("./UI/hpmp/mpbar.png");
	_loading->loadTexture("./UI/hpmp/����ġ��-3.png");
	_loading->loadTexture("./UI/bossRaidUI-3.png");
	_loading->loadTexture("./UI/skill/��Ÿ.png");
	_loading->loadTexture("./UI/skill/����.png");
	_loading->loadTexture("./UI/skill/����.png");
	_loading->loadTexture("./UI/skill/����-1.png");
	_loading->loadTexture("./UI/skill/���丮�� �������.png");
	_loading->loadTexture("./UI/skill/�����ѹ���.png");
	_loading->loadTexture("./UI/skill/�ټ�����-1.png");
	_loading->loadTexture("./UI/skill/���̳� ���� �߻�.png");
	_loading->loadTexture("./UI/skill/���̳� ������ȯ.png");
	_loading->loadTexture("./UI/skill/���̳� �������.png");
	_loading->loadTexture("./UI/skill/���̳� 120������.png");
	_loading->loadTexture("./UI/skill/¡��.png");
	_loading->loadTexture("./UI/skill/��ź.png");
	_loading->loadTexture("./UI/skill/��ö�Ǻ�.png");
	_loading->loadTexture("./UI/skill/�����¹���.png");
	_loading->loadTexture("./UI/item/HP����.png");
	_loading->loadTexture("./UI/item/MP����.png");
	_loading->loadTexture("./UI/item/�Ŀ����.png");
	_loading->loadTexture("./UI/item/�Ƹ�����.png");
	_loading->loadTexture("./UI/item/���Ͽ� �ܰ�.png");
	_loading->loadTexture("./UI/item/�����ֹ���.png");
	_loading->loadTexture("./UI/atifact/����.png");
	_loading->loadTexture("./UI/atifact/��������.png");
	_loading->loadTexture("./UI/atifact/������ȭ.png");
	_loading->loadMesh ("Stage1Enemy/", "VikingAssert.x");
	_loading->loadTexture("��-2.png");
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