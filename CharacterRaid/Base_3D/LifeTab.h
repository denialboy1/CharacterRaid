#pragma once
#include "UI_Base.h"
class LifeTab : public UI_Base
{
public:
	LifeTab();
	~LifeTab();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize(Item* _item,int _character);
	void Update();

	void Destroy();

private:
	//공통
	UI_Image* background = nullptr;
	UI_Image* list[1];
	UI_Button* buy = nullptr;
	UI_Button* tabOut = nullptr;

	bool isDrag = false;
	POINT prevMouse;

	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;

	Item* item = nullptr;

	int character = 0;

	//요한나
	UI_Image* johanna = nullptr;
	UI_Text* johannaName = nullptr;
	UI_Text* johannaDesc = nullptr;
	UI_Text* johannaPrice = nullptr;
	UI_Text* johannaNum = nullptr;
	UI_Button* johannaUp = nullptr;
	UI_Button* johannaDown = nullptr;

	//노바
	UI_Image* nova = nullptr;
	UI_Text* novaName = nullptr;
	UI_Text* novaDesc = nullptr;
	UI_Text* novaPrice = nullptr;
	UI_Text* novaNum = nullptr;
	UI_Button* novaUp = nullptr;
	UI_Button* novaDown = nullptr;

	//제이나
	UI_Image* jaina = nullptr;
	UI_Text* jainaName = nullptr;
	UI_Text* jainaDesc = nullptr;
	UI_Text* jainaPrice = nullptr;
	UI_Text* jainaNum = nullptr;
	UI_Button* jainaUp = nullptr;
	UI_Button* jainaDown = nullptr;
};

