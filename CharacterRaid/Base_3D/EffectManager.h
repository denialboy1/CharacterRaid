#pragma once
#include "IceImpact.h"
#include "FireCircleExplosion.h"
class EffectManager
{
public:
	EffectManager();
	~EffectManager();

	void Initialize();
	void Destroy();
	void Update(D3DXVECTOR3 _cameraPos);
	void Render();

	static EffectManager& Get(){
		static EffectManager Instance;
		return Instance;
	}
private:
	IceImpact* iceImpact = nullptr;
	FireCircleExplosion* fireCircleExplosion = nullptr;

public :
	IceImpact* GetIceImpact(){ return iceImpact; }
	FireCircleExplosion* GetFireCircleExplosion() { return fireCircleExplosion; }
};

