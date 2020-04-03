#pragma once
#include "SkillObject.h"
#include "BattleCruiserBoom.h"
class Battlecruiser : public SkillObject
{
public:
	Battlecruiser();
	~Battlecruiser();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	float BattleCruiserMoveZ;
	float BattleCruiserMoveX;
	float BattleCruiserAngle;

	BattleCruiserBoom* battleCruiserBoom;

	

private:

};

