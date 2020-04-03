#include "stdafx.h"
#include "NuClear.h"


NuClear::NuClear()
{
}


NuClear::~NuClear()
{
}


void NuClear::Initialize()
{
	NukeY = 100.0;
	///NukeX = 0.0;
	///NukeZ = 0.0;
	NukeBoomTimer = 0.0f;
	IsNukeBoomTimerOn = false;
	Nuke = false;
	IsNukeBoomShereOn = false;
	SkillObject::Initialize();
	if (mesh == nullptr)
	{
		mesh = new SkinnedMesh;
		mesh->Initialize("", "Nuke.X", scale);
		scale.x = 5;
		scale.y = 5;
		scale.z = 5;
		//mesh->SetAnimationIndex(4);
		//mesh->GetCollisionSphere()->GetBoundingSphere().radius = 15;
	}
	

	BoomSphere = new Collider_Sphere;
	BoomSphere->Initialize(D3DXVECTOR3(0, 0, 0)/*BoomSpherePos*/, 0);
	//BoomSphere->GetBoundingSphere().radius = 20;
	
		
}
void NuClear::Destroy()
{
	SkillObject::Destroy();
	SAFE_DELETE(BoomSphere);
}
void NuClear::Update()
{
	
	
}
void NuClear::Render()
{
}

//void NuClear::ChangeMotion(NUCLEAR_STATE _NuclearState)
//{
//	if (action)
//		action->SetIsStart(false);
//	NuclearState = _NuclearState;
//	mesh->SetAnimationIndex(NuclearState);
//	mesh->GetAnimController()->SetTrackPosition(0, 0);
//
//	LPD3DXANIMATIONSET animSet = nullptr;							//애니메이션 정보를 받아줄 변수
//	mesh->GetAnimController()->GetAnimationSet(NuclearState, &animSet);	//등록된 애니메이션에서 animSet변수에 정보를 등록
//	aniTime = animSet->GetPeriod();									//애니메이션 시간길이 저장
//	startTimer = timeGetTime();										//현재 시간 갱신
//	SAFE_RELEASE(animSet);
//}


void NuClear::positionSet(D3DXVECTOR3 pickingPosition)
{
	position.x = pickingPosition.x;
	position.z = pickingPosition.z;

	

}

void NuClear::NuClearMove()
{

	mesh->GetAnimController()->SetTrackPosition(0, 0);
	mesh->GetAnimController()->SetTrackSpeed(0, 0.0001);
	BoomSphere->Update();
	SkillObject::Update();
	position.y = NukeY;
	//position.x = NukeX;
	//position.z = NukeZ;
	if (Nuke)
	{
		rotationAngle += 0.036;
		//scale.x -= 0.03;
		//scale.y -= 0.03;
		//scale.z -= 0.03;
		//NukeX -= 0.05;
		NukeY -= 0.7;
	}
	//if (KeyboardManager::Get().IsOnceKeyDown('O')){
	//	Nuke = true;
	//}
	if (NukeY <= -5)
	{
		//scale.x = 5;
		//scale.y = 5; 
		//scale.z = 5;
		//NukeX = 0;
		NukeY = 100;
		rotationAngle = 0;
		Nuke = false;
		//mesh->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(10, 5, 10);
		//BoomSphere->GetBoundingSphere().center = D3DXVECTOR3(0, 0, 0);
		IsNukeBoomShereOn = true;
		IsNukeBoomTimerOn = true;
		BoomSphere->GetBoundingSphere().radius = 20;
	}
	
	BoomSpherePos = D3DXVECTOR3(position.x, 0, position.z);
	
	if (IsNukeBoomShereOn)
	{
		BoomSphere->GetBoundingSphere().center.y = 0;
		BoomSphere->GetBoundingSphere().center.x = BoomSpherePos.x;
		BoomSphere->GetBoundingSphere().center.z = BoomSpherePos.z;
	}
	if (IsNukeBoomTimerOn)
	{
		NukeBoomTimer++;
	}
	if (NukeBoomTimer == 1000)
	{
		IsNukeBoomTimerOn = false;
		NukeBoomTimer = 0;
		BoomSphere->GetBoundingSphere().radius = 0;
	}

}

void NuClear::NuClearMoveRender()
{

	SkillObject::Render();
	if (mesh){
		mesh->UpdateAndRender();
	}
	//if (NukeY <= -5)
	//{
	//	
	//}
	if (IsNukeBoomShereOn)
	{
		BoomSphere->Render();
	}
	
	
}