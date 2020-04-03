#pragma once
#include "Billboard.h"

class characterDeath
{
public:
	characterDeath();
	~characterDeath();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Start(D3DXVECTOR3 pos);
private:
	Billboard* death = nullptr;
};

