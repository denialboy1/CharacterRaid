#pragma once
#include "Grid.h"
class Stage
{
public:
	Stage();
	~Stage();

	virtual void Initialize(float _width, float _height, char* fileName);
	virtual void Destroy();
	virtual void Update();
	virtual void Render();
protected:
	Grid* grid = nullptr;

public:
	Grid* GetGrid(){ return grid; }
};

