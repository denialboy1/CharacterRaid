#include "stdafx.h"
#include "jaina.h"


Jaina::Jaina()
{
}


Jaina::~Jaina()
{
}

void Jaina::Initialize(){
	player::Initialize();

	scale.x = 0.01f;
	scale.y = 0.01f;
	scale.z = 0.01f;

	mesh->Initialize("", "���̳�.x",scale);
	mesh->GetCollisionSphere()->GetBoundingSphere().center.y = 2;
	mesh->GetCollisionSphere()->GetBoundingSphere().radius = 0.1;
	mesh->SetAnimationIndex(STAND01);
	
	
	D3DXVECTOR3 min = mesh->GetCollisionBox()->GetBoundingBox().min;
	min.z = min.z / 2 + min.z / 4;
	D3DXVECTOR3 max = mesh->GetCollisionBox()->GetBoundingBox().max;
	max.z = max.z / 2 +max.z / 4;
	mesh->SetBoundingBoxMinMax(min, max);

	//��ų
	if (skillManager == nullptr) {
		skillManager = new SkillManager;
		skillManager->Initialize();
	}

	obb = new cOBB;
	obb->Setup(D3DXVECTOR3(-0.5, -0.5, -0.5), D3DXVECTOR3(0.5, 3, 0.5));

	if (item == nullptr){
		item = new Item;
	}
	DataLoad();
	
	if (stunItemSphere == nullptr){
		stunItemSphere = new Collider_Sphere;
		stunItemSphere->Initialize(D3DXVECTOR3(0, 0, 0), 2);
	}

	if (mpRe == nullptr){
		mpRe = new mpRegion;
		mpRe->Initialize();
	}

	if (invincibleEffect == nullptr){
		invincibleEffect = new InvincibleEffect;
		invincibleEffect->Initialize();
	}

	if (healEffect == nullptr){
		healEffect = new Heal;
		healEffect->Initialize();
	}


	soundManager::Get().addSound("iceAttack", "Data/Sound/jaina/Jaina_Attack_Impact02.wav", false, false);
	soundManager::Get().addSound("����ȸ��", "Data/Sound/jaina/����ȸ��.wav", false, false);
}

void Jaina::Destroy(){
	player::Destroy();
	if (skillManager)skillManager->Destroy();
	SAFE_DELETE(stunItemSphere);
	delete item;

	for (auto iter = vIceEffect.begin(); iter != vIceEffect.end();){
			(*iter)->Destroy();
			iter++;
	}
	vIceEffect.clear();
	SAFE_DELETE(mpRe);
	SAFE_DELETE(invincibleEffect);

	for (auto iter = vBlinkEft.begin(); iter != vBlinkEft.end();){
		(*iter)->Destroy();
		iter++;
	}

	SAFE_DELETE(healEffect);
}

void Jaina::Update(){
	player::Update();
	
	KeyInput();	//Ű�����Է�
	ActionAfter();
	
	if (skillManager)	skillManager->Update();

	obb->Update(&obbWorld);

	//������ ȿ��
	if (hp >= hpMax){ hp = hpMax; }
	if (mp >= mpMax){ mp = mpMax; }
	if (isAttackBuff){
		if ((timeGetTime() - attackBuffStartTimer)*0.001 > 10){	//10�� ����
			isAttackBuff = false;
			attackPoint -= 100;
		}
	}
	if (isArmorBuff){
		if ((timeGetTime() - armorBuffStartTimer)*0.001 > 10){	//10�� ����
			isArmorBuff = false;
			armorPoint -= 40;
		}
	}
	if (isInvincibleItem){
		if ((timeGetTime() - invincibleItemStartTimer)*0.001 > 3){	//3�� ����
			isInvincibleItem = false;
		}
	}

	//���� ��Ƽ��Ʈ
	if (isInvincibleArt){
		if ((timeGetTime() - invincibleArtStartTimer)*0.001 > 1.5){
			isInvincibleArt = false;
		}
	}

	if (isInvincibleArtCoolTime){
		if ((timeGetTime() - invincibleArtCoolTime)*0.001 > 30){
			isInvincibleArtCoolTime = false;
		}
	}

	//���ǵ� ��Ƽ��Ʈ
	if (isSpeedArt){
		if ((timeGetTime() - speedArtStartTimer)*0.001 > 5){
			isSpeedArt = false;
			speedPoint -= 20;
		}
	}

	//����
	if (isInvincibleItem || isInvincibleArt|| isInvincibleSkill){
		isInvincible = true;
	}
	else{
		isInvincible = false;
		invincibleEffect->SetIsStart(false);
	}


	//��ų
	if (isDownE){
		if ((timeGetTime() - eSkillCoolTimer)*0.001 > 15){
			isDownE = false;
		}
	}

	if (isDownR){
		if ((timeGetTime() - rSkillCoolTimer)*0.001 > 7){
			isDownR = false;
		}
	}

	for (auto iter = vIceEffect.begin(); iter != vIceEffect.end(); ){
		if (!(*iter)->GetIce()->GetIsPlay()){
			(*iter)->Destroy();
			iter = vIceEffect.erase(iter);
		}
		else{
			(*iter)->Update();
			iter++;
		}
		
	}


	if (mpRe) mpRe->Update(position);
	if (invincibleEffect) invincibleEffect->Update(position);

	for (auto iter = vBlinkEft.begin(); iter != vBlinkEft.end();){
		if (!(*iter)->GetIsBlink()->GetIsPlay()){
			(*iter)->Destroy();
			iter = vBlinkEft.erase(iter);
		}
		else{
			(*iter)->Update();
			iter++;
		}

	}

	if (healEffect) healEffect->Update(position);

	if (isInvincibleSkill){
		if ((timeGetTime() - invincibleSkill)*0.001 > 5){
			isInvincibleSkill = false;
		}
	}


	//eSkillCoolTimer++;

}

void Jaina::Render(){
	mesh->UpdateAndRender();
	
	if (skillManager)	skillManager->Render();
	

	for (int i = 0; i < vIceEffect.size(); i++){
		vIceEffect[i]->Render();
	}
	
	if (mpRe) mpRe->Render();
	if (invincibleEffect) invincibleEffect->Render();
	for (int i = 0; i < vBlinkEft.size(); i++){
		vBlinkEft[i]->Render();
	}
	if (healEffect) healEffect->Render();
}

void Jaina::Battle(unit& enemy){
	for (auto iter = skillManager->GetIceMake()->GetMIce().begin(); iter != skillManager->GetIceMake()->GetMIce().end();){
		if (Collision::IsSphereToSphere(enemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), (*iter)->GetMesh()->GetCollisionSphere()->GetBoundingSphere())){
			if (cOBB::IsCollision(enemy.GetObbBox(), (*iter)->GetObbBox())){
				IceEffect* iceEffect = new IceEffect;
				iceEffect->Initialize();
				iceEffect->Start((*iter)->GetPosition());
				vIceEffect.push_back(iceEffect);
				(*iter)->Reset();
				skillManager->GetIceMake()->GetMIceUnUsed().push_back(*iter);
				iter = skillManager->GetIceMake()->GetMIce().erase(iter);
				skillManager->GetIceFire()->SetIsFire(false);
				//iter = skillManager->GetIceMake()->GetMIce().begin();
				D3DXVECTOR3 temp = enemy.GetPosition();
				temp.y = temp.y + 3;
				//EffectManager::Get().GetIceImpact()->Start(temp);
				
				enemy.SetHp(enemy.GetHp() - attackPoint*2);
			}
			else{
				iter++;
			}
		}
		else{
			iter++;
		}
	}

	if (isStunItemClick){
		if (Collision::IsSphereToSphere(stunItemSphere->GetBoundingSphere(), enemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere())){
			item->revenge--;
			//���� ����
			position.x = enemy.GetPosition().x + enemy.GetDirection().x * 5;
			position.z = enemy.GetPosition().z + enemy.GetDirection().z * 5;
		}
		isStunItemClick = false;
	}
}


LRESULT Jaina::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;
	

	switch (message){
	case WM_LBUTTONDOWN:
	{
		result = WM_LBUTTONDOWN;
		if (!isDownA && !isDownQ && !(isDownE&&isSkillSwitch) && !isDownD) break;
		if (grid)
		{
			SAFE_DELETE(action);
			//���� ã��
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
			}
			//�ٸ� Ȱ�� ����
			SwitchOff();
			
		}
		break;
	}
	case WM_RBUTTONDOWN:
	{
		if (state == STAND01 || state == STAND_DANCE || state == ATTACK02 || state == WALK){
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
						goal = targetPosition;
						/*
						bool isCollision = pathFinder->CheckBarricadeCollision(position, targetPosition);
						if (isCollision == true)
						{
							state = WALK;
							mesh->SetAnimationIndex(WALK);
							//��ã�� ����
							int startIndex = pathFinder->FindNearestPathNode(position);
							int goalIndex = pathFinder->FindNearestPathNode(targetPosition);
							if (startIndex != -1 && goalIndex != -1)
							{
								std::list<int> path;
								pathFinder->PathFind(path, startIndex, goalIndex);
								pathFinder->PathOptimize(path, position, targetPosition);

								//�׼� �߰�
								SAFE_DELETE(action);

								ActionSequence* sequence1 = new ActionSequence;
								auto iterStart = path.cbegin();
								auto iterNext = ++path.cbegin();
								float length = 1.0f;
								D3DXVECTOR3 temp;

								//����� -> ù��° ���
								ActionMove* firstMove = new ActionMove;
								const D3DXVECTOR3& startPos = pathFinder->GetPathNodePosition(*iterStart);
								temp = startPos - position;
								length = D3DXVec3Length(&temp);
								firstMove->SetStart(position);
								firstMove->SetGoal(startPos);
								firstMove->SetDuration(1+0.1f * length);
								firstMove->SetTarget(this);
								firstMove->SetDelegate(sequence1);
								firstMove->SetSpeed(speedPoint*0.05);
								sequence1->AddAction(firstMove);

								//ù��° ��� -> ������ ���
								while (iterStart != path.cend() && iterNext != path.cend())
								{
									ActionMove* move = new ActionMove;

									const D3DXVECTOR3& start = pathFinder->GetPathNodePosition(*iterStart);
									const D3DXVECTOR3& next = pathFinder->GetPathNodePosition(*iterNext);
									temp = next - start;
									length = D3DXVec3Length(&temp);
									move->SetStart(start);
									move->SetGoal(next);
									move->SetDuration(0.1f * length);
									move->SetTarget(this);
									move->SetSpeed(1 + speedPoint*0.05);
									move->SetDelegate(sequence1);
									sequence1->AddAction(move);

									++iterStart;
									++iterNext;
								}

								//������ ��� -> ������
								ActionMove* LastMove = new ActionMove;
								const D3DXVECTOR3& lastPos = pathFinder->GetPathNodePosition(*iterStart);
								temp = targetPosition - lastPos;
								length = D3DXVec3Length(&temp);
								LastMove->SetStart(lastPos);
								LastMove->SetGoal(targetPosition);
								LastMove->SetDuration(0.1f * length);
								LastMove->SetTarget(this);
								LastMove->SetSpeed(1 + speedPoint*0.05);
								LastMove->SetDelegate(sequence1);
								sequence1->AddAction(LastMove);

								//���� �� ����
								action = sequence1;
								action->Start();
								
							}
							
						}
						else
						*/
						{
							//�׳� �̵�
							D3DXVECTOR3 targetLength = targetPosition - position;
							float length = D3DXVec3Length(&targetLength);
							//OutputDebugStringA(std::string("lenght : " + std::to_string(length) + "\n").c_str());

							SAFE_DELETE(action);
							ActionMove* move = new ActionMove;
							move->SetStart(position);
							move->SetGoal(targetPosition);
							move->SetDuration(0.1f * length);
							move->SetTarget(this);
							move->SetSpeed(1 + speedPoint*0.05);
							move->Start();

							SetAction(move);
						}
						state = WALK;
						mesh->SetAnimationIndex(WALK);
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

void Jaina::ChangeMotion(STATE _state){
	if (action)
		removeAction();
	state = _state;
	mesh->SetAnimationIndex(state);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//�ִϸ��̼� ������ �޾��� ����
	mesh->GetAnimController()->GetAnimationSet(state, &animSet);	//��ϵ� �ִϸ��̼ǿ��� animSet������ ������ ���
	aniTime = animSet->GetPeriod();									//�ִϸ��̼� �ð����� ����
	startTimer = timeGetTime();										//���� �ð� ����
	SAFE_RELEASE(animSet);
	SAFE_DELETE(stunItemSphere);
}

void Jaina::KeyInput(){
	
	if (KeyboardManager::Get().IsOnceKeyDown('Q')){
		if (isSkillSwitch){
			if (supportQCount > 0){
				hp += 2000;
				healEffect->Start(position);
				supportQCount = 0;
			}
		}
		else{
			if (state == STAND01 || state == WALK){
				if (mp - 10 >= 0){
					mp -= 10;
					isDownQ = true;
				}
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('W')){
		if (isSkillSwitch){
			if (supportWCount > 0){
				mp += 2000;
				mpRe->Start(position);
				supportWCount = 0;
			}
		}
		else{
			if (state == STAND01 || state == WALK){
				if (mp - 5 >= 0){
					mp -= 5;
					ChangeMotion(SPELL_B);
					skillManager->GetIceMake()->Make(position + D3DXVECTOR3(0, 2, 0), rotationAngle);
					mesh->GetAnimController()->SetTrackSpeed(0, iceBirthSpeed);
				}
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('E')){
		if (isSkillSwitch){
			if (supportECount > 0){
				isDownE = true;
			}
		}
		else{
			if (state == STAND01 || state == WALK){
				if (!isDownE){
					isDownE = true;
					eSkillCoolTimer = timeGetTime();
					mp += 500;
					soundManager::Get().play("����ȸ��", 1.0f);
					mpRe->Start(position);
				}
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('R')){

		if (isSkillSwitch){
			if (supportRCount > 0){
				isInvincibleSkill = true;
				invincibleSkill = timeGetTime();
				invincibleEffect->SetIsStart(true);
				supportRCount = 0;
			}
		}
		else{
			if (state == STAND01 || state == WALK){
				if (!isDownR){
					if (mp - 100 >= 0){
						isDownR = true;
						mp -= 100;
						ChangeMotion(SPELL_D);
						skillManager->GetIceWorld()->Fire();
						rSkillCoolTimer = timeGetTime();
					}
				}
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('A')){
		if (state == STAND01 || state == WALK)
			isDownA = true;

	}

	if (KeyboardManager::Get().IsOnceKeyDown('S')){
		if (state == WALK){
			ChangeMotion(STAND01);
			SAFE_DELETE(action);
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('D')){
		switch (artefact){
		case EMPTY:
			//��Ƽ��Ʈ ���Ծ���
			break;
		case BLINK:
			if (mp - 50 >= 0){
				isDownD = true;
			}
			break;
		case FASTMOVE:
			//ĳ�������� ����
			if (!isSpeedArt){
				isSpeedArt = true;
				speedArtStartTimer = timeGetTime();
				speedPoint += 20;
			}
			break;
		case INVINCIBLE:
			//ĳ������
			if (!isInvincibleArtCoolTime){
				isInvincibleArt = true;
				isInvincibleArtCoolTime = true;
				invincibleArtCoolTime = invincibleArtStartTimer = timeGetTime();
				invincibleEffect->Start(position);
			}
			break;
		}
			
	}


	//����ȸ��
	if (KeyboardManager::Get().IsOnceKeyDown('F')){
		isSkillSwitch = !isSkillSwitch;
	}

	if (KeyboardManager::Get().IsOnceKeyDown('S')){
		if (state == WALK){
			ChangeMotion(STAND01);
			SAFE_DELETE(action);
		}
	}


	if (KeyboardManager::Get().IsOnceKeyDown('1')){
		if (item->hpPotion > 0){
			item->hpPotion--;
			hp += 1000;
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('2')){
		if (item->mpPotion > 0){
			item->mpPotion--;
			mp += 1000;
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('3')){
		if (!isAttackBuff){
			if (item->attackBuff > 0){
				item->attackBuff--;
				attackBuffStartTimer = timeGetTime();
				isAttackBuff = true;
				attackPoint += 100;
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('4')){
		if (!isArmorBuff){
			if (item->armorBuff > 0){
				item->armorBuff--;
				armorBuffStartTimer = timeGetTime();
				isArmorBuff = true;
				armorPoint += 40;
			}
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('5')){
		if (item->revenge > 0){
			isStunItem = true;
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('6')){
		if (item->invincible > 0){
			item->invincible--;
			invincibleItemStartTimer = timeGetTime();
			isInvincibleItem = true;
			invincibleEffect->Start(position);
		}
	}
}

void Jaina::SwitchOff(){
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
}

void Jaina::Action(D3DXVECTOR3 clickPos){
	if (isDownA){
		ChangeMotion(ATTACK02);
	}

	if (isDownQ){
		if (isSkillSwitch){
			
		}
		else{
			ChangeMotion(SPELL_A);
			skillManager->GetIceFire()->Fire(clickPos + D3DXVECTOR3(0, 3, 0));
		}
	}

	if (isDownW){
		
	}

	if (isDownE){
		if (isSkillSwitch){
			blinkEffect* blinkEft = new blinkEffect;
			blinkEft->Initialize();
			blinkEft->Start(position);
			vBlinkEft.push_back(blinkEft);
			position = clickPos;
			goal = clickPos;
			SAFE_DELETE(action);
			supportECount = 0;
		}
		else{
			ChangeMotion(SPELL_C);
		}
	}

	if (isDownR){
	}

	if (isDownS){

	}
	if (isDownD){
		switch (artefact){
		case BLINK:{
			blinkEffect* blinkEft = new blinkEffect;
			blinkEft->Initialize();
			blinkEft->Start(position);
			vBlinkEft.push_back(blinkEft);
			position = clickPos;
			goal = clickPos;
			SAFE_DELETE(action);
			mp -= 50;
			
			}
			break;
		case FASTMOVE:
			//speed
			break;
		case INVINCIBLE:
			break;
		}
		
	}

	if (isDownA){

	}

	if (isStunItem){
		stunItemSphere->GetBoundingSphere().center = clickPos;
		isStunItem = false;
	}
}

void Jaina::ActionAfter(){
	//�ִϸ��̼� �ð����
	float time = (timeGetTime() - startTimer)*0.001f;

	switch (state){
	case WALK:
		if (D3DXVec3LengthSq(&(goal - position))<0.0001 || isIdle){
			ChangeMotion(STAND01);
			isIdle = false;
		}
		break;

	case ATTACK02:
		if (time >= aniTime / 2 - 0.01f){
			ChangeMotion(STAND01);
		}
		break;

	case SPELL_A:
		if (time >= aniTime - 0.01f){
			ChangeMotion(STAND01);
		}
		break;

	case SPELL_B:
		if (time >= aniTime/iceBirthSpeed){
			ChangeMotion(STAND01);
			mesh->GetAnimController()->SetTrackSpeed(0, 1);
		}
		break;

	case SPELL_C:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND01);
		}
		break;

	case SPELL_D:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND01);
		}
		break;

	case SPELL_F:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND01);
		}
		break;

	}
}

float Jaina::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
	D3DXVECTOR3 a(0, 0, 1);
	D3DXVECTOR3 b = v2 - v1;

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&b);
	float dot = D3DXVec3Dot(&a, &b);

	// �ð�������� �ݽð�������� �Ǻ�
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &b);
	if (cross.y < 0)
	{
		dot *= -1;		// �ݽð� �����̴�. �׷��� ������ �ݴ��
	}

	float angle = acos(dot / (aLength * bLength));	//acos�� 0~180�� ������ ���� ���´�.

	//���� 180�� �̻����� �Ǻ�
	D3DXVECTOR3 c(1, 0, 0);	//a�� 90�� ��ŭ ���� ����
	bool over180 = false;
	if (D3DXVec3Dot(&b, &c) < 0.0f)	// c,b�� 90�� �̻��̸� a,b�� 180�� �̻��̶�� �Ҹ�
	{
		over180 = true;
	}

	//180�� �̻��̸� 180���� ������
	if (over180)
	{
		angle += D3DX_PI;
	}

	return angle;
}


void Jaina::DataLoad(){
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

	item->iceSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "Ice");
	item->iceFireSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "IceFire");
	item->icePowerSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "MpRegen");
	item->iceWorldSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "IceWorld");


	item->commonHpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "SupportHp");
	item->commonMpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "SupportMp");
}

