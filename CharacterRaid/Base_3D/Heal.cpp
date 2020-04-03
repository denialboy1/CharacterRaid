#include "stdafx.h"
#include "Heal.h"


Heal::Heal()
{
}


Heal::~Heal()
{
}


void Heal::Initialize(){
	if (heal == nullptr){
		heal = new Billboard;
		heal->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(2, 2, 2), 6, 1);
		heal->SetTexture(TextureManager::GetTexture("heal.png"));
		heal->SetIsPlay(false);
	}
}

void Heal::Destroy(){
	SAFE_DELETE(heal);
}

void Heal::Update(D3DXVECTOR3 pos){
	if (!heal->GetIsPlay()) return;

	heal->Update(GameManager::Get().GetCamera()->GetEyePosition());
	heal->SetPos(pos + D3DXVECTOR3(0, 3, 0));
}

void Heal::Render(){
	if (!heal->GetIsPlay()) return;
	heal->Render();
}

void Heal::Start(D3DXVECTOR3 pos){
	heal->SetPos(pos);
	heal->SetIsPlay(true);
}