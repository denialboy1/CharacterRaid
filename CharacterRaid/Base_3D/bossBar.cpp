#include "stdafx.h"
#include "bossBar.h"


bossBar::bossBar()
{
}


bossBar::~bossBar()
{
}

void bossBar::Initialize(float _maxHp, float _maxMp){
	currentHp = maxHp = _maxHp;
	currentMp = maxMp = _maxMp;

	if (hpBottom == nullptr){
		hpBottom = new Billboard;
		hpBottom->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(4, 1, 1), 1, 1, true);
		hpBottom->SetTexture(TextureManager::GetTexture("./enemy/bossEmpty.png"));
	}
	if (hpTop == nullptr){
		hpTop = new Billboard;
		hpTop->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(4, 1, 1), 1, 1, true);
		hpTop->SetTempX(0);
		hpTop->SetTexture(TextureManager::GetTexture("./enemy/bossHp.png"));
	}

	if (mpBottom == nullptr){
		mpBottom = new Billboard;
		mpBottom->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(4, 1, 1), 1, 1, true);
		mpBottom->SetTexture(TextureManager::GetTexture("./enemy/bossEmpty2.png"));
	}
	if (mpTop == nullptr){
		mpTop = new Billboard;
		mpTop->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(4, 1, 1), 1, 1, true);
		mpTop->SetTempX(0);
		mpTop->SetTexture(TextureManager::GetTexture("./enemy/bossMp.png"));
	}

	if (hpBar == nullptr){
		hpBar = new Billboard;
		hpBar->Initialize(D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(4, 1, 1), 1, 1, true);
		hpBar->SetTexture(TextureManager::GetTexture("./enemy/bossBar.png"));
	}
}

void bossBar::Destroy(){
	SAFE_DELETE(hpBottom);
	SAFE_DELETE(hpTop);
	SAFE_DELETE(mpBottom);
	SAFE_DELETE(mpTop);
	SAFE_DELETE(hpBar);
}

void bossBar::Update(D3DXVECTOR3 cameraPos, D3DXVECTOR3 pos){
	if (hpBottom){
		hpBottom->Update(cameraPos);
		hpBottom->SetVPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
	}
	if (hpTop){
		hpTop->Update(cameraPos);
		hpTop->SetTempX(hpTop->GetWidth() - currentHp * hpTop->GetWidth() / maxHp);
		hpTop->SetVPos(D3DXVECTOR3(pos.x,pos.y,pos.z));
	}
	if (mpBottom){
		mpBottom->Update(cameraPos);
		mpBottom->SetVPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
	}
	if (mpTop){
		mpTop->Update(cameraPos);
		mpTop->SetTempX(mpTop->GetWidth() - currentMp * mpTop->GetWidth() / maxMp);
		mpTop->SetVPos(D3DXVECTOR3(pos.x, pos.y, pos.z));
	}

	if (hpBar){
		hpBar->Update(cameraPos);
		hpBar->SetVPos(pos);
	}
}

void bossBar::Render(){
	if (hpBottom){
		hpBottom->Render();
	}
	if (hpTop){
		hpTop->Render();
	}
	if (mpBottom){
		mpBottom->Render();
	}
	if (mpTop){
		mpTop->Render();
	}
	if (hpBar){
		hpBar->Render();
	}
	
}