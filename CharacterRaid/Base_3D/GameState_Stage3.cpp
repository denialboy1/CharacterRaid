#include "stdafx.h"
#include "GameState_Stage3.h"


GameState_Stage3::GameState_Stage3()
{
}


GameState_Stage3::~GameState_Stage3()
{
}

void GameState_Stage3::Initialize(){

	if (stage == nullptr){
		stage = new Stage3;
		stage->Initialize(200, 140,"stage3_5.png");
	}

	if (jaina == nullptr){
		jaina = new Jaina;
		jaina->Initialize();
		jaina->SetGrid(stage->GetGrid());
		jaina->SetPathFinder(stage->GetPathFinder());
		jaina->GetSkinedMesh()->SetIsBoundingBoxShow(true);
		
		_player = jaina;
	}

	if (kealthas == nullptr){
		kealthas = new Kealthas;
		kealthas->Initialize();
	}

	if (ui_interface == nullptr){
		ui_interface = new UI_Interface;
		ui_interface->SetJainaAddress((Jaina*)_player);
		ui_interface->Initialize();
	}

	startTimer = timeGetTime();
	GameManager::Get().GetCamera()->SetLookTarget(jaina->GetPositionAdress());

	if (deathEffect == nullptr){
		deathEffect = new BossDeath;
		deathEffect->Initialize();
	}

	if (playerDeathEffect == nullptr){
		playerDeathEffect = new characterDeath;
		playerDeathEffect->Initialize();
	}

	soundManager::Get().addSound("stage3bgm", "Data/Sound/스테이지3.ogg", true, true);
	soundManager::Get().play("stage3bgm", 0.5f);
}
void GameState_Stage3::Destroy(){
	
	if (_player){
		SAFE_DELETE(_player);
	}

	if (grid){
		SAFE_DELETE(grid);
	}

	if (billboard){
		SAFE_DELETE(billboard);
	}

	if (stage){
		SAFE_DELETE(stage);
	}

	for (auto iter = vPheonix.begin(); iter != vPheonix.end(); iter++){
		SAFE_DELETE((*iter));
	}
	vPheonix.clear();

	if (kealthas){
		SAFE_DELETE(kealthas);
	}

	if (ui_interface) SAFE_DELETE(ui_interface);

	if (deathEffect) SAFE_DELETE(deathEffect);

	soundManager::Get().stop("stage3bgm");
}
void GameState_Stage3::Reset(){

}
void GameState_Stage3::Update(){
	GameManager::Get().GetCamera()->Update();
	if (_player != nullptr){
		if (!(_player->GetHp() < 0)){
			_player->Update();
			
		}
		else{
			if (!isReborn){
				rebornTimer = timeGetTime();
				isReborn = true;
				playerDeathEffect->Start(_player->GetPosition());
//				kealthas->Set
			}
			playerDeathEffect->Update();
			if (_player->GetLife() < 1){
				///게임오버씬
				

			}
			else{
				//3초뒤 부활
				if ((timeGetTime() - rebornTimer)*0.001f > 3){
					_player->SetHp(_player->GetMaxHp());
					_player->SetMp(_player->GetMaxMp());
					_player->SetLife(_player->GetLife() - 1);
					isReborn = false;
				}
			}
		}
		
	}

	if (stage && _player){
		stage->Update(*_player);
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
		ui_interface->SetSupportSkillSwitch(_player->GetIsSkillSwitch());
		ui_interface->SetSupportQCount(_player->GetSupportQCount());
		ui_interface->SetSupportWCount(_player->GetSupportWCount());
		ui_interface->SetSupportECount(_player->GetSupportECount());
		ui_interface->SetSupportRCount(_player->GetSupportRCount());

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

	switch (state){
	case IDLE:
		timer = (timeGetTime() - startTimer)*0.001f;
		if (15 < timer){
			state = BOSS;
			startTimer = timeGetTime();
		}
		break;
	case MINION:
		//몬스터 ATTACK
		if (_player){
			timer = (timeGetTime() - startTimer)*0.001f;
			if (timer < 60){
				CreateMonster(timer);

				for (auto iter = vPheonix.begin(); iter != vPheonix.end(); iter++){
					if (*iter){
						(*iter)->Update(_player);
						(*iter)->Battle(_player);
						(*iter)->Trace(_player);
						//if (!(*iter)->GetIsTrace()) && (*iter)->GetAction() == nullptr) WalkHome((*(*iter)), (*iter)->GetStartPosition());
						_player->Battle(*(*iter));
						switch ((*iter)->GetState()){
						case STAND:

							if (D3DXVec3LengthSq(&((*iter)->GetPosition() - (*iter)->GetStartPosition())) < 0.0001){
								(*iter)->removeAction();
								WalkRoute((*(*iter)), (*iter)->GetStartPosition(), true);
								(*iter)->SetState(WALK);
							}
							break;
						case WALK:
							if ((*iter)->GetAction() == nullptr) WalkRoute((*(*iter)), (*iter)->GetStartPosition(), true);
							break;
						case TRACE:
							break;
						case TRACE_AFTER:
							if ((*iter)->GetAction() == nullptr){
								WalkHome((*(*iter)), ((*iter)->GetStartPosition()));
								(*iter)->SetState(STAND);
							}
							break;
						}
					}
				}
			}
			else{
				state = BOSS;
				startTimer = timeGetTime();
			}
		}
		break;
	case BOSS:
		timer = (timeGetTime() - startTimer)*0.001f;
		if (kealthas && _player){
			kealthas->Update(timer,_player);
			kealthas->Battle(*_player);
			_player->Battle(*kealthas);
		}

		if (kealthas->GetHp() <= 0){
			deathEffect->Start(kealthas->GetPosition());
			state = BOSS_AFTER;

		}
		break;
	case BOSS_AFTER:
		if (deathEffect) deathEffect->Update();
		timer = (timeGetTime() - startTimer)*0.001f;
		if (timer > 10){
			GameStateManager::Get().ChangeGameState(GameStateType::STATE_ENDING);
		}
		break;
	}
	
	
	
	
}
void GameState_Stage3::Render(){
	if (grid){
		grid->Render();
	}

	

	if (stage){
		stage->Render();
	}

	if (_player != nullptr){
		if (!(_player->GetHp() < 0)){
			_player->Render();
		}
		else{
			playerDeathEffect->Render();
		}

	}

	switch (state){
	case IDLE:
		break;
	case MINION:
		//몬스터
		for (auto iter = vPheonix.begin(); iter != vPheonix.end(); iter++){
			if (*iter){
				(*iter)->Render();
			}
		}
		break;
	case BOSS:
		if (kealthas){
			kealthas->Render();
		}
		break;
	case BOSS_AFTER:
		if (deathEffect){ deathEffect->Render(); }
		break;
	}

	
	if (ui_interface){
		ui_interface->Render();
	}
	
	
}

HRESULT GameState_Stage3::OnEnterState(){
	Initialize();
	if (_player){
		GameManager::GetCamera()->Initialize(_player->GetPositionAdress());
	}
	
	return S_OK;
}
void GameState_Stage3::OnLeaveState(){
	Destroy();
}

LRESULT GameState_Stage3::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;
	if (result == 0 && _player){
		_player->InputProc(hWnd, message, wParam, lParam);
	}
	return result;
}

void GameState_Stage3::WalkRoute(Phoenix& _phoenix, D3DXVECTOR3 _goal,bool _loop){
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

void GameState_Stage3::WalkHome(Phoenix& _phoenix, D3DXVECTOR3 _goal){
	ActionSequence* sequence = new ActionSequence;

	ActionMove* move2 = new ActionMove;
	move2->SetStart(_phoenix.GetPosition());
	move2->SetGoal(_goal);
	move2->SetDuration(5);
	move2->SetTarget(&_phoenix);
	move2->SetDelegate(sequence);
	sequence->AddAction(move2);

	sequence->SetLoop(false);
	_phoenix.SetAction(sequence);
	_phoenix.Start();
}

void GameState_Stage3::CreateMonster(float timer){
	if (timer < 3){
		if (vPheonix.size() < 8){
			Phoenix* phoenix1 = new Phoenix;
			phoenix1->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix1->SetPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->SetStartPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, -30);
			WalkRoute(*phoenix1, D3DXVECTOR3(0, 0, -30),true);
			vPheonix.push_back(phoenix1);

			Phoenix* phoenix2 = new Phoenix;
			phoenix2->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix2->SetPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetStartPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetAngle(D3DX_PI / 6);
			phoenix2->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, -25);
			WalkRoute(*phoenix2, D3DXVECTOR3(-35.5, 0, -25), true);
			vPheonix.push_back(phoenix2);

			Phoenix* phoenix3 = new Phoenix;
			phoenix3->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix3->SetPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix3->SetAngle(D3DX_PI / 2);
			phoenix3->SetStartPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-44, 0,0 );
			WalkRoute(*phoenix3, D3DXVECTOR3(-44, 0, 0), true);
			vPheonix.push_back(phoenix3);

			Phoenix* phoenix4 = new Phoenix;
			phoenix4->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix4->SetPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->SetAngle(D3DX_PI / 3 + D3DX_PI / 2);
			phoenix4->SetStartPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, 25);
			WalkRoute(*phoenix4, D3DXVECTOR3(-35.5, 0, 25), true);
			vPheonix.push_back(phoenix4);

			Phoenix* phoenix5 = new Phoenix;
			phoenix5->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix5->SetPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->SetAngle(D3DX_PI);
			phoenix5->SetStartPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, 30);
			WalkRoute(*phoenix5, D3DXVECTOR3(0, 0, 30), true);
			vPheonix.push_back(phoenix5);

			Phoenix* phoenix6 = new Phoenix;
			phoenix6->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix6->SetPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix6->SetAngle(D3DX_PI / 5 + D3DX_PI);
			phoenix6->SetStartPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, 25);
			WalkRoute(*phoenix6, D3DXVECTOR3(35.5, 0, 25), true);
			vPheonix.push_back(phoenix6);

			Phoenix* phoenix7 = new Phoenix;
			phoenix7->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix7->SetPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->SetAngle(D3DX_PI / 2 + D3DX_PI);
			phoenix7->SetStartPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(44,0,0);
			WalkRoute(*phoenix7, D3DXVECTOR3(44, 0, 0), true);
			vPheonix.push_back(phoenix7);

			Phoenix* phoenix8 = new Phoenix;
			phoenix8->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix8->SetPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix8->SetAngle(-D3DX_PI / 6);
			phoenix8->SetStartPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, -25);
			WalkRoute(*phoenix8, D3DXVECTOR3(35.5, 0, -25), true);
			vPheonix.push_back(phoenix8);
		}
	}
	else if (timer < 6){
		if (vPheonix.size() < 16){
			Phoenix* phoenix1 = new Phoenix;
			phoenix1->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix1->SetPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->SetStartPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, -30);
			WalkRoute(*phoenix1, D3DXVECTOR3(0, 0, -30), true);
			vPheonix.push_back(phoenix1);

			Phoenix* phoenix2 = new Phoenix;
			phoenix2->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix2->SetPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetStartPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetAngle(D3DX_PI / 6);
			phoenix2->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, -25);
			WalkRoute(*phoenix2, D3DXVECTOR3(-35.5, 0, -25), true);
			vPheonix.push_back(phoenix2);

			Phoenix* phoenix3 = new Phoenix;
			phoenix3->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix3->SetPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix3->SetAngle(D3DX_PI / 2);
			phoenix3->SetStartPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-44, 0, 0);
			WalkRoute(*phoenix3, D3DXVECTOR3(-44, 0, 0), true);
			vPheonix.push_back(phoenix3);

			Phoenix* phoenix4 = new Phoenix;
			phoenix4->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix4->SetPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->SetAngle(D3DX_PI / 3 + D3DX_PI / 2);
			phoenix4->SetStartPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, 25);
			WalkRoute(*phoenix4, D3DXVECTOR3(-35.5, 0, 25), true);
			vPheonix.push_back(phoenix4);

			Phoenix* phoenix5 = new Phoenix;
			phoenix5->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix5->SetPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->SetAngle(D3DX_PI);
			phoenix5->SetStartPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, 30);
			WalkRoute(*phoenix5, D3DXVECTOR3(0, 0, 30), true);
			vPheonix.push_back(phoenix5);

			Phoenix* phoenix6 = new Phoenix;
			phoenix6->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix6->SetPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix6->SetAngle(D3DX_PI / 5 + D3DX_PI);
			phoenix6->SetStartPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, 25);
			WalkRoute(*phoenix6, D3DXVECTOR3(35.5, 0, 25), true);
			vPheonix.push_back(phoenix6);

			Phoenix* phoenix7 = new Phoenix;
			phoenix7->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix7->SetPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->SetAngle(D3DX_PI / 2 + D3DX_PI);
			phoenix7->SetStartPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(44, 0, 0);
			WalkRoute(*phoenix7, D3DXVECTOR3(44, 0, 0), true);
			vPheonix.push_back(phoenix7);

			Phoenix* phoenix8 = new Phoenix;
			phoenix8->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix8->SetPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix8->SetAngle(-D3DX_PI / 6);
			phoenix8->SetStartPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, -25);
			WalkRoute(*phoenix8, D3DXVECTOR3(35.5, 0, -25), true);
			vPheonix.push_back(phoenix8);
		}
	}
	else if (timer < 9){
		if (vPheonix.size() < 24){
			Phoenix* phoenix1 = new Phoenix;
			phoenix1->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix1->SetPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->SetStartPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, -30);
			WalkRoute(*phoenix1, D3DXVECTOR3(0, 0, -30), true);
			vPheonix.push_back(phoenix1);

			Phoenix* phoenix2 = new Phoenix;
			phoenix2->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix2->SetPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetStartPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetAngle(D3DX_PI / 6);
			phoenix2->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, -25);
			WalkRoute(*phoenix2, D3DXVECTOR3(-35.5, 0, -25), true);
			vPheonix.push_back(phoenix2);

			Phoenix* phoenix3 = new Phoenix;
			phoenix3->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix3->SetPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix3->SetAngle(D3DX_PI / 2);
			phoenix3->SetStartPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-44, 0, 0);
			WalkRoute(*phoenix3, D3DXVECTOR3(-44, 0, 0), true);
			vPheonix.push_back(phoenix3);

			Phoenix* phoenix4 = new Phoenix;
			phoenix4->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix4->SetPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->SetAngle(D3DX_PI / 3 + D3DX_PI / 2);
			phoenix4->SetStartPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, 25);
			WalkRoute(*phoenix4, D3DXVECTOR3(-35.5, 0, 25), true);
			vPheonix.push_back(phoenix4);

			Phoenix* phoenix5 = new Phoenix;
			phoenix5->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix5->SetPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->SetAngle(D3DX_PI);
			phoenix5->SetStartPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, 30);
			WalkRoute(*phoenix5, D3DXVECTOR3(0, 0, 30), true);
			vPheonix.push_back(phoenix5);

			Phoenix* phoenix6 = new Phoenix;
			phoenix6->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix6->SetPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix6->SetAngle(D3DX_PI / 5 + D3DX_PI);
			phoenix6->SetStartPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, 25);
			WalkRoute(*phoenix6, D3DXVECTOR3(35.5, 0, 25), true);
			vPheonix.push_back(phoenix6);

			Phoenix* phoenix7 = new Phoenix;
			phoenix7->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix7->SetPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->SetAngle(D3DX_PI / 2 + D3DX_PI);
			phoenix7->SetStartPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(44, 0, 0);
			WalkRoute(*phoenix7, D3DXVECTOR3(44, 0, 0), true);
			vPheonix.push_back(phoenix7);

			Phoenix* phoenix8 = new Phoenix;
			phoenix8->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix8->SetPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix8->SetAngle(-D3DX_PI / 6);
			phoenix8->SetStartPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, -25);
			WalkRoute(*phoenix8, D3DXVECTOR3(35.5, 0, -25), true);
			vPheonix.push_back(phoenix8);
		}
	}
	else if (timer < 12){
		if (vPheonix.size() < 32){
			Phoenix* phoenix1 = new Phoenix;
			phoenix1->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix1->SetPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->SetStartPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, -30);
			WalkRoute(*phoenix1, D3DXVECTOR3(0, 0, -30), true);
			vPheonix.push_back(phoenix1);

			Phoenix* phoenix2 = new Phoenix;
			phoenix2->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix2->SetPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetStartPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetAngle(D3DX_PI / 6);
			phoenix2->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, -25);
			WalkRoute(*phoenix2, D3DXVECTOR3(-35.5, 0, -25), true);
			vPheonix.push_back(phoenix2);

			Phoenix* phoenix3 = new Phoenix;
			phoenix3->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix3->SetPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix3->SetAngle(D3DX_PI / 2);
			phoenix3->SetStartPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-44, 0, 0);
			WalkRoute(*phoenix3, D3DXVECTOR3(-44, 0, 0), true);
			vPheonix.push_back(phoenix3);

			Phoenix* phoenix4 = new Phoenix;
			phoenix4->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix4->SetPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->SetAngle(D3DX_PI / 3 + D3DX_PI / 2);
			phoenix4->SetStartPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, 25);
			WalkRoute(*phoenix4, D3DXVECTOR3(-35.5, 0, 25), true);
			vPheonix.push_back(phoenix4);

			Phoenix* phoenix5 = new Phoenix;
			phoenix5->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix5->SetPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->SetAngle(D3DX_PI);
			phoenix5->SetStartPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, 30);
			WalkRoute(*phoenix5, D3DXVECTOR3(0, 0, 30), true);
			vPheonix.push_back(phoenix5);

			Phoenix* phoenix6 = new Phoenix;
			phoenix6->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix6->SetPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix6->SetAngle(D3DX_PI / 5 + D3DX_PI);
			phoenix6->SetStartPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, 25);
			WalkRoute(*phoenix6, D3DXVECTOR3(35.5, 0, 25), true);
			vPheonix.push_back(phoenix6);

			Phoenix* phoenix7 = new Phoenix;
			phoenix7->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix7->SetPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->SetAngle(D3DX_PI / 2 + D3DX_PI);
			phoenix7->SetStartPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(44, 0, 0);
			WalkRoute(*phoenix7, D3DXVECTOR3(44, 0, 0), true);
			vPheonix.push_back(phoenix7);

			Phoenix* phoenix8 = new Phoenix;
			phoenix8->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix8->SetPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix8->SetAngle(-D3DX_PI / 6);
			phoenix8->SetStartPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, -25);
			WalkRoute(*phoenix8, D3DXVECTOR3(35.5, 0, -25), true);
			vPheonix.push_back(phoenix8);
		}
	}
	else if (timer < 15){
		if (vPheonix.size() < 40){
			Phoenix* phoenix1 = new Phoenix;
			phoenix1->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix1->SetPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->SetStartPosition(D3DXVECTOR3(0, 0, -30));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, -30);
			WalkRoute(*phoenix1, D3DXVECTOR3(0, 0, -30), true);
			vPheonix.push_back(phoenix1);

			Phoenix* phoenix2 = new Phoenix;
			phoenix2->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix2->SetPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetStartPosition(D3DXVECTOR3(-35.5, 0, -25));
			phoenix2->SetAngle(D3DX_PI / 6);
			phoenix2->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, -25);
			WalkRoute(*phoenix2, D3DXVECTOR3(-35.5, 0, -25), true);
			vPheonix.push_back(phoenix2);

			Phoenix* phoenix3 = new Phoenix;
			phoenix3->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix3->SetPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix3->SetAngle(D3DX_PI / 2);
			phoenix3->SetStartPosition(D3DXVECTOR3(-44, 0, 0));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-44, 0, 0);
			WalkRoute(*phoenix3, D3DXVECTOR3(-44, 0, 0), true);
			vPheonix.push_back(phoenix3);

			Phoenix* phoenix4 = new Phoenix;
			phoenix4->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix4->SetPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->SetAngle(D3DX_PI / 3 + D3DX_PI / 2);
			phoenix4->SetStartPosition(D3DXVECTOR3(-35.5, 0, 25));
			phoenix4->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(-35.5, 0, 25);
			WalkRoute(*phoenix4, D3DXVECTOR3(-35.5, 0, 25), true);
			vPheonix.push_back(phoenix4);

			Phoenix* phoenix5 = new Phoenix;
			phoenix5->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix5->SetPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->SetAngle(D3DX_PI);
			phoenix5->SetStartPosition(D3DXVECTOR3(0, 0, 30));
			phoenix5->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(0, 0, 30);
			WalkRoute(*phoenix5, D3DXVECTOR3(0, 0, 30), true);
			vPheonix.push_back(phoenix5);

			Phoenix* phoenix6 = new Phoenix;
			phoenix6->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix6->SetPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix6->SetAngle(D3DX_PI / 5 + D3DX_PI);
			phoenix6->SetStartPosition(D3DXVECTOR3(35.5, 0, 25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, 25);
			WalkRoute(*phoenix6, D3DXVECTOR3(35.5, 0, 25), true);
			vPheonix.push_back(phoenix6);

			Phoenix* phoenix7 = new Phoenix;
			phoenix7->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix7->SetPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->SetAngle(D3DX_PI / 2 + D3DX_PI);
			phoenix7->SetStartPosition(D3DXVECTOR3(44, 0, 0));
			phoenix7->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(44, 0, 0);
			WalkRoute(*phoenix7, D3DXVECTOR3(44, 0, 0), true);
			vPheonix.push_back(phoenix7);

			Phoenix* phoenix8 = new Phoenix;
			phoenix8->Initialize(D3DXVECTOR3(0.02, 0.02, 0.02));
			phoenix8->SetPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix8->SetAngle(-D3DX_PI / 6);
			phoenix8->SetStartPosition(D3DXVECTOR3(35.5, 0, -25));
			phoenix1->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere().center = D3DXVECTOR3(35.5, 0, -25);
			WalkRoute(*phoenix8, D3DXVECTOR3(35.5, 0, -25), true);
			vPheonix.push_back(phoenix8);
		}
	}
}