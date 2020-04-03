#pragma once
#include "Stage.h"
#include "StructureObject.h"
#include "Billboard.h"
#include "PathFinder.h"
#include "Collider_Sphere.h"
#include "player.h"


class Stage3 : public Stage
{
	
public:
	Stage3();
	~Stage3();

	virtual void Initialize(float _width, float _height, char* fileName);
	virtual void Destroy();
	virtual void Update(player& _player);
	virtual void Render();

private:
	std::vector<StructureObject*> vWall;
	std::vector<Billboard*> vTeleport;
	std::vector<Collider_Sphere*> vTeleportCollision;

	PathFinder* path = nullptr;
	
public:
	PathFinder* GetPathFinder(){ return path; }
};

