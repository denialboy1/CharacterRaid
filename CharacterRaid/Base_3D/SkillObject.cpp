#include "stdafx.h"
#include "SkillObject.h"


SkillObject::SkillObject()
{
}


SkillObject::~SkillObject()
{
}

void SkillObject::Initialize(){
	if (sphere == nullptr){
		sphere = new Collider_Sphere;
		sphere->Initialize(D3DXVECTOR3(0, 0, 0), 1.0f, nullptr);
	}
	if (obbBox == nullptr){
		obbBox = new cOBB;
	}
}

void SkillObject::Destroy(){
	GameObject::Destroy();
	SkinnedMeshManager::Get().Destroy();
	if(mesh) SAFE_DELETE(mesh);
	if (sphere)
	{
		SAFE_DELETE(sphere);
	}
	
	delete obbBox;
}

void SkillObject::Update(){
	

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
	if (mesh)
	{
		mesh->SetWorld(world);
	}
	

	if (action)		action->SetSpeed(speed);
	if (obbBox)		
		obbBox->Update(&world);


	//obb¿ë
	D3DXMatrixIdentity(&obbWorld);
	obbWorld = rotation * mPosition;

	GameObject::Update();
}

void SkillObject::Render(){
	//if (isDebug && obbBox) 
		//obbBox->DebugRender(D3DCOLOR_XRGB(255, 0, 0));
}

