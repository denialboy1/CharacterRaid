#include "stdafx.h"
#include "FireCircleWorld.h"


FireCircleWorld::FireCircleWorld()
{
}


FireCircleWorld::~FireCircleWorld()
{
}

void FireCircleWorld::Initialize(){
	mUnFireCircle.clear();
	//안쓰는 총알 초기화
	fireCircleAll = new FireCircle[16];

	FireCircle* fire1 = &fireCircleAll[0];
	fire1->Initialize();
	fire1->SetPosition(D3DXVECTOR3(-10, -1.2, -15));
	fire1->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 7;// (fire1->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire1->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire1);

	FireCircle* fire2 = &fireCircleAll[1];
	fire2->Initialize();
	fire2->SetPosition(D3DXVECTOR3(-32, -1.2, -22));
	fire2->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 7;//(fire2->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire2->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire2);

	FireCircle* fire3 = &fireCircleAll[2];
	fire3->Initialize();
	fire3->SetPosition(D3DXVECTOR3(-20, -1.2, -7));
	fire3->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire3->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire3->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire3);

	FireCircle* fire4 = &fireCircleAll[3];
	fire4->Initialize();
	fire4->SetPosition(D3DXVECTOR3(0, -1.2, -3));
	fire4->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire4->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire4->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire4);

	FireCircle* fire5 = &fireCircleAll[4];
	fire5->Initialize();
	fire5->SetPosition(D3DXVECTOR3(10, -1.2, -15));
	fire5->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;// (fire5->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire5->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire5);

	FireCircle* fire6 = &fireCircleAll[5];
	fire6->Initialize();
	fire6->SetPosition(D3DXVECTOR3(18, -1.2, -4));
	fire6->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire6->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire6->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire6);

	FireCircle* fire7 = &fireCircleAll[6];
	fire7->Initialize();
	fire7->SetPosition(D3DXVECTOR3(10, -1.2, -15));
	fire7->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire7->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire7->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire7);

	FireCircle* fire8 = &fireCircleAll[7];
	fire8->Initialize();
	fire8->SetPosition(D3DXVECTOR3(30, -1.2, 0));
	fire8->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire8->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire8->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire8);

	FireCircle* fire9 = &fireCircleAll[8];
	fire9->Initialize();
	fire9->SetPosition(D3DXVECTOR3(30, -1.2, 20));
	fire9->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire9->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire9->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire9);

	FireCircle* fire10 = &fireCircleAll[9];
	fire10->Initialize();
	fire10->SetPosition(D3DXVECTOR3(20, -1.2, 15));
	fire10->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire10->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire10->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire10);

	FireCircle* fire11 = &fireCircleAll[10];
	fire11->Initialize();
	fire11->SetPosition(D3DXVECTOR3(10, -1.2, 4));
	fire11->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire11->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire11->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire11);

	FireCircle* fire12 = &fireCircleAll[11];
	fire12->Initialize();
	fire12->SetPosition(D3DXVECTOR3(0, -1.2, 23));
	fire12->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire12->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire12->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire12);

	FireCircle* fire13 = &fireCircleAll[12];
	fire13->Initialize();
	fire13->SetPosition(D3DXVECTOR3(-3, -1.2, 10));
	fire13->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire13->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire13->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire13);

	FireCircle* fire14 = &fireCircleAll[13];
	fire14->Initialize();
	fire14->SetPosition(D3DXVECTOR3(-10, -1.2, 20));
	fire14->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire14->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire14->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire14);

	FireCircle* fire15 = &fireCircleAll[14];
	fire15->Initialize();
	fire15->SetPosition(D3DXVECTOR3(-23, -1.2, 1));
	fire15->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire15->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire15->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire15);

	FireCircle* fire16 = &fireCircleAll[15];
	fire16->Initialize();
	fire16->SetPosition(D3DXVECTOR3(-30, -1.2, 14));
	fire16->GetMesh()->GetCollisionSphere()->GetBoundingSphere().radius = 5;//(fire16->GetMesh()->GetCollisionBox()->GetBoundingBox().max.x - fire16->GetMesh()->GetCollisionBox()->GetBoundingBox().min.x) / 2;
	mUnFireCircle.push_back(fire16);

	mFireCircle.clear();
}

void FireCircleWorld::Make(){
	for (auto iter = mUnFireCircle.begin(); iter != mUnFireCircle.end();){
		mFireCircle.push_back((*iter));
		iter = mUnFireCircle.erase(iter);
	}

}

void FireCircleWorld::Update(){
	for (auto iter = mFireCircle.begin(); iter != mFireCircle.end(); iter++){
		(*iter)->Update();
		(*iter)->GetMesh()->GetCollisionSphere()->GetBoundingSphere().center = (*iter)->GetPosition();
	}
}
 
void FireCircleWorld::Render(){
	for (auto iter = mFireCircle.begin(); iter != mFireCircle.end(); iter++){
		(*iter)->Render();
	}
}

void FireCircleWorld::Destroy(){
	for (auto iter = mFireCircle.begin(); iter != mFireCircle.end(); iter++){
		(*iter)->Destroy();
	}

	mFireCircle.clear();

	for (auto iter = mUnFireCircle.begin(); iter != mUnFireCircle.end(); iter++){
		(*iter)->Destroy();
	}

	mUnFireCircle.clear();
}


