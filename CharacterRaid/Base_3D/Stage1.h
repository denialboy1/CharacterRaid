#pragma once
#include "Stage.h"
#include "StructureObject.h"

class Stage1 : public Stage
{
public:
	Stage1();
	~Stage1();


	virtual void Initialize(float _width, float _height, char* fileName);
	virtual void Destroy();
	virtual void Update();
	virtual void Render();

	std::vector<StructureObject*> vMineral;
	std::vector<StructureObject*> vFactory;
	StructureObject* CommandCenter;


	std::vector<StructureObject*> vTurret;
	std::vector<StructureObject*> vSupplyDepot;
	std::vector<StructureObject*> vTechLab;
	std::vector<StructureObject*> vMetalWall;
	std::vector<StructureObject*> vMetalWallCorner;
	//StructureObject* MetalWallCorner;
	//std::vector<StructureObject*> vMineral;

};
