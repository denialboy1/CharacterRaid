#pragma once
#include "Billboard.h"
class mpRegion : public Billboard
{
public:
	mpRegion();
	~mpRegion();

	void Initialize();
	void Destroy();
	void Update(D3DXVECTOR3 pos);
	void Render();

	void Start(D3DXVECTOR3 pos);
private:
	Billboard* death = nullptr;
};

