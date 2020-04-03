#include "stdafx.h"
#include "EffectManager.h"


EffectManager::EffectManager()
{
}


EffectManager::~EffectManager()
{
}

void EffectManager::Initialize(){
	if (iceImpact == nullptr){
		iceImpact = new IceImpact;
		iceImpact->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(5, 5, 5), 1, 1);
	}

	if (fireCircleExplosion==nullptr){
		fireCircleExplosion = new FireCircleExplosion;
		fireCircleExplosion->Initialize(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	}
}

void EffectManager::Destroy(){
	if (iceImpact)	iceImpact->Destroy();
	if (fireCircleExplosion)	fireCircleExplosion->Destroy();
}

void EffectManager::Update(D3DXVECTOR3 _cameraPos){
	if (iceImpact) iceImpact->Update(_cameraPos);
	if (fireCircleExplosion) fireCircleExplosion->Update(_cameraPos);
}

void EffectManager::Render(){
	if (iceImpact) iceImpact->Render();
	if (fireCircleExplosion) fireCircleExplosion->Render();
}