#pragma once
#include "UI_Base.h"
class ArtifactTab :public UI_Base
{
public:
	ArtifactTab();
	~ArtifactTab();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize(Item* _item);
	void Update();

	void Destroy();

private:
	//°øÅë
	UI_Image* background = nullptr;
	UI_Image* list[3];
	UI_Button* buy = nullptr;
	UI_Button* tabOut = nullptr;

	bool isDrag = false;
	POINT prevMouse;

	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;

	Item* item = nullptr;

	UI_Image* blink = nullptr;
	UI_Text* blinkName = nullptr;
	UI_Text* blinkDesc = nullptr;
	UI_Image* blinkCheck = nullptr;
	UI_Button* blinkUnCheck = nullptr;

	UI_Image* invincible = nullptr;
	UI_Text* invincibleName = nullptr;
	UI_Text* invincibleDesc = nullptr;
	UI_Image* invincibleCheck = nullptr;
	UI_Button* invincibleUnCheck = nullptr;


	UI_Image* speed = nullptr;
	UI_Text* speedName = nullptr;
	UI_Text* speedDesc = nullptr;
	UI_Image* speedCheck = nullptr;
	UI_Button* speedUnCheck = nullptr;
};

