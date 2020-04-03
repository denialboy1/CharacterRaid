#pragma once
#include "Skill.h"
#include "Ice.h"

#define ICE_COUNT 400

class IceMake : public Skill
{
public:
	IceMake();
	~IceMake();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Make(D3DXVECTOR3 position, float angle);

	std::list<Ice*>& GetMIce(){ return mIceUsed; }
	std::list<Ice*>& GetMIceUnUsed(){ return mIceUnUsed; }

private:
	std::list<Ice*> mIceUsed;
	std::list<Ice*> mIceUnUsed;
	Ice *iceAll = nullptr;
};

