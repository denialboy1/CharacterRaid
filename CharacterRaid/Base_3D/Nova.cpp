#include "stdafx.h"
#include "Nova.h"


Nova::Nova()
{
}


Nova::~Nova()
{
}


void Nova::Initialize()
{
	player::Initialize();

	BattleCruiserBoomTimer = 0;
	IsBattleCruiserBoomTimerOn = false;
	
	mesh->Initialize("", "노바.x", scale);
	scale.x = 0.01f;
	scale.y = 0.01f;
	scale.z = 0.01f;
	mesh->SetAnimationIndex(STAND);
	_NuClear = 0;
	NuClearTimer = false;
	isBattleCruiserMove = false;
	mesh->GetCollisionSphere()->GetBoundingSphere().radius = 4;
	//스킬
	//if (skillManager == nullptr) {
	//	skillManager = new SkillManager;
	//	skillManager->Initialize();
	//}

	if (nuclear == nullptr)
	{
		nuclear = new NuClear;
		nuclear->Initialize();
	}
	if (battlecruiser == nullptr)
	{
		battlecruiser = new Battlecruiser;
		battlecruiser->Initialize();
	}
	if (nuclearExplosion == nullptr)
	{
		nuclearExplosion = new NuclearExplosion;
		nuclearExplosion->Initialize(D3DXVECTOR3(0, 30, 0), D3DXVECTOR3(7, 7, 7));
	}
	
	if (battleCruiserBoom1 == nullptr)
	{
		battleCruiserBoom1 = new BattleCruiserBoom;
		battleCruiserBoom1->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom1->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom1);
	}
	
	if (battleCruiserBoom2 == nullptr)
	{
		battleCruiserBoom2 = new BattleCruiserBoom;
		battleCruiserBoom2->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom2->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom2);
	}


	if (battleCruiserBoom3 == nullptr)
	{
		battleCruiserBoom3 = new BattleCruiserBoom;
		battleCruiserBoom3->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom3->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom3);
	}


	if (battleCruiserBoom4 == nullptr)
	{
		battleCruiserBoom4 = new BattleCruiserBoom;
		battleCruiserBoom4->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom4->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom4);
	}

	
	if (battleCruiserBoom5 == nullptr)
	{

		battleCruiserBoom5 = new BattleCruiserBoom;
		battleCruiserBoom5->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom5->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom5);
	}

	if (battleCruiserBoom6 == nullptr)
	{
		battleCruiserBoom6 = new BattleCruiserBoom;
		battleCruiserBoom6->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom6->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom6);
	}


	if (battleCruiserBoom7 == nullptr)
	{
		battleCruiserBoom7 = new BattleCruiserBoom;
		battleCruiserBoom7->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom7->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom7);
	}

	
	if (battleCruiserBoom8 == nullptr)
	{
		battleCruiserBoom8 = new BattleCruiserBoom;
		battleCruiserBoom8->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom8->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom8);
	}

	

	if (battleCruiserBoom9 == nullptr)
	{
		battleCruiserBoom9 = new BattleCruiserBoom;
		battleCruiserBoom9->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom9->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom9);
	}


	if (battleCruiserBoom10 == nullptr)
	{
		battleCruiserBoom10 = new BattleCruiserBoom;
		battleCruiserBoom10->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom10->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom10);
	}


	if (battleCruiserBoom11 == nullptr)
	{
		battleCruiserBoom11 = new BattleCruiserBoom;
		battleCruiserBoom11->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom11->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom11);
	}


	if (battleCruiserBoom12 == nullptr)
	{
		battleCruiserBoom12 = new BattleCruiserBoom;
		battleCruiserBoom12->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom12->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom12);
	}


	if (battleCruiserBoom13 == nullptr)
	{
		battleCruiserBoom13 = new BattleCruiserBoom;
		battleCruiserBoom13->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom13->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom13);
	}

	if (battleCruiserBoom14 == nullptr)
	{
		battleCruiserBoom14 = new BattleCruiserBoom;
		battleCruiserBoom14->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom14->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom14);
	}

	
	if (battleCruiserBoom15 == nullptr)
	{
		battleCruiserBoom15 = new BattleCruiserBoom;
		battleCruiserBoom15->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom15->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom15);
	}

	if (battleCruiserBoom16 == nullptr)
	{
		battleCruiserBoom16 = new BattleCruiserBoom;
		battleCruiserBoom16->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom16->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom16);
	}

	if (battleCruiserBoom17 == nullptr)
	{
		battleCruiserBoom17 = new BattleCruiserBoom;
		battleCruiserBoom17->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom17->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom17);
	}

	if (battleCruiserBoom18 == nullptr)
	{
		battleCruiserBoom18 = new BattleCruiserBoom;
		battleCruiserBoom18->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom18->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom18);
	}

	if (battleCruiserBoom19 == nullptr)
	{
		battleCruiserBoom19 = new BattleCruiserBoom;
		battleCruiserBoom19->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom19->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom19);

	}
	
	if (battleCruiserBoom20 == nullptr)
	{
		battleCruiserBoom20 = new BattleCruiserBoom;
		battleCruiserBoom20->Initialize(D3DXVECTOR3(0, 5, 0), D3DXVECTOR3(5, 5, 5));
		//battleCruiserBoom20->SetScale(D3DXVECTOR3(5, 5, 5));
		vBattleCruiserBoomList.push_back(battleCruiserBoom20);
	}

	if (novaNomalAttack == nullptr)
	{
		novaNomalAttack = new NovaNomalAttack;
		novaNomalAttack->Initialize(D3DXVECTOR3(0,20,0), D3DXVECTOR3(5,5,5));
	}
	BattleCruiserBoomSphere = new Collider_Sphere;
	BattleCruiserBoomSphere->Initialize(D3DXVECTOR3(0, 0, 0), 10);
	
	soundManager::Get().addSound("쏠때", "Data/Sound/Nova/쏠때.wav", false, false);
	soundManager::Get().addSound("드랍", "Data/Sound/Nova/드랍.wav", false, false);
	soundManager::Get().addSound("터짐", "Data/Sound/Nova/터짐.wav", false, false);
	soundManager::Get().addSound("폭팔음1", "Data/Sound/Nova/폭팔음1.wav", false, false);
	soundManager::Get().addSound("폭팔음2", "Data/Sound/Nova/폭팔음2.wav", false, false);
	soundManager::Get().addSound("폭팔음3", "Data/Sound/Nova/폭팔음3.wav", false, false);
	soundManager::Get().addSound("폭팔음4", "Data/Sound/Nova/폭팔음4.wav", false, false);
	soundManager::Get().addSound("폭팔음5", "Data/Sound/Nova/폭팔음5.wav", false, false);
	soundManager::Get().addSound("폭팔음6", "Data/Sound/Nova/폭팔음6.wav", false, false);
	soundManager::Get().addSound("통신음", "Data/Sound/Nova/통신음.wav", false, false);
	soundManager::Get().addSound("평타", "Data/Sound/Nova/평타.wav", false, false);
	soundManager::Get().addSound("핵쏘기", "Data/Sound/Nova/핵쏘기.wav", false, false);

}
void Nova::Destroy()
{
	player::Destroy();
	//if (skillManager)skillManager->Destroy();
	if (nuclear)
	{
		nuclear->Destroy();
	}
	if (battlecruiser)
	{
		battlecruiser->Destroy();
	}
	for (auto iter = vBattleCruiserBoomList.begin(); iter != vBattleCruiserBoomList.end(); iter++)
	{
		
		(*iter)->Destroy();
	}
	
	nuclearExplosion->Destroy();

	novaNomalAttack->Destroy();
	SAFE_DELETE(BattleCruiserBoomSphere);
}
void Nova::Update()
{
	player::Update();


	KeyInput();	//키보드입력
	ActionAfter();
	if (NuClearTimer)
	{
		_NuClear++;
	}
	if (_NuClear == 1)
	{
		soundManager::Get().play("쏠때", 1.0f);
	}
	if (_NuClear == 60)
	{
		ChangeMotion(HOLOSIGHT_AIM);
	}
	if (_NuClear == 200)
	{
		ChangeMotion(HOLOSIGHT_SHOT);
		nuclear->Nuke = true;
		soundManager::Get().play("핵쏘기", 1.0f);
		soundManager::Get().play("드랍", 1.0f);
	}
	if (_NuClear == 220)
	{
		ChangeMotion(HOLOSIGHT_UP);
		_NuClear = 0;
		NuClearTimer = false;
	}
	if (nuclear)
	{
		nuclear->NuClearMove();
	}
	if (battlecruiser)
	{
	    battlecruiser->Update();
	}
	if (isBattleCruiserMove)
	{
		battlecruiser->BattleCruiserMoveZ += 0.1;
		IsBattleCruiserBoomTimerOn = true;
	}
	if (BattleCruiserBoomTimer == 800)
	{
		battlecruiser->BattleCruiserMoveZ == -50;
		isBattleCruiserMove = false;
		BattleCruiserBoomTimer = 0;
		IsBattleCruiserBoomTimerOn = false;
	}
	if (IsBattleCruiserBoomTimerOn)
	{
		BattleCruiserBoomTimer++;
	}
	/////////////////////////이펙트
	if (nuclear->GetNukeY() < -4.5f)
	{
		nuclearExplosion->Start(D3DXVECTOR3(nuclear->GetPosition().x, 5, nuclear->GetPosition().z));
		nuclearExplosion->GetIsPlay();
		soundManager::Get().play("터짐", 1.0f);
		//nova->GetNuClear()->SetBoomSpherePos(D3DXVECTOR3(nova->GetNuClear()->GetPosition().x, 0, nova->GetNuClear()->GetPosition().z));
	}

	BattleCruiserBoomSphere->GetBoundingSphere().center.x = battlecruiser->GetPosition().x;
	BattleCruiserBoomSphere->GetBoundingSphere().center.z = battlecruiser->GetPosition().z;
	BattleCruiserBoomSphere->GetBoundingSphere().center.y = 0;


	nuclearExplosion->Update(GameManager::Get().GetCamera()->GetEyePosition());


	for (auto iter = vBattleCruiserBoomList.begin(); iter != vBattleCruiserBoomList.end(); iter++)
	{
		(*iter)->Update(GameManager::Get().GetCamera()->GetEyePosition());
	}
	if (BattleCruiserBoomTimer == 10)
	{
		battleCruiserBoom1->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom1->GetIsPlay();
		soundManager::Get().play("폭팔음1", 1.0f);
	}
	if (BattleCruiserBoomTimer == 50)
	{
		battleCruiserBoom2->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom2->GetIsPlay();
	}
	if (BattleCruiserBoomTimer == 100)
	{
		battleCruiserBoom3->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom3->GetIsPlay();
		soundManager::Get().play("폭팔음2", 1.0f);
	}
	if (BattleCruiserBoomTimer == 150)
	{
		battleCruiserBoom4->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom4->GetIsPlay();
	}
	if (BattleCruiserBoomTimer == 200)
	{
		battleCruiserBoom5->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom5->GetIsPlay();
		soundManager::Get().play("폭팔음3", 1.0f);
	}
	if (BattleCruiserBoomTimer == 250)
	{
		battleCruiserBoom6->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom6->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 300)
	{
		battleCruiserBoom7->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom7->GetIsPlay();
		soundManager::Get().play("폭팔음4", 1.0f);
	}

	if (BattleCruiserBoomTimer == 350)
	{
		battleCruiserBoom8->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom8->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 400)
	{
		battleCruiserBoom9->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom9->GetIsPlay();
		soundManager::Get().play("폭팔음5", 1.0f);
	}

	if (BattleCruiserBoomTimer == 450)
	{
		battleCruiserBoom10->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom10->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 500)
	{
		battleCruiserBoom11->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom11->GetIsPlay();
		soundManager::Get().play("폭팔음6", 1.0f);
	}

	if (BattleCruiserBoomTimer == 550)
	{
		battleCruiserBoom12->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom12->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 600)
	{
		battleCruiserBoom13->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom13->GetIsPlay();
		soundManager::Get().play("폭팔음1", 1.0f);
	}

	if (BattleCruiserBoomTimer == 650)
	{
		battleCruiserBoom14->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom14->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 700)
	{
		battleCruiserBoom15->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom15->GetIsPlay();
		soundManager::Get().play("폭팔음2", 1.0f);
	}

	if (BattleCruiserBoomTimer == 750)
	{
		battleCruiserBoom16->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom16->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 800)
	{
		battleCruiserBoom17->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom17->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 850)
	{
		battleCruiserBoom18->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom18->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 900)
	{
		battleCruiserBoom19->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom19->GetIsPlay();
	}

	if (BattleCruiserBoomTimer == 900)
	{
		battleCruiserBoom20->Start(D3DXVECTOR3(battlecruiser->GetPosition().x, 5, battlecruiser->GetPosition().z));
		battleCruiserBoom20->GetIsPlay();
	}
	
	novaNomalAttack->Start(D3DXVECTOR3(0,20,0));
	novaNomalAttack->GetIsPlay();
	



}
void Nova::Render()
{

	mesh->UpdateAndRender();
	//if (skillManager)	skillManager->Render();
	if (nuclear)
	{
		nuclear->NuClearMoveRender();
	}
	if (isBattleCruiserMove)
	{
		if (battlecruiser)
		{
			battlecruiser->Render();
		}
	}
	
	/////////////////이펙트/./////////////////
	nuclearExplosion->Render();

	for (auto iter = vBattleCruiserBoomList.begin(); iter != vBattleCruiserBoomList.end(); iter++)
	{
		(*iter)->Render();
	}

	//novaNomalAttack->Render();

	//if (BattleCruiserBoomSphere)
	//{
	//	BattleCruiserBoomSphere->Render();
	//}
}

LRESULT Nova::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		result = WM_LBUTTONDOWN;
		//if (!isBlink) break;
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
			}
			//다른 활동 종료
			SwitchOff();

		}
		break;
	}
	case WM_RBUTTONDOWN:
	{
		POINT mousePt;
		mousePt.x = GET_X_LPARAM(lParam);
		mousePt.y = GET_Y_LPARAM(lParam);
		Ray ray = Ray::CalcRayFromSceenPoint(mousePt);

		if (grid)
		{
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
					move->SetTarget(this);
					move->Start();
					SetAction(move);
					NovaState = RUN;
					mesh->SetAnimationIndex(RUN);
				}
			}
		}
		result = WM_LBUTTONDOWN;
	}
	break;
	}
	return result;
}
void Nova::ChangeMotion(NOVASTATE _state)
{
	if (action)
		action->SetIsStart(false);
	NovaState = _state;
	mesh->SetAnimationIndex(NovaState);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//애니메이션 정보를 받아줄 변수
	mesh->GetAnimController()->GetAnimationSet(NovaState, &animSet);	//등록된 애니메이션에서 animSet변수에 정보를 등록
	aniTime = animSet->GetPeriod();									//애니메이션 시간길이 저장
	startTimer = timeGetTime();										//현재 시간 갱신
	SAFE_RELEASE(animSet);
}
void Nova::KeyInput()
{
	if (KeyboardManager::Get().IsOnceKeyDown('Q'))
	{
		if (NovaState == STAND || NovaState == RUN)
			isDownQ = true;
	}

	if (KeyboardManager::Get().IsOnceKeyDown('W'))
	{
		if (NovaState == STAND || NovaState == RUN)
			//ChangeMotion(MOTION_6);
		isDownW = true;
		isBattleCruiserMove = true;
		D3DXVECTOR3 pos = position + direction * 40;
		pos.y = 5;
		battlecruiser->SetPosition(pos);
		battlecruiser->SetAngle(rotationAngle);
		soundManager::Get().play("통신음", 1.0f);
	}

	if (KeyboardManager::Get().IsOnceKeyDown('E'))
	{
		if (NovaState == STAND || NovaState == RUN)
			isDownE = true;
	}

	if (KeyboardManager::Get().IsOnceKeyDown('R'))
	{
		if (NovaState == STAND || NovaState == RUN)
			isDownR = true;
	
		//nuclear->positionSet(NukePicking);
		NuClearTimer = true;
	}

	if (KeyboardManager::Get().IsOnceKeyDown('A'))
	{
		if (NovaState == STAND || NovaState == RUN)
			isDownA = true;
	
	}

	if (KeyboardManager::Get().IsOnceKeyDown('S'))
	{
		if (NovaState == RUN){
			ChangeMotion(STAND);
			action->SetIsStart(false);
		}
	}

	if (KeyboardManager::Get().IsOnceKeyDown('D'))
	{
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
		if (NovaState != VICTORY)
			ChangeMotion(STAND);

	}
}
void Nova::Action(D3DXVECTOR3 pickingPos)
{


	if (isDownA){
		ChangeMotion(HOLOSIGHT_SHOT);
		NomalAttackPicking.x = pickingPos.x;
		NomalAttackPicking.z = pickingPos.z;
		soundManager::Get().play("평타", 1.0f);
	}

	if (isDownQ){
		ChangeMotion(SKILL_2);
	}

	if (isDownW){
		ChangeMotion(MOTION_6);
	}

	if (isDownE){
		ChangeMotion(FINGER_GUN);
	}

	if (isDownR)
	{

		nuclear->positionSet(pickingPos);
		ChangeMotion(HOLOSIGHT_DOWN);
	}

	if (isDownS){

	}
	if (isDownD){
		position = pickingPos;
		//action->SetIsStart(false);
		ChangeMotion(LAND);
	}

	if (isDownA){

	}
}
void Nova::ActionAfter()
{
	//애니메이션 시간재기
	float time = (timeGetTime() - startTimer)*0.001f;

	switch (NovaState){
	case RUN:
		if (!action->GetIsStart()){
			ChangeMotion(STAND);
		}
		break;

	case HOLOSIGHT_SHOT:
		if (time >= aniTime / 2 - 0.01f){
			ChangeMotion(STAND);
		}
		break;

	case SKILL_2:
		if (time >= aniTime - 0.01f){
			ChangeMotion(STAND);
		}
		break;

	case MOTION_6:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND);
		}
		break;

	case FINGER_GUN:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND);
		}
		break;

	case HOLOSIGHT_DOWN:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND);
		}
		break;

	case HOLOSIGHT_UP:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND);
		}
		break;

	case LAND:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND);
		}
		break;
	case SKILL_1:
		if (time >= aniTime - 0.02f){
			ChangeMotion(STAND);
		}
		break;

	}
}
void Nova::SwitchOff()
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
}

float Nova::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2){
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


