#include "stdafx.h"
#include "IceEffect.h"


IceEffect::IceEffect()
{
}


IceEffect::~IceEffect()
{
}


void IceEffect::Initialize(){
	if (ice == nullptr){
		ice = new Billboard;
		ice->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(3, 3, 3),8, 8);
		ice->SetTexture(TextureManager::GetTexture("particlefx_14_1.png"));
		ice->SetIsPlay(false);
	}

	
}

void IceEffect::Destroy(){
	SAFE_DELETE(ice);
}

void IceEffect::Update(){
	if (!ice->GetIsPlay()) return;

	ice->Update(GameManager::Get().GetCamera()->GetEyePosition());
}

void IceEffect::Render(){
	if (!ice->GetIsPlay())return;
	ice->Render();
}

void IceEffect::Start(D3DXVECTOR3 pos){
	ice->SetPos(pos + D3DXVECTOR3(0,3,0));
	ice->SetIsPlay(true);
	soundManager::Get().play("iceAttack", 1.0f);
}