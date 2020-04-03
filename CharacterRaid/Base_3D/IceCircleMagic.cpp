#include "stdafx.h"
#include "IceCircleMagic.h"


IceCircleMagic::IceCircleMagic()
{
}


IceCircleMagic::~IceCircleMagic()
{
}

void IceCircleMagic::Make(){

}
void IceCircleMagic::Destroy(){
	SAFE_DELETE(iceCircle);
}
void IceCircleMagic::Update(){
	if (iceCircle){
		iceCircle->Update();
	}
}
void IceCircleMagic::Render(){
	if (iceCircle){
		iceCircle->Render();
	}
}