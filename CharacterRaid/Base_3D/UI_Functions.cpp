#include "stdafx.h"
#include <string>
#include "UI_Functions.h"
#include "UI_Button.h"


UI_Functions::UI_Functions()
{
}


UI_Functions::~UI_Functions()
{
}


void UI_Functions::ButtonClick(UI_Base* sender)
{
	UI_Text* textUI = (UI_Text*)UI_Manager::Get().GetRoot()->GetChildByID(0);

	int senderID = sender->GetID();
	textUI->SetText(std::to_string(senderID) + " 번 버튼을 눌렀습니다.");
}

void UI_Functions::ButtonQuestOK(UI_Base* sender)
{
	UI_Quest* root = (UI_Quest*)UI_Manager::Get().GetRoot();
	
	QUEST_STEP step = root->GetQuestStep();
	if ( root->GetOpenByStartNode() )
	{		
		if ( step == QUEST_NOT_ACCEPT )
		{
			root->SetQuestStep(QUEST_ACCEPT);
		}
	}
	else
	{
		if ( step == QUEST_ACCEPT )
		{
			root->SetQuestStep(QUEST_DONE);
		}
	}

	root->SetShow(false);
	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);

	//퀘스트 목록에 추가
}



void UI_Functions::ButtonQuestCancel(UI_Base* sender)
{
	UI_Quest* root = (UI_Quest*)UI_Manager::Get().GetRoot();
	if ( root->GetOpenByStartNode() )
	{		
		QUEST_STEP step = root->GetQuestStep();
		if ( step == QUEST_ACCEPT )
		{
			root->SetQuestStep(QUEST_NOT_ACCEPT);
		}
	}

	root->SetShow(false);
	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);	
}
void UI_Functions::ButtonSelectStep(UI_Base* sender,int _selectStep)
{
	Select_UI* root = (Select_UI*)UI_Manager::Get().GetRoot();

	root->SetSelectStep((SELECT_STEP)_selectStep);


	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);

}

void UI_Functions::ButtonStep(UI_Base* sender, int _selectStep)
{
	Select_UI* root = (Select_UI*)UI_Manager::Get().GetRoot();

	root->SetSelectStep((SELECT_STEP)_selectStep);

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
	GameStateManager::Get().ChangeGameState(STATE_SELECT);
}
void UI_Functions::ButtonShopStep(UI_Base* sender, int _shopStep){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	root->SetShopStep((SHOP_STEP)_shopStep);

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}

void UI_Functions::ButtonBuy(UI_Base* sender, Item* item){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	int total = item->hpPotion * item->hpMoney + item->mpPotion * item->mpMoney + item->attackBuff * item->attackBuffMoney + item->armorBuff * item->armorBuffMoney + item->revenge * item->revengeMoney + item->invincible * item->invincibleMoney;
	//요한나 스킬
	if (item->armorSkillUp) {
		if (!root->GetItem()->armorSkillLearn){
			total += item->armorSkillMoney;
		}
	}
	if (item->attackSkillUp) {
		if (!root->GetItem()->attackSkillLearn){
			total += item->attackSkillMoney;
		}
	}

	//노바 스킬
	if (item->sniperSkill) {
		if (!root->GetItem()->sniperSkillLearn){
			total += item->sniperSkillMoney;
		}
	}
	if (item->hyperionSkill) {
		if (!root->GetItem()->hyperionSkillLearn){
			total += item->hyperionSkillMoney;
		}
	}
	if (item->powerUpSkill) {
		if (!root->GetItem()->powerUpSkillLearn){
			total += item->powerUpSkillMoney;
		}
	}
	if (item->nuclearSkill) {
		if (!root->GetItem()->nuclearSkillLearn){
			total += item->nuclearSkillMoney;
		}
	}

	//제이나 스킬
	if (item->iceSkill) {
		if (!root->GetItem()->iceSkillLearn){
			total += item->iceSkillMoney;
		}
	}
	if (item->iceFireSkill) {
		if (!root->GetItem()->iceFireSkillLearn){
			total += item->iceFireSkillMoney;
		}
	}
	if (item->icePowerSkill) {
		if (!root->GetItem()->icePowerSkillLearn){
			total += item->icePowerSkillMoney;
		}
	}
	if (item->iceWorldSkill) {
		if (!root->GetItem()->iceWorldSkillLearn){
			total += item->iceWorldSkillMoney;
		}
	}

	//일반스킬
	if (item->commonHpSkill) {
		if (!root->GetItem()->commonHpSkillLearn){
			total += item->commonHpSkillMoney;
		}
	}
	if (item->commonMpSkill) {
		if (!root->GetItem()->commonMpSkillLearn){
			total += item->commonMpSkillMoney;
		}
	}

	total += item->atk * item->atkMoney + item->def * item->defMoney + item->move * item->moveMoney;

	//라이프
	total += item->life * 10000;

	if (root->GetMoney() - total >= 0){

		root->SetMoney(root->GetMoney() - total);

		root->GetItem()->SetArmorBuff(root->GetItem()->GetArmorBuff() + item->GetArmorBuff());
		root->GetItem()->SetAttackBuff(root->GetItem()->GetAttackBuff() + item->GetAttackBuff());
		root->GetItem()->SetHpPotion(root->GetItem()->GetHpPotion() + item->GetHpPotion());
		root->GetItem()->SetMpPotion(root->GetItem()->GetMpPotion() + item->GetMpPotion());
		root->GetItem()->SetInvincible(root->GetItem()->GetInvincible() + item->GetInvincible());
		root->GetItem()->SetRevenge(root->GetItem()->GetRevenge() + item->GetRevenge());
		root->GetItem()->artifact = item->artifact;

		item->armorBuff = 0;
		item->attackBuff = 0;
		item->hpPotion = 0;
		item->mpPotion = 0;
		item->revenge = 0;
		item->invincible = 0;

		root->SetShopStep(SHOP_NORMAL);


		if (item->armorSkillUp){
			root->GetItem()->armorSkillLearn = true;
			item->armorSkillLearn = true;
		}
		if (item->attackSkillUp){
			root->GetItem()->attackSkillLearn = true;
			item->attackSkillLearn = true;
		}

		if (item->sniperSkill) {
			root->GetItem()->sniperSkillLearn = true;
			item->sniperSkillLearn = true;
		}
		if (item->hyperionSkill) {
			root->GetItem()->hyperionSkillLearn = true;
			item->hyperionSkillLearn = true;
		}
		if (item->powerUpSkill){
			root->GetItem()->powerUpSkillLearn = true;
			item->powerUpSkillLearn = true;
		}
		if (item->nuclearSkill) {
			root->GetItem()->nuclearSkillLearn = true;
			item->nuclearSkillLearn = true;
		}

		if (item->iceSkill) {
			root->GetItem()->iceSkillLearn = true;
			item->iceSkillLearn = true;
		}
		if (item->iceFireSkill) {
			root->GetItem()->iceFireSkillLearn = true;
			item->iceFireSkillLearn = true;
		}
		if (item->icePowerSkill){
			root->GetItem()->icePowerSkillLearn = true;
			item->icePowerSkillLearn = true;
		}
		if (item->iceWorldSkill) {
			root->GetItem()->iceWorldSkillLearn = true;
			item->iceWorldSkillLearn = true;
		}


		//일반스킬
		if (item->commonHpSkill){
			root->GetItem()->commonHpSkillLearn = true;
			item->commonHpSkillLearn = true;
		}
		if (item->commonMpSkill) {
			root->GetItem()->commonMpSkillLearn = true;
			item->commonMpSkillLearn = true;
		}

		//스텟
		root->GetItem()->atk = root->GetItem()->atk + item->atk;
		root->GetItem()->def = root->GetItem()->def + item->def;
		root->GetItem()->move = root->GetItem()->move + item->move;

		item->atk = 0;
		item->def = 0;
		item->move = 0;

		//라이프
		root->GetItem()->life += item->life;

		item->life = 0;
	}
	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}

void UI_Functions::ButtonCancel(UI_Base* sender, Item* item){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	item->armorBuff = 0;
	item->attackBuff = 0;
	item->hpPotion = 0;
	item->mpPotion = 0;
	item->revenge = 0;
	item->invincible = 0;

	item->blink = false;
	item->invincibleA = false;
	item->speedUp = false;

	item->artifact = NONE;

	//요한나
	item->armorSkillUp = false;
	item->attackSkillUp = false;

	item->armorSkillLearn = false;
	item->attackSkillLearn = false;

	//노바
	item->sniperSkill = false;
	item->hyperionSkill = false;
	item->powerUpSkill = false;
	item->nuclearSkill = false;

	
	//제이나
	item->iceSkill = false;
	item->iceFireSkill = false;
	item->icePowerSkill = false;
	item->iceWorldSkill = false;

	//일반스킬
	item->commonHpSkill = false;
	item->commonMpSkill = false;

	//스텟
	item->atk = 0;
	item->def = 0;
	item->move = 0;

	//라이프
	item->life = 0;

	root->SetShopStep(SHOP_NORMAL);

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}

void UI_Functions::ButtonUp(UI_Base* sender, int* item){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	(*item)++;
	

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}

void UI_Functions::ButtonDown(UI_Base* sender, int* item){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	(*item)--;
	if ((*item) <= 0) (*item) = 0;

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}

void UI_Functions::ButtonCheck(UI_Base* sender, Item* item,int _artifact){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	item->artifact = (EQUIP_ARTIFACT)_artifact;

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}

void UI_Functions::ButtonSkillCheck(UI_Base* sender, bool* skill){
	Shop* root = (Shop*)UI_Manager::Get().GetRoot();

	if ((*skill)){
		(*skill) = false;
	}
	else{
		(*skill) = true;
	}

	UI_Button* button = (UI_Button*)sender;
	button->SetState(STATE_NORMAL);
}