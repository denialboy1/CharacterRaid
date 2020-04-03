#include "stdafx.h"
#include "IceCircle.h"


IceCircle::IceCircle()
{
}


IceCircle::~IceCircle()
{
}

void IceCircle::Initialize(float _size){
	SkillObject::Initialize();
	size = _size;
	triangle[0].vertex[0].pos = D3DXVECTOR3(-size/2, 0.1, -size/2);
	triangle[0].vertex[0].tex = D3DXVECTOR2(0, 1);
	triangle[0].vertex[1].pos = D3DXVECTOR3(-size / 2, 0.1, size / 2);
	triangle[0].vertex[1].tex = D3DXVECTOR2(0, 0);
	triangle[0].vertex[2].pos = D3DXVECTOR3(size / 2, 0.1, size / 2);
	triangle[0].vertex[2].tex = D3DXVECTOR2(1, 0);

	triangle[1].vertex[0].pos = D3DXVECTOR3(-size / 2, 0.1, -size / 2);
	triangle[1].vertex[0].tex = D3DXVECTOR2(0, 1);
	triangle[1].vertex[1].pos = D3DXVECTOR3(size / 2, 0.1, size / 2);
	triangle[1].vertex[1].tex = D3DXVECTOR2(1, 0);
	triangle[1].vertex[2].pos = D3DXVECTOR3(size / 2, 0.1, -size / 2);
	triangle[1].vertex[2].tex = D3DXVECTOR2(1, 1);

	SetTexture("Storm_IceCrackA.dds");
}

void IceCircle::SetTexture(char* fileName){ texture = TextureManager::GetTexture(fileName); }

void IceCircle::Destroy(){

}

void IceCircle::Update(){
	SkillObject::Update();
}

void IceCircle::Render(){
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetFVF(FVF_PositionTexture::FVF);
	GameManager::GetDevice()->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		2,
		&triangle[0],
		sizeof(FVF_PositionTexture));
}

void IceCircle::Fire(D3DXVECTOR3 _pos){
	position = _pos;
	sphere->GetBoundingSphere().center = _pos;
}