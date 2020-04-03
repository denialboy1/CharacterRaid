#pragma once
#include "UI_Base.h"

class SkillTab : public UI_Base
{
public:
	SkillTab();
	~SkillTab();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize(Item* _item,int _character);
	void Update();

	void Destroy();

private:
	//공통
	UI_Image* background = nullptr;
	UI_Image* list[4];
	UI_Button* buy = nullptr;
	UI_Button* tabOut = nullptr;

	bool isDrag = false;
	POINT prevMouse;

	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;

	Item* item = nullptr;

	int character = 0;

	//요한나
	UI_Image* armorBuff = nullptr;
	UI_Text* armorBuffName = nullptr;
	UI_Text* armorBuffDesc = nullptr;
	UI_Text* armorBuffPrice = nullptr;
	UI_Image* armorCheck = nullptr;
	UI_Button* armorUnCheck = nullptr;

	UI_Image* attackBuff = nullptr;
	UI_Text* attackBuffName = nullptr;
	UI_Text* attackBuffDesc = nullptr;
	UI_Text* attackBuffPrice = nullptr;
	UI_Image* attackCheck = nullptr;
	UI_Button* attackUnCheck = nullptr;

	//노바
	UI_Image* sniper = nullptr;
	UI_Text* sniperName = nullptr;
	UI_Text* sniperDesc = nullptr;
	UI_Text* sniperPrice = nullptr;
	UI_Image* sniperCheck = nullptr;
	UI_Button* sniperUnCheck = nullptr;

	UI_Image* hyperion = nullptr;
	UI_Text* hyperionName = nullptr;
	UI_Text* hyperionDesc = nullptr;
	UI_Text* hyperionPrice = nullptr;
	UI_Image* hyperionCheck = nullptr;
	UI_Button* hyperionUnCheck = nullptr;

	UI_Image* powerUp = nullptr;
	UI_Text* powerUpName = nullptr;
	UI_Text* powerUpDesc = nullptr;
	UI_Text* powerUpPrice = nullptr;
	UI_Image* powerUpCheck = nullptr;
	UI_Button* powerUpUnCheck = nullptr;

	UI_Image* nuclear = nullptr;
	UI_Text* nuclearName = nullptr;
	UI_Text* nuclearDesc = nullptr;
	UI_Text* nuclearPrice = nullptr;
	UI_Image* nuclearCheck = nullptr;
	UI_Button* nuclearUnCheck = nullptr;

	//제이나
	UI_Image* ice = nullptr;
	UI_Text* iceName = nullptr;
	UI_Text* iceDesc = nullptr;
	UI_Text* icePrice = nullptr;
	UI_Image* iceCheck = nullptr;
	UI_Button* iceUnCheck = nullptr;

	UI_Image* iceFire = nullptr;
	UI_Text* iceFireName = nullptr;
	UI_Text* iceFireDesc = nullptr;
	UI_Text* iceFirePrice = nullptr;
	UI_Image* iceFireCheck = nullptr;
	UI_Button* iceFireUnCheck = nullptr;

	UI_Image* icePower = nullptr;
	UI_Text* icePowerName = nullptr;
	UI_Text* icePowerDesc = nullptr;
	UI_Text* icePowerPrice = nullptr;
	UI_Image* icePowerCheck = nullptr;
	UI_Button* icePowerUnCheck = nullptr;

	UI_Image* iceWorld = nullptr;
	UI_Text* iceWorldName = nullptr;
	UI_Text* iceWorldDesc = nullptr;
	UI_Text* iceWorldPrice = nullptr;
	UI_Image* iceWorldCheck = nullptr;
	UI_Button* iceWorldUnCheck = nullptr;
};

