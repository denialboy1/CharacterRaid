#pragma once
#include "unit.h"

class VikingEnemy : public unit
{
public:
	VikingEnemy();
	~VikingEnemy();

	virtual void Initialize(D3DXVECTOR3 _scale);
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render() override;

	Collider_Sphere* MoveSphere = nullptr;
	Collider_Sphere* AttackSphere = nullptr;
	//Collider_Sphere* WithSphere = nullptr;
	bool IsAttack;

	void Battle(unit& vikingEnemy);
	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2);

	void SetGoal(D3DXVECTOR3 _goal){ goal = _goal; }
	D3DXVECTOR3 GetGoal(){ return goal; }
	float damageTimer = 0;
	bool IsDamageTimer= false;
	//bool IsAttack;
private:
	D3DXVECTOR3 goal = D3DXVECTOR3(0, 0, 0);
};



