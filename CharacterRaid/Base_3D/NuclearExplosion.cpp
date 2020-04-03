#include "stdafx.h"
#include "NuclearExplosion.h"


NuclearExplosion::NuclearExplosion()
{
}


NuclearExplosion::~NuclearExplosion()
{
}

void NuclearExplosion::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 7, 7);
	Billboard::SetTexture(TextureManager::GetTexture("ÇÙ-3.png"));
	

}

void NuclearExplosion::Destroy(){
	Billboard::Destroy();
}

void NuclearExplosion::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}

void NuclearExplosion::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void NuclearExplosion::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	m_vPos.y = 14;
	m_vPos.z += 6;
	isPlay = true;
}

void NuclearExplosion::Reset(){
	frameX = 0;
	frameY = 0;

}