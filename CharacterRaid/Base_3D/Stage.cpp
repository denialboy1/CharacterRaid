#include "stdafx.h"
#include "Stage.h"


Stage::Stage()
{
}


Stage::~Stage()
{
}

void Stage::Initialize(float _width,float _height,char* fileName){
	if (grid == nullptr){
		grid = new Grid;
		grid->Initialize(_width, _height);
		grid->SetTexture(TextureManager::GetTexture(fileName));
		grid->SetShowGround(true);
	}


	
}
void Stage::Destroy(){
	SAFE_DELETE(grid);

}
void Stage::Update(){
}
void Stage::Render(){
	if (grid)	grid->Render();
}