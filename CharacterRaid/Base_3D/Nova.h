#pragma once
#include "player.h"
#include "SkinnedMesh.h"
#include "Grid.h"
#include "NuClear.h"
#include "Battlecruiser.h"
#include "SkillManager.h"
#include "BattleCruiserBoom.h"
#include "NuclearExplosion.h"
#include "NovaNomalAttack.h"
class Nova : public player
{
	enum NOVASTATE
	{
		NORMAL_ATTACK,
		MOTION_1,                 //고민하는듯한 모션
		MOTION_2,                 //무엇을 줍는듯한 모션
		MOTION_3,                 //허우적거리는 모션
		MOTION_4,                 //앞에서 끌려가는 모션
		MOTION_5,                 //뒤에서 끌려가는 모션
		SKILL_1,                  //스킬1
		SKILL_2,                  //스킬2
		MOTION_6,                 //교신하는 모션
		MOTION_7,                 //공격하라고 명령내리는 모션
		HOLOSIGHT_SHOT,           //조준경끼고 평타(공속 빠름)
		MOTION_9,                 //명령1
		MOTION_10,                //명령2
		STAND,                    //스탠드모션
		STAND_SEARCH,             //두리번거리는 스탠드 모션
		HOLOSIGHT_AIM,            //조준경끼고 조준상태
		HOLOSIGHT_UP,             //조준경 풀고 서는 상태
		HOLOSIGHT_DOWN,           //조준경 끼고 앉는 상태
		DANCE,                    //춤추기
		NORMAL_AIM,               //일반 조준
		CHANGE_STAND,             //어택모션에서 스탠드로 전환하는 모션
		TICK,                     //틱오는 모션
		VICTORY,                  //승리모션
		STUN,                     //기절 모션
		FINGER_GUN,               //손가락총
		RUN,                      //달리기
		LAND,                     //착지
		RUN_AIM                   //조준 달리기
	};



public:

	Nova();
	~Nova();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void ChangeMotion(NOVASTATE _state);
	void KeyInput();
	void Action(D3DXVECTOR3 pickingPos);
	void ActionAfter();
	void SwitchOff();
	
	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2);

	Collider_Sphere* BattleCruiserBoomSphere;

private:

	NOVASTATE NovaState = STAND;

	//애니메이션 한번만 실행
	float startTimer = 0.0f;
	float aniTime = 0.0f;

	//현재 눌러진 단축키 불값
	bool isDownA = false;
	bool isDownQ = false;
	bool isDownW = false;
	bool isDownE = false;
	bool isDownR = false;
	bool isDownS = false;
	bool isDownD = false;
	bool isDownF = false;
	bool isDown5 = false;
	bool isDown6 = false;
	bool IsBattleCruiserBoomTimerOn;
	float BattleCruiserBoomTimer;
	int _NuClear;
	bool NuClearTimer;
	D3DXVECTOR3 NomalAttackPicking = D3DXVECTOR3(0,0,0);

	int i = 0;
	SkillManager* skillManager = nullptr;
	Grid* grid = nullptr;
	NuClear* nuclear = nullptr;
	Battlecruiser* battlecruiser = nullptr;
	
	NuclearExplosion* nuclearExplosion = nullptr;
	BattleCruiserBoom* battleCruiserBoom1 = nullptr;
	BattleCruiserBoom* battleCruiserBoom2 = nullptr;
	BattleCruiserBoom* battleCruiserBoom3 = nullptr;
	BattleCruiserBoom* battleCruiserBoom4 = nullptr;
	BattleCruiserBoom* battleCruiserBoom5 = nullptr;
	BattleCruiserBoom* battleCruiserBoom6 = nullptr;
	BattleCruiserBoom* battleCruiserBoom7 = nullptr;
	BattleCruiserBoom* battleCruiserBoom8 = nullptr;
	BattleCruiserBoom* battleCruiserBoom9 = nullptr;
	BattleCruiserBoom* battleCruiserBoom10 = nullptr;
	BattleCruiserBoom* battleCruiserBoom11 = nullptr;
	BattleCruiserBoom* battleCruiserBoom12 = nullptr;
	BattleCruiserBoom* battleCruiserBoom13 = nullptr;
	BattleCruiserBoom* battleCruiserBoom14 = nullptr;
	BattleCruiserBoom* battleCruiserBoom15 = nullptr;
	BattleCruiserBoom* battleCruiserBoom16 = nullptr;
	BattleCruiserBoom* battleCruiserBoom17 = nullptr;
	BattleCruiserBoom* battleCruiserBoom18 = nullptr;
	BattleCruiserBoom* battleCruiserBoom19 = nullptr;
	BattleCruiserBoom* battleCruiserBoom20 = nullptr;
	std::list<BattleCruiserBoom*> vBattleCruiserBoomList;
	NovaNomalAttack* novaNomalAttack = nullptr;


	bool isBattleCruiserMove;

public:
	inline void SetGrid(Grid* _grid){ grid = _grid; }
	inline NuClear* GetNuClear(){ return nuclear; }
	inline Battlecruiser* GetBattlecruiser() { return battlecruiser; }
	inline float GetBattleCruiserBoomTimer() { return BattleCruiserBoomTimer; }
	
};