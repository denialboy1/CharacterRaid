#include "stdafx.h"
#include "VikingEnemy.h"


VikingEnemy::VikingEnemy()
{
}


VikingEnemy::~VikingEnemy()
{
}


void VikingEnemy::Initialize(D3DXVECTOR3 _scale)
{
	unit::Initialize();
	scale = _scale;
	mesh->Initialize("Stage1Enemy/", "VikingAssert.x", scale);
	mesh->SetAnimationIndex(0);
	obb = new cOBB;
	obb->Setup(mesh);
	if (MoveSphere == nullptr)
	{
		MoveSphere = new Collider_Sphere;
		MoveSphere->Initialize(mesh->GetCollisionSphere()->GetBoundingSphere().center, 20);
	}
	if (AttackSphere == nullptr)
	{
		AttackSphere = new Collider_Sphere;
		AttackSphere->Initialize(mesh->GetCollisionSphere()->GetBoundingSphere().center, 5);
	}
	//if (WithSphere == nullptr)
	//{
	//	WithSphere = new Collider_Sphere;
	//	WithSphere->Initialize(mesh->GetCollisionSphere()->GetBoundingSphere().center, 5);
	//}
	IsAttack = false;
	unit::Update();
	mesh->SetisSphereShow(true);
	MoveSphere->SetWireRender(true);
	AttackSphere->SetWireRender(true);
	//WithSphere->SetWireRender(true);
	//IsAttack = false;
}
void VikingEnemy::Destroy()
{
	unit::Destroy();

	SAFE_DELETE(MoveSphere);
	SAFE_DELETE(AttackSphere);
	//SAFE_DELETE(WithSphere);
}
void VikingEnemy::Update()
{
	unit::Update();
	MoveSphere->GetBoundingSphere().center = mesh->GetCollisionSphere()->GetBoundingSphere().center;
	MoveSphere->Update();
	AttackSphere->GetBoundingSphere().center = mesh->GetCollisionSphere()->GetBoundingSphere().center;
	AttackSphere->Update();
	//WithSphere->GetBoundingSphere().center = mesh->GetCollisionSphere()->GetBoundingSphere().center;
	//WithSphere->Update();
	obb->Update(&obbWorld);

	if (IsDamageTimer)
	{
		damageTimer++;
	}
	if (damageTimer == 50)
	{
		//데미지 깍는거설정
	}

}
void VikingEnemy::Render()
{
	MoveSphere->Render();
	AttackSphere->Render();
	//WithSphere->Render();
	mesh->UpdateAndRender();
	obb->DebugRender(D3DCOLOR_XRGB(255, 0, 0));
}

void VikingEnemy::Battle(unit& vikingEnemy)
{
	if (IsAttack)
	{
		SetAngle(GetAngle(vikingEnemy.GetPosition(), GetPosition()) + D3DX_PI);
		SetPosition(-GetDirection() * 0.1 + GetPosition());
	}
	

	if (Collision::IsSphereToSphere(vikingEnemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), MoveSphere->GetBoundingSphere()))
	{
		IsAttack = true;
		mesh->SetAnimationIndex(0);
		IsDamageTimer = true;
	
	}
	else
	{
		mesh->SetAnimationIndex(2);
		IsAttack = false;
		IsDamageTimer = false;
		damageTimer = 0;
	
	}


	if (Collision::IsSphereToSphere(vikingEnemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), AttackSphere->GetBoundingSphere()))
	{
		mesh->SetAnimationIndex(1);
		IsAttack = false;
		IsDamageTimer = false;
		damageTimer = 0;

	}

	

}

float VikingEnemy::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
	D3DXVECTOR3 a(0, 0, 1);
	D3DXVECTOR3 b = v2 - v1;

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&b);
	float dot = D3DXVec3Dot(&a, &b);

	// 시계방향인지 반시계방향인지 판별
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &b);
	if (cross.y < 0)
	{
		dot *= -1;		// 반시계 방향이다. 그러면 각도가 반대로
	}

	float angle = acos(dot / (aLength * bLength));	//acos는 0~180도 사이의 값만 나온다.

	//따라서 180도 이상인지 판별
	D3DXVECTOR3 c(1, 0, 0);	//a를 90도 만큼 돌린 백터
	bool over180 = false;
	if (D3DXVec3Dot(&b, &c) < 0.0f)	// c,b가 90도 이상이면 a,b가 180도 이상이라는 소리
	{
		over180 = true;
	}

	//180도 이상이면 180도를 더해줌
	if (over180)
	{
		angle += D3DX_PI;
	}

	return angle;
}