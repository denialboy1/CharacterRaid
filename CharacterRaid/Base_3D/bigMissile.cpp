#include "stdafx.h"
#include "bigMissile.h"


bigMissile::bigMissile()
{
}


bigMissile::~bigMissile()
{
}

void bigMissile::Initialize()
{
	SkillObject::Initialize();

	if (mesh == nullptr)
	{
		mesh = new SkinnedMesh;
		mesh->Initialize("HammerBoss/", "BansheeMissile.X", scale);
		scale.x = 50.0;
		scale.y = 50.0;
		scale.z = 50.0;
		position = D3DXVECTOR3(0, 5, 0);
		mesh->SetAnimationIndex(2);
	}

	if (MissileBoomSphere == nullptr)
	{
		MissileBoomSphere = new Collider_Sphere;
		MissileBoomSphere->Initialize(D3DXVECTOR3(0, 5, 0), 7);
		MissileBoomSphere->SetWireRender(true);
	}

	soundManager::Get().addSound("미사일지나가는소리", "Data/Sound/Nova/미사일지나가는소리.wav", false, false);

}
void bigMissile::Destroy()
{
	SkillObject::Destroy();
	SAFE_DELETE(MissileBoomSphere);
}
void bigMissile::Update()
{
	SkillObject::Update();
	MissileBoomSphere->GetBoundingSphere().center.x = MissileX;
	MissileBoomSphere->GetBoundingSphere().center.z = MissileZ;
	//MissileBoomSphere->Initialize(D3DXVECTOR3(MissileX, 20, MissileZ), 15);
	position = D3DXVECTOR3(MissileX, 5, MissileZ);

	if (IsMissileSpawnTimer)
	{
		MissileSpawnTimer++;
	}
	if (MissileSpawnTimer >= 100)
	{
		MissileZ += 2;
		
	}

	if (MissileSpawnTimer == 110)
	{
		soundManager::Get().play("미사일지나가는소리", 1.0f);
	}

	if (MissileSpawnTimer >= 200)
	{
		MissileX = RND->GetInteger(40, -40);
		MissileZ = -100;
		MissileSpawnTimer = 0;

	}
	//if (KeyboardManager::Get().IsOnceKeyDown('K'))
	//{
	//	IsMissileSpawnTimer = true;
	//	
	//}
	MissileBoomSphere->Update();
}
void bigMissile::Render()
{
	SkillObject::Render();

	if (mesh){
		mesh->UpdateAndRender();
	}
	//if (MissileBoomSphere)
	//{
	//	MissileBoomSphere->Render();
	//}
}
