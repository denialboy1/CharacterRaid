#pragma once
#include "Skill.h"
#include "HitSphere.h"

class HitSphereMake :
	public Skill
{
public:
	HitSphereMake();
	~HitSphereMake();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Make(D3DXVECTOR3 position, D3DXVECTOR3 direction);

	std::list<HitSphere*>& GetMHSphere(){ return mHSphere; }

private:
	std::list<HitSphere*> mHSphere;
	HitSphere* sphere1 = nullptr;
	//HitSphere *HSphereAll = nullptr;
};

