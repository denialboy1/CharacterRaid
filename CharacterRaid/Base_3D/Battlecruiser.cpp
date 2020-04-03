#include "stdafx.h"
#include "Battlecruiser.h"


Battlecruiser::Battlecruiser()
{
}


Battlecruiser::~Battlecruiser()
{
}


void Battlecruiser::Initialize()
{
	SkillObject::Initialize();
	//BattleCruiserMoveX = 0.0f;
	BattleCruiserMoveZ = 0.0f;
	BattleCruiserAngle = 0;
	if (mesh == nullptr)
	{
		mesh = new SkinnedMesh;
		mesh->Initialize("", "Battlecruiser.X", scale);
		rotationAngle = BattleCruiserAngle;
		scale.x = 5;
		scale.y = 5;
		scale.z = 5;
		mesh->SetAnimationIndex(1);
	}
	//battleCruiserBoom = new BattleCruiserBoom;
	//battleCruiserBoom->Initialize(position, D3DXVECTOR3(4, 4, 4));



}
void Battlecruiser::Destroy()
{
	SkillObject::Destroy();
	
	//SAFE_DELETE(battleCruiserBoom);
}
void Battlecruiser::Update() 
{
	SkillObject::Update();

	
	//battleCruiserBoom->Update(GameManager::Get().GetCamera()->GetEyePosition());
	position = position - direction * 0.2;

	//position = D3DXVECTOR3(0, 7, BattleCruiserMoveZ);
	//BattleCruiserMoveZ += 0.1f;
	position.y = 19;
	//BattleCruiserBoomSphere->GetBoundingSphere().
}
void Battlecruiser::Render()
{

	SkillObject::Render();
	//battleCruiserBoom->Render();
	if (mesh){
		mesh->UpdateAndRender();
	}

}