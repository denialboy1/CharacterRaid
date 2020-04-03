#pragma once
#include "Particle_Base.h"
class Particle_Snow :
	public Particle_Base
{
public:
	Particle_Snow(BoundingBox& _boundingBox, int numParticles);
	virtual ~Particle_Snow();

	void Update() override;
	void ResetParticle(ParticleAttribute& attribute) override;

protected:
	BoundingBox boundingBox;	//눈이 내리는 범위용 바운딩 박스
};
