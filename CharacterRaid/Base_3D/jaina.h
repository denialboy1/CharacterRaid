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

	//���°��� ����� �ٲ��ش�
	void ChangeMotion(STATE _state);
	void KeyInput();
	void Action(D3DXVECTOR3 clickPos);	 //�ִϸ��̼� �����̱�
	void ActionAfter(); //�ִϸ��̼� ������ ��
	void SwitchOff();
	float GetAngle(D3DXVECTOR3 v1,D3DXVECTOR3 v2); //�� ���ͻ����� ���� ���ϱ�

	void DataLoad();
	void DataSave();
private:
	int stage = 0;
	//ĳ���� ����
	STATE state = STAND01;

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

	int i = 0;

	//���콺 �̵�
	Grid* grid = nullptr; //��ŷ������ ����
	D3DXVECTOR3 goal = { 0, 0, 0 };

	//��ų
	SkillManager* skillManager = nullptr;

	//E��ų ��Ÿ��
	float eSkillCoolTimer = 0;
	float rSkillCoolTimer = 0;

	//R��ų ��Ÿ��

	//������
	bool isAttackBuff = false;
	float attackBuffStartTimer = 0;

	bool isArmorBuff = false;
	float armorBuffStartTimer = 0;

	bool isInvincibleItem = false;
	float invincibleItemStartTimer = 0;

	bool isStunItem = false;
	bool isStunItemClick = false;
	Collider_Sphere* stunItemSphere = nullptr;

	//��Ƽ��Ʈ
	bool isSpeedArt = false;
	float speedArtStartTimer = 0;

	bool isInvincibleArt = false;
	bool isInvincibleArtCoolTime = false;
	float invincibleArtStartTimer = 0;
	float invincibleArtCoolTime = 0;

	//��ȯ ���ǵ�
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

