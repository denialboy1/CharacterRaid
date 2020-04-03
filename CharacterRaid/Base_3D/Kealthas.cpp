#include "stdafx.h"
#include "Kealthas.h"


Kealthas::Kealthas()
{
}


Kealthas::~Kealthas()
{
}

void Kealthas::Initialize(){
	unit::Initialize();
	scale.x = 0.02f;
	scale.y = 0.02f;
	scale.z = 0.02f;
	position.y = 2;
	mesh->Initialize("", "��Ÿ��.x", scale);
	scale.x = 0.03f;
	scale.y = 0.03f;
	scale.z = 0.03f;
	mesh->GetCollisionSphere()->GetBoundingSphere().center.y = 2;
	mesh->GetCollisionSphere()->GetBoundingSphere().radius = 0.1;

	ChangeMotion(state);

	obb = new cOBB;
	obb->Setup(mesh);

	attackRange = 20;
	attackRangeSphere = new Collider_Sphere;
	attackRangeSphere->Initialize(mesh->GetCollisionSphere()->GetBoundingSphere().center, attackRange);


	//��ų

	if (fireBallFire == nullptr){
		fireBallFire = new FireBallFire;
		fireBallFire->Initialize();
	}

	if (shield == nullptr){
		shield = new Fire_Shield;
		shield->Initialize();
	}

	if (fireArrowWorld == nullptr){
		fireArrowWorld = new FireArrowWorld;
		fireArrowWorld->Initialize();
	}

	if (hpBar == nullptr){
		hpBar = new bossBar;
		hpBar->Initialize(15000,15000);
		hp = hpMax = 15000;
		mp = 0;
	}

	//����
	soundManager::Get().addSound("kealthas_shiled", "Data/Sound/Kealthas/Illidan_Evasion_Launch01.wav", false, false);
	soundManager::Get().addSound("kealthas_death", "Data/Sound/Kealthas/��Ÿ������.wav", false, false);

	mesh->GetCollisionSphere()->GetBoundingSphere().radius = 3;

	
}

void Kealthas::Destroy(){
	unit::Destroy();

	SAFE_DELETE(attackRangeSphere);
	if(hpBar)SAFE_DELETE(hpBar);
	if (fireBallFire) SAFE_DELETE(fireBallFire);
	if (shield) SAFE_DELETE(shield);
	if (fireArrowWorld) SAFE_DELETE(fireArrowWorld);
	
}

void Kealthas::Update(float _timer, unit* player){
	if (state == DEATH) return;
	unit::Update();
	Action(_timer,player);
	obb->Update(&obbWorld);

	if (fireBallFire)		fireBallFire->Update(); 
	if (shield) shield->Update(position);
	if (fireArrowWorld) fireArrowWorld->Update();
	D3DXVECTOR3 pos = position;
	pos.y = 13;
	if (hpBar){
		hpBar->Update(GameManager::Get().GetCamera()->GetEyePosition(), pos);
		hpBar->SetCurrentHp(hp);
		hpBar->SetCurrentMp(mp);
	}

	
	if (hp < 0){
		
		soundManager::Get().play("kealthas_death", 1.0f);
		state = DEATH;
	}

	
}

void Kealthas::Render(){
	if (state == DEATH) return;
	mesh->UpdateAndRender();

	if (fireBallFire)		fireBallFire->Render();
	if (shield) shield->Render();
	if (fireArrowWorld) fireArrowWorld->Render();
	if (hpBar) hpBar->Render();
}

void Kealthas::Battle(unit& enemy){
	if (!enemy.GetIsInvincible()){
		//Attack Collision
		if (fireBallFire){
			fireBallFire->Battle(&enemy);
		}


		//fire_shield
		if (shield->GetStart()){

			enemy.SetHp(enemy.GetHp() - (revengeHp - hp));
			revengeHp = hp;
		}

		//fireArrowWorld
		if (fireArrowWorld->GetIsStart()){
			fireArrowWorld->Battle(&enemy);
		}
	}
}


float Kealthas::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
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

void Kealthas::ChangeMotion(KEALTHAS_STATE _state){
	if (state == _state) return;
	if (action)
		removeAction();
	state = _state;
	mesh->SetAnimationIndex(state);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//�ִϸ��̼� ������ �޾��� ����
	if (animSet == nullptr){
		mesh->GetAnimController()->GetAnimationSet(state, &animSet);	//��ϵ� �ִϸ��̼ǿ��� animSet������ ������ ���
		aniTime = animSet->GetPeriod();									//�ִϸ��̼� �ð����� ����
		startTimer = timeGetTime();										//���� �ð� ����
	}
	SAFE_RELEASE(animSet);
}

void Kealthas::Action(float _timer, unit* player){
	if (state == DEATH) return;
	mp += 0.1f;
	if (!isPattern4){
		if (mp <= 100){
			if (!(isPattern1 || isPattern3)){
				if ((int)((timeGetTime() - _timer) * 0.001f) % 10 == 0){
					switch (RandomUtil::GetInteger(3, 0)){
					case 0:
						break;
					case 1:
						state = PATTERN1;
						break;
					case 2:
						state = PATTERN3;
						break;
					}
				}
			}
		}
		else{
			ChangeMotion(PATTERN4);
			mp = 0;
		}
	}


	//����1 Ȱ��ȭ
	if (isPattern1){
		if ((timeGetTime() - pattern1Timer)*0.001f > 4){
			isPattern1 = false;
			attackTrackSpeed = 5;
			mesh->GetAnimController()->SetTrackSpeed(0, attackTrackSpeed);
		}
	}

	//����3 Ȱ��ȭ
	if (isPattern3){
		if ((timeGetTime() - pattern1Timer)*0.001f > 5){
			isPattern3 = false;
		}
	}

	if (isPattern4){
		if ((timeGetTime() - pattern4Timer)*0.001f > 8){
			isPattern4 = false;
			fireArrowWorld->SetIsStart(false);
			for (auto iter = fireArrowWorld->GetMFireArrowUsed().begin(); iter != fireArrowWorld->GetMFireArrowUsed().end();){
				(*iter)->SetStand();
				fireArrowWorld->GetMFireArrowUnUsed().push_back((*iter));
				iter = fireArrowWorld->GetMFireArrowUsed().erase(iter);
			}
		}
	}

	switch (state){
	case STAND:
		ChangeMotion(WALK);
		break;

	case WALK:
		//����		
		rotationAngle = GetAngle(player->GetPosition(), position) + D3DX_PI;
		DirectionUpdate();
		position -= direction * 0.2;
		attackRangeSphere->GetBoundingSphere().center = mesh->GetCollisionSphere()->GetBoundingSphere().center;
		//���ݹ����� ������ �Ϲݰ���
		if (Collision::IsSphereToSphere(attackRangeSphere->GetBoundingSphere(), player->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere())){
			ChangeMotion(ATTACK);
			
			mesh->GetAnimController()->SetTrackSpeed(0, attackTrackSpeed);
			if (fireBallFire)
				fireBallFire->Fire(position, player->GetPosition(), rotationAngle, aniTime / attackTrackSpeed *0.5);
		}
		break;

	case ATTACK:
		if (!Collision::IsSphereToSphere(attackRangeSphere->GetBoundingSphere(), player->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere())){
			if ((timeGetTime() - startTimer)*0.001f > aniTime / attackTrackSpeed){
				ChangeMotion(WALK);
				mesh->GetAnimController()->SetTrackSpeed(0, walkTrackSpeed);
			}
		}
		
		if ((timeGetTime() - startTimer)*0.001f > aniTime / attackTrackSpeed){
			rotationAngle = GetAngle(player->GetPosition(), position) + D3DX_PI;
			DirectionUpdate();
			startTimer = timeGetTime();
			mesh->GetAnimController()->SetTrackSpeed(0, attackTrackSpeed);
			if (fireBallFire)
				fireBallFire->Fire(position, player->GetPosition(), rotationAngle, aniTime / attackTrackSpeed * 0.5);
		}
		break;

	case PATTERN1:
		attackTrackSpeed = 10;
		ChangeMotion(ATTACK);
		pattern1Timer = timeGetTime();
		isPattern1 = true;
		break;
	case PATTERN2:
		if (fireCircleWorld){
			fireCircleWorld->Make();
			ChangeMotion(STAND);
		}
		fireCircleWorld->Make();
		ChangeMotion(STAND);
		break;
	case PATTERN3:
		shield->Start();
		ChangeMotion(WALK);
		isPattern3 = true;
		revengeHp = hp;
		startTimer = timeGetTime();
		soundManager::Get().play("kealthas_shiled", 1.0f);
		break;
	case PATTERN4:
		if (!fireArrowWorld->GetIsStart()){
			fireArrowWorld->Make(player->GetPosition());
			startTimer = timeGetTime();
			pattern4Timer = timeGetTime();
			mesh->SetAnimationIndex(STAND);
			mesh->GetAnimController()->SetTrackPosition(0, 0);
			isPattern4 = true;
		}
		if (((timeGetTime() - startTimer) * 0.001f) > 3){
			fireArrowWorld->Fire(player->GetPosition());
			ChangeMotion(WALK);
		}
		break;
	case PATTERN5:
		break;
	}
}

