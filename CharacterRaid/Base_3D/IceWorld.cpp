#include "stdafx.h"
#include "IceWorld.h"


IceWorld::IceWorld()
{
}


IceWorld::~IceWorld()
{
}

void IceWorld::Update(){

	//µ¥ÀÌÅÍ ¹Ý³³
	float time = (timeGetTime() - startTime)*0.001f;
	if (time > durationTime){
		for (auto iter = iceMake->GetMIce().begin(); iter != iceMake->GetMIce().end(); iter++){
			if ((*iter)->GetIsUltimate()){
				iceMake->GetMIceUnUsed().push_back((*iter));
				iceMake->GetMIce().erase(iter);
				if (iceMake->GetMIce().size() == 0) break;
				iter = iceMake->GetMIce().begin();
			}
		}

		iceFire->SetIsFire(false);
	}

	if (iceFire->GetIsFire()) return;
	for (auto iter = iceMake->GetMIce().begin(); iter != iceMake->GetMIce().end(); iter++){
		if ((*iter)->GetIsUltimate()){
			(*iter)->SetPosition((*iter)->GetPosition() - (*iter)->GetDirection()*0.05);
		}
	}

}
void IceWorld::Fire(){
	if (isChant){ power = CHANT; }
	else{ power = NORMAL; }
	
	for (int i = 0; i < power; i++){
		for (auto iter = iceMake->GetMIceUnUsed().begin(); iter != iceMake->GetMIceUnUsed().end();){
			(*iter)->SetPosition(D3DXVECTOR3(RandomUtil::GetInteger(30, -45), 3, RandomUtil::GetInteger(20, -25)));
			(*iter)->SetAngle(RandomUtil::GetFloat(-D3DX_PI, D3DX_PI));
			(*iter)->SetIsUltimate(true);
			iceMake->GetMIce().push_back((*iter));
			iceMake->GetMIceUnUsed().erase(iter);
			break;
		}
	}

	startTime = timeGetTime();

	durationTime = 3;
}

void IceWorld::Destroy(){
}