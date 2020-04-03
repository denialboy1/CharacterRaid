#pragma once
#include "UI_Base.h"

class SupportSkillTap : public UI_Base
{
public:
	SupportSkillTap();
	~SupportSkillTap();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize(Item* _item, int _character);
	void Update();

	void Destroy();

private:
	//°øÅë
	UI_Image* background = nullptr;
	UI_Image* list[2];
	UI_Button* buy = nullptr;
	UI_Button* tabOut = nullptr;

	bool isDrag = false;
	POINT prevMouse;

	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;

	Item* item = nullptr;

	UI_Image* hp = nullptr;
	UI_Text* hpName = nullptr;
	UI_Text* hpDesc = nullptr;
	UI_Text* hpPrice = nullptr;
	UI_Image* hpCheck = nullptr;
	UI_Button* hpUnCheck = nullptr;

	UI_Image* mp = nullptr;
	UI_Text* mpName = nullptr;
	UI_Text* mpDesc = nullptr;
	UI_Text* mpPrice = nullptr;
	UI_Image* mpCheck = nullptr;
	UI_Button* mpUnCheck = nullptr;

};

