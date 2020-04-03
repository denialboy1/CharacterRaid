#include "stdafx.h"
#include "IceMake.h"


IceMake::IceMake()
{
}


IceMake::~IceMake()
{
}

void IceMake::Initialize(){
	mIceUnUsed.clear();
	//안쓰는 총알 초기화
	iceAll = new Ice[ICE_COUNT];
	for (int i = 0; i < ICE_COUNT; i++){
		Ice *ice = &iceAll[i];
		ice->Initialize();
		mIceUnUsed.push_back(ice);
	}

	mIceUsed.clear();
}

void IceMake::Make(D3DXVECTOR3 position, float angle){
	if (mIceUnUsed.size() == 0){
		return;
	}

	for (auto iter = mIceUnUsed.begin(); iter != mIceUnUsed.end(); iter++){
		(*iter)->SetAngle(angle);
		(*iter)->SetState(Ice::BIRTH);		
		D3DXVECTOR3 newPos = position - (*iter)->GetDirection() * 3;
		newPos.y += 1.5;
		(*iter)->SetPosition(newPos);
		(*iter)->Update();
		mIceUsed.push_back((*iter));
		mIceUnUsed.erase(iter);
		break;
	}
}

void IceMake::Destroy(){
	
	for (auto iter = mIceUsed.begin(); iter != mIceUsed.end(); iter++){
		(*iter)->Destroy();
	}
	
	for (auto iter = mIceUnUsed.begin(); iter != mIceUnUsed.end(); iter++){
		(*iter)->Destroy();
	}

	mIceUsed.clear();
	mIceUnUsed.clear();
	
}

void IceMake::Update(){
	for (auto iter= mIceUsed.begin(); iter != mIceUsed.end(); iter++){
			(*iter)->Update();
	}


}

void IceMake::Render(){
	for (auto iter = mIceUsed.begin(); iter != mIceUsed.end(); iter++){
		(*iter)->Render();
	}
}

