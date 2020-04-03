#pragma once
#include "UI_Base.h"
#include "UI_Image.h"
#include <Windows.h>
#include <string>
#include "CalcScore.h"
#include "jaina.h"
enum INTERFACE_STATE
{
	INTERFACE_NORMAL = 0,
	INTERFACE_SKILL
};
class UI_Interface : public UI_Base
{
public:
	UI_Interface();
	~UI_Interface();

	void Initialize();
	void Update();
	void Destroy();
	virtual void Render() override;
	LPD3DXFONT font = nullptr;
	LPD3DXFONT font2 = nullptr;
	LPD3DXFONT font3 = nullptr;
	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void SetJainaAddress(Jaina* _j){ _jaina = _j; }
protected:
	bool isDrag = false;
	POINT prevMouse;

	UI_Image* backGround = nullptr;
	UI_Image* BasicAttack = nullptr;
	UI_Image* Move = nullptr;
	UI_Image* Stop = nullptr;
	UI_Image* NovaQSkill = nullptr;
	UI_Image* NovaWSkill = nullptr;
	UI_Image* NovaESkill = nullptr;
	UI_Image* NovaRSkill = nullptr;

	UI_Image* JainaQSkill = nullptr;
	UI_Image* JainaWSkill = nullptr;
	UI_Image* JainaESkill = nullptr;
	UI_Image* JainaRSkill = nullptr;

	UI_Image* JohannaQSkill = nullptr;
	UI_Image* JohannaWSkill = nullptr;
	UI_Image* JohannaESkill = nullptr;
	UI_Image* JohannaRSkill = nullptr;

	UI_Image* HpPotion = nullptr;
	UI_Image* MpPotion = nullptr;
	UI_Image* PowerHerb = nullptr;
	UI_Image* ArmourPotion = nullptr;
	UI_Image* StunSword = nullptr;
	UI_Image* InvincibilityScroll = nullptr;

	UI_Image* Blink = nullptr;
	UI_Image* Ring = nullptr;
	UI_Image* Boots = nullptr;

	UI_Image* HpBar = nullptr;

	UI_Image* MpBar = nullptr;

	UI_Image* EXP = nullptr;

	UI_Text* hpPotionText = nullptr;
	UI_Text* mpPotionText = nullptr;
	UI_Text* attackBuffText = nullptr;
	UI_Text* armorBuffText = nullptr;
	UI_Text* revengeText = nullptr;
	UI_Text* invincibleText = nullptr;

	UI_Text* JainaSkillECoolTime = nullptr;
	UI_Text* JainaSkillRCoolTime = nullptr;
	UI_Text* AtifactCoolTime = nullptr;

	Jaina* _jaina = nullptr;

	int eSkillCoolTimeTimer = 0;
	int rSkillCoolTimeTimer = 0;
	int AtifactUseCoolTime = 100;
	bool IsAtifactUseCoolTime = true;
	int AtifactUnUseTimer = 0;
	bool IsAtifactUnUse = false;

	int hpPotionCount = 0;
	int mpPotionCount = 0;
	int attacBuffCount = 0;
	int armorBuffCount = 0;
	int revengeCount = 0;
	int invincibleCount = 0;
	float SkillECount = 0;
	float CurrentHp;

	float hp = 0;
	float mp = 0;
	float hpMax = 0;
	float mpMax = 0;
	enum CHILD_TYPE
	{
		IMAGE_BACKGROUND = 0,
		TEXT_TITLE,
		TEXT_DESC,
		BUTTON_OK,
		BUTTON_CANCEL
	};

	INTERFACE_STATE InterfaceState = INTERFACE_NORMAL;

	UI_Text* Score = nullptr;
	UI_Text* timer = nullptr;
	int minute = 0;
	int second = 0;

	CalcScore* calcScore = nullptr;
	bool isNova;
	bool isJaina;
	bool isJohanna;
	bool isBlink;
	bool isRing;
	bool isBoots;


	UI_Image* coolTimeBox1 = nullptr;
	UI_Image* coolTimeBox2 = nullptr;
	UI_Image* coolTimeBox3 = nullptr;
	UI_Image* coolTimeBox4 = nullptr;

	UI_Image* supportQ = nullptr;
	UI_Image* supportW = nullptr;
	UI_Image* supportE = nullptr;
	UI_Image* supportR = nullptr;

	bool supportSkillSwitch = false;

	int supportQCount = 0;
	int supportWCount = 0;
	int supportECount = 0;
	int supportRCount = 0;
public:
	void SetHpPotionCount(int itemCount){ hpPotionCount = itemCount; }
	void SetMpPotionCount(int itemCount){ mpPotionCount = itemCount; }
	void SetAttackBuffCount(int itemCount){ attacBuffCount = itemCount; }
	void SetArmorBuffCount(int itemCount){ armorBuffCount = itemCount; }
	void SetRevengeCount(int itemCount){ revengeCount = itemCount; }
	void SetInvincibleCount(int itemCount){ invincibleCount = itemCount; }

	void SetHpMax(float _hpMax){ hpMax = _hpMax; }
	void SetHp(float _hp){ hp = _hp; }
	void SetMpMax(float _mpMax){ mpMax = _mpMax; }
	void SetMp(float _mp){ mp = _mp; }

	void SetIsBlink(bool _isBlink){ isBlink = _isBlink; }
	void SetIsRing(bool _isRing){ isRing = _isRing; }
	void SetIsBoots(bool _isBoots){ isBoots = _isBoots; }

	void SetIsNova(bool _isNova){ isNova = _isNova; }
	void SetIsJaina(bool _isJaina){ isJaina = _isJaina; }
	void SetIsJohanna(bool _isJohanna){ isJohanna = _isJohanna; }

	CalcScore* GetCalcScore(){ return calcScore; }

	void SetMinute(int _minute){ minute = _minute; }
	void SetSecond(int _second){ second = _second; }

	void SetSupportSkillSwitch(bool _switch){ supportSkillSwitch = _switch; }

	void SetSupportQCount(int count){ supportQCount = count; }
	void SetSupportWCount(int count){ supportWCount = count; }
	void SetSupportECount(int count){ supportECount = count; }
	void SetSupportRCount(int count){ supportRCount = count; }
};



