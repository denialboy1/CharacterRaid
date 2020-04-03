#pragma once
#include "FVF.h"
#include "Pyramid.h"


class Grid
{
public:
	Grid();
	~Grid();

	void Initialize(float width =1, float height = 1);
	void Destroy();
	void Render();

	//const FVF_PositionTexture* GetGroundVertex(){ return m_Vertex; }
	const std::vector<D3DXVECTOR3>& GetGroundVertex(){ return groundVertex; }
	inline void SetShowGround(bool show){ showGround = show; }
	inline void SetTexture(LPDIRECT3DTEXTURE9 _texture){ texture = _texture; }
private:
	FVF_PositionTexture m_Vertex[6];

	std::vector<D3DXVECTOR3> groundVertex;
	

	static const int axisCount = 3;
	Pyramid* axisArrow[axisCount];

	D3DMATERIAL9 material;
	D3DXMATRIXA16 world;

	bool showGround = false;

	LPDIRECT3DTEXTURE9 texture = nullptr;
};

