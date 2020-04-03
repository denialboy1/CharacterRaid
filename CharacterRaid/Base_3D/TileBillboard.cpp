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

	//���� ��ġ�� �Ű������� ���� ��ġ�� �ϰ�
	m_vPos = _pos;
	//���� ��ġ�� ���� �������� �ʱ�ȭ
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

	//�̵����
	D3DXMatrixIdentity(&m_Translation);
	D3DXMatrixTranslation(&m_Translation, m_vPos.x, m_vPos.y, m_vPos.z);

	//�⺻ ���� ����
	D3DXVECTOR3 vDir = D3DXVECTOR3(0, 0, 1);
	//ī�޶� ���� ����
	D3DXVECTOR3 vCamera = cameraPos - m_vPos;
	D3DXVec3Normalize(&vCamera, &vCamera);

	//���⺤�Ϳ� �´� ȸ�� �� ����
	D3DXVec3Cross(&m_vRot, &vCamera, &vDir);

	//ȸ���࿡ ���� ȸ������ �� ���
	//������ ������ ���� �ƴϱ� ������ ī�޶� ���⺤������ ����,
	//�װ��� �̿��� ���� ������ ���Ͽ� ����� �����
	float inner = D3DXVec3Dot(&vCamera, &vDir);
	float theta = acos(inner);
	D3DXMatrixRotationAxis(&m_Rot, &-m_vRot, theta);

	//�� ����� ���� ���ο� ���⺤�� ���ϱ�
	D3DXVec3TransformNormal(&m_vDir, &vDir, &m_Rot);

	//ũ�� ���
	D3DXMatrixIdentity(&m_Scale);
	D3DXMatrixScaling(&m_Scale, m_vScale.x, m_vScale.y, m_vScale.z);

	//ũ����� * ȸ����� * �̵����
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
	//������Ʈ���� i_CurrentFrame�� Count�� ���� ++�Ǳ� ������
	//[0,1] �������� tempX�� �� Frame�� X ��ŭ ������ ���� ������ �����ϸ�
	//[0,1] �������� tempY�� �� Frame�� X ��ŭ ���� ������ �����Ѵ�.
	tempX = currentFrame % frameX;
	tempY = currentFrame / frameX;

	//�� Frame�� Width�� Height�� ������ ����� Frame ������ ������ ����Ѵ�.
	width = 1.0f / (float)frameX;
	height = 1.0f / (float)frameY;

	//���� ���� (0,0)�̶� ���� �ʱ�ȭ ���� ���� Texture Pointer�� �����ش�.

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
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);	//������ ������ �����ϱ� ���� ��

	// �ؽ��Ŀ� �ִ� ���İ��� ���ڴٰ� ����
	GameManager::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	GameManager::GetDevice()->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	GameManager::GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		//src�� ���� ���� �Ѱ� �׸��°�
	GameManager::GetDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	//desc�� �� ���� �׷��� �ִ� ��

	GameManager::GetDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, true);	// ���� ���� �ѱ�
	GameManager::GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, false);	// �������Ѱ� �׸��� �ణ�� �ӵ� ���

	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &m_World);
	GameManager::GetDevice()->SetMaterial(&material);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetFVF(FVF_PositionTexture::FVF);
	GameManager::GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &m_Vertex[0], sizeof(FVF_PositionTexture));

	GameManager::GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, true);
	GameManager::GetDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, false);// ��� �� ������ ����m_W

	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);

}

void TileBillboard::Destroy(){
}