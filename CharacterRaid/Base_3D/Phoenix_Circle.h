#pragma once
#include "SkinnedMesh.h"

class Phoenix_Circle
{
public:
	Phoenix_Circle();
	~Phoenix_Circle();

	void Initialize();
	void Destroy();
	void Update(D3DXVECTOR3 pos);
	void Render();
	

private:
	SkinnedMesh* mesh = nullptr;

	D3DXMATRIXA16 world;

	D3DXVECTOR3 scale, rotate, position;
};

