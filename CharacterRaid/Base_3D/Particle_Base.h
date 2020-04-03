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
	
	virtual void AddParticle();	//��ƼŬ �ϳ� �߰�

	virtual void Reset();		//��ƼŬ �����		
	virtual void ResetParticle(ParticleAttribute& attribute) = 0;	//��ƼŬ Ÿ�Կ� �°� �����ϱ� ���Ѱ�(���� ���������Լ�)
		
	bool IsEmpty();	//��ƼŬ�� �����
	bool IsDead();	//��ƼŬ�� �� �׾���
	
protected:
	D3DXMATRIXA16 world;
	DWORD FloatToDword(float f){ return *( (DWORD*)( &f ) ); }
	
	float size = 0.1f;								//��ƼŬ ũ��
	LPDIRECT3DTEXTURE9	texture = nullptr;			//��ƼŬ �ؽ���
	LPDIRECT3DVERTEXBUFFER9 vertexBuffer = nullptr;	//���ؽ� ����
	std::list<ParticleAttribute> particles;			//��ü ��ƼŬ ����Ʈ

	// �Ʒ�3���� ��ƼŬ�� �� �� ȿ�������� �׸��� ���� �ʿ��� ��������
	DWORD vbSize = 2048;							// ���ؽ� ���� ũ��
	DWORD vbOffset = 0;								// ���ؽ� ���۸� ��ױ� ���� offset(��ƼŬ ���� ����)
	DWORD vbBatchSize = 512;						// �ϳ��� �ܰ迡 �� ��ƼŬ�� ����

	virtual void PreRender();
	virtual void PostRender();
};


