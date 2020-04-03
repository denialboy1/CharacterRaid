#pragma once
#include "Billboard.h"
class IceImpact : public Billboard
{
public:
	IceImpact();
	~IceImpact();

	void Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size, int _frameX, int _frameY);
	void Destroy();
	void Update(D3DXVECTOR3 _cameraPos);
	void Render();

	void Start(D3DXVECTOR3 _pos);
	void Reset();
private:
};

