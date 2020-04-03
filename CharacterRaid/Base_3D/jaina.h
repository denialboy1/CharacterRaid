#pragma once
#include "player.h"
#include "SkinnedMesh.h"
#include "SkillManager.h"
#include "Grid.h"

#include "IceEffect.h"
#include "mpRegion.h"
#include "InvincibleEffect.h"
#include "blinkEffect.h"
#include "Heal.h"

class Jaina :
	public player
{
	enum STATE{
		ATTACK01,
		SPELL_A,
		ATTACK03,
		ATTACK04,
		ATTACK05,
		ATTACK06,
		FIDGET01,
		FIDGET02,
		FIDGET03,
		FIDGET04,
		FLAIL,
		FLAIL_BACK,
		FLAIL_FORWARD,
		GLSTAND,
		ATTACK02,
		SPELL_F,
		SPELL_C,
		SPELL_C_ALTERNATE,
		SPELL_CHANNEL,
		SPELL_D,
		SPELL_B,
		SPELL_FORWARD,
		SPELL_G,
		SPELL_OMNI,
		STAND01,
		STAND02,
		STAND03,
		STAND_DANCE,
		STAND_READY,
		STAND_READY_END,
		STAND_READY_END_S,
		STAND_READY_S,
		STAND_READY_START_S,
		STAND_S,
		STAND_START,
		STAND_START_READY,
		STAND_VICTORY,
		STUN,
		TAUNT,
		WALK,
		STATE_NUM,
	};


public:
	Jaina();
	~Jaina();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Battle(unit& enemy);

	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//상태값과 모션을 바꿔준다
	void ChangeMotion(STATE _state);
	void KeyInput();
	void Action(D3DXVECTOR3 clickPos);	 //애니메이션 움직이기
	void ActionAfter(); //애니메이션 움직인 후
	void SwitchOff();
	float GetAngle(D3DXVECTOR3 v1,D3DXVECTOR3 v2); //두 벡터사이의 각도 구하기

	void DataLoad();
	void DataSave();
private:
	int stage = 0;
	//캐릭터 상태
	STATE state = STAND01;

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

	int i = 0;

	//마우스 이동
	Grid* grid = nullptr; //피킹을위해 깔음
	D3DXVECTOR3 goal = { 0, 0, 0 };

	//스킬
	SkillManager* skillManager = nullptr;

	//E스킬 쿨타임
	float eSkillCoolTimer = 0;
	float rSkillCoolTimer = 0;

	//R스킬 쿨타임

	//아이템
	bool isAttackBuff = false;
	float attackBuffStartTimer = 0;

	bool isArmorBuff = false;
	float armorBuffStartTimer = 0;

	bool isInvincibleItem = false;
	float invincibleItemStartTimer = 0;

	bool isStunItem = false;
	bool isStunItemClick = false;
	Collider_Sphere* stunItemSphere = nullptr;

	//아티팩트
	bool isSpeedArt = false;
	float speedArtStartTimer = 0;

	bool isInvincibleArt = false;
	bool isInvincibleArtCoolTime = false;
	float invincibleArtStartTimer = 0;
	float invincibleArtCoolTime = 0;

	//소환 스피드
	float iceBirthSpeed = 3;

	std::vector<IceEffect*> vIceEffect;

	mpRegion* mpRe = nullptr;
	InvincibleEffect* invincibleEffect = nullptr;
	std::vector<blinkEffect*> vBlinkEft;
	Heal* healEffect = nullptr;

	bool isInvincibleSkill = false;
	float invincibleSkill = 0.0f;

	
public:
	inline void SetGrid(Grid* _grid){ grid = _grid; }
	inline SkillManager* GetSkillManager(){ return skillManager; }


	float& GeteSkillCoolTimer(){ return eSkillCoolTimer; }
	float& GetrSkillCoolTimer(){ return rSkillCoolTimer; }
	
	
	
};

