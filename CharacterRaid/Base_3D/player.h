#pragma once
#include "unit.h"
#include "Item.h"
#define BASE_ANGLE 3.14
class player :
	public unit
{
	enum LVBAR{
		LV2 = 100,
		LV3 = 200,
		LV4 = 300,
		LV5 = 400,
		LV6 = 500,
		LV7 = 600,
		LV8 = 700,
		LV9 = 800,
		LV10 = 900,
	};

	
protected:
	enum ARTEFACT{ EMPTY, BLINK, INVINCIBLE, FASTMOVE,ARTEFACT_COUNT };
	enum BUFF{NOBUFF,ATTACK_UP,ARMOR_UP,FAST,INVINCIBLE_MODE,BUFF_COUNT};

	//ġƮŰ
	bool isCheatkeyOn = false;
	
	int lv=1;
	int exp = 0;
	int skillPoint = 1;
	int statePoint = 0;

	int attackPoint;
	int armorPoint;
	int speedPoint;

	int life = 2; //�÷��̾� ���
	int money = 1000; //��

	//������ ���� ����(����Ű 1~6, ����Ű d�� �ڽ��� ������ ��Ƽ��Ʈ)
	int hpPotion = 0;
	int mpPotion = 0;
	int attackBuffItem = 0;
	int armorBuffItem = 0;
	int eraseMisiileItem = 0;
	int attentionItem = 0;

	ARTEFACT artefact = EMPTY;
	BUFF buff = NOBUFF;
	Item* item = nullptr;

	int damageCount = 0;	//�ǰ�ī��Ʈ

public:
	player();
	~player();

	virtual void Initialize() override;
	virtual void Detroy();
	virtual void Update() override;
	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	virtual void Battle(unit& enemy);

	void LvUp();
	void GameOver();

	inline Item* GetItem(){ return item; }
	bool isSkillSwitch = false;
	bool GetIsSkillSwitch(){ return isSkillSwitch; }
	ARTEFACT GetArtefact(){ return artefact; }
	int GetDamageCount(){ return damageCount; }
	int GetLife(){ return life; }
	void SetLife(int _life){ life = _life; }


	int supportQCount = 1;
	int supportWCount = 1;
	int supportECount = 1;
	int supportRCount = 1;

	int GetSupportQCount(){ return supportQCount; }
	int GetSupportWCount(){ return supportWCount; }
	int GetSupportECount(){ return supportECount; }
	int GetSupportRCount(){ return supportRCount; }

	int GetMoney(){ return money; }

	void DataSave();
};

