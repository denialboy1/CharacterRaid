#pragma once
#include "Skill.h"
#include "Ice.h"


#define CHANT 200
#define NORMAL 100

class IceFire;
class IceMake;
class IceWorld : public Skill
{
public:
	IceWorld();
	~IceWorld();

	void Destroy();
	void Update();
	void Fire();

	void AddLinkedAddressIceMake(IceMake* _iceMake){ iceMake = _iceMake; }
	void AddLinkedIceFireAddress(IceFire* _iceFire){ iceFire = _iceFire; }

	void SetDuration(float _duration){ durationTime = _duration; }
private:
	std::list< Ice*>* mIceUsed;
	std::list< Ice*>* mIceUnUsed;

	bool isChant = false;
	int power = 0;
	float speed = 3;

	float startTime = 0;

	IceFire* iceFire;
	IceMake* iceMake;
public :
	void SetIsChant(bool _isChant){ isChant = _isChant; }
};

