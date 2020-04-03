#pragma once

struct Particle
{
	//FVF_PositionColor�� ����. �׸����
	D3DXVECTOR3 position = D3DXVECTOR3(0, 0, 0);
	D3DCOLOR color = D3DCOLOR_XRGB(0, 0, 0);

	Particle()
	{
	}
	Particle(D3DXVECTOR3 _posision, D3DCOLOR _color)
		: position(_posision), color(_color)
	{
	}

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE, };
};

struct ParticleAttribute
{
	//��ƼŬ�� �Ӽ���
	D3DXVECTOR3 position = D3DXVECTOR3(0, 0, 0);		// ��ƼŬ ��ġ
	D3DXVECTOR3 velocity = D3DXVECTOR3(0, 0, 0);		// ��ƼŬ �ӵ�(���� �ʴ� �ӵ�)
	//D3DXVECTOR3 acceleration = D3DXVECTOR3(0, 0, 0);	// ��ƼŬ�� ���ӵ�. �̹����� �Ⱦ�
	float lifeTime = 0.0f;								// ������ ���� �ɸ��� �ð�(����)
	float age = 0.0f;									// ����������� ���� �ð�(���� ����)
	D3DXCOLOR color = D3DCOLOR_XRGB(255, 255, 255);		// ��ƼŬ�� ���� 
	D3DXCOLOR colorFade = D3DCOLOR_XRGB(0, 0, 0);		// �ð��� ���� ��ȭ�� ��� ����
	bool isAlive = false;								// ��ƼŬ�� ��ƣ����� ����
};