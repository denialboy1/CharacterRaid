#include "stdafx.h"
#include "Grid.h"


Grid::Grid()
{
	ZeroMemory(axisArrow, sizeof(Pyramid*) * axisCount);
}


Grid::~Grid()
{
	Destroy();
}

void Grid::Initialize(float width /*= 1*/, float height/* = 1.0f*/)
{
	float w = width / 2, h = height/2;

	//¹Ù´Ú ÇÇÅ·¿ë

	m_Vertex[0].pos = D3DXVECTOR3(-w, 0, -h);
	m_Vertex[1].pos = D3DXVECTOR3(-w, 0, h);
	m_Vertex[2].pos = D3DXVECTOR3(w, 0, h);
	m_Vertex[3].pos = D3DXVECTOR3(-w, 0, -h);
	m_Vertex[4].pos = D3DXVECTOR3(w, 0, h);
	m_Vertex[5].pos = D3DXVECTOR3(w, 0, -h);

	m_Vertex[0].tex = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[1].tex = D3DXVECTOR2(0.0f, 0.0f);
	m_Vertex[2].tex = D3DXVECTOR2(1.0f, 0.0f);
	m_Vertex[3].tex = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[4].tex = D3DXVECTOR2(1.0f, 0.0f);
	m_Vertex[5].tex = D3DXVECTOR2(1.0f, 1.0f);

	ZeroMemory(&material, sizeof(D3DMATERIAL9));
	//material.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	//material.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	//material.Specular = D3DXCOLOR(0.9f, 0.9f, 0.9f, 1.0f);

	D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	material.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	material.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	material.Specular =D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	D3DXMatrixIdentity(&world);

	groundVertex.push_back(m_Vertex[0].pos);
	groundVertex.push_back(m_Vertex[1].pos);
	groundVertex.push_back(m_Vertex[2].pos);
	groundVertex.push_back(m_Vertex[3].pos);
	groundVertex.push_back(m_Vertex[4].pos);
	groundVertex.push_back(m_Vertex[5].pos);
}

void Grid::Destroy()
{
}

void Grid::Render()
{	
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetMaterial(&material);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetFVF(FVF_PositionTexture::FVF);
	GameManager::GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &m_Vertex[0], sizeof(FVF_PositionTexture));
}
