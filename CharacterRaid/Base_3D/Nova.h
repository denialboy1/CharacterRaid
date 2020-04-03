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
		MOTION_1,                 //����ϴµ��� ���
		MOTION_2,                 //������ �ݴµ��� ���
		MOTION_3,                 //������Ÿ��� ���
		MOTION_4,                 //�տ��� �������� ���
		MOTION_5,                 //�ڿ��� �������� ���
		SKILL_1,                  //��ų1
		SKILL_2,                  //��ų2
		MOTION_6,                 //�����ϴ� ���
		MOTION_7,                 //�����϶�� ��ɳ����� ���
		HOLOSIGHT_SHOT,           //���ذ波�� ��Ÿ(���� ����)
		MOTION_9,                 //���1
		MOTION_10,                //���2
		STAND,                    //���ĵ���
		STAND_SEARCH,             //�θ����Ÿ��� ���ĵ� ���
		HOLOSIGHT_AIM,            //���ذ波�� ���ػ���
		HOLOSIGHT_UP,             //���ذ� Ǯ�� ���� ����
		HOLOSIGHT_DOWN,           //���ذ� ���� �ɴ� ����
		DANCE,                    //���߱�
		NORMAL_AIM,               //�Ϲ� ����
		CHANGE_STAND,             //���ø�ǿ��� ���ĵ�� ��ȯ�ϴ� ���
		TICK,                     //ƽ���� ���
		VICTORY,                  //�¸����
		STUN,                     //���� ���
		FINGER_GUN,               //�հ�����
		RUN,                      //�޸���
		LAND,                     //����
		RUN_AIM                   //���� �޸���
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

	//�ִϸ��̼� �ѹ��� ����
	float startTimer = 0.0f;
	float aniTime = 0.0f;

	//���� ������ ����Ű �Ұ�
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