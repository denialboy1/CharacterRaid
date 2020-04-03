#include "stdafx.h"
#include "Particle_Fireworks.h"


Particle_Fireworks::Particle_Fireworks(D3DXVECTOR3& _origin, int numParticles)
{
	origin = _origin;
	size = 0.9f;

	for ( int i = 0; i < numParticles; i++ )
	{
		AddParticle();
	}
}


Particle_Fireworks::~Particle_Fireworks()
{
}

void Particle_Fireworks::Update()
{
	for ( auto iter = particles.begin(); iter != particles.end(); ++iter )
	{
		// 살아있는 것만 업데이트
		if ( iter->isAlive )
		{
			iter->position += ( iter->velocity * (float)GameManager::GetTick() );

			iter->age += (float)GameManager::GetTick();

			if ( iter->age > iter->lifeTime )	//수명이 끝났음
			{
				iter->isAlive = false;
			}
		}
	}

	//파티클이 다 죽으면 리셋
	if ( IsDead() )
	{
		Reset();
	}
}

void Particle_Fireworks::ResetParticle(ParticleAttribute& attribute)
{
	attribute.isAlive = true;
	attribute.position = origin;

	D3DXVECTOR3 min = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
	D3DXVECTOR3 max = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	RandomUtil::GetVector(attribute.velocity, max, min);

	// 원으로 만들기 위해 방향만 남김
	D3DXVec3Normalize(&attribute.velocity, &attribute.velocity);

	attribute.velocity *= radius;

	attribute.color = D3DXCOLOR(RandomUtil::GetFloat(1.0f), RandomUtil::GetFloat(1.0f), RandomUtil::GetFloat(1.0f), 1.0f);

	attribute.age = 0.0f;
	attribute.lifeTime = bombTime;
}

void Particle_Fireworks::PreRender()
{
	Particle_Base::PreRender();

	GameManager::GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	GameManager::GetDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//z-buffer 읽기만 하고 쓰기는 금지
	GameManager::GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, false);
}

void Particle_Fireworks::PostRender()
{
	Particle_Base::PostRender();

	GameManager::GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, true);
}