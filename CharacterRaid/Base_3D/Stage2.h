#pragma once
#include "Stage.h"
#include "StructureObject.h"
#include "Billboard.h"
#include "PathFinder.h"
#include "Collider_Sphere.h"
#include "player.h"

class Stage2 :public Stage
{
public:
	Stage2();
	~Stage2();

	virtual void Initialize(float _width, float _height, char* fileName);
	virtual void Destroy();
	virtual void Update();
	virtual void Render();

private:
	std::vector<StructureObject*> vWall;

	PathFinder* path = nullptr;

public:
	PathFinder* GetPathFinder(){ return path; }
};

