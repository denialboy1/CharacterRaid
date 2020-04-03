#include "stdafx.h"
#include "IceImpact.h"


IceImpact::IceImpact()
{
}


IceImpact::~IceImpact()
{
}

void IceImpact::Initialize(D3DXVECTOR3 _pos,D3DXVECTOR3 _size,int _frameX, int _frameY){
	Billboard::Initialize(_pos, _size, _frameX, _frameY);
	Billboard::SetTexture(TextureManager::GetTexture("Storm_Hero_Melee_ImpactBlue.dds"));
}

void IceImpact::Destroy(){
	Billboard::Destroy();
}

void IceImpact::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}

void IceImpact::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void IceImpact::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	isPlay = true;
}

void IceImpact::Reset(){
	frameX = 0;
	frameY = 0;

}