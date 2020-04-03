#include "stdafx.h"
#include "johanna.h"


johanna::johanna()
{
}


johanna::~johanna()
{
}

void johanna::Initialize()
{
	player::Initialize();
	scale.x = 0.01f;
	scale.y = 0.01f;
	scale.z = 0.01f;
	mesh->Initialize("요한나/", "요한나.X", scale);
	mesh->SetAnimationIndex(state);
	//mesh->SetisSphereShow(true);
	attackSphere = new Collider_Sphere;
	attackSphere->Initialize(object, 0.5f);
	if (item == nullptr)
	{
		item = new Item;
	}
	DataLoad();

	if (stunItemSphere == nullptr){
		stunItemSphere = new Collider_Sphere;
		stunItemSphere->Initialize(D3DXVECTOR3(0, 0, 0), 2);
	}
}
void johanna::Destroy()
{
	player::Destroy();
	
	if (attackSphere)
	{
		SAFE_DELETE(attackSphere);
	}
	
	
}
void johanna::Update()
{
	player::Update();

	

	if (hp >= hpMax){ hp = hpMax; }
	if (mp >= mpMax){ mp = mpMax; }
	if (isAttackBuff){
		if ((timeGetTime() - attackBuffStartTimer*0.001 > 10)){
			isAttackBuff = false;
			attackPoint -= 100;
		}
	}
	if (isArmorBuff){
		if ((timeGetTime() - armorBuffStartTimer)*0.001 > 10){
			isArmorBuff = false;
			armorPoint -= 40;
		}
	}
	if (isInvincibleItem){
		if ((timeGetTime() - invincibleItemStartTimer)*0.001 > 3){
			isInvincibleItem = false;
		}
	}

	if (isInvincibleArt){
		if ((timeGetTime() - invincibleItemStartTimer)*0.001 > 3)
		{
			isInvincibleItem = false;
		}
	}
	if (isSpeedArt){
		if ((timeGetTime() - speedArtStartTimer)*0.001 > 5){
			isSpeedArt = false;
			speedPoint -= 20;
		}
	}

	if (isInvincibleItem || isInvincibleArt){
		isInvincible = true;
	}
	else{
		isInvincible = false;
	}

	if (hp <= 0){
		if (life > 0){
			hp = hpMax;
			life--;
		}
		else{
			GameStateManager::Get().ChangeGameState(GameStateType::STATE_GAMEOVER);
		}
	}

	if (attackSphere)
	{
		attackSphere->Update();
	}
	KeyInput();	//키보드입력
	ActionAfter();
	if (SkillQCoolTimer <= 0.0f){
		UsableSkillQ = true;
	}
	else{
		UsableSkillQ = false;
	}
	if (UsableSkillQ == false){
		SkillQCoolTimer -= 0.1f;
	}
	//W스킬이 켜졌을경우 지속시간 타이머 시작
	if (SkillWCoolTimer <= 0.0f){
		UsableSkillW = true;
	}
	else{
		UsableSkillW = false;
	}
	//쿨타임 계산
	if (UsableSkillW == false){
		SkillWCoolTimer -= 0.1f;
		WSkillTimer += 0.1f;
	}
	//W스킬 지속시간 지나면 비활성
	if (WSkillTimer >= W_SKILL_TIME){
		OnSkillW = false;
		WSkillTimer = 0;
	}
	
	if (SkillECoolTimer <= 0.0f){
		UsableSkillE = true;
	}
	else{
		UsableSkillE = false;
	}
	if (UsableSkillE == false){
		SkillECoolTimer -= 0.1f;
	}

	//W스킬이 켜졌을경우 지속시간 타이머 시작
	if (SkillRCoolTimer <= 0.0f){
		UsableSkillR = true;
	}
	else{
		UsableSkillR = false;
	}
	//쿨타임 계산
	if (UsableSkillR == false){
		SkillRCoolTimer -= 0.1f;
		RSkillTimer += 0.1f;
	}
	//W스킬 지속시간 지나면 비활성
	if (RSkillTimer >= R_SKILL_TIME){
		OnSkillR = false;
		RSkillTimer = 0;
	}

	if (state == STATE_STAND ||
		state == STATE_WALK_A)
	{
		mesh->GetAnimController()->SetTrackSpeed(0, 1.0f);
	}
}
void johanna::Render()
{
	mesh->UpdateAndRender();
	if (attackSphere&&
		hitable)
	{
		//attackSphere->SetWireRender(true);
		//attackSphere->Render();
	}
}

void johanna::Battle(unit& enemy)
{
	if (Collision::IsSphereToSphere(enemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), attackSphere->GetBoundingSphere())){
		if (hitable)
		{
			D3DXVECTOR3 temp = enemy.GetPosition();
			EffectManager::Get().GetIceImpact()->Start(temp);
			EffectManager::Get().GetIceImpact()->SetPos(EffectManager::Get().GetIceImpact()->GetPos()+D3DXVECTOR3(0,10,0));
			HitCounter++;
			if (state == STATE_SPELL_A)
			{
				enemy.SetHp(enemy.GetHp() - (attackPoint+(attackPoint*1.5f)) * 2);
			}
			else if (state == STATE_SPELL_C)
			{
				int knockback=0;
				knockback++;
				if (knockback<=3){
					enemy.SetPosition(enemy.GetPosition() + enemy.GetDirection());
				}
				enemy.SetHp(enemy.GetHp() - (attackPoint+(attackPoint*0.5f))* 2);
			}
			else
			{
				enemy.SetHp(enemy.GetHp() - attackPoint * 2);
			}
		}
		
	}
	
	if (isStunItemClick){
		if (Collision::IsSphereToSphere(stunItemSphere->GetBoundingSphere(), enemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere())){
			item->revenge--;
			//보스 스턴
			position.x = enemy.GetPosition().x + enemy.GetDirection().x * 5;
			position.z = enemy.GetPosition().z + enemy.GetDirection().z * 5;
		}
		isStunItemClick = false;
	}
}
void johanna::KeyInput()
{
	if (KeyboardManager::Get().IsOnceKeyDown('Q')){
		if (state == STATE_STAND || state == STATE_WALK_A){
			if (UsableSkillQ){
				isDownQ = true;
			}
		}
	}
	if (KeyboardManager::Get().IsOnceKeyDown('W')){
		if (state == STATE_STAND || state == STATE_WALK_A){
			if (UsableSkillW){
				ChangeMotion(STATE_SPELL_E);
				OnSkillW = true;
				UsableSkillW = false;
				SkillWCoolTimer = W_SKILL_COOLTIME;
				attackPoint += 15;
			}
			else
			{
				attackPoint -= 15;
			}
		}
	}
	if (KeyboardManager::Get().IsOnceKeyDown('E')){
		if (state == STATE_STAND || state == STATE_WALK_A){
			if (UsableSkillE){
				isDownE = true;
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('R')){
		if (state == STATE_STAND || state == STATE_WALK_A){
			if (UsableSkillR){
				ChangeMotion(STATE_SPELL_D_START);
				//isDownR = true;
				OnSkillR = true;
				UsableSkillR = false;
				SkillRCoolTimer = R_SKILL_COOLTIME;
				armorPoint += 2;
			}
			else
			{
				armorPoint -= 2;
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('A')){
		if (state == STATE_STAND || state == STATE_WALK_A)
			isDownA = true;
		
	}

	if (KeyboardManager::Get().IsOnceKeyDown('S')){
		if (state == STATE_WALK_A){
			ChangeMotion(STATE_STAND);
			action->SetIsStart(false);
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('D')){
		artefact = BLINK;
		switch (artefact){
		case EMPTY:
			//아티펙트 구입안함
			break;
		case BLINK:
			isDownD = true;
			break;
		case FASTMOVE:
			//캐릭빠르게 적용
			break;
		case INVINCIBLE:
			//캐릭무적
			break;
		}
	
	}


	//마나회복
	if (KeyboardManager::Get().IsOnceKeyDown('F')){
		if (state != STATE_SPELL_F)
			ChangeMotion(STATE_SPELL_F);
	}

	if (state == STATE_STAND)
	{
		hitable = false;
		HitCounter = 0;
	}
}
//공격속도를 증가시킬수 있는 방안을 찾을것
void johanna::Action(D3DXVECTOR3 clickPos)
{
	if (isDownA){
		ChangeMotion(STATE_ATTACK_1);
	}

	if (isDownQ){
		ChangeMotion(STATE_SPELL_A);
		UsableSkillQ = false;
		SkillQCoolTimer = Q_SKILL_COOLTIME;
	}

	if (isDownW){
		//ChangeMotion(STATE_SPELL_E);
	}

	if (isDownE){
		ChangeMotion(STATE_SPELL_C);
		UsableSkillQ = false;
		SkillECoolTimer = E_SKILL_COOLTIME;
	}

	if (isDownR){
		//ChangeMotion(STATE_SPELL_D_START);
	}

	if (isDownS){

	}
	if (isDownD){
		position = clickPos;
		action->SetIsStart(false);
	}
}
void johanna::ActionAfter()
{
	//애니메이션 시간재기
	float time = (timeGetTime() - startTimer)*0.001f;

	switch (state){
	case STATE_WALK_A:
		if (!action->GetIsStart()){
			ChangeMotion(STATE_STAND);
		}
		break;

	case STATE_ATTACK_1:
		mesh->GetAnimController()->SetTrackSpeed(0, 1.6f);
		if (time >= aniTime - 0.8f){
			ChangeMotion(STATE_STAND);
		}
		if (time >= aniTime - 1.2f)
		{
			if (HitCounter <= 1)
			{
				hitable = true;	
			}
			else
			{
				hitable = false;
			}
		}
		break;

	case STATE_SPELL_A:
		if (time >= aniTime - 0.01f){
			ChangeMotion(STATE_STAND);
		}
		if (time >= aniTime - 1.1f)
		{
			if (HitCounter <= 3)
			{
				hitable = true;
			}
			else
			{
				hitable = false;
			}
		}
		
		break;

	case STATE_SPELL_E:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STATE_STAND);
		}
		break;

	case STATE_SPELL_C:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STATE_STAND);
		}
		if (time >= aniTime - 1.0f)
		{
			if (HitCounter <= 1)
			{
				hitable = true;
			}
			else
			{
				hitable = false;
			}
		}
		break;

	case STATE_SPELL_D_START:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STATE_STAND);
		}
		break;

	case STATE_SPELL_F:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STATE_STAND);
		}
		break;

	}
}
void johanna::SwitchOff()
{
	isDownA = false;
	isDownQ = false;
	isDownW = false;
	isDownE = false;
	isDownR = false;
	isDownS = false;
	isDownD = false;
	isDownF = false;
	isDown5 = false;
	isDown6 = false;

	OnSkillW = false;
}
float johanna::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2)
{
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
void johanna::ChangeMotion(STATE _state)
{
	if (action)
		action->SetIsStart(false);
	state = _state;
	mesh->SetAnimationIndex(state);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//애니메이션 정보를 받아줄 변수
	mesh->GetAnimController()->GetAnimationSet(state, &animSet);		//등록된 애니메이션에서 animSet변수에 정보를 등록
	aniTime = animSet->GetPeriod();									//애니메이션 시간길이 저장
	startTimer = timeGetTime();										//현재 시간 갱신
	SAFE_RELEASE(animSet);
}
LRESULT johanna::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;


	switch (message){
	case WM_LBUTTONDOWN:
	{
		result = WM_LBUTTONDOWN;
		if (!isDownA&&!/*isDownW&&!*/isDownQ&&!isDownE&&!isDownR&&!isDownD) break;
		if (grid)
		{
			
			//각도 찾기
			POINT mousePt;
			mousePt.x = GET_X_LPARAM(lParam);
			mousePt.y = GET_Y_LPARAM(lParam);
			Ray ray = Ray::CalcRayFromSceenPoint(mousePt);
			const std::vector<D3DXVECTOR3>& groundVertex = grid->GetGroundVertex();
			for (unsigned int i = 0; i < groundVertex.size(); i += 3)
			{
				float u, v, distance;
				if (D3DXIntersectTri(&groundVertex[i], &groundVertex[i + 1], &groundVertex[i + 2],
					&ray.origin, &ray.direction, &u, &v, &distance))
				{
					D3DXVECTOR3 targetPosition = ray.origin + ray.direction * distance;
					rotationAngle = GetAngle(position, targetPosition);
					Action(targetPosition);
					
				}
				player::Update();
				D3DXVECTOR3 newPos = position - direction * 3;
				object = newPos;
				attackSphere->GetBoundingSphere().center = object;

				int a = 0;
			}
			//다른 활동 종료
			SwitchOff();
			
		}
		break;
	}
	case WM_RBUTTONDOWN:
	{
		if (state == STATE_STAND || state == STATE_STAND_DANCE || state == STATE_ATTACK_1 || state == STATE_WALK_A){
			hitable = false;
			if (grid)
			{
				
				POINT mousePt;
				mousePt.x = GET_X_LPARAM(lParam);
				mousePt.y = GET_Y_LPARAM(lParam);
				Ray ray = Ray::CalcRayFromSceenPoint(mousePt);
				const std::vector<D3DXVECTOR3>& groundVertex = grid->GetGroundVertex();

				for (unsigned int i = 0; i < groundVertex.size(); i += 3)
				{
					float u, v, distance;
					if (D3DXIntersectTri(&groundVertex[i], &groundVertex[i + 1], &groundVertex[i + 2],
						&ray.origin, &ray.direction, &u, &v, &distance))
					{
						D3DXVECTOR3 targetPosition = ray.origin + ray.direction * distance;

						//이동
						D3DXVECTOR3 targetLength = targetPosition - position;
						float length = D3DXVec3Length(&targetLength);

						SAFE_DELETE(action);
						ActionMove* move = new ActionMove;
						move->SetStart(position);
						move->SetGoal(targetPosition);
						move->SetDuration(0.1f * length);
						move->SetSpeed(1 + speedPoint*0.05);
						//W스킬이 활성화 된 상태의 이동속도

						if (OnSkillW)
						{
							speedPoint += 3.0f;
						}
						//평소의 이동속도로 돌아옴
						else
						{
							if (speedPoint > 1)
							{
								speedPoint -= 3.0f;
							}
						}
						

						move->SetTarget(this);
						move->Start();
						SetAction(move);
						state = STATE_WALK_A;
						mesh->SetAnimationIndex(STATE_WALK_A);
					}
				}
			}
		}
		result = WM_RBUTTONDOWN;
	}
	break;
	}
	return result;
}

void johanna::DataLoad(){
	stage = iniDataManager::Get().loadDataInterger("player", "Player", "stage");

	item->life = iniDataManager::Get().loadDataInterger("player", "Player", "Life");
	lv = iniDataManager::Get().loadDataInterger("player", "Player", "LV");
	exp = iniDataManager::Get().loadDataInterger("player", "Player", "Exp");

	hpMax = hp = iniDataManager::Get().loadDataInterger("player", "Player", "HP");
	mpMax = mp = iniDataManager::Get().loadDataInterger("player", "Player", "MP");
	attackPoint = iniDataManager::Get().loadDataInterger("player", "Player", "Attack");
	armorPoint = iniDataManager::Get().loadDataInterger("player", "Player", "Armor");
	speedPoint = iniDataManager::Get().loadDataInterger("player", "Player", "Speed");

	money = iniDataManager::Get().loadDataInterger("player", "Item", "Money");
	item->hpPotion = iniDataManager::Get().loadDataInterger("player", "Item", "HpPotion");
	item->mpPotion = iniDataManager::Get().loadDataInterger("player", "Item", "MpPotion");
	item->attackBuff = iniDataManager::Get().loadDataInterger("player", "Item", "PowerHerb");
	item->armorBuff = iniDataManager::Get().loadDataInterger("player", "Item", "ArmorPotion");
	item->revenge = iniDataManager::Get().loadDataInterger("player", "Item", "StunDagger");
	item->invincible = iniDataManager::Get().loadDataInterger("player", "Item", "Invincible");

	item->blink = iniDataManager::Get().loadDataInterger("player", "Item", "Neckles");
	if (item->blink){ artefact = BLINK; }
	item->invincibleA = iniDataManager::Get().loadDataInterger("player", "Item", "Ring");
	if (item->invincibleA){ artefact = INVINCIBLE; }
	item->speedUp = iniDataManager::Get().loadDataInterger("player", "Item", "boots");
	if (item->speedUp){ artefact = FASTMOVE; }

	item->armorSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "ArmorBuff");
	item->attackSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "AttackBuff");

	item->commonHpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "SupportHp");
	item->commonMpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "SupportMp");
}

void johanna::DataSave(){
	iniDataManager::Get().addData("Player", "Character", "2");

	char str[128];
	_itoa_s(stage, str, 10);
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
	_itoa_s(item->sniperSkill, str, 10);
	iniDataManager::Get().addData("Item", "Sniper", str);
	_itoa_s(item->hyperionSkill, str, 10);
	iniDataManager::Get().addData("Item", "Hyperion", str);
	_itoa_s(item->powerUpSkill, str, 10);
	iniDataManager::Get().addData("Item", "PowerUp", str);
	_itoa_s(item->nuclearSkill, str, 10);
	iniDataManager::Get().addData("Item", "Nuclear", str);


	//요한나
	_itoa_s(item->armorSkillUp, str, 10);
	iniDataManager::Get().addData("Item", "ArmorBuff", str);
	_itoa_s(item->attackSkillUp, str, 10);
	iniDataManager::Get().addData("Item", "AttackBuff", str);

	//제이나
	_itoa_s(item->iceSkill, str, 10);
	iniDataManager::Get().addData("Item", "Ice", str);
	_itoa_s(item->iceFireSkill, str, 10);
	iniDataManager::Get().addData("Item", "IceFire", str);
	_itoa_s(item->icePowerSkill, str, 10);
	iniDataManager::Get().addData("Item", "MpRegen", str);
	_itoa_s(item->iceWorldSkill, str, 10);
	iniDataManager::Get().addData("Item", "IceWorld", str);

	_itoa_s(item->commonHpSkill, str, 10);
	iniDataManager::Get().addData("Item", "SupportHp", str);
	_itoa_s(item->commonMpSkill, str, 10);
	iniDataManager::Get().addData("Item", "SupportMp", str);

	iniDataManager::Get().iniSave("player");
}