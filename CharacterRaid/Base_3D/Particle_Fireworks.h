#pragma once
#include "Particle_Base.h"
class Particle_Fireworks :
	public Particle_Base
{
public:
	Particle_Fireworks(D3DXVECTOR3& _origin, int numParticles);
	virtual ~Particle_Fireworks();

	void Update() override;
	void ResetParticle(ParticleAttribute& attribute) override;

protected:
	D3DXVECTOR3 origin;		//ºÒ²É³îÀÌ ¿øÁ¡
	float radius = 100.0f;	//ºÒ²É³îÀÌ ¹İÁö¸§
	float bombTime = 2.0f;	//ºÒ²É³îÀÌ ÅÍÁö´Â ½Ã°£

	void PreRender() override;
	void PostRender() override;
};
