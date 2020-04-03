#pragma once
#include "SkillObject.h"
class VikingAttack : public SkillObject
{
public:
	VikingAttack();
	~VikingAttack();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	float BattleCruiserMoveZ;
	float BattleCruiserAngle;
private:

};

