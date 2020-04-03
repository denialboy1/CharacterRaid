#include "stdafx.h"
#include "minionHpBar.h"


minionHpBar::minionHpBar()
{
}


minionHpBar::~minionHpBar()
{
}

void minionHpBar::Initialize(float _maxHp,float _currentHp){
	maxHp = _maxHp;
	currentHp = _currentHp;

	if (hpBottom == nullptr){
		hpBottom = new Billboard;
		hpBottom->Initialize(pos, D3DXVECTOR3(2, 0.75, 1), 1, 1,true);
		hpBottom->SetTexture(TextureManager::GetTexture("./enemy/empty.png"));

	}
	if (hpTop == nullptr){
		hpTop = new Billboard;
		hpTop->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(2, 0.75, 1), 1, 1, true);
		hpTop->SetTempX(0);
		hpTop->SetTexture(TextureManager::GetTexture("./enemy/hp.png"));
	}
	if (hpBar == nullptr){
		hpBar = new Billboard;
		hpBar->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(2, 1, 1), 1, 1, true);
		hpBar->SetTexture(TextureManager::GetTexture("./enemy/enemyBarBottom.png"));
	}
}

void minionHpBar::Destroy(){
	SAFE_DELETE(hpBottom);
	SAFE_DELETE(hpTop);
}

void minionHpBar::Update(D3DXVECTOR3 cameraPos, D3DXVECTOR3 pos){
	pos.y = 10;
	if (hpBottom){
		hpBottom->Update(cameraPos);
		hpBottom->SetVPos(pos);
	}
	if (hpTop){
		hpTop->Update(cameraPos);
		hpTop->SetTempX(hpTop->GetWidth() - currentHp * hpTop->GetWidth() / maxHp);
		hpTop->SetVPos(pos);
	}
	if (hpBar){
		hpBar->Update(cameraPos);
		hpBar->SetVPos(pos);
		
	}
}

void minionHpBar::Render(){
	if (hpBottom){
		hpBottom->Render();
	}
	if (hpTop){
		hpTop->Render();
	}
	if (hpBar){
		hpBar->Render();
	}
}