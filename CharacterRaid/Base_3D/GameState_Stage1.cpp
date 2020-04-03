#include "stdafx.h"
#include "GameState_Stage1.h"


GameState_Stage1::GameState_Stage1()
{
}


GameState_Stage1::~GameState_Stage1()
{
}




void GameState_Stage1::Initialize()
{

	IsHammerBossMove = false;
	HammerBossMove = 2950;

	if (grid == nullptr)
	{
		grid = new Grid;
		grid->Initialize(100, 50);
		grid->SetShowGround(true);
	}

	if (stage1 == nullptr)
	{
		stage1 = new Stage1;
		stage1->Initialize(100, 50, "stage1-3.jpg");
	}

	if (nova == nullptr)
	{
		nova = new Nova;
		nova->Initialize();
		nova->SetGrid(grid);

		jaina = new Jaina;
		jaina->Initialize();
		jaina->SetGrid(grid);

		_player = jaina;
	}
	if (hammerBoss == nullptr)
	{
		hammerBoss = new HammerBoss;
		hammerBoss->Initialize();
	}
	//if (_bigMissile == nullptr)
	//{
	//	_bigMissile = new bigMissile;
	//	_bigMissile->Initialize();
	//}
	if (UI == nullptr)
	{
		UI = new UI_Interface;
		UI->SetJainaAddress((Jaina*)_player);
		UI->Initialize();
	}

	

	

	///////////////왼쪽 바이킹///////////////////////

	if (vikingEnemy1 == nullptr)
	{
		vikingEnemy1 = new VikingEnemy;
		vikingEnemy1->Initialize(D3DXVECTOR3(2, 2, 2));
		vikingEnemy1->SetScale(D3DXVECTOR3(3, 3, 3));

		ActionSequence* sequence1 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(30, 0, -27));
		move1->SetGoal(D3DXVECTOR3(30, 0, 10));
		vikingEnemy1->SetGoal(D3DXVECTOR3(30, 0, 10));
		move1->SetDuration(5.0f);
		move1->SetTarget(vikingEnemy1);
		move1->SetDelegate(sequence1);
		sequence1->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(30, 0, 10));
		move2->SetGoal(D3DXVECTOR3(15, 0, 10));
		vikingEnemy1->SetGoal(D3DXVECTOR3(15, 0, 10));
		move2->SetDuration(2.0f);
		move2->SetTarget(vikingEnemy1);
		move2->SetDelegate(sequence1);
		sequence1->AddAction(move2);

		vikingEnemy1->SetAction(sequence1);
		vikingEnemy1->GetAction()->Start();
		vikingEnemyList.push_back(vikingEnemy1);
	}
	if (vikingEnemy2 == nullptr)
	{
		vikingEnemy2 = new VikingEnemy;
		vikingEnemy2->Initialize(D3DXVECTOR3(2, 2, 2));
		vikingEnemy2->SetScale(D3DXVECTOR3(3, 3, 3));

		ActionSequence* sequence2 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(30, 0, -27));
		move1->SetGoal(D3DXVECTOR3(30, 0, 0));
		vikingEnemy2->SetGoal(D3DXVECTOR3(30, 0, 0));
		move1->SetDuration(4.5f);
		move1->SetTarget(vikingEnemy2);
		move1->SetDelegate(sequence2);
		sequence2->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(30, 0, 0));
		move2->SetGoal(D3DXVECTOR3(15, 0, 0));
		vikingEnemy2->SetGoal(D3DXVECTOR3(15, 0, 0));
		move2->SetDuration(2.0f);
		move2->SetTarget(vikingEnemy2);
		move2->SetDelegate(sequence2);
		sequence2->AddAction(move2);

		vikingEnemy2->SetAction(sequence2);
		vikingEnemy2->GetAction()->Start();
		vikingEnemyList.push_back(vikingEnemy2);
	}
	if (vikingEnemy3 == nullptr)
	{
		vikingEnemy3 = new VikingEnemy;
		vikingEnemy3->Initialize(D3DXVECTOR3(2, 2, 2));
		vikingEnemy3->SetScale(D3DXVECTOR3(3, 3, 3));

		ActionSequence* sequence3 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(30, 0, -27));
		move1->SetGoal(D3DXVECTOR3(30, 0, -10));
		vikingEnemy3->SetGoal(D3DXVECTOR3(30, 0, -10));
		move1->SetDuration(4.0f);
		move1->SetTarget(vikingEnemy3);
		move1->SetDelegate(sequence3);
		sequence3->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(30, 0, -10));
		move2->SetGoal(D3DXVECTOR3(15, 0, -10));
		vikingEnemy3->SetGoal(D3DXVECTOR3(15, 0, -10));
		move2->SetDuration(2.0f);
		move2->SetTarget(vikingEnemy3);
		move2->SetDelegate(sequence3);
		sequence3->AddAction(move2);

		vikingEnemy3->SetAction(sequence3);
		vikingEnemy3->GetAction()->Start();
		vikingEnemyList.push_back(vikingEnemy3);
	}
	///////////////////////////////////////////////////



	///////////////오른쪽 바이킹/////////////////////

	if (vikingEnemy4 == nullptr)
	{
		vikingEnemy4 = new VikingEnemy;
		vikingEnemy4->Initialize(D3DXVECTOR3(2, 2, 2));
		vikingEnemy4->SetScale(D3DXVECTOR3(3, 3, 3));

		ActionSequence* sequence4 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(-30, 0, -27));
		move1->SetGoal(D3DXVECTOR3(-30, 0, -10));
		vikingEnemy4->SetGoal(D3DXVECTOR3(-30, 0, -10));
		move1->SetDuration(4.0f);
		move1->SetTarget(vikingEnemy4);
		move1->SetDelegate(sequence4);
		sequence4->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(-30, 0, -10));
		move2->SetGoal(D3DXVECTOR3(-15, 0, -10));
		vikingEnemy4->SetGoal(D3DXVECTOR3(-15, 0, -10));
		move2->SetDuration(2.0f);
		move2->SetTarget(vikingEnemy4);
		move2->SetDelegate(sequence4);
		sequence4->AddAction(move2);

		vikingEnemy4->SetAction(sequence4);
		vikingEnemy4->GetAction()->Start();
		vikingEnemyList.push_back(vikingEnemy4);
	}
	if (vikingEnemy5 == nullptr)
	{
		vikingEnemy5 = new VikingEnemy;
		vikingEnemy5->Initialize(D3DXVECTOR3(2, 2, 2));
		vikingEnemy5->SetScale(D3DXVECTOR3(3, 3, 3));

		ActionSequence* sequence5 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(-30, 0, -27));
		move1->SetGoal(D3DXVECTOR3(-30, 0, 0));
		vikingEnemy5->SetGoal(D3DXVECTOR3(-30, 0, 0));
		move1->SetDuration(4.5f);
		move1->SetTarget(vikingEnemy5);
		move1->SetDelegate(sequence5);
		sequence5->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(-30, 0, 0));
		move2->SetGoal(D3DXVECTOR3(-15, 0, 0));
		vikingEnemy5->SetGoal(D3DXVECTOR3(-15, 0, 0));
		move2->SetDuration(2.0f);
		move2->SetTarget(vikingEnemy5);
		move2->SetDelegate(sequence5);
		sequence5->AddAction(move2);

		vikingEnemy5->SetAction(sequence5);
		vikingEnemy5->GetAction()->Start();
		vikingEnemyList.push_back(vikingEnemy5);
	}
	if (vikingEnemy6 == nullptr)
	{
		vikingEnemy6 = new VikingEnemy;
		vikingEnemy6->Initialize(D3DXVECTOR3(2, 2, 2));
		vikingEnemy6->SetScale(D3DXVECTOR3(3, 3, 3));

		ActionSequence* sequence6 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(-30, 0, -27));
		move1->SetGoal(D3DXVECTOR3(-30, 0, 10));
		vikingEnemy6->SetGoal(D3DXVECTOR3(-30, 0, 10));
		move1->SetDuration(5.0f);
		move1->SetTarget(vikingEnemy6);
		move1->SetDelegate(sequence6);
		sequence6->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(-30, 0, 10));
		move2->SetGoal(D3DXVECTOR3(-15, 0, 10));
		vikingEnemy6->SetGoal(D3DXVECTOR3(-15, 0, 10));
		move2->SetDuration(2.0f);
		move2->SetTarget(vikingEnemy6);
		move2->SetDelegate(sequence6);
		sequence6->AddAction(move2);

		vikingEnemy6->SetAction(sequence6);
		vikingEnemy6->GetAction()->Start();
		vikingEnemyList.push_back(vikingEnemy6);
	}
	///////////////////////////////////////////////////




	//////////////////////해머상사무브/////////////////////////
	//if (IsHammerBossMove == true)
	//{
	if (hammerBoss)
	{
		ActionSequence* sequence7 = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(0, 0, 0));
		move1->SetGoal(D3DXVECTOR3(0, 0, 20));
		hammerBoss->SetGoal(D3DXVECTOR3(0, 0, 20));
		move1->SetDuration(0.8f);
		move1->SetTarget(hammerBoss);
		move1->SetDelegate(sequence7);
		sequence7->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(0, 0, 20));
		move2->SetGoal(D3DXVECTOR3(0, 0, -15));
		hammerBoss->SetGoal(D3DXVECTOR3(0, 0, -15));
		move2->SetDuration(0.8f);
		move2->SetTarget(hammerBoss);
		move2->SetDelegate(sequence7);
		sequence7->AddAction(move2);

		ActionMove* move3 = new ActionMove;
		move3->SetStart(D3DXVECTOR3(0, 0, -15));
		move3->SetGoal(D3DXVECTOR3(-35, 0, 0));
		hammerBoss->SetGoal(D3DXVECTOR3(-35, 0, 0));
		move3->SetDuration(0.8f);
		move3->SetTarget(hammerBoss);
		move3->SetDelegate(sequence7);
		sequence7->AddAction(move3);

		ActionMove* move4 = new ActionMove;
		move4->SetStart(D3DXVECTOR3(-35, 0, 0));
		move4->SetGoal(D3DXVECTOR3(35, 0, -10));
		hammerBoss->SetGoal(D3DXVECTOR3(35, 0, -10));
		move4->SetDuration(0.8f);
		move4->SetTarget(hammerBoss);
		move4->SetDelegate(sequence7);
		sequence7->AddAction(move4);

		ActionMove* move5 = new ActionMove;
		move5->SetStart(D3DXVECTOR3(35, 0, -10));
		move5->SetGoal(D3DXVECTOR3(-35, 0, 15));
		hammerBoss->SetGoal(D3DXVECTOR3(-35, 0, 15));
		move5->SetDuration(0.8f);
		move5->SetTarget(hammerBoss);
		move5->SetDelegate(sequence7);
		sequence7->AddAction(move5);

		ActionMove* move6 = new ActionMove;
		move6->SetStart(D3DXVECTOR3(-35, 0, 15));
		move6->SetGoal(D3DXVECTOR3(35, 0, 15));
		hammerBoss->SetGoal(D3DXVECTOR3(35, 0, 15));
		move6->SetDuration(0.8f);
		move6->SetTarget(hammerBoss);
		move6->SetDelegate(sequence7);
		sequence7->AddAction(move6);

		ActionMove* move7 = new ActionMove;
		move7->SetStart(D3DXVECTOR3(35, 0, 15));
		move7->SetGoal(D3DXVECTOR3(0, 0, -15));
		hammerBoss->SetGoal(D3DXVECTOR3(0, 0, -15));
		move7->SetDuration(0.8f);
		move7->SetTarget(hammerBoss);
		move7->SetDelegate(sequence7);
		sequence7->AddAction(move7);

		ActionMove* move8 = new ActionMove;
		move8->SetStart(D3DXVECTOR3(0, 0, -15));
		move8->SetGoal(D3DXVECTOR3(-20, 0, 10));
		hammerBoss->SetGoal(D3DXVECTOR3(-20, 0, 10));
		move8->SetDuration(0.8f);
		move8->SetTarget(hammerBoss);
		move8->SetDelegate(sequence7);
		sequence7->AddAction(move8);

		ActionMove* move9 = new ActionMove;
		move9->SetStart(D3DXVECTOR3(-20, 0, 10));
		move9->SetGoal(D3DXVECTOR3(-20, 0, -10));
		hammerBoss->SetGoal(D3DXVECTOR3(-20, 0, -10));
		move9->SetDuration(0.8f);
		move9->SetTarget(hammerBoss);
		move9->SetDelegate(sequence7);
		sequence7->AddAction(move9);

		ActionMove* move10 = new ActionMove;
		move10->SetStart(D3DXVECTOR3(-20, 0, -10));
		move10->SetGoal(D3DXVECTOR3(20, 0, 10));
		hammerBoss->SetGoal(D3DXVECTOR3(20, 0, 10));
		move10->SetDuration(0.8f);
		move10->SetTarget(hammerBoss);
		move10->SetDelegate(sequence7);
		sequence7->AddAction(move10);

		ActionMove* move11 = new ActionMove;
		move11->SetStart(D3DXVECTOR3(20, 0, 10));
		move11->SetGoal(D3DXVECTOR3(20, 0, -10));
		hammerBoss->SetGoal(D3DXVECTOR3(20, 0, -10));
		move11->SetDuration(0.8f);
		move11->SetTarget(hammerBoss);
		move11->SetDelegate(sequence7);
		sequence7->AddAction(move11);

		ActionMove* move12 = new ActionMove;
		move12->SetStart(D3DXVECTOR3(20, 0, -10));
		move12->SetGoal(D3DXVECTOR3(0, 0, 0));
		hammerBoss->SetGoal(D3DXVECTOR3(0, 0, 0));
		move12->SetDuration(0.8f);
		move12->SetTarget(hammerBoss);
		move12->SetDelegate(sequence7);
		sequence7->AddAction(move12);
		sequence7->SetLoop(true);
		hammerBoss->SetAction(sequence7);
		hammerBoss->GetAction()->Start();
	}
	
	//}
	startTimer = timeGetTime();

	///////////////////////////////////////////////////

	
	soundManager::Get().addSound("stage1bgm", "Data/Sound/스테이지1.ogg", true, true);
	soundManager::Get().play("stage1bgm", 0.5f);
	GameManager::Get().GetCamera()->SetLookTarget(_player->GetPositionAdress());
	//GameManager::Get().SetCameraTarget(nova->GetPositionAdress());
}
void GameState_Stage1::Destroy()
{

	if (grid){
		SAFE_DELETE(grid);
	}

	if (stage1){
		SAFE_DELETE(stage1);
	}
	for (auto iter = vikingEnemyList.begin(); iter != vikingEnemyList.end(); iter++)
	{
		SAFE_DELETE((*iter));
	}
	if (hammerBoss)
	{
		SAFE_DELETE(hammerBoss);
	}
	//if (_bigMissile)
	//{
	//	SAFE_DELETE(_bigMissile);
	//}
	if (UI)
	{
		SAFE_DELETE(UI);
	}


	if (_player)
	{
		SAFE_DELETE(_player);
	}
	soundManager::Get().stop("stage1bgm");
}
void GameState_Stage1::Reset()
{

}
void GameState_Stage1::Update()
{

	if (_player != nullptr)
	{
		_player->Update();
	}

	if (stage1)
	{
		stage1->Update();
	}

	for (auto iter = vikingEnemyList.begin(); iter != vikingEnemyList.end(); iter++)
	{

		if ((*iter)->GetAction() != nullptr)
		{
			(*iter)->Update();
			if (D3DXVec3LengthSq(&((*iter)->GetPosition() - (*iter)->GetGoal())) < 0.001)
			{
				(*iter)->removeAction();
			}
		}
		else
		{

			(*iter)->Update();
			(*iter)->Battle(*_player);

		}
	}

	

	if (hammerBoss != nullptr)
	{
		hammerBoss->Update();
		hammerBoss->Battle(*_player);
		if (_player){
			_player->Battle(*hammerBoss);
		}
	}
	//HammerBossMove++;
	//
	//if (HammerBossMove >= 3000)
	//{
	//	IsHammerBossMove = true;
	//	HammerBossMove = 0;
	//}

	//if (_bigMissile != nullptr)
	//{
	//	_bigMissile->Update();
	//}
	if (UI != nullptr){
		if (UI){
			UI->Update();
			switch (iniDataManager::Get().loadDataInterger("player", "Player", "Character")){
			case 0:
				UI->SetIsNova(true);
				UI->SetIsJaina(false);
				UI->SetIsJohanna(false);
				break;
			case 1:
				UI->SetIsNova(false);
				UI->SetIsJaina(false);
				UI->SetIsJohanna(true);
				break;
			case 2:
				UI->SetIsNova(false);
				UI->SetIsJaina(true);
				UI->SetIsJohanna(false);
				break;
			}

			UI->SetHpPotionCount(_player->GetItem()->hpPotion);
			UI->SetMpPotionCount(_player->GetItem()->mpPotion);
			UI->SetAttackBuffCount(_player->GetItem()->attackBuff);
			UI->SetArmorBuffCount(_player->GetItem()->armorBuff);
			UI->SetRevengeCount(_player->GetItem()->revenge);
			UI->SetInvincibleCount(_player->GetItem()->invincible);
			UI->SetHpMax(_player->GetMaxHp());
			UI->SetHp(_player->GetHp());
			UI->SetMpMax(_player->GetMaxMp());
			UI->SetMp(_player->GetMp());
			UI->SetSupportSkillSwitch(_player->GetIsSkillSwitch());
			UI->SetSupportQCount(_player->GetSupportQCount());
			UI->SetSupportWCount(_player->GetSupportWCount());
			UI->SetSupportECount(_player->GetSupportECount());
			UI->SetSupportRCount(_player->GetSupportRCount());

			switch (_player->GetArtefact()){
			case 0:
				UI->SetIsBlink(false);
				UI->SetIsRing(false);
				UI->SetIsBoots(false);
				break;
			case 1:
				UI->SetIsBlink(true);
				UI->SetIsRing(false);
				UI->SetIsBoots(false);
				break;
			case 2:
				UI->SetIsBlink(false);
				UI->SetIsRing(true);
				UI->SetIsBoots(false);
				break;
			case 3:
				UI->SetIsBlink(false);
				UI->SetIsRing(false);
				UI->SetIsBoots(true);
				break;
			}

			float time = (timeGetTime() - startTimer)*0.001f;
			UI->GetCalcScore()->Calculation(time, _player->GetDamageCount());
			int minute = time / 60;
			int second = (int)time % 60;
			UI->SetMinute(minute);
			UI->SetSecond(second);

		}
	}
	//if (BlNuclear != nullptr)
	//{r
	//	BlNuclear->Update();
	//}
	

	if (hammerBoss->GetHp() < 0){
		_player->DataSave();
		GameStateManager::Get().ChangeGameState(STATE_SHOP);
		//char str1[128];
		//iniDataManager::Get().addData("Player", "Stage", "2");
		//
		//iniDataManager::Get().addData("Player", "Character", "3");
		//iniDataManager::Get().addData("Player", "Life", "1");
		//iniDataManager::Get().addData("Player", "LV", "2");
		//iniDataManager::Get().addData("Player", "Exp", "0");
		//iniDataManager::Get().addData("Player", "HP", "1000");
		//iniDataManager::Get().addData("Player", "MP", "1000");
		//iniDataManager::Get().addData("Player", "Attack", "20");
		//iniDataManager::Get().addData("Player", "Armor", "4");
		//iniDataManager::Get().addData("Player", "Speed", "5");
		//
		//
		//_itoa_s(_player->GetMoney(), str1, 10);
		//iniDataManager::Get().addData("Item", "Money", str1);
		//_itoa_s(_player->GetItem()->hpPotion, str1, 10);
		//iniDataManager::Get().addData("Item", "HpPotion", str1);
		//_itoa_s(_player->GetItem()->mpPotion, str1, 10);
		//iniDataManager::Get().addData("Item", "MpPotion", str1);
		//_itoa_s(_player->GetItem()->attackBuff, str1, 10);
		//iniDataManager::Get().addData("Item", "PowerHerb", str1);
		//_itoa_s(_player->GetItem()->armorBuff, str1, 10);
		//iniDataManager::Get().addData("Item", "ArmorPotion", str1);
		//_itoa_s(_player->GetItem()->revenge, str1, 10);
		//iniDataManager::Get().addData("Item", "StunDagger", str1);
		//_itoa_s(_player->GetItem()->invincible, str1, 10);
		//iniDataManager::Get().addData("Item", "Invincible", str1);
		//_itoa_s(_player->GetItem()->blink, str1, 10);
		//iniDataManager::Get().addData("Item", "Neckles", str1);
		//_itoa_s(_player->GetItem()->invincibleA, str1, 10);
		//iniDataManager::Get().addData("Item", "Ring", str1);
		//_itoa_s(_player->GetItem()->speedUp, str1, 10);
		//iniDataManager::Get().addData("Item", "boots", str1);
		//
		////노바
		//_itoa_s(_player->GetItem()->sniperSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "Sniper", "1");
		//_itoa_s(_player->GetItem()->hyperionSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "Hyperion", "0");
		//_itoa_s(_player->GetItem()->powerUpSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "PowerUp", "0");
		//_itoa_s(_player->GetItem()->nuclearSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "Nuclear", "0");
		//
		////요한나
		//_itoa_s(_player->GetItem()->armorSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "ArmorBuff", "0");
		//_itoa_s(_player->GetItem()->attackSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "AttackBuff", "0");
		//
		////제이나
		//_itoa_s(_player->GetItem()->iceSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "Ice", str1);
		//_itoa_s(_player->GetItem()->iceFireSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "IceFire", str1);
		//_itoa_s(_player->GetItem()->icePowerSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "MpRegen", str1);
		//_itoa_s(_player->GetItem()->iceWorldSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "IceWorld", str1);
		//
		//_itoa_s(_player->GetItem()->commonHpSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "SupportHp", str1);
		//_itoa_s(_player->GetItem()->commonMpSkillLearn, str1, 10);
		//iniDataManager::Get().addData("Item", "SupportMp", str1);
		//
		//iniDataManager::Get().iniSave("player");
		//



	}

	

	

	




}
void GameState_Stage1::Render()
{
	if (grid){
		grid->Render();
	}

	if (stage1)
	{
		stage1->Render();
	}

	if (_player != nullptr)
	{
		_player->Render();
	}

	

	//for (auto iter = vikingEnemyList.begin(); iter != vikingEnemyList.end(); iter++)
	//{
	//	(*iter)->Render();
	//}
	if (hammerBoss != nullptr)
	{
		hammerBoss->Render();
	}
	//if (_bigMissile != nullptr)
	//{
	//	_bigMissile->Render();
	//}
	if (UI != nullptr)
	{
		UI->Render();
	}

}

HRESULT GameState_Stage1::OnEnterState()
{
	Initialize();
	GameManager::GetCamera()->Initialize(_player->GetPositionAdress());
	return S_OK;
}
void GameState_Stage1::OnLeaveState()
{
	Destroy();
}

LRESULT GameState_Stage1::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	if (result == 0 && jaina)
	{
		jaina->InputProc(hWnd, message, wParam, lParam);
	}
	if (result == 0 && UI)
	{
		UI->InputProc(hWnd, message, wParam, lParam);
	}
	return result;
}

float GameState_Stage1::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
	D3DXVECTOR3 a(0, 0, 1);
	D3DXVECTOR3 b = v2 - v1;

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&b);
	float dot = D3DXVec3Dot(&a, &b);

	// 시계방향인지 반시계방향인지 판별
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &b);
	if (cross.y < 0)
	{
		dot *= -1;		// 반시계 방향이다. 그러면 각도가 반대로
	}

	float angle = acos(dot / (aLength * bLength));	//acos는 0~180도 사이의 값만 나온다.

	//따라서 180도 이상인지 판별
	D3DXVECTOR3 c(1, 0, 0);	//a를 90도 만큼 돌린 백터
	bool over180 = false;
	if (D3DXVec3Dot(&b, &c) < 0.0f)	// c,b가 90도 이상이면 a,b가 180도 이상이라는 소리
	{
		over180 = true;
	}

	//180도 이상이면 180도를 더해줌
	if (over180)
	{
		angle += D3DX_PI;
	}

	return angle;
}