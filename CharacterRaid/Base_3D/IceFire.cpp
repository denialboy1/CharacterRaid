#include "stdafx.h"
#include "IceFire.h"


IceFire::IceFire()
{
}


IceFire::~IceFire()
{
}

void IceFire::Update(){
}

void IceFire::Fire(D3DXVECTOR3 _pos){
	IsFire = true;
	pos = _pos;

	
	for (auto iter = iceMake->GetMIce().begin(); iter != iceMake->GetMIce().end(); iter++){
		(*iter)->FindAngle((*iter)->GetPosition(),pos, (*iter)->GetAngle());
	}

	iceWorld->SetDuration(15);
}

void IceFire::Destroy(){
}