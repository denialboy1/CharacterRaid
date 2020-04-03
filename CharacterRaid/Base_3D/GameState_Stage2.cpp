#include "stdafx.h"
#include "GameState_Stage2.h"


GameState_Stage2::GameState_Stage2()
{
}


GameState_Stage2::~GameState_Stage2()
{
}


void GameState_Stage2::Initialize(){

	if (stage == nullptr)
	{
		stage = new Stage2;
		stage->Initialize(100, 100, "Stage_2.png");
	}
	if (Johanna == nullptr){
		Johanna = new johanna;
		Johanna->Initialize();
		Johanna->SetGrid(stage->GetGrid());

		jaina = new Jaina;
		jaina->Initialize();
		jaina->SetGrid(stage->GetGrid());

		_player = jaina;
	}
	if (azmodan == nullptr)
	{
		azmodan = new Azmodan;
		azmodan->Initialize();
		azmodan->SetPosition(D3DXVECTOR3(10, 0, 0));
	}

	if (ui_interface == nullptr){
		ui_interface = new UI_Interface;
		ui_interface->SetJainaAddress((Jaina*)_player);
		ui_interface->Initialize();
	}

	if (effect == nullptr){
		effect = new BossDeathEffect;
		effect->Initialize(azmodan->GetPosition()+D3DXVECTOR3(0,6,0), D3DXVECTOR3(6, 6, 6));
	}
	startTimer = timeGetTime();
	GameManager::Get().GetCamera()->SetLookTarget(Johanna->GetPositionAdress());

	soundManager::Get().addSound("stage2bgm", "Data/Sound/스테이지2.ogg", true, true);
	soundManager::Get().play("stage2bgm", 0.5f);
}
void GameState_Stage2::Destroy(){
	if (_player)
	{
		SAFE_DELETE(_player);
	}

	if (stage)
	{
		SAFE_DELETE(stage);
	}
	if (azmodan)
	{
		SAFE_DELETE(azmodan);
		
	}
	if (billboard)
	{
		SAFE_DELETE(billboard);
	}
	if (ui_interface){
		SAFE_DELETE(ui_interface);
	}
	if (effect){
		SAFE_DELETE(effect);
	}

	soundManager::Get().stop("stage2bgm");
}
void GameState_Stage2::Reset(){

}
void GameState_Stage2::Update(){
	if (_player)
	{
		_player->Update();
	}
	if (stage)
	{
		stage->Update();
	}
	if (ui_interface){
		ui_interface->Update();
		switch (iniDataManager::Get().loadDataInterger("player", "Player", "Character")){
		case 0:
			ui_interface->SetIsNova(true);
			ui_interface->SetIsJaina(false);
			ui_interface->SetIsJohanna(false);
			break;
		case 1:
			ui_interface->SetIsNova(false);
			ui_interface->SetIsJaina(false);
			ui_interface->SetIsJohanna(true);
			break;
		case 2:
			ui_interface->SetIsNova(false);
			ui_interface->SetIsJaina(true);
			ui_interface->SetIsJohanna(false);
			break;
		}

		ui_interface->SetHpPotionCount(_player->GetItem()->hpPotion);
		ui_interface->SetMpPotionCount(_player->GetItem()->mpPotion);
		ui_interface->SetAttackBuffCount(_player->GetItem()->attackBuff);
		ui_interface->SetArmorBuffCount(_player->GetItem()->armorBuff);
		ui_interface->SetRevengeCount(_player->GetItem()->revenge);
		ui_interface->SetInvincibleCount(_player->GetItem()->invincible);
		ui_interface->SetHpMax(_player->GetMaxHp());
		ui_interface->SetHp(_player->GetHp());
		ui_interface->SetMpMax(_player->GetMaxMp());
		ui_interface->SetMp(_player->GetMp());
		switch (_player->GetArtefact()){
		case 0:
			ui_interface->SetIsBlink(false);
			ui_interface->SetIsRing(false);
			ui_interface->SetIsBoots(false);
			break;
		case 1:
			ui_interface->SetIsBlink(true);
			ui_interface->SetIsRing(false);
			ui_interface->SetIsBoots(false);
			break;
		case 2:
			ui_interface->SetIsBlink(false);
			ui_interface->SetIsRing(true);
			ui_interface->SetIsBoots(false);
			break;
		case 3:
			ui_interface->SetIsBlink(false);
			ui_interface->SetIsRing(false);
			ui_interface->SetIsBoots(true);
			break;
		}

		if (state == BOSS){
			float time = (timeGetTime() - startTimer)*0.001f;
			ui_interface->GetCalcScore()->Calculation(time, _player->GetDamageCount());
			int minute = time / 60;
			int second = (int)time % 60;
			ui_interface->SetMinute(minute);
			ui_interface->SetSecond(second);
		}
		else{
			ui_interface->GetCalcScore()->Calculation(0, 0);
		}

	}
	if (azmodan->GetHp() <= 0){
		state = BOSS_AFTER;
		bool isClear = true;
		int changeTimer = 0;
		if (isClear)
		{
			changeTimer++;
			if (changeTimer >= 15)
			{
				//상점
				
			}
		}
	}
	switch (state){
	case IDLE:
		timer = (timeGetTime() - startTimer)*0.001f;
		if (10 < timer){
			state = MINION;
			startTimer = timeGetTime();
		}
		break;
	case MINION:
		
		break;
	case BOSS:
		timer = (timeGetTime() - startTimer)*0.001f;
		if (azmodan&&_player){
			azmodan->Update(timer, _player);
			azmodan->Battle(*_player);
			_player->Battle(*azmodan);
		}
		break;
	case BOSS_AFTER:
		timer = (timeGetTime() - startTimer)*0.001f;
		if (timer > 10){
			
			effect->Update(GameManager::Get().GetCamera()->GetEyePosition());
			CalcScore* calc = new CalcScore;
			calc->Calculation(timeGetTime(), (Johanna->GetMaxHp() - Johanna->GetHp()));
			calc->ScoreSave();
			if (effect->GetIsPlay() != true){

				char str1[128];
				iniDataManager::Get().addData("Player", "Stage", "3");

				iniDataManager::Get().addData("Player", "Character", "3");
				iniDataManager::Get().addData("Player", "Life", "1");
				iniDataManager::Get().addData("Player", "LV", "3");
				iniDataManager::Get().addData("Player", "Exp", "0");
				iniDataManager::Get().addData("Player", "HP", "1500");
				iniDataManager::Get().addData("Player", "MP", "1500");
				iniDataManager::Get().addData("Player", "Attack", "30");
				iniDataManager::Get().addData("Player", "Armor", "10");
				iniDataManager::Get().addData("Player", "Speed", "5");


				_itoa_s(_player->GetMoney(), str1, 10);
				iniDataManager::Get().addData("Item", "Money", str1);
				_itoa_s(_player->GetItem()->hpPotion, str1, 10);
				iniDataManager::Get().addData("Item", "HpPotion", str1);
				_itoa_s(_player->GetItem()->mpPotion, str1, 10);
				iniDataManager::Get().addData("Item", "MpPotion", str1);
				_itoa_s(_player->GetItem()->attackBuff, str1, 10);
				iniDataManager::Get().addData("Item", "PowerHerb", str1);
				_itoa_s(_player->GetItem()->armorBuff, str1, 10);
				iniDataManager::Get().addData("Item", "ArmorPotion", str1);
				_itoa_s(_player->GetItem()->revenge, str1, 10);
				iniDataManager::Get().addData("Item", "StunDagger", str1);
				_itoa_s(_player->GetItem()->invincible, str1, 10);
				iniDataManager::Get().addData("Item", "Invincible", str1);
				_itoa_s(_player->GetItem()->blink, str1, 10);
				iniDataManager::Get().addData("Item", "Neckles", str1);
				_itoa_s(_player->GetItem()->invincibleA, str1, 10);
				iniDataManager::Get().addData("Item", "Ring", str1);
				_itoa_s(_player->GetItem()->speedUp, str1, 10);
				iniDataManager::Get().addData("Item", "boots", str1);

				//노바
				_itoa_s(_player->GetItem()->sniperSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "Sniper", "1");
				_itoa_s(_player->GetItem()->hyperionSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "Hyperion", "0");
				_itoa_s(_player->GetItem()->powerUpSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "PowerUp", "0");
				_itoa_s(_player->GetItem()->nuclearSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "Nuclear", "0");

				//요한나
				_itoa_s(_player->GetItem()->armorSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "ArmorBuff", "0");
				_itoa_s(_player->GetItem()->attackSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "AttackBuff", "0");

				//제이나
				_itoa_s(_player->GetItem()->iceSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "Ice", str1);
				_itoa_s(_player->GetItem()->iceFireSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "IceFire", str1);
				_itoa_s(_player->GetItem()->icePowerSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "MpRegen", str1);
				_itoa_s(_player->GetItem()->iceWorldSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "IceWorld", str1);

				_itoa_s(_player->GetItem()->commonHpSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "SupportHp", str1);
				_itoa_s(_player->GetItem()->commonMpSkillLearn, str1, 10);
				iniDataManager::Get().addData("Item", "SupportMp", str1);

				iniDataManager::Get().iniSave("player");
				GameStateManager::Get().ChangeGameState(STATE_SHOP);

			}
		}
		break;
	}
	GameManager::Get().GetCamera()->Update();
}
void GameState_Stage2::Render(){

	if (_player != nullptr){
		_player->Render();
	}

	if (stage)
	{
		stage->Render();
	}

	switch (state){
	case IDLE:
		break;
	case MINION:
		//몬스터
		//for (auto iter = vPheonix.begin(); iter != vPheonix.end(); iter++){
		//	if (*iter){
		//		(*iter)->Render();
		//	}
		//}
		break;
	case BOSS:
		if (azmodan)
		{
			azmodan->Render();
		}
		break;
	case BOSS_AFTER:
		effect->Render();
		break;
	}
	if (ui_interface){
		ui_interface->Render();
	}
}

HRESULT GameState_Stage2::OnEnterState(){
	Initialize();
	GameManager::GetCamera()->Initialize();
	if (_player){
		GameManager::GetCamera()->Initialize(_player->GetPositionAdress());
	}
	return S_OK;
}
void GameState_Stage2::OnLeaveState(){
	Destroy();
}

LRESULT GameState_Stage2::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;
	if (result == 0 && _player){
		_player->InputProc(hWnd, message, wParam, lParam);
	}
	return result;
}

void GameState_Stage2::WalkRoute(Phoenix& _phoenix, D3DXVECTOR3 _goal, bool _loop){
	ActionSequence* sequence = new ActionSequence;

	ActionMove* move1 = new ActionMove;
	move1->SetStart(_phoenix.GetPosition());
	move1->SetGoal(D3DXVECTOR3(0, 0, 0));
	move1->SetDuration(5);
	move1->SetTarget(&_phoenix);
	move1->SetDelegate(sequence);
	sequence->AddAction(move1);

	ActionMove* move2 = new ActionMove;
	move2->SetStart(D3DXVECTOR3(0, 0, 0));
	move2->SetGoal(_goal);
	move2->SetDuration(5);
	move2->SetTarget(&_phoenix);
	move2->SetDelegate(sequence);
	sequence->AddAction(move2);

	sequence->SetLoop(_loop);
	_phoenix.SetAction(sequence);
	_phoenix.Start();
}

//void GameState_Stage3::WalkHome(Phoenix& _phoenix, D3DXVECTOR3 _goal){
//	ActionSequence* sequence = new ActionSequence;
//
//	ActionMove* move2 = new ActionMove;
//	move2->SetStart(_phoenix.GetPosition());
//	move2->SetGoal(_goal);
//	move2->SetDuration(5);
//	move2->SetTarget(&_phoenix);
//	move2->SetDelegate(sequence);
//	sequence->AddAction(move2);
//
//	sequence->SetLoop(false);
//	_phoenix.SetAction(sequence);
//	_phoenix.Start();
//}