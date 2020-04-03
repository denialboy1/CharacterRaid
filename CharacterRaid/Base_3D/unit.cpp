#include "stdafx.h"
#include "unit.h"


unit::unit()
{
}


unit::~unit()
{
}

void unit::Initialize(){
	mesh = new SkinnedMesh;
	collision = new Collider_Sphere;
}

void unit::Destroy(){
	SkinnedMeshManager::Get().Destroy();
	SAFE_DELETE(mesh);
	SAFE_DELETE(collision);
}

void unit::Update(){
	GameObject::Update();

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

	mesh->GetCollisionSphere()->GetBoundingSphere().center = position;
	mesh->GetCollisionBox()->SetPosition(position);
	mesh->GetCollisionBox()->Update();
	world = mScale * rotation * mPosition;

	mesh->SetWorld(world);


	D3DXMatrixIdentity(&obbWorld);
	obbWorld = rotation * mPosition;
}

void unit::Battle(unit& enemy)
{
	;
}

void unit::removeAction(){
	SAFE_DELETE(action);
}

void unit::DirectionUpdate(){
	D3DXMatrixIdentity(&world);

	D3DXMATRIX rotation;
	D3DXMatrixRotationY(&rotation, rotationAngle + BASE_ANGLE);
	world *= rotation;

	D3DXVECTOR3 baseDirection(0, 0, 1);
	D3DXVec3TransformCoord(&direction, &baseDirection, &world);
}