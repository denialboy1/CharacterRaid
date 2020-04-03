#include "stdafx.h"
#include "PillarOfFire.h"


PillarOfFire::PillarOfFire()
{
}


PillarOfFire::~PillarOfFire()
{
}

void PillarOfFire::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 6, 2);
	Billboard::SetTexture(TextureManager::GetTexture("pillar_of_fire.png"));
	isPlay = true;
}
void PillarOfFire::Destroy(){
	Billboard::Destroy();
}
void PillarOfFire::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}
void PillarOfFire::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void PillarOfFire::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	isPlay = true;
}
void PillarOfFire::Reset(){
	frameX = 0;
	frameY = 0;
}