#pragma once
#include "UI_Base.h"
class StateTab : public UI_Base
{
public:
	StateTab();
	~StateTab();

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

	//atk
	UI_Image* atk = nullptr;
	UI_Text* atkName = nullptr;
	UI_Text* atkDesc = nullptr;
	UI_Text* atkPrice = nullptr;
	UI_Text* atkNum = nullptr;
	UI_Button* atkUp = nullptr;
	UI_Button* atkDown = nullptr;

	//def
	UI_Image* def = nullptr;
	UI_Text* defName = nullptr;
	UI_Text* defDesc = nullptr;
	UI_Text* defPrice = nullptr;
	UI_Text* defNum = nullptr;
	UI_Button* defUp = nullptr;
	UI_Button* defDown = nullptr;

	//move
	UI_Image* move = nullptr;
	UI_Text* moveName = nullptr;
	UI_Text* moveDesc = nullptr;
	UI_Text* movePrice = nullptr;
	UI_Text* moveNum = nullptr;
	UI_Button* moveUp = nullptr;
	UI_Button* moveDown = nullptr;
};

