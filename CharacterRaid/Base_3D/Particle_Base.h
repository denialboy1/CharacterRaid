#pragma once
#include "Particle.h"

class Particle_Base
{
public:
	Particle_Base();
	virtual ~Particle_Base();

	virtual bool Initialize(char* textureFileName);
	virtual void Destroy();
	virtual void Update() = 0;	
	virtual void Render();	
	
	virtual void AddParticle();	//파티클 하나 추가

	virtual void Reset();		//파티클 재사용용		
	virtual void ResetParticle(ParticleAttribute& attribute) = 0;	//파티클 타입에 맞게 리셋하기 위한것(따라서 순수가상함수)
		
	bool IsEmpty();	//파티클이 비었음
	bool IsDead();	//파티클이 다 죽었음
	
protected:
	D3DXMATRIXA16 world;
	DWORD FloatToDword(float f){ return *( (DWORD*)( &f ) ); }
	
	float size = 0.1f;								//파티클 크기
	LPDIRECT3DTEXTURE9	texture = nullptr;			//파티클 텍스쳐
	LPDIRECT3DVERTEXBUFFER9 vertexBuffer = nullptr;	//버텍스 버퍼
	std::list<ParticleAttribute> particles;			//전체 파티클 리스트

	// 아래3개는 파티클을 좀 더 효율적으로 그리기 위해 필요한 변수들임
	DWORD vbSize = 2048;							// 버텍스 버퍼 크기
	DWORD vbOffset = 0;								// 버텍스 버퍼를 잠그기 위한 offset(파티클 갯수 단위)
	DWORD vbBatchSize = 512;						// 하나의 단계에 들어갈 파티클의 갯수

	virtual void PreRender();
	virtual void PostRender();
};


