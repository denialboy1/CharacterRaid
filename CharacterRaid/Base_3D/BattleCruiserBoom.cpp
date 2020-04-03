#include "stdafx.h"
#include "BattleCruiserBoom.h"


BattleCruiserBoom::BattleCruiserBoom()
{
}


BattleCruiserBoom::~BattleCruiserBoom()
{
}

void BattleCruiserBoom::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 10, 10);
	Billboard::SetTexture(TextureManager::GetTexture("지원포격-2.png"));


}

void BattleCruiserBoom::Destroy(){
	Billboard::Destroy();
}

void BattleCruiserBoom::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}

void BattleCruiserBoom::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void BattleCruiserBoom::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	m_vPos.y = 12;
	m_vPos.z += 6;
	isPlay = true;
}

void BattleCruiserBoom::Reset(){
	frameX = 0;
	frameY = 0;

}