#include "stdafx.h"
#include "ShieldBash.h"


ShieldBash::ShieldBash()
{
}


ShieldBash::~ShieldBash()
{
}

void ShieldBash::Initialize()
{
	SkillObject::Initialize();
	if (mesh == nullptr)
	{
		mesh = new SkinnedMesh;
		mesh->Initialize("ShieldBash/", "ShieldBash.X", scale);
		scale.x = 0.01f;
		scale.y = 0.01f;
		scale.z = 0.01f;
		mesh->SetAnimationIndex(0);
	}
}
void ShieldBash::Destroy()
{
	SkillObject::Destroy();
}
void ShieldBash::Update()
{
	SkillObject::Update();
	if (IsAnimInit)
	{
		mesh->GetAnimController()->SetTrackPosition(0, 0);
		mesh->GetAnimController()->SetTrackSpeed(0, 0.0001);
	}
	else{
		//mesh->GetAnimController()->SetTrackPosition(0, 0);
		mesh->GetAnimController()->SetTrackSpeed(0, 1);
	}
}
void ShieldBash::Render()
{
	SkillObject::Render();
	if (mesh)
	{
		mesh->UpdateAndRender();
	}
}
void ShieldBash::ChangeMotion(EFFECT_STATE _state)
{

}