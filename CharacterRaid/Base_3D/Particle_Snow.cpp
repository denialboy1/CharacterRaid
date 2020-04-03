#include "stdafx.h"
#include "Particle_Snow.h"


Particle_Snow::Particle_Snow(BoundingBox& _boundingBox, int numParticles)
{
	boundingBox = _boundingBox;
	size = 0.25f;

	for ( int i = 0; i < numParticles; i++ )
	{
		AddParticle();
	}
}

Particle_Snow::~Particle_Snow()
{
}

void Particle_Snow::Update()
{
	for ( auto iter = particles.begin(); iter != particles.end(); ++iter )
	{
		iter->position += (iter->velocity * (float)GameManager::GetTick());

		// 바운딩 박스 밖을 벗어나면 리셋(눈은 계속 내려야 하니까)
		if ( boundingBox.IsPointIn(iter->position) == false )
		{
			ResetParticle( *iter );
		}
	}
}

void Particle_Snow::ResetParticle(ParticleAttribute& attribute)
{
	attribute.isAlive = true;

	// 랜덤으로 눈의 위치 결정
	RandomUtil::GetVector(attribute.position, boundingBox.max, boundingBox.min);
	
	// y는 무조건 제일 높은 곳으로
	attribute.position.y = boundingBox.max.y;

	// 떨어지는 방향 지정
	attribute.velocity.x = RandomUtil::GetFloat(1.0f) * -3.0f;
	attribute.velocity.y = RandomUtil::GetFloat(1.0f) * -10.0f;
	attribute.velocity.z = 0.0f;

	// 흰색으로
	attribute.color = D3DCOLOR_XRGB(255, 255, 255);	
}
