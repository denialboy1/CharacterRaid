#pragma once

struct Particle
{
	//FVF_PositionColor와 같음. 그리기용
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
	//파티클의 속성들
	D3DXVECTOR3 position = D3DXVECTOR3(0, 0, 0);		// 파티클 위치
	D3DXVECTOR3 velocity = D3DXVECTOR3(0, 0, 0);		// 파티클 속도(보통 초당 속도)
	//D3DXVECTOR3 acceleration = D3DXVECTOR3(0, 0, 0);	// 파티클의 가속도. 이번에는 안씀
	float lifeTime = 0.0f;								// 죽을때 까지 걸릴는 시간(수명)
	float age = 0.0f;									// 만들어지고나서 지난 시간(현재 나이)
	D3DXCOLOR color = D3DCOLOR_XRGB(255, 255, 255);		// 파티클의 색깔 
	D3DXCOLOR colorFade = D3DCOLOR_XRGB(0, 0, 0);		// 시간에 따라 변화될 대상 색깔
	bool isAlive = false;								// 파티클이 살아짔는지 여부
};