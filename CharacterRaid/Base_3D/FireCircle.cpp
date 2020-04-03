#include "stdafx.h"
#include "FireCircle.h"


FireCircle::FireCircle()
{
}


FireCircle::~FireCircle()
{
}

void FireCircle::Initialize(){
	SkillObject::Initialize();
	if (mesh == nullptr){
		mesh = new SkinnedMesh;
		scale.x = 0.05f;
		scale.y = 0.05f;
		scale.z = 0.05f;
		mesh->Initialize("켈타스스킬/", "Ring.X", scale);  //경로지정
		mesh->SetAnimationIndex(2);
		mesh->GetAnimController()->SetTrackSpeed(0,0.00001);

		obbBox->Setup(mesh);
	}

	if (pillarOfFire == nullptr){
		pillarOfFire = new PillarOfFire;
	}
}

void FireCircle::Destroy(){
	SkillObject::Destroy();
}

void FireCircle::Update(){
	SkillObject::Update();
	obbBox->Update(&obbWorld);
	rotationAngle += 0.1f;

	switch (state){
	case IDLE:
		break;
	case COLLISION:
		startTimer = timeGetTime();
		state = COLLISION_AFTER;
		break;
	case COLLISION_AFTER:
		scale.x -= 0.001f;
		//scale.y -= 0.01f;
		scale.z -= 0.001f;

		if (((timeGetTime() - startTimer)*0.001f) > 0.7){
			scale.x = 0;
			scale.y = 0;
			scale.z = 0;
			D3DXVECTOR3 pos = position;
			pos.y = 3;
			pos.z = position.z;
			pillarOfFire->Initialize(pos, D3DXVECTOR3(3, 3, 3));
			
			pillarOfFire->Start(pos);
			startTimer = timeGetTime();
			state = EXPLOSION;
		}
		break;
	case EXPLOSION:
		pillarOfFire->Update(GameManager::Get().GetCamera()->GetEyePosition());
		if (((timeGetTime() - startTimer)*0.001f) > 4){
			isAfter = true;
		}
		break;
	}

}

void FireCircle::Render(){
	SkillObject::Render();
	if (mesh){
		mesh->UpdateAndRender();
	}
	obbBox->DebugRender(D3DCOLOR_XRGB(255, 0, 0));

	if (state == EXPLOSION){
		pillarOfFire->Render();
	}
}

void FireCircle::Reset(){
	fire = false;
	startTimer = 0.0f;
	currentTimer = 0.0f;
	timer = 0.0f;

	state = IDLE;
	isAfter = false;
	scale = D3DXVECTOR3(0.05f, 0.05f, 0.05f);
}