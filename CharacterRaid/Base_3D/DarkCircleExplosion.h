#pragma once
#include "Billboard.h"
class DarkCircleExplosion :public Billboard
{
public:
	DarkCircleExplosion();
	~DarkCircleExplosion();

	void Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size);
	void Destroy();
	void Update(D3DXVECTOR3 pos);
	void Render();

	void Start(D3DXVECTOR3 _pos);
	void Reset();
};

