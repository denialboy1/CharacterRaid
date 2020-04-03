#pragma once
#include "UI_Base.h"
class UI_Image :
	public UI_Base
{
public:
	UI_Image();
	virtual ~UI_Image();

	virtual void Render() override;

	void SetTexture(char* fileName);

	inline float& GetDeleteY(){ return DeleteY; }

	inline void SetDeleteY(float _DeleteY){ DeleteY = _DeleteY; }

	inline float& GetDeleteX(){ return DeleteX; }

	inline void SetDeleteX(float _DeleteX){ DeleteX = _DeleteX; }
private:
	RECT rc;

	float DeleteY = 0;
	float DeleteX = 0;


protected:
	LPDIRECT3DTEXTURE9 texture = nullptr;
};

