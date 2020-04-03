#include "stdafx.h"
#include "characterDeath.h"


characterDeath::characterDeath()
{
}


characterDeath::~characterDeath()
{
}

void characterDeath::Initialize(){
	if (death == nullptr){
		death = new Billboard;
		death->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(5, 5, 5), 10, 2);
		death->SetTexture(TextureManager::GetTexture("CharacterDeath.png"));
		death->SetIsPlay(false);
	}
}

void characterDeath::Destroy(){
	SAFE_DELETE(death);
}

void characterDeath::Update(){
	if (!death->GetIsPlay()) return;

	death->Update(GameManager::Get().GetCamera()->GetEyePosition());
}

void characterDeath::Render(){
	if (!death->GetIsPlay()) return;
	death->Render();
}

void characterDeath::Start(D3DXVECTOR3 pos){
	death->SetPos(pos);
	death->SetIsPlay(true);
}