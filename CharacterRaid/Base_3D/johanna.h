#pragma once
#include "player.h"
#include "SkinnedMesh.h"
#include "Grid.h"
#define Q_SKILL_COOLTIME 15.0f
#define W_SKILL_COOLTIME 45.0f
#define E_SKILL_COOLTIME 30.0f
#define R_SKILL_COOLTIME 90.0f

#define W_SKILL_TIME 15.0f
#define R_SKILL_TIME 45.0f

enum STATE
{
	STATE_ATTACK_1=0,
	STATE_ATTACK_2,
	STATE_ATTACK_3,
	STATE_ATTACK_4,
	STATE_ATTACK_5,
	STATE_CHANNEL_HEARTH,
	STATE_CHANNEL_INTERACT,
	STATE_CHANNEL_MOUNT,
	STATE_FLAIL,
	STATE_FLAIL_BACK,
	STATE_FLAIL_FORWARD,
	STATE_SPELL_A,
	STATE_SPELL_C,
	STATE_SPELL_CHANNEL,
	STATE_SPELL_D_END,
	STATE_SPELL_D_START,
	STATE_SPELL_E,
	STATE_SPELL_F,
	STATE_SPELL_FORWARD,
	STATE_SPELL_OMNI,
	STATE_STAND,
	STATE_STAND_01,
	STATE_STAND_DANCE,
	STATE_STAND_DANCE_S,
	STATE_STAND_READY,
	STATE_STAND_READY_END,
	STATE_STAND_READY_END_S,
	STATE_STAND_READY_S,
	STATE_STAND_READY_START_S,
	STATE_STAND_S,
	STATE_STAND_S_01,
	STATE_STAND_START,
	STATE_STAND_VICTORY,
	STATE_STUN,
	STATE_TAUNT,
	STATE_WALK_A,
	STATE_WALK_A_READY,
	STATE_WALK_A_2
};
enum ATTACK_STATE
{
	STATE_NORMAL_ATTACK,
	STATE_SKILL_1,
	STATE_SKILL_2,
	STATE_SKILL_3,
	STATE_SKILL_4,
	STATE_END
};
class johanna :
	public player
{
public:
	johanna();
	~johanna();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Battle(unit& enemy);
	void ChangeMotion(STATE _state);
	void KeyInput();
	void Action(D3DXVECTOR3 clickPos);	 //�ִϸ��̼� �����̱�
	void ActionAfter(); //�ִϸ��̼� ������ ��
	void SwitchOff();
	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2); //�� ���ͻ����� ���� ���ϱ�

	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	inline void SetGrid(Grid* _grid){ grid = _grid; }
	
	void DataLoad();
	void DataSave();

private:
	int stage = 0;
	Collider_Sphere* attackSphere = nullptr;
	
	ATTACK_STATE attack_state = STATE_END;
	STATE state = STATE_STAND;

	float aniTime = 0.0f;
	float startTimer = 0.0f;
	D3DXVECTOR3 object = D3DXVECTOR3(0, 0, 0);;
	Grid* grid = nullptr;

	float SkillQCoolTimer = 0.0f;
	float SkillWCoolTimer = 0.0f;
	float SkillECoolTimer = 0.0f;
	float SkillRCoolTimer = 0.0f;

	float WSkillTimer = 0.0f;
	float RSkillTimer = 0.0f;


	//����Ƚ�� ����
	int HitCounter = 0;

	//��Ʈ ���Ǿ Ÿ���� ���Ǵ°� �ȵǴ°� üũ
	bool hitable = false;

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

	//W��ų�� ���Ǿ��°� üũ
	bool OnSkillW = false;
	bool OnSkillR = false;
	//W��ų ��밡�� ���� üũ
	bool UsableSkillQ = true;
	bool UsableSkillW = true;
	bool UsableSkillE = true;
	bool UsableSkillR = true;

	char timer[128];

	D3DXVECTOR3 goal = { 0, 0, 0 };
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
};

