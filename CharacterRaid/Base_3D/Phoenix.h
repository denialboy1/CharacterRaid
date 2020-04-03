#pragma once
#include "unit.h"
#include "Phoenix_Circle.h"
#include "minionHpBar.h"
#include "Burn.h"
class player;

enum PHOENIX_STATE{ STAND,WALK, TRACE, TRACE_AFTER };

class Phoenix : public unit
{
	
public:
	Phoenix();
	~Phoenix();

	virtual void Initialize(D3DXVECTOR3 _scale);
	virtual void Destroy() override;
	virtual void Update(unit* _enemy);
	virtual void Render() override;
	
	virtual void Battle(unit* _enemy);

	void Start(){ action->Start(); }
	void Trace( unit* _enemy);

	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2); //두 벡터사이의 각도 구하기

private:
	D3DXVECTOR3 startPosition;
	Collider_Sphere* traceRange = nullptr;

	PHOENIX_STATE state = WALK;
	Phoenix_Circle* circle = nullptr;
	minionHpBar* hpBar = nullptr;
	Burn* burn = nullptr;

	bool isDeath = false;
public:
	void SetStartPosition(D3DXVECTOR3 _pos){ startPosition = _pos; }
	D3DXVECTOR3 GetStartPosition(){ return startPosition; }
	void SetState(PHOENIX_STATE _state){ state = _state; }
	PHOENIX_STATE GetState(){ return state; }

};

