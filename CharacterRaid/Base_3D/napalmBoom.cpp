#include "stdafx.h"
#include "napalmBoom.h"


napalmBoom::napalmBoom()
{
}


napalmBoom::~napalmBoom()
{
}


void napalmBoom::Initialize()
{
	SkillObject::Initialize();

	if (mesh == nullptr)
	{
		mesh = new SkinnedMesh;
		mesh->Initialize("", "Battlecruiser.X", scale);
		scale.x = 4;
		scale.y = 4;
		scale.z = 4;
		mesh->SetAnimationIndex(1);
	}
}
void napalmBoom::Destroy()
{
	SkillObject::Destroy();


}
void napalmBoom::Update()
{
	SkillObject::Update();


}
void napalmBoom::Render()
{
	SkillObject::Render();

	if (mesh){
		mesh->UpdateAndRender();
	}
}