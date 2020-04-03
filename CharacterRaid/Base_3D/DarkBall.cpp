#include "stdafx.h"
#include "DarkBall.h"


DarkBall::DarkBall()
{
}


DarkBall::~DarkBall()
{
}
void DarkBall::Initialize(){
	SkillObject::Initialize();
	if (mesh == nullptr){
		mesh = new SkinnedMesh;
		scale.x = 0.005f;
		scale.y = 0.005f;
		scale.z = 0.005f;
		mesh->Initialize("켈타스스킬/", "LivingBomb.X", scale);  //경로지정
		mesh->SetAnimationIndex(0);

		obbBox->Setup(mesh);
	}
}

void DarkBall::Destroy(){
	SkillObject::Destroy();
}

void DarkBall::Update(){
	SkillObject::Update();
	obbBox->Update(&obbWorld);

	if (!fire){
		currentTimer = (timeGetTime() - startTimer)*0.001f;
		if (currentTimer > timer){
			fire = true;
		}
	}
	else{
		D3DXVECTOR3 temp;
		D3DXVec3Normalize(&temp, &(enemyPos - kelthasPos));
		temp.x = direction.x;
		temp.z = direction.z;
		temp.y = -temp.y;
		position -= temp * 0.5;
	}
}

void DarkBall::Render(){
	SkillObject::Render();
	if (mesh){
		mesh->UpdateAndRender();
	}
	//obbBox->DebugRender(D3DCOLOR_XRGB(255, 0, 0));
}

void DarkBall::Reset(){
	fire = false;
	startTimer = 0.0f;
	currentTimer = 0.0f;
	timer = 0.0f;
}