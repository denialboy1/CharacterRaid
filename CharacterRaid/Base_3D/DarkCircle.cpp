#include "stdafx.h"
#include "DarkCircle.h"


DarkCircle::DarkCircle()
{
}


DarkCircle::~DarkCircle()
{
}

void DarkCircle::Initialize()
{
	SkillObject::Initialize();
	if (mesh == nullptr){
		mesh = new SkinnedMesh;
		scale.x = 0.05f;
		scale.y = 0.05f;
		scale.z = 0.05f;
		mesh->Initialize("Azmodan/Skill/", "BlackPool.X", scale);  //경로지정
		mesh->SetAnimationIndex(2);
		mesh->GetAnimController()->SetTrackSpeed(0, 0.00001);

		obbBox->Setup(mesh);
	}

}

void DarkCircle::Destroy()
{
	SkillObject::Destroy();
}

void DarkCircle::Update()
{
	SkillObject::Update();
	obbBox->Update(&obbWorld);
	rotationAngle += 0.1f;
}

void DarkCircle::Render(){
	SkillObject::Render();
	if (mesh){
		mesh->UpdateAndRender();
	}
	//obbBox->DebugRender(D3DCOLOR_XRGB(255, 0, 0));

}

void DarkCircle::Reset(){
	fire = false;
	startTimer = 0.0f;
	currentTimer = 0.0f;
	timer = 0.0f;

	state = IDLE;
	isAfter = false;
	scale = D3DXVECTOR3(0.05f, 0.05f, 0.05f);
}

void DarkCircle::Battle(unit* enemy){
	if (Collision::IsBoxToSphere(mesh->GetCollisionBox()->GetBoundingBox(),enemy->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere())){
		enemy->SetHp(enemy->GetHp() - 1);
	}
	
}