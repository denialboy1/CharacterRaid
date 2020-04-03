#include "stdafx.h"
#include "VikingAttack.h"


VikingAttack::VikingAttack()
{
}


VikingAttack::~VikingAttack()
{
}


void VikingAttack::Initialize()
{
	SkillObject::Initialize();

	BattleCruiserMoveZ = 0.0f;
	BattleCruiserAngle = 0;
	if (mesh == nullptr)
	{
		mesh = new SkinnedMesh;
		mesh->Initialize("", "Battlecruiser.X", scale);
		rotationAngle = BattleCruiserAngle;
		scale.x = 4;
		scale.y = 4;
		scale.z = 4;
		mesh->SetAnimationIndex(1);
	}
}
void VikingAttack::Destroy()
{
	SkillObject::Destroy();
}
void VikingAttack::Update()
{
	SkillObject::Update();


	position = position - direction * 0.2;

	//position = D3DXVECTOR3(0, 7, BattleCruiserMoveZ);
	//BattleCruiserMoveZ += 0.1f;



}
void VikingAttack::Render()
{

	SkillObject::Render();

	if (mesh){
		mesh->UpdateAndRender();
	}
}