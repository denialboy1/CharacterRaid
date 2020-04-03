#pragma once
#include "unit.h"
#include "DarkBallFire.h"
#include "DarkCircle.h"
#include "bossBar.h"

//enum AZ_STATE
//{
//	ATTACK,
//	ATTACK01,
//	FIDGET,
//	FIDGET01,
//	FLAIL,
//	FLAIL_BACK,
//	FLAIL_FORWARD,
//	SPELL_A,
//	SPELL_B,
//	SPELL_C,
//	SPELL_CHANNEL,
//	SPELL_D,
//	SPELL_E,
//	SPELL_F,
//	SPELL_G,
//	SPELL_H,
//	SPELL_OMNI,
//	STAND_A,
//	STAND_ALTERNATE,
//	STAND_DANCE,
//	STAND_DANCE_S,
//	STAND_LEFT,
//	STAND_LEFT_ALTERNATE,
//	STAND_READY,
//	STAND_READY_END,
//	STAND_READY_END_S,
//	STAND_READY_S,
//	STAND_READY_START_S,
//	STAND_RIGHT,
//	STAND_RIGHT_ALTERNATE,
//	STAND_S,
//	STAND_START,
//	STAND_START_READY,
//	STAND_VICTORY,
//	STAND_WORK,
//	STAND_WORK_END,
//	STAND_WORK_START,
//	STUN,
//	TAUNT,
//	WALK_A,
//	WALK_B,
//	WALK_C,
//	WALK_D,
//	WALK_E,
//	WALK_F,
//	WALK_G,
//	WALK_H
//};


class Azmodan :
	public unit
{
	enum AZ_STATE{ STAND = 20, WALK = 39, ATTACK = 1, PATTERN1 = 11, PATTERN2 = 12, PATTERN3 = 13, PATTERN4 = 14, PATTERN5 = 15};
//public:
//	Azmodan();
//	~Azmodan();
//
//	virtual void Initialize(D3DXVECTOR3 _scale);
//	virtual void Destroy() override;
//	virtual void Update(float _timer, unit* player);
//	virtual void Render() override;
//
//	void Battle(unit& enemy);
//	void ChangeMotion(AZ_STATE _state);
//	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2);
//	void Action(float _timer, unit* player);
//
//	void Trace(unit* player);
//private:
//	float startTimer = 0.0f;
//	float aniTime = 0.0f;
//	AZ_STATE state=STAND_A;
//
//	Collider_Sphere* attackRangeSphere = nullptr;
//
//	bool isPattern1 = false;
//	bool isPattern2 = false;
//	bool isPattern3 = false;
//	bool isPattern4 = false;
//	bool isPattern5 = false;
//
//	float attackTrackSpeed = 10;
//	float walkTrackSpeed = 1;
//
//	bossBar* hpBar = nullptr;
public:
	Azmodan();
	~Azmodan();

	void Initialize();
	void Destroy();
	void Update(float _timer, unit* player);
	void Render();

	void Battle(unit& enemy);
	void ChangeMotion(AZ_STATE _state);	//상태값과 모션을 바꿔준다
	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2); //두 벡터사이의 각도 구하기
	void Action(float _timer, unit* player);

	//추적
	void Trace(unit* player);
private:
	float startTimer = 0.0f;
	float aniTime = 0.0f;
	AZ_STATE state = WALK;

	Collider_Sphere* attackRangeSphere = nullptr;

	bool isPattern1 = false;
	bool isPattern2 = false;

	float pattern1Timer = 0.0f;
	float pattern2Timer = 0.0f;
	//bool isPattern3 = false;
	//bool isPattern4 = false;
	//bool isPattern5 = false;

	float attackTrackSpeed = 5;
	float walkTrackSpeed = 0.5f;

	float revenge = 0;

	//스킬
	DarkBallFire* darkBallFire = nullptr;
	DarkCircle* darkCircle = nullptr;

	//hpBar
	bossBar* hpBar = nullptr;
public:
	//Dark_Shield* GetShield(){ return darkShield; }
	void SetRevenge(float _revenge){ revenge = _revenge; }
};
