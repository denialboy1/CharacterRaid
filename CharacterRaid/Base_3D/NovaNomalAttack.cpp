#include "stdafx.h"
#include "NovaNomalAttack.h"


NovaNomalAttack::NovaNomalAttack()
{
}


NovaNomalAttack::~NovaNomalAttack()
{
}

void NovaNomalAttack::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size){
	Billboard::Initialize(_pos, _size, 13, 1);
	Billboard::SetTexture(TextureManager::GetTexture("∆Ú≈∏¿Ã∆Â∆Æ.png"));


}

void NovaNomalAttack::Destroy(){
	Billboard::Destroy();
}

void NovaNomalAttack::Update(D3DXVECTOR3 _cameraPos){
	if (!isPlay) return;
	Billboard::Update(_cameraPos);
}

void NovaNomalAttack::Render(){
	if (!isPlay) return;
	Billboard::Render();
}

void NovaNomalAttack::Start(D3DXVECTOR3 _pos){
	m_vPos = _pos;
	//m_vPos.y = 2;
	//m_vPos.z += 6;
	isPlay = true;
}

void NovaNomalAttack::Reset(){
	frameX = 0;
	frameY = 0;

}
