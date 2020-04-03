#include "stdafx.h"
#include "Stage2.h"


Stage2::Stage2()
{
}


Stage2::~Stage2()
{
}

void Stage2::Initialize(float _width, float _height, char* fileName){
	Stage::Initialize(_width, _height, fileName);

	vWall.resize(8);

	vWall[0] = new StructureObject;
	vWall[0]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[0]->SetPosition(D3DXVECTOR3(26, 0, -44));
	vWall[0]->SetAngle(0.55f*D3DX_PI);
	
	vWall[1] = new StructureObject;
	vWall[1]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[1]->SetPosition(D3DXVECTOR3(-26, 0, -44));
	vWall[1]->SetAngle(-0.5f*D3DX_PI);
	
	vWall[2] = new StructureObject;
	vWall[2]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[2]->SetPosition(D3DXVECTOR3(-46, 0, -26));
	vWall[2]->SetAngle(-0.96f*D3DX_PI);
	
	vWall[3] = new StructureObject;
	vWall[3]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[3]->SetPosition(D3DXVECTOR3(-44, 0, 26));
	vWall[3]->SetAngle(0.03f*D3DX_PI);
	
	vWall[4] = new StructureObject;
	vWall[4]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[4]->SetPosition(D3DXVECTOR3(-26, 0, 46));
	vWall[4]->SetAngle(-0.48f*D3DX_PI);
	
	vWall[5] = new StructureObject;
	vWall[5]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[5]->SetPosition(D3DXVECTOR3(26, 0, 43));
	vWall[5]->SetAngle(0.54f*D3DX_PI);

	vWall[6] = new StructureObject;
	vWall[6]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[6]->SetPosition(D3DXVECTOR3(46, 0, 28));
	vWall[6]->SetAngle(0.05f*D3DX_PI);
	

	vWall[7] = new StructureObject;
	vWall[7]->Initialize("Heaven_Wall/", "Wall.X", D3DXVECTOR3(0.045f, 0.03f, 0.0675f));
	vWall[7]->SetPosition(D3DXVECTOR3(46, 0, -30));
	vWall[7]->SetAngle(-1.0f*D3DX_PI);

	if (path == nullptr)
	{
		path = new PathFinder;
		path->Initialize("stage3.txt");
	}
}
void Stage2::Destroy(){
	Stage::Destroy();

	for (int i = 0; i < vWall.size(); i++)
	{
		SAFE_DELETE(vWall[i]);
	}
	vWall.clear();
	if (path)
	{
		SAFE_DELETE(path);
	}
}
void Stage2::Update(){
	for (int i = 0; i < vWall.size(); i++)
	{
		vWall[i]->Update();
	}
}
void Stage2::Render(){
	Stage::Render();

	for (int i = 0; i < vWall.size(); i++)
	{
		vWall[i]->Render();
	}
}