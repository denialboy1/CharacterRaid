#include "stdafx.h"
#include "HitSphere.h"


HitSphere::HitSphere()
{
}


HitSphere::~HitSphere()
{
}

void HitSphere::Initialize()
{
	SkillObject::Initialize();

}
void HitSphere::Destroy()
{
	SkillObject::Destroy();
	//if (sphere)
	//{
	//	SAFE_DELETE(sphere);
	//}
	
}
void HitSphere::Update()
{
	SkillObject::Update();
	if (sphere)
	{
		sphere->Update();

	}
}
void HitSphere::Render()
{
	SkillObject::Render();
	if (sphere)
	{
		sphere->Render();
	}
}
void HitSphere::Reset(){
	passedTime = 0.0f;
	passedTime1 = 0.0f;
}