#pragma once
#include "Billboard.h"


class BattleCruiserBoom : public Billboard
{

public:

	BattleCruiserBoom();
	~BattleCruiserBoom();

	void Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size);
	void Destroy();
	void Update(D3DXVECTOR3 _cameraPos);
	void Render();

	void Start(D3DXVECTOR3 _pos);
	void Reset();

private:

};


