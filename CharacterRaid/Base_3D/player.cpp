#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

void player::Update(){
	unit::Update();
	LvUp();
	GameOver();
	
}
void player::DataSave(){
	iniDataManager::Get().addData("Player", "Character", "3");

	char str[128];
	_itoa_s(iniDataManager::Get().loadDataInterger("Player","Player","stage")+1, str, 10);
	iniDataManager::Get().addData("Player", "stage", str);

	_itoa_s(item->life, str, 10);
	iniDataManager::Get().addData("Player", "Life", str);
	_itoa_s(lv, str, 10);
	iniDataManager::Get().addData("Player", "LV", str);
	_itoa_s(exp, str, 10);
	iniDataManager::Get().addData("Player", "Exp", str);
	_itoa_s(hp, str, 10);
	iniDataManager::Get().addData("Player", "HP", str);
	_itoa_s(mp, str, 10);
	iniDataManager::Get().addData("Player", "MP", str);
	_itoa_s(attackPoint, str, 10);
	iniDataManager::Get().addData("Player", "Attack", str);
	_itoa_s(armorPoint, str, 10);
	iniDataManager::Get().addData("Player", "Armor", str);
	_itoa_s(speedPoint, str, 10);
	iniDataManager::Get().addData("Player", "Speed", str);

	_itoa_s(money, str, 10);
	iniDataManager::Get().addData("Item", "Money", str);
	_itoa_s(item->hpPotion, str, 10);
	iniDataManager::Get().addData("Item", "HpPotion", str);
	_itoa_s(item->mpPotion, str, 10);
	iniDataManager::Get().addData("Item", "MpPotion", str);
	_itoa_s(item->attackBuff, str, 10);
	iniDataManager::Get().addData("Item", "PowerHerb", str);
	_itoa_s(item->armorBuff, str, 10);
	iniDataManager::Get().addData("Item", "ArmorPotion", str);
	_itoa_s(item->revenge, str, 10);
	iniDataManager::Get().addData("Item", "StunDagger", str);
	_itoa_s(item->invincible, str, 10);
	iniDataManager::Get().addData("Item", "Invincible", str);

	_itoa_s(item->blink, str, 10);
	iniDataManager::Get().addData("Item", "Neckles", str);
	_itoa_s(item->invincibleA, str, 10);
	iniDataManager::Get().addData("Item", "Ring", str);
	_itoa_s(item->speedUp, str, 10);
	iniDataManager::Get().addData("Item", "boots", str);

	//노바
	_itoa_s(item->sniperSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "Sniper", str);
	_itoa_s(item->hyperionSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "Hyperion", str);
	_itoa_s(item->powerUpSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "PowerUp", str);
	_itoa_s(item->nuclearSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "Nuclear", str);


	//요한나
	_itoa_s(item->armorSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "ArmorBuff", str);
	_itoa_s(item->attackSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "AttackBuff", str);

	//제이나
	_itoa_s(item->iceSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "Ice", str);
	_itoa_s(item->iceFireSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "IceFire", str);
	_itoa_s(item->icePowerSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "MpRegen", str);
	_itoa_s(item->iceWorldSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "IceWorld", str);

	_itoa_s(item->commonHpSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "SupportHp", str);
	_itoa_s(item->commonMpSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "SupportMp", str);

	iniDataManager::Get().iniSave("player");
}
void player::LvUp(){
	switch (lv){
	case 1:
		if (LV2 <= exp){ lv = 2; }
		break;
	case 2:
		if (LV3 <= exp){ lv = 3; }
		break;
	case 3:
		if (LV4 <= exp){ lv = 4; }
		break;
	case 4:
		if (LV5 <= exp){ lv = 5; }
		break;
	case 5:
		if (LV6 <= exp){ lv = 6; }
		break;
	case 6:
		if (LV7 <= exp){ lv = 7; }
		break;
	case 7:
		if (LV8 <= exp){ lv = 8; }
		break;
	case 8:
		if (LV9 <= exp){ lv = 9; }
		break;
	case 9:
		if (LV10 <= exp){ lv = 10; }
		break;
	}
}


void player::GameOver(){
	if (life <= 0 && hp < 0){
		//게임오버
	}
}

LRESULT player::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;

	return result;
}

void player::Initialize(){
	unit::Initialize();
}
void player::Detroy(){
	unit::Destroy();
}

void player::Battle(unit& enemy){

}