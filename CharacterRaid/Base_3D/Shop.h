#pragma once
#include "Item.h"
#include "UI_Image.h"
#include "UI_Base.h"
#include "UsedItemTab.h"
#include "ArtifactTab.h"
#include "SkillTab.h"
#include "SupportSkillTap.h"
#include "StateTab.h"
#include "LifeTab.h"

enum SHOP_STEP
{
	SHOP_NORMAL=0,
	SHOP_USED_ITEM,
	SHOP_ARTIFACT,
	SHOP_SKILL,
	SHOP_SUPPORT_SKILL,
	SHOP_STATE,
	SHOP_LIFE,
	SHOP_QUIT
};

class Shop : public UI_Base
{
public:
	Shop();
	~Shop();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void SetShopStep(SHOP_STEP _shopStep){ shopStep = _shopStep; }
	void SetItem(Item* _item){ item = _item; }
	Item* GetItem(){ return item; }

	void DataLoad();
	void DataSave();
	void DataStageSave();
private:
	int character = 2;
	
	int stage = 0;
	

	UI_Image* background = nullptr;
	UI_Image* shopName = nullptr;
	UI_Image* bag = nullptr;
	UI_Image* bagImage = nullptr;
	UI_Image* ilife = nullptr;
	UI_Image* imoney = nullptr;
	UI_Image* menu = nullptr;
	UI_Image* menu2 = nullptr;
	UI_Image* stateImage = nullptr;

	UI_Button* usedItem = nullptr;
	UI_Button* artifact = nullptr;
	UI_Button* skill = nullptr;
	UI_Button* supportSkill = nullptr;
	UI_Button* state = nullptr;
	UI_Button* lifeBuy = nullptr;
	UI_Button* out = nullptr;

	UI_Text* lv = nullptr;
	UI_Text* lifes = nullptr;
	UI_Text* attack = nullptr;
	UI_Text* armor = nullptr;
	UI_Text* speed = nullptr;
	UI_Text* learnSkill = nullptr;
	UI_Text* totalMoney = nullptr;

	UI_Text* hpCount = nullptr;
	UI_Text* mpCount = nullptr;
	UI_Text* attackCount = nullptr;
	UI_Text* armorCount = nullptr;
	UI_Text* revengeCount = nullptr;
	UI_Text* invincibleCount = nullptr;
	UI_Text* currentArtifact = nullptr;

	UI_Image* imgBlink = nullptr;
	UI_Image* imgInvincible = nullptr;
	UI_Image* imgSpeedUp = nullptr;

	//요한나 스킬
	UI_Image* imgArmorSkill = nullptr;
	UI_Image* imgAttackSkill = nullptr;

	//노바 스킬
	UI_Image* imgSniperSkill = nullptr;
	UI_Image* imgHyperionSkill = nullptr;
	UI_Image* imgPowerUpSkill = nullptr;
	UI_Image* imgNuclearSkill = nullptr;

	//제이나 스킬
	UI_Image* imgIceSkill = nullptr;
	UI_Image* imgIceFireSkill = nullptr;
	UI_Image* imgIcePowerSkill = nullptr;
	UI_Image* imgIceWorldSkill = nullptr;

	//일반스킬
	UI_Image* imgCommonHpSkill = nullptr;
	UI_Image* imgCommonMpSkill = nullptr;

	UsedItemTab* usedItemTab = nullptr;
	ArtifactTab* artifactTab = nullptr;
	SkillTab* skillTab = nullptr;
	SupportSkillTap* supportSkillTap = nullptr;
	StateTab* stateTab = nullptr;
	LifeTab* lifeTab = nullptr;
	enum CHILD_TYPE
	{
		IMAGE_BACKGROUND = 0,
		TEXT_TITLE,
		TEXT_DESC,
		BUTTON_OK,
		BUTTON_CANCEL
	};

	SHOP_STEP shopStep = SHOP_NORMAL;
	
	int money = 100000;
	int level = 1;
	int stateAttack = 0;
	int exp = 0;
	int hp = 0;
	int mp = 0;
	int stateArmor = 0;
	int stateSpeed = 0;
	Item* item = nullptr;


	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;
	LPD3DXFONT font3 = nullptr;


public:
	int GetMoney(){ return money; }
	void SetMoney(int _money){ money = _money; }

};

