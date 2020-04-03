#include "stdafx.h"
#include "BossDeath.h"


BossDeath::BossDeath()
{
}


BossDeath::~BossDeath()
{
}

void BossDeath::Initialize(){
	if (death == nullptr){
		death = new Billboard;
		death->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(5, 5, 5), 9, 2);
		death->SetTexture(TextureManager::GetTexture("enemyDeath.png"));
		death->SetIsPlay(false);
	}
}

void BossDeath::Destroy(){
	SAFE_DELETE(death);
}

void BossDeath::Update(){
	if (!death->GetIsPlay()) return;

	death->Update(GameManager::Get().GetCamera()->GetEyePosition());
}

void BossDeath::Render(){
	if (!death->GetIsPlay()) return;
	death->Render();
}

void BossDeath::Start(D3DXVECTOR3 pos){
	death->SetPos(pos);
	death->SetIsPlay(true);
}
