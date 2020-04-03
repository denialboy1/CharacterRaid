#pragma once
#include "Billboard.h"
class FireArrowEffect 
{
public:
	FireArrowEffect();
	~FireArrowEffect();

	void Initialize();
	void Update();
	void Render();
	void Destroy();
	void Start(D3DXVECTOR3 pos);
private:
	Billboard* billboard = nullptr;
	bool isStart=false;
};

