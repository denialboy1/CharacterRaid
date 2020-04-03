#include "stdafx.h"
#include "TileBillboard.h"


TileBillboard::TileBillboard()
{
}


TileBillboard::~TileBillboard()
{
}


void TileBillboard::Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size, int _frameX, int _frameY){
	frameX = _frameX;
	frameY = _frameY;

	currentFrame = 0;
	frameCount = 0;
	maxFrame = frameX*frameY;

	//중점 위치는 매개변수로 받은 위치로 하고
	m_vPos = _pos;
	//정점 위치를 중점 기준으로 초기화
	m_Vertex[0].pos = D3DXVECTOR3(_size.x / 2.0f, 0.0f,-_size.z / 2.0f);
	m_Vertex[1].pos = D3DXVECTOR3(-_size.x / 2.0f, 0.0f, -_size.z / 2.0f);
	m_Vertex[2].pos = D3DXVECTOR3(_size.x / 2.0f, 0.0f, _size.z / 2.0f);
	m_Vertex[3].pos = D3DXVECTOR3(_size.x / 2.0f, 0.0f, _size.z / 2.0f);
	m_Vertex[4].pos = D3DXVECTOR3(-_size.x / 2.0f, 0.0f, -_size.z / 2.0f);
	m_Vertex[5].pos = D3DXVECTOR3(-_size.x / 2.0f, 0.0f, _size.z / 2.0f);
	
		
	m_Vertex[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	m_Vertex[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	m_Vertex[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[3].tex = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[4].tex = D3DXVECTOR2(1.0f, 0.0f);
	m_Vertex[5].tex = D3DXVECTOR2(1.0f, 1.0f);

	ZeroMemory(&material, sizeof(D3DMATERIAL9));
	material.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	material.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	material.Specular = D3DXCOLOR(0.9f, 0.9f, 0.9f, 1.0f);

	m_vScale = _size;
}

void TileBillboard::Update(D3DXVECTOR3 cameraPos){
	//if (!isPlay) return;

	SetTextureFrame();

	//이동행렬
	D3DXMatrixIdentity(&m_Translation);
	D3DXMatrixTranslation(&m_Translation, m_vPos.x, m_vPos.y, m_vPos.z);

	//기본 방향 벡터
	D3DXVECTOR3 vDir = D3DXVECTOR3(0, 0, 1);
	//카메라 방향 벡터
	D3DXVECTOR3 vCamera = cameraPos - m_vPos;
	D3DXVec3Normalize(&vCamera, &vCamera);

	//방향벡터에 맞는 회전 축 벡터
	D3DXVec3Cross(&m_vRot, &vCamera, &vDir);

	//회전축에 의해 회전값이 들어간 행렬
	//무작정 돌리는 것이 아니기 떄문에 카메라 방향벡ㅌ와의 내적,
	//그것을 이용해 내적 각도를 구하여 행렬을 만든다
	float inner = D3DXVec3Dot(&vCamera, &vDir);
	float theta = acos(inner);
	D3DXMatrixRotationAxis(&m_Rot, &-m_vRot, theta);

	//위 행렬을 곱해 새로운 방향벡터 구하기
	D3DXVec3TransformNormal(&m_vDir, &vDir, &m_Rot);

	//크기 행렬
	D3DXMatrixIdentity(&m_Scale);
	D3DXMatrixScaling(&m_Scale, m_vScale.x, m_vScale.y, m_vScale.z);

	//크기행렬 * 회전행렬 * 이동행렬
	m_World = m_Scale *  m_Translation;

	//Frame
	if (frameCount++ >= 1){
		frameCount = 0;
		currentFrame++;
		if (currentFrame >= maxFrame)
		{
			currentFrame = 0;
			isPlay = false;
		}
	}
}

void TileBillboard::SetTextureFrame()
{
	float tempX, tempY, width, height;
	//업데이트에서 i_CurrentFrame이 Count에 따라 ++되기 때문에
	//[0,1] 구간에서 tempX는 총 Frame의 X 만큼 나누어 남은 값으로 설정하며
	//[0,1] 구간에서 tempY는 총 Frame의 X 만큼 나눈 값으로 설정한다.
	tempX = currentFrame % frameX;
	tempY = currentFrame / frameX;

	//한 Frame의 Width와 Height는 위에서 계산한 Frame 값으로 나누어 계산한다.
	width = 1.0f / (float)frameX;
	height = 1.0f / (float)frameY;

	//위의 값을 (0,0)이라 보고 초기화 때와 같이 Texture Pointer를 정해준다.

	m_Vertex[5].tex = D3DXVECTOR2(tempX * width, tempY * height);
	m_Vertex[3].tex = D3DXVECTOR2((tempX + 1) * width, tempY * height);
	m_Vertex[4].tex = D3DXVECTOR2(tempX * width, (tempY + 1) * height);
	m_Vertex[1].tex = D3DXVECTOR2(tempX * width, (tempY + 1) * height);
	m_Vertex[2].tex = D3DXVECTOR2((tempX + 1) * width, tempY * height);
	m_Vertex[0].tex = D3DXVECTOR2((tempX + 1) * width, (tempY + 1) * height);

	//m_Vertex[0].tex = D3DXVECTOR2(tempX * width, tempY * height);
	//m_Vertex[1].tex = D3DXVECTOR2((tempX + 1) * width, tempY * height);
	//m_Vertex[2].tex = D3DXVECTOR2(tempX * width, (tempY + 1) * height);
	//m_Vertex[3].tex = D3DXVECTOR2(tempX * width, (tempY + 1) * height);
	//m_Vertex[4].tex = D3DXVECTOR2((tempX + 1) * width, tempY * height);
	//m_Vertex[5].tex = D3DXVECTOR2((tempX + 1) * width, (tempY + 1) * height);
}


void TileBillboard::Render()
{
	//if (!isPlay) return;
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);	//조명의 영향을 제거하기 위해 끔

	// 텍스쳐에 있는 알파값을 쓰겠다고 설정
	GameManager::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	GameManager::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	GameManager::GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		//src는 알파 블랜드 켜고 그리는거
	GameManager::GetDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	//desc는 그 전에 그려져 있던 것

	GameManager::GetDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, true);	// 알파 블랜드 켜기
	GameManager::GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, false);	// 반투명한것 그릴때 약간의 속도 향상

	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &m_World);
	GameManager::GetDevice()->SetMaterial(&material);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetFVF(FVF_PositionTexture::FVF);
	GameManager::GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &m_Vertex[0], sizeof(FVF_PositionTexture));

	GameManager::GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, true);
	GameManager::GetDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, false);// 사용 다 했으면 복구m_W

	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);

}

void TileBillboard::Destroy(){
}