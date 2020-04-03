#include "stdafx.h"
#include "Fire_Shield.h"


Fire_Shield::Fire_Shield()
{
}


Fire_Shield::~Fire_Shield()
{
}

void Fire_Shield::Initialize(){
	SkillObject::Initialize();
	if (mesh == nullptr){
		mesh = new SkinnedMesh;
		scale.x = 0.07f;
		scale.y = 0.07f;
		scale.z = 0.07f;
		mesh->Initialize("켈타스스킬/shield/", "shield.X", scale);  //경로지정
		mesh->SetAnimationIndex(0);
		timer = 10;
		obbBox->Setup(mesh);
	}
}

void Fire_Shield::Destroy(){
	SkillObject::Destroy();
}

void Fire_Shield::Update(D3DXVECTOR3 pos){
	if (!start) return;
	SkillObject::Update();
	position = pos;
	position.y = 3;
	currentTimer = (timeGetTime() - startTimer)*0.001f;
	rotationAngle += 0.05f;
	if (currentTimer > timer){
		start = false;
		Reset();
	}
}

void Fire_Shield::Render(){
	if (!start) return;
	SkillObject::Render();
	if (mesh){
		mesh->UpdateAndRender();
	}
}

void Fire_Shield::Reset(){
	start = false;
	startTimer = 0.0f;
	currentTimer = 0.0f;
	rotationAngle = 0.0f;
}

void Fire_Shield::Start(){
	start = true;
	startTimer = timeGetTime();
}