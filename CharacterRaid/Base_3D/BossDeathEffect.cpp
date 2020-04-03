#include "stdafx.h"
#include "BossDeathEffect.h"


BossDeathEffect::BossDeathEffect()
{
}


BossDeathEffect::~BossDeathEffect()
{
}

void BossDeathEffect::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 8, 4);
	Billboard::SetTexture(TextureManager::GetTexture("acidsplash_anim1.png"));
	isPlay = true;
}
void BossDeathEffect::Destroy(){
	Billboard::Destroy();
}
void BossDeathEffect::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}
void BossDeathEffect::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void BossDeathEffect::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	isPlay = true;
}
void BossDeathEffect::Reset(){
	frameX = 0;
	frameY = 0;
}