#pragma once
#include "Billboard.h"

class BossDeath 
{
public:
	BossDeath();
	~BossDeath();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Start(D3DXVECTOR3 pos);
private:
	Billboard* death = nullptr;
};

