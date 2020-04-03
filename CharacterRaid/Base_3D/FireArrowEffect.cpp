#include "stdafx.h"
#include "FireArrowEffect.h"


FireArrowEffect::FireArrowEffect()
{
}


FireArrowEffect::~FireArrowEffect()
{
}


void FireArrowEffect::Initialize(){
	if (billboard == nullptr){
		billboard = new Billboard;
		billboard->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(3, 3, 3), 10, 2, false);
		billboard->SetTexture(TextureManager::GetTexture("fireArrowEffect.png"));
		billboard->SetIsPlay(false);
	}
}

void FireArrowEffect::Update(){
	if (!isStart)  return;
	if (billboard) billboard->Update(GameManager::Get().GetCamera()->GetEyePosition());
	isStart = billboard->GetIsPlay();
}

void FireArrowEffect::Render(){
	if (!isStart)  return;
	if (billboard) billboard->Render();
}

void FireArrowEffect::Destroy(){
	if (billboard) SAFE_DELETE(billboard);
}

void FireArrowEffect::Start(D3DXVECTOR3 pos){
	billboard->SetPos(pos);
	billboard->SetIsPlay(true);
	isStart = true;
}