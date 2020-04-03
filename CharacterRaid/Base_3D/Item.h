#pragma once

enum EQUIP_ARTIFACT {BLINK,INVINCIBLE,SPEEDUP,NONE};
class Item
{
public:
	Item();
	~Item();

	bool BuyHp();
	bool BuyMp();
	bool BuyAttackBuff();
	bool BuyArmorBuff();
	bool BuyRevenge();
	bool BuyInvincible();

	bool UseHpPotion();
	bool UseMpPotion();
	bool UseAttackBuff();
	bool UseArmorBuff();
	bool UseRevenge();
	bool UseInvincible();
public:
	int hpPotion = 0;
	int mpPotion = 0;
	int attackBuff = 0;
	int armorBuff = 0;
	int revenge = 0;
	int invincible = 0;

	int hpMoney = 1000;
	int mpMoney = 1200;
	int attackBuffMoney = 2000;
	int armorBuffMoney = 1500;
	int revengeMoney = 2500;
	int invincibleMoney = 3000;

	bool blink = false;
	bool invincibleA = false;
	bool speedUp = false;

	EQUIP_ARTIFACT artifact = NONE;

	//요한나
	bool armorSkillUp = false;
	bool attackSkillUp = false;

	bool armorSkillLearn = false;
	bool attackSkillLearn = false;

	int armorSkillMoney = 2500;
	int attackSkillMoney = 2500;

	//노바 스킬
	bool sniperSkill = false;
	bool hyperionSkill = false;
	bool powerUpSkill = false;
	bool nuclearSkill = false;

	bool sniperSkillLearn = false;
	bool hyperionSkillLearn = false;
	bool powerUpSkillLearn = false;
	bool nuclearSkillLearn = false;

	int sniperSkillMoney = 2500;
	int hyperionSkillMoney = 3000;
	int powerUpSkillMoney = 2000;
	int nuclearSkillMoney = 4000;

	//제이나 스킬
	bool iceSkill = false;
	bool iceFireSkill = false;
	bool icePowerSkill = false;
	bool iceWorldSkill = false;

	bool iceSkillLearn = false;
	bool iceFireSkillLearn = false;
	bool icePowerSkillLearn = false;
	bool iceWorldSkillLearn = false;

	int iceSkillMoney = 2000;
	int iceFireSkillMoney = 2000;
	int icePowerSkillMoney = 2000;
	int iceWorldSkillMoney = 4000;

	//일반스킬
	bool commonHpSkill = false;
	bool commonMpSkill = false;

	bool commonHpSkillLearn = false;
	bool commonMpSkillLearn = false;

	int commonHpSkillMoney = 1000;
	int commonMpSkillMoney = 1000;


	//스텟
	int atk = 0;
	int def = 0;
	int move = 0;

	int atkMoney = 100;
	int defMoney = 100;
	int moveMoney = 100;

	//라이프
	int life = 0;

public:
	void SetHpPotion(int _hpPotion){ hpPotion = _hpPotion; }
	void SetMpPotion(int _mpPotion){ mpPotion = _mpPotion; }
	void SetAttackBuff(int _attackBuff){ attackBuff = _attackBuff; }
	void SetArmorBuff(int _armorBuff){ armorBuff = _armorBuff; }
	void SetRevenge(int _revenge){ revenge = _revenge; }
	void SetInvincible(int _invincible){ invincible = _invincible; }

	int GetHpPotion(){return hpPotion; }
	int GetMpPotion(){return mpPotion; }
	int GetAttackBuff(){return  attackBuff; }
	int GetArmorBuff(){ return armorBuff; }
	int GetRevenge(){ return revenge; }
	int GetInvincible(){ return invincible; }

};

