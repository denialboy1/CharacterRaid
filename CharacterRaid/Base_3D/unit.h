
#pragma once
#include "GameObject.h"
#include "SkinnedMesh.h"
#include "PathFinder.h"

class unit : public GameObject
{
public:
	unit();
	~unit();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;

	virtual void Battle(unit& enemy);
	virtual void removeAction();
	virtual void DirectionUpdate();
protected:
	//ĳ���� ����
	float hp = 0;
	float hpMax = 0;
	float mp = 0;
	float mpMax = 0;

	float attackRange = 0;
	float moveSpeed = 0;
	float moveAccelerate = 0;					 //������ ���ӵ�
	float armor = 0;
	float attack = 0;
	bool isDamaged = false;						// �ǰݴ��ߴ��� ����
	bool isInvincible = false;					// ĳ���� ����

	bool isIdle = false;
	//ĳ���� ��
	SkinnedMesh* mesh = nullptr;

	//�浹
	Collider_Sphere* collision = nullptr;
	cOBB* obb;
	PathFinder* pathFinder = nullptr;
public: 
	//����,���� 
	float GetHp(){ return hp; }
	void SetHp(float _hp){ hp = _hp; }
	float GetMaxHp(){ return hpMax; }
	void SetMaxHp(float _maxHp){hpMax = _maxHp;	}
	float GetMp(){ return mp; }
	void SetMp(float _mp){ mp = _mp; }
	float GetMaxMp(){ return mpMax; }
	void SetMaxMp(float _maxMp){ mpMax = _maxMp; }
	float GetAttackRange(){ return attackRange; }
	void SetAttackRange(float _attackRange){ attackRange = _attackRange; }
	float GetMoveSpeed(){ return moveSpeed; }
	void SetMoveSpeed(float _moveSpeed){ moveSpeed = _moveSpeed; }
	float GetMoveAccelate() { return moveAccelerate; }
	void SetMoveAccelerate(float _moveAccelerate){ moveAccelerate = _moveAccelerate; }
	float GetArmor(){ return armor; }
	void SetArmor(float _armor){ armor = _armor; }
	float GetAttack(){ return attack; }
	void SetAttack(float _attack){ attack = _attack; }
	bool GetIsDamaged(){ return isDamaged; }
	void SetIsDamaged(bool _isDamaged){ isDamaged = _isDamaged; }
	bool GetIsIdle(){ return isIdle; }
	void SetIsIdle(bool _isIdle){ isIdle = _isIdle; }

	SkinnedMesh* GetSkinedMesh(){ return mesh; }
	Collider_Sphere* GetCollision(){ return collision; }

	inline cOBB* GetObbBox(){ return obb; }

	inline void SetPathFinder(PathFinder* _pathFinder){ pathFinder = _pathFinder; }

	bool GetIsInvincible(){ return isInvincible; }
};

