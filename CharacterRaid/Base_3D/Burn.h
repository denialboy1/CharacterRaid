#pragma once
#include "Billboard.h"
class Burn
{
public:
	Burn();
	~Burn();

	void Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size);
	void Destroy();
	void Update(D3DXVECTOR3 pos, D3DXVECTOR3 playerPos);
	void Render();

	void Start(D3DXVECTOR3 _pos);
	void Reset();
	
private:
	Billboard* fire1 = nullptr;
	Billboard* fire2 = nullptr;
	Billboard* fire3 = nullptr;

	bool isStart = false;
};

