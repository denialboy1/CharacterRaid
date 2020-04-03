#include "stdafx.h"
#include "Phoenix_Circle.h"


Phoenix_Circle::Phoenix_Circle()
{
}


Phoenix_Circle::~Phoenix_Circle()
{
}

void Phoenix_Circle::Initialize(){
	if (mesh == nullptr){
		mesh = new SkinnedMesh;
		mesh->Initialize("ÇÇ´Ð½º/AOE/", "aoe.X", scale);
		scale = D3DXVECTOR3(0.03, 0.03, 0.03);
		rotate = D3DXVECTOR3(0, 0, 0);
		position = D3DXVECTOR3(0, 2.1, 0);
	}
}

void Phoenix_Circle::Destroy(){
	SAFE_DELETE(mesh);
}

void Phoenix_Circle::Update(D3DXVECTOR3 pos){

	rotate.y += 0.1f;
	position = pos;
	position.y += 2;
	D3DXMATRIXA16 mScale;
	D3DXMatrixIdentity(&mScale);
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);

	D3DXMATRIXA16 mRotate;
	D3DXMatrixIdentity(&mRotate);
	D3DXMatrixRotationY(&mRotate, rotate.y);

	D3DXMATRIXA16 mPosition;
	D3DXMatrixIdentity(&mPosition);
	D3DXMatrixTranslation(&mPosition, position.x, position.y, position.z);

	world = mScale * mRotate * mPosition;
	mesh->SetWorld(world);
}

void Phoenix_Circle::Render(){
	if (mesh) mesh->UpdateAndRender();
}