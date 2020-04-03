#pragma once
#include "unit.h"
class Marine :	public unit
{
public:
	Marine();
	~Marine();

	virtual void Initialize(D3DXVECTOR3 _scale) ;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;

private:
};

