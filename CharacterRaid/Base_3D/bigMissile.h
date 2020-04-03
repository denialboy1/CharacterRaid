#pragma once
#include "SkillObject.h"
#include "RandomUtil.h"
class bigMissile : public SkillObject
{
public:
	bigMissile();
	~bigMissile();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	int MissileX = 0;
	int MissileZ = -50;

	float MissileSpawnTimer = 0;
	bool IsMissileSpawnTimer = true;
	RandomUtil* RND;
	
	Collider_Sphere* GetMissileBoomSphere() { return MissileBoomSphere; }
	
private:
	Collider_Sphere* MissileBoomSphere = nullptr;
	
};

