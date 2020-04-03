#include "stdafx.h"
#include "Azmodan.h"


Azmodan::Azmodan()
{
}


Azmodan::~Azmodan()
{
}

void Azmodan::Initialize(){
	unit::Initialize();
	scale.x = 0.02f;
	scale.y = 0.02f;
	scale.z = 0.02f;
	position.y = 2;
	mesh->Initialize("Azmodan/", "아즈모단.x", scale);
	scale.x = 0.03f;
	scale.y = 0.03f;
	scale.z = 0.03f;
	mesh->GetCollisionSphere()->GetBoundingSphere().center.y = 2;
	mesh->GetCollisionSphere()->GetBoundingSphere().radius = 8.0f;
	//mesh->SetisSphereShow(true);
	ChangeMotion(state);

	obb = new cOBB;
	obb->Setup(mesh);

	attackRange = 20;
	attackRangeSphere = new Collider_Sphere;
	attackRangeSphere->Initialize(mesh->GetCollisionSphere()->GetBoundingSphere().center, attackRange);
	attackRangeSphere->SetWireRender(true);

	if (darkCircle == nullptr)
	{
		darkCircle = new DarkCircle;
		darkCircle->Initialize();
	}

	if (darkBallFire == nullptr){
		darkBallFire = new DarkBallFire;
		darkBallFire->Initialize();
	}

	hpMax = 10000;
	hp = 10000;

	if (hpBar == nullptr){
		hpBar = new bossBar;
		hpBar->Initialize(hpMax, hp);
	}
}

void Azmodan::Destroy(){
	unit::Destroy();

	SAFE_DELETE(attackRangeSphere);
	if (hpBar)SAFE_DELETE(hpBar);
	//if (darkCircleWorld) SAFE_DELETE(darkCircleWorld);
	if (darkBallFire) SAFE_DELETE(darkBallFire);
	if (darkCircle) SAFE_DELETE(darkCircle);
	//if (shield) SAFE_DELETE(shield);
	//if (darkArrowWorld) SAFE_DELETE(darkArrowWorld);
}

void Azmodan::Update(float _timer, unit* player){
	unit::Update();
	Action(_timer, player);
	obb->Update(&obbWorld);

	if (darkBallFire&&hp>0)		darkBallFire->Update();

	if (darkCircle&&hp>0){
		if (isPattern2){
			darkCircle->Update();
		}
	}
	//if (darkCircleWorld)	darkCircleWorld->Update();
	//if (shield) shield->Update(position);
	//if (darkArrowWorld) darkArrowWorld->Update();
	D3DXVECTOR3 pos = position;
	pos.y = 13;
	if (hpBar){
		hpBar->Update(GameManager::Get().GetCamera()->GetEyePosition(), pos);
		hpBar->SetCurrentHp(hp);
		hpBar->SetCurrentMp(mp);
	}
}

void Azmodan::Render(){
	
	if (mesh && hp > 0)
	{
		mesh->UpdateAndRender();
	}
	
	//obb->DebugRender(D3DCOLOR_XRGB(255, 0, 0));

	if (darkBallFire&&hp>0)		darkBallFire->Render();
	if (darkCircle&&isPattern2&&hp>0)			darkCircle->Render();
	//if (darkCircleWorld)	fireCircleWorld->Render();
	//if (shield) shield->Render();
	//if (darkArrowWorld) darkArrowWorld->Render();
	if (hpBar&&hp>0) hpBar->Render();
}

void Azmodan::Battle(unit& enemy){
	//Attack Collision

	if (darkCircle&&isPattern2&&hp>0)
	{
		darkCircle->Battle(&enemy);
	}

	if (!enemy.GetIsInvincible()){
		//Attack Collision
		if (darkBallFire&&hp>0){
			darkBallFire->Battle(&enemy);
		}	
	}
}


float Azmodan::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
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

void Azmodan::ChangeMotion(AZ_STATE _state){
	if (state == _state) return;
	if (action)
		removeAction();
	state = _state;
	mesh->SetAnimationIndex(state);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//애니메이션 정보를 받아줄 변수
	if (animSet == nullptr){
		mesh->GetAnimController()->GetAnimationSet(state, &animSet);	//등록된 애니메이션에서 animSet변수에 정보를 등록
		aniTime = animSet->GetPeriod();									//애니메이션 시간길이 저장
		startTimer = timeGetTime();										//현재 시간 갱신
	}
	SAFE_RELEASE(animSet);
}

void Azmodan::Action(float _timer, unit* player){

	mp += 0.1f;
	if (!isPattern2)
	{
		if (mp < 100)
		{
			if (!(isPattern1))
			{
				if ((int)((timeGetTime() - _timer) * 0.001f) % 10 == 0)
				{
					switch (RandomUtil::GetInteger(3, 0))
					{
					case 0:
						break;
					case 1:
						state = PATTERN1;
						break;
					}
				}
			}
		}
		else{
			ChangeMotion(PATTERN2);
			mp = 0;
		}
	}


	//패턴1 활성화
	if (isPattern1){
		if ((timeGetTime() - pattern1Timer)*0.001f > 4){
			isPattern1 = false;
			attackTrackSpeed = 5;
			mesh->GetAnimController()->SetTrackSpeed(0, attackTrackSpeed);
		}
	}

	//패턴2 활성화
	if (isPattern2){
		if ((timeGetTime() - pattern1Timer)*0.001f > 8){
			isPattern2 = false;
		}
	}

	switch (state){
	case STAND:
		ChangeMotion(WALK);
		break;
	case WALK:
		//추적		
		rotationAngle = GetAngle(player->GetPosition(), position) + D3DX_PI;
		DirectionUpdate();
		position -= direction * 0.1f;
		attackRangeSphere->GetBoundingSphere().center = mesh->GetCollisionSphere()->GetBoundingSphere().center;
		//공격범위에 들어오면 일반공격
		if (Collision::IsSphereToSphere(attackRangeSphere->GetBoundingSphere(), player->GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere())){
			ChangeMotion(ATTACK);

			mesh->GetAnimController()->SetTrackSpeed(0, attackTrackSpeed);
			if (darkBallFire)
				darkBallFire->Fire(position, player->GetPosition(), rotationAngle, aniTime / attackTrackSpeed *0.5);
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
			if (darkBallFire)
				darkBallFire->Fire(position, player->GetPosition(), rotationAngle, aniTime / attackTrackSpeed * 0.5);
		}
		break;
	case PATTERN1:
		attackTrackSpeed = 10;
		ChangeMotion(ATTACK);
		pattern1Timer = timeGetTime();
		isPattern1 = true;
		break;
	case PATTERN2:
		if (darkCircle)
		{
			darkCircle->SetPosition(position);
			ChangeMotion(STAND);
			startTimer = timeGetTime();
			pattern2Timer = timeGetTime();
			mesh->SetAnimationIndex(STAND);
			mesh->GetAnimController()->SetTrackPosition(0, 0);
			isPattern2 = true;
		}
		if (((timeGetTime() - startTimer) * 0.001f) > 3){
			ChangeMotion(WALK);
		}
		//if (fireCircleWorld){
		//	fireCircleWorld->Make();
		//	ChangeMotion(STAND);
		//}
		//fireCircleWorld->Make();
		//ChangeMotion(STAND);
		break;
	}
}

