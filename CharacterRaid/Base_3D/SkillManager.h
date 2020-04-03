#pragma once
//플레이어 스킬 매니저
#include "IceMake.h"
#include "IceFire.h"
#include "IceWorld.h"

#include "FireBallFire.h"
#include "FireCircleWorld.h"

#include "HitSphereMake.h"

class SkillManager
{
public:
	SkillManager();
	~SkillManager();


	void Initialize();
	void Update();
	void Render();
	void Destroy();

	static SkillManager& Get(){
		static SkillManager Instance;
		return Instance;
	}

private:
	//제이나
	IceMake* iceMake = nullptr;
	IceFire* iceFire = nullptr;
	IceWorld* iceWorld = nullptr;

	//켈타스
	FireBallFire* fireBallFire = nullptr;
	FireCircleWorld* fireCircleWorld = nullptr;

	//요한나
	HitSphereMake* hitSphereMake = nullptr;
public:
	//getter

	//제이나
	IceMake* GetIceMake(){ return iceMake; }
	IceFire* GetIceFire(){ return iceFire; }
	IceWorld* GetIceWorld(){ return iceWorld; }

	//켈타스
	FireBallFire* GertFireBallFire(){ return fireBallFire; }
	FireCircleWorld* GetFireCircleWorld(){ return fireCircleWorld; }

	//요한나
	HitSphereMake* GetHitSphereMake(){ return hitSphereMake; }
};

