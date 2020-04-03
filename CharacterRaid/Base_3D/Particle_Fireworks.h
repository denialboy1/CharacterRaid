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
	D3DXVECTOR3 origin;		//�Ҳɳ��� ����
	float radius = 100.0f;	//�Ҳɳ��� ������
	float bombTime = 2.0f;	//�Ҳɳ��� ������ �ð�

	void PreRender() override;
	void PostRender() override;
};
