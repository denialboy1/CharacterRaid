#pragma once
#include "Skill.h"

class IceWorld;
class IceMake;
class IceFire : public Skill
{
public:
	IceFire();
	~IceFire();

	void Destroy();
	void Update();
	void Fire(D3DXVECTOR3 _pos);

	void AddLinkedAddressIceMake(IceMake* _iceMake){ iceMake = _iceMake; }
	void AddLinkedAddressIceWorld(IceWorld* _iceWorld){ iceWorld = _iceWorld; }

	bool GetIsFire(){ return IsFire; }
	void SetIsFire(bool _isFire){ IsFire = _isFire; }

	
private:
	D3DXVECTOR3 pos;
	bool IsFire = false;
	IceWorld* iceWorld = nullptr;

	IceMake* iceMake;
	
};

