#include "stdafx.h"
#include "Burn.h"


Burn::Burn()
{
}


Burn::~Burn()
{
}


void Burn::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	isStart = false;
	if (fire1 == nullptr){
		fire1 = new Billboard;
		fire1->Initialize(_pos, _size, 12, 6);
		fire1->SetTexture(TextureManager::GetTexture("burn.png"));
	}

	if (fire2 == nullptr){
		fire2 = new Billboard;
		fire2->Initialize(_pos, _size, 12, 6);
		fire2->SetTexture(TextureManager::GetTexture("burn.png"));
	}

	if (fire3 == nullptr){
		fire3 = new Billboard;
		fire3->Initialize(_pos, _size, 12, 6);
		fire3->SetTexture(TextureManager::GetTexture("burn.png"));
	}
}
void Burn::Destroy(){
	SAFE_DELETE(fire1);
}
void Burn::Update(D3DXVECTOR3 pos,D3DXVECTOR3 playerPos){
	if (!isStart) return;
	if (fire1) {
		D3DXVECTOR3 temp = playerPos;
		temp.z = playerPos.z + 1;
		fire1->Update(pos);
		fire1->SetPos(temp);
	}
	if (fire2) {
		D3DXVECTOR3 temp = playerPos;
		temp.z = playerPos.z + 0.5;
		temp.x = playerPos.x + 0.5;
		fire2->Update(pos);
		fire2->SetPos(temp);
	}
	if (fire3) {
		D3DXVECTOR3 temp = playerPos;
		temp.z = playerPos.z + 0.3;
		temp.x = playerPos.x - 0.3;
		fire3->Update(pos);
		fire3->SetPos(temp);
	}
	if (!fire1->GetIsPlay()) isStart = false;
}
void Burn::Render(){
	if (!isStart) return;
	if (fire1) fire1->Render();
	if (fire2) fire2->Render();
	if (fire3) fire3->Render();
}

void Burn::Start(D3DXVECTOR3 _pos){
	isStart = true;

	if (fire1){
		fire1->Initialize(_pos, D3DXVECTOR3(1, 1, 1), 12, 6);
		fire1->SetIsPlay(true);
	}
	if (fire2){
		fire2->Initialize(_pos, D3DXVECTOR3(1, 1, 1), 12, 6);
		fire2->SetIsPlay(true);
	}
	if (fire3){
		fire3->Initialize(_pos, D3DXVECTOR3(1, 1, 1), 12, 6);
		fire3->SetIsPlay(true);
	}
	
}
void Burn::Reset(){

}