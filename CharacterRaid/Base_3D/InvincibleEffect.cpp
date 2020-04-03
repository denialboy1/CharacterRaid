#include "stdafx.h"
#include "InvincibleEffect.h"


InvincibleEffect::InvincibleEffect()
{
}


InvincibleEffect::~InvincibleEffect()
{
}

void InvincibleEffect::Initialize(){
	if (shield == nullptr){
		shield = new Billboard;
		shield->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(2, 2, 2), 4, 1);
		shield->SetTexture(TextureManager::GetTexture("shield1.png"));
		shield->SetIsPlay(false);
	}
}

void InvincibleEffect::Destroy(){
	SAFE_DELETE(shield);
}

void InvincibleEffect::Update(D3DXVECTOR3 pos){
	if (!isStart) return;

	shield->Update(GameManager::Get().GetCamera()->GetEyePosition());
	shield->SetPos(pos + D3DXVECTOR3(0, 2, 0));
}

void InvincibleEffect::Render(){
	if (!isStart) return;
	shield->Render();
}

void InvincibleEffect::Start(D3DXVECTOR3 pos){
	shield->SetPos(pos);
	isStart = true;
}