#include "stdafx.h"
#include "Marine.h"


Marine::Marine()
{
}


Marine::~Marine()
{
}

void Marine::Initialize(D3DXVECTOR3 _scale){
	unit::Initialize();
	scale = _scale;
	mesh->Initialize("Marine/", "Marine.x",scale);
	
	
	unit::Update();
	obb = new cOBB;
	obb->Setup(mesh);
}

void Marine::Destroy(){
	unit::Destroy();
}

void Marine::Update(){
	unit::Update();
	obb->Update(&obbWorld);
}

void Marine::Render(){
	mesh->UpdateAndRender();
	obb->DebugRender(D3DCOLOR_XRGB(255,0,0));
}