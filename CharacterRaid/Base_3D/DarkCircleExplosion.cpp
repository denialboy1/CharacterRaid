#include "stdafx.h"
#include "DarkCircleExplosion.h"


DarkCircleExplosion::DarkCircleExplosion()
{
}


DarkCircleExplosion::~DarkCircleExplosion()
{
}

void DarkCircleExplosion::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 4, 4);
	Billboard::SetTexture(TextureManager::GetTexture("animbloodsplat1_purple.dds"));
	isPlay = true;
}
void DarkCircleExplosion::Destroy(){
	Billboard::Destroy();
}
void DarkCircleExplosion::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}
void DarkCircleExplosion::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void DarkCircleExplosion::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	isPlay = true;
}
void DarkCircleExplosion::Reset(){
	frameX = 0;
	frameY = 0;
}