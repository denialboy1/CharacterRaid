#include "stdafx.h"
#include "SkillManager.h"


SkillManager::SkillManager()
{
}


SkillManager::~SkillManager()
{
}

void SkillManager::Initialize(){
	//���̳� ��ų ����
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
	//��Ÿ�� ��ų ����
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
	//���̳� ��ų ����
	if (iceMake)	iceMake->Update();
	if (iceFire)	iceFire->Update();
	if (iceWorld)	iceWorld->Update();

	//��Ÿ�� ��ų ����
	if (fireBallFire) fireBallFire->Update();
	if (fireCircleWorld) fireCircleWorld->Update();

	//���ѳ�
	if (hitSphereMake)	hitSphereMake->Update();
}

void SkillManager::Render(){
	//���̳� ��ų ����
	if (iceMake)	iceMake->Render();

	//��Ÿ�� ��ų ����
	if (fireBallFire) fireBallFire->Render();
	if (fireCircleWorld) fireCircleWorld->Render();

	//���ѳ�
	if (hitSphereMake) hitSphereMake->Render();
}

void SkillManager::Destroy(){
	//���̳� ��ų ����
	if (iceMake)	SAFE_DELETE(iceMake);
	if (iceFire)	SAFE_DELETE(iceFire);
	if (iceWorld)	SAFE_DELETE(iceWorld);

	//��Ÿ�� ��ų ����
	if (fireBallFire) SAFE_DELETE(fireBallFire);
	if (fireCircleWorld) SAFE_DELETE(fireCircleWorld);

	//���ѳ�
	if (hitSphereMake) SAFE_DELETE(hitSphereMake);
}