#include "stdafx.h"
#include "UI_Loading.h"


UI_Loading::UI_Loading()
{
}


UI_Loading::~UI_Loading()
{
}

void UI_Loading::Render(){
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();
}

LRESULT UI_Loading::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;
	return result;
}

void UI_Loading::Initialize(){
	if (backGround == nullptr){
		backGround = new UI_Image;
		backGround->SetTexture("./Loading/backGround.png");
		backGround->SetPosition(0, 0, 0);
		this->size = backGround->GetSize();
		this->AddChild(backGround);
	}

	/*
	if (bar == nullptr){
		bar = new UI_Image;
		bar->SetTexture("./Loading/bar.png");
		bar->SetPosition(x, y, 0);
		this->AddChild(bar);
	}

	if (empty == nullptr){
		empty = new UI_Image;
		empty->SetTexture("./Loading/empty.png");
		empty->SetPosition(x, y, 0);
		this->AddChild(empty);
	}

	if (full == nullptr){
		full = new UI_Image;
		full->SetTexture("./Loading/full.png");
		full->SetPosition(x, y, 0);
		this->AddChild(full);
	}*/
}

void UI_Loading::Update(){
	if (isShow != true)
	{
		return;
	}

	UI_Base::Update();
}

void UI_Loading::Destroy(){
	SAFE_DELETE(backGround);
	SAFE_DELETE(bar);
	SAFE_DELETE(empty);
	SAFE_DELETE(full);
}