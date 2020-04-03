#include "stdafx.h"
#include "FireCircleExplosion.h"


FireCircleExplosion::FireCircleExplosion()
{
}


FireCircleExplosion::~FireCircleExplosion()
{
}

void FireCircleExplosion::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 3, 4);
	Billboard::SetTexture(TextureManager::GetTexture("explosion.png"));
	isPlay = true;
}
void FireCircleExplosion::Destroy(){
	Billboard::Destroy();
}
void FireCircleExplosion::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}
void FireCircleExplosion::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void FireCircleExplosion::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	isPlay = true;
}
void FireCircleExplosion::Reset(){
	frameX = 0;
	frameY = 0;
}