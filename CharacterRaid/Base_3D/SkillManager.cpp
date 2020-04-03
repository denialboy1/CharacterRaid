#include "stdafx.h"
#include "SkillManager.h"


SkillManager::SkillManager()
{
}


SkillManager::~SkillManager()
{
}

void SkillManager::Initialize(){
	//제이나 스킬 모음
		if (iceMake == nullptr){
			iceMake = new IceMake;
			iceMake->Initialize();
		}
		if (iceWorld == nullptr && iceMake){
			iceWorld = new IceWorld;
			iceWorld->AddLinkedAddressIceMake(iceMake);
		}
		if (iceFire == nullptr && iceMake){
			iceFire = new IceFire;
			iceFire->AddLinkedAddressIceWorld(iceWorld);
			iceFire->AddLinkedAddressIceMake(iceMake);
			iceWorld->AddLinkedIceFireAddress(iceFire);
		}
	//켈타스 스킬 모음
	if (fireBallFire == nullptr){
		fireBallFire = new FireBallFire;
		fireBallFire->Initialize();
	}
	if (fireCircleWorld == nullptr){
	//	fireCircleWorld = new FireCircleWorld;
	//	fireCircleWorld->Initialize();
	}

	if (hitSphereMake == nullptr)
	{
		hitSphereMake = new HitSphereMake;
		hitSphereMake->Initialize();
	}
}
void SkillManager::Update(){
	//제이나 스킬 모음
	if (iceMake)	iceMake->Update();
	if (iceFire)	iceFire->Update();
	if (iceWorld)	iceWorld->Update();

	//켈타스 스킬 모음
	if (fireBallFire) fireBallFire->Update();
	if (fireCircleWorld) fireCircleWorld->Update();

	//요한나
	if (hitSphereMake)	hitSphereMake->Update();
}

void SkillManager::Render(){
	//제이나 스킬 모음
	if (iceMake)	iceMake->Render();

	//켈타스 스킬 모음
	if (fireBallFire) fireBallFire->Render();
	if (fireCircleWorld) fireCircleWorld->Render();

	//요한나
	if (hitSphereMake) hitSphereMake->Render();
}

void SkillManager::Destroy(){
	//제이나 스킬 모음
	if (iceMake)	SAFE_DELETE(iceMake);
	if (iceFire)	SAFE_DELETE(iceFire);
	if (iceWorld)	SAFE_DELETE(iceWorld);

	//켈타스 스킬 모음
	if (fireBallFire) SAFE_DELETE(fireBallFire);
	if (fireCircleWorld) SAFE_DELETE(fireCircleWorld);

	//요한나
	if (hitSphereMake) SAFE_DELETE(hitSphereMake);
}