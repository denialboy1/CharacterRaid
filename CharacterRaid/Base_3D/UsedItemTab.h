#pragma once
#include "UI_Base.h"
class UsedItemTab : public UI_Base
{
public:
	UsedItemTab();
	~UsedItemTab();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize();
	void Update();

	void Destroy();
private:
	UI_Image* background = nullptr;
	UI_Image* list[6];
	


	UI_Button* buy = nullptr;
	UI_Button* tabOut = nullptr;

	UI_Image* hpPotion = nullptr;
	UI_Text* hpName = nullptr;
	UI_Text* hpDesc = nullptr;
	UI_Text* hpPrice = nullptr;
	UI_Text* hpNum = nullptr;
	UI_Button* hpUp = nullptr;
	UI_Button* hpDown = nullptr;

	UI_Image* mpPotion = nullptr;
	UI_Text* mpName = nullptr;
	UI_Text* mpDesc = nullptr;
	UI_Text* mpPrice = nullptr;
	UI_Text* mpNum = nullptr;
	UI_Button* mpUp = nullptr;
	UI_Button* mpDown = nullptr;

	//attackBuff
	UI_Image* attackBuff = nullptr;
	UI_Text* attackBuffName = nullptr;
	UI_Text* attackBuffDesc = nullptr;
	UI_Text* attackBuffPrice = nullptr;
	UI_Text* attackBuffNum = nullptr;
	UI_Button* attackBuffUp = nullptr;
	UI_Button* attackBuffDown = nullptr;

	//defenceBuff
	UI_Image* defenceBuff = nullptr;
	UI_Text* defenceBuffName = nullptr;
	UI_Text* defenceBuffDesc = nullptr;
	UI_Text* defenceBuffPrice = nullptr;
	UI_Text* defenceBuffNum = nullptr;
	UI_Button* defenceBuffUp = nullptr;
	UI_Button* defenceBuffDown = nullptr;

	//attack
	UI_Image* attack = nullptr;
	UI_Text* attackName = nullptr;
	UI_Text* attackDesc = nullptr;
	UI_Text* attackPrice = nullptr;
	UI_Text* attackNum = nullptr;
	UI_Button* attackUp = nullptr;
	UI_Button* attackDown = nullptr;

	//Invincible
	UI_Image* invincible = nullptr;
	UI_Text* invincibleName = nullptr;
	UI_Text* invincibleDesc = nullptr;
	UI_Text* invinciblePrice = nullptr;
	UI_Text* invincibleNum = nullptr;
	UI_Button* invincibleUp = nullptr;
	UI_Button* invincibleDown = nullptr;

	bool isDrag = false;
	POINT prevMouse;

	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;

	Item* item = nullptr;
};

