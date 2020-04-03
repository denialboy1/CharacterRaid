#include "stdafx.h"
#include "HitSphereMake.h"


HitSphereMake::HitSphereMake()
{
}


HitSphereMake::~HitSphereMake()
{
}

void HitSphereMake::Initialize()
{
	mHSphere.clear();
}

void HitSphereMake::Make(D3DXVECTOR3 position, D3DXVECTOR3 direction)
{
	sphere1 = new HitSphere;
	sphere1->Initialize();
	D3DXVECTOR3 newPos = position - direction * 3;
	sphere1->SetPosition(newPos);
	sphere1->GetSphere()->GetBoundingSphere().center = newPos;
	sphere1->GetSphere()->GetBoundingSphere().radius = 3;
	sphere1->Update();
	mHSphere.push_back(sphere1);
}

void HitSphereMake::Destroy()
{
	for (auto iter = mHSphere.begin(); iter != mHSphere.end(); iter++)
	{
		SAFE_DELETE((*iter));

	}
	
	mHSphere.clear();
}
void HitSphereMake::Update()
{
	for (auto iter = mHSphere.begin(); iter != mHSphere.end(); iter++)
	{
		(*iter)->Update();
	}
}
void HitSphereMake::Render()
{
	for (auto iter = mHSphere.begin(); iter != mHSphere.end(); iter++)
	{
		(*iter)->Render();
	}
}
