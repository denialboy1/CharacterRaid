#pragma once
#include "Item.h"

class UI_Functions
{
public:
	UI_Functions();
	~UI_Functions();

	void ButtonClick(UI_Base* sender);
	void ButtonQuestOK(UI_Base* sender);
	void ButtonQuestCancel(UI_Base* sender);
	
	void ButtonSelectStep(UI_Base* sender,int _selectStep);
	void ButtonStep(UI_Base* sender, int _selectStep);
	
	void ButtonShopStep(UI_Base* sender,int _shopStep);
	void ButtonBuy(UI_Base* sender,Item* item);
	void ButtonCancel(UI_Base* sender,Item* item);
	void ButtonUp(UI_Base* sender, int* item);
	void ButtonDown(UI_Base* sender, int* item);
	void ButtonCheck(UI_Base* sender, Item* item,int _artifact);
	void UI_Functions::ButtonSkillCheck(UI_Base* sender, bool* skill);
};

