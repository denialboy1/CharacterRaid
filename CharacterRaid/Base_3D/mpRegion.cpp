#include "stdafx.h"
#include "mpRegion.h"


mpRegion::mpRegion()
{
}


mpRegion::~mpRegion()
{
}

void mpRegion::Initialize(){
	if (death == nullptr){
		death = new Billboard;
		death->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(2, 2, 2), 7, 1);
		death->SetTexture(TextureManager::GetTexture("마나회복.png"));
		death->SetIsPlay(false);
	}
}

void mpRegion::Destroy(){
	SAFE_DELETE(death);
}

void mpRegion::Update(D3DXVECTOR3 pos){
	if (!death->GetIsPlay()) return;

	death->Update(GameManager::Get().GetCamera()->GetEyePosition());
	death->SetPos(pos + D3DXVECTOR3(0,3,0));
}

void mpRegion::Render(){
	if (!death->GetIsPlay()) return;
	death->Render();
}

void mpRegion::Start(D3DXVECTOR3 pos){
	death->SetPos(pos);
	death->SetIsPlay(true);
}