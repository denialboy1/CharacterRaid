#pragma once
//�÷��̾� ��ų �Ŵ���
#include "IceMake.h"
#include "IceFire.h"
#include "IceWorld.h"

#include "FireBallFire.h"
#include "FireCircleWorld.h"

#include "HitSphereMake.h"

class SkillManager
{
public:
	SkillManager();
	~SkillManager();


	void Initialize();
	void Update();
	void Render();
	void Destroy();

	static SkillManager& Get(){
		static SkillManager Instance;
		return Instance;
	}

private:
	//���̳�
	IceMake* iceMake = nullptr;
	IceFire* iceFire = nullptr;
	IceWorld* iceWorld = nullptr;

	//��Ÿ��
	FireBallFire* fireBallFire = nullptr;
	FireCircleWorld* fireCircleWorld = nullptr;

	//���ѳ�
	HitSphereMake* hitSphereMake = nullptr;
public:
	//getter

	//���̳�
	IceMake* GetIceMake(){ return iceMake; }
	IceFire* GetIceFire(){ return iceFire; }
	IceWorld* GetIceWorld(){ return iceWorld; }

	//��Ÿ��
	FireBallFire* GertFireBallFire(){ return fireBallFire; }
	FireCircleWorld* GetFireCircleWorld(){ return fireCircleWorld; }

	//���ѳ�
	HitSphereMake* GetHitSphereMake(){ return hitSphereMake; }
};

