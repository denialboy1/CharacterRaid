#pragma once
#include "Billboard.h"
class BossDeathEffect :
	public Billboard
{
public:
	BossDeathEffect();
	~BossDeathEffect();

	void Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size);
	void Destroy();
	void Update(D3DXVECTOR3 pos);
	void Render();

	void Start(D3DXVECTOR3 _pos);
	void Reset();
};

