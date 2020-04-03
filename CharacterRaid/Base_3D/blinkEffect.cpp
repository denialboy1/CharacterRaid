#include "stdafx.h"
#include "blinkEffect.h"


blinkEffect::blinkEffect()
{
}


blinkEffect::~blinkEffect()
{
}

void blinkEffect::Initialize(){
	if (blink == nullptr){
		blink = new Billboard;
		blink->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(3, 3, 3), 8, 7);
		blink->SetTexture(TextureManager::GetTexture("teleport.png"));
		blink->SetIsPlay(false);
	}
}

void blinkEffect::Destroy(){
	SAFE_DELETE(blink);
}

void blinkEffect::Update(){
	if (!blink->GetIsPlay()) return;

	blink->Update(GameManager::Get().GetCamera()->GetEyePosition());
}

void blinkEffect::Render(){
	if (!blink->GetIsPlay()) return;
	blink->Render();
}

void blinkEffect::Start(D3DXVECTOR3 pos){
	blink->SetPos(pos + D3DXVECTOR3(0,3,0));
	blink->SetIsPlay(true);
}
