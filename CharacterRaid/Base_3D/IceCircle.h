#pragma once
#include "SkillObject.h"
class IceCircle : public SkillObject
{
public:
	IceCircle();
	~IceCircle();

	virtual void Initialize(float _size);
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	void SetTexture(char* fileName);
	void Fire(D3DXVECTOR3 _pos);
private:
	TextureTriangle triangle[2];
	LPDIRECT3DTEXTURE9 texture;

	float size=1;
};

