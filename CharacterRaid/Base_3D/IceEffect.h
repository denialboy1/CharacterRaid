#pragma once
#include "Billboard.h"

class IceEffect
{
public:
	IceEffect();
	~IceEffect();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Start(D3DXVECTOR3 pos);
	Billboard* GetIce(){ return ice; }
private:
	Billboard* ice = nullptr;
	bool isStart = false;
};

