#pragma once
#include "unit.h"
#include "SkillManager.h"
#include "FireCircleWorld.h"
#include "FireBallFire.h"
#include "Fire_Shield.h"
#include "FireArrowWorld.h"
#include "bossBar.h"
#include "BossDeath.h"
class Kealthas :
	public unit
{
	enum KEALTHAS_STATE{STAND=20,WALK=38,ATTACK=0,PATTERN1=11,PATTERN2=12,PATTERN3=13,PATTERN4=14,PATTERN5=15,DEATH=16};
public:
	Kealthas();
	~Kealthas();

	void Initialize();
	void Destroy();
	void Update(float _timer,unit* player);
	void Render();

	void Battle(unit& enemy);
	void ChangeMotion(KEALTHAS_STATE _state);	//���°��� ����� �ٲ��ش�
	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2); //�� ���ͻ����� ���� ���ϱ�
	void Action(float _timer, unit* player);

	//����
	void Trace(unit* player);
private:
	float startTimer = 0.0f;
	float aniTime = 0.0f;
	KEALTHAS_STATE state = WALK;

	Collider_Sphere* attackRangeSphere = nullptr;

	//����1
	bool isPattern1 = false;
	float pattern1Timer = 0.0f;
	
	bool isPattern2 = false;
	bool isPattern3 = false;
	bool isPattern4 = false;
	float pattern4Timer = 0.0f;
	bool isPattern5 = false;

	float attackTrackSpeed = 5;
	float walkTrackSpeed = 1;

	float revenge = 0;

	//��ų
	FireBallFire* fireBallFire = nullptr;
	FireCircleWorld* fireCircleWorld = nullptr;
	Fire_Shield* shield = nullptr;
	FireArrowWorld* fireArrowWorld = nullptr;

	//hpBar
	bossBar* hpBar = nullptr;

	//revengeHp
	float revengeHp = 0;

	BossDeath* deathEffect = nullptr;
public:
	Fire_Shield* GetShield(){ return shield; }
	void SetRevenge(float _revenge){ revenge = _revenge; }
};

