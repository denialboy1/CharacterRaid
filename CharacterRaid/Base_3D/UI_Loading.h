#pragma once
#include "UI_Base.h"
class UI_Loading : public UI_Base
{
public:
	UI_Loading();
	~UI_Loading();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize();
	void Update();

	void Destroy();

private:
	float x = 0, y = 750;
	//°øÅë
	UI_Image* bar = nullptr;
	UI_Image* empty = nullptr;
	UI_Image* full = nullptr;
	UI_Image* backGround = nullptr;

public:
	UI_Image* GetBar(){ return bar; }
};

