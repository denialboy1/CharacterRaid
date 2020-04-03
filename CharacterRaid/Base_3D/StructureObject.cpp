#include "stdafx.h"
#include "StructureObject.h"


StructureObject::StructureObject()
{
}


StructureObject::~StructureObject()
{
}

void StructureObject::Initialize(char* path, char* fileName, D3DXVECTOR3 _scale){
	mesh = new SkinnedMesh;
	mesh->Initialize(path, fileName, _scale);
	scale = _scale;
	sphere = new Collider_Sphere;
	sphere->Initialize(position, (mesh->GetMin().x + mesh->GetMax().x) / 2);
}

void StructureObject::Destroy(){
	GameObject::Destroy();
	SkinnedMeshManager::Get().Destroy();
	SAFE_DELETE(mesh);
	SAFE_DELETE(sphere);
}

void StructureObject::Update(){
	

	D3DXMatrixIdentity(&world);
	D3DXMATRIX rotation;
	D3DXMatrixRotationY(&rotation, rotationAngle + BASE_ANGLE);
	world *= rotation;

	D3DXVECTOR3 baseDirection(0, 0, 1);
	D3DXVec3TransformCoord(&direction, &baseDirection, &world);

	D3DXMATRIXA16 mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);

	D3DXMATRIXA16 mPosition;
	D3DXMatrixTranslation(&mPosition, position.x, position.y, position.z);

	world = mScale * rotation * mPosition;

	mesh->SetWorld(world);


	D3DXMatrixIdentity(&obbWorld);

	GameObject::Update();
}

void StructureObject::Render(){
	if (mesh) mesh->UpdateAndRender();
	if (sphere && isDebug) sphere->Render();
}