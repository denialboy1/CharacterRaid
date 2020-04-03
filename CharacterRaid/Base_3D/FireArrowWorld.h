#pragma once
#include "FireArrow.h"
#include "FireArrowEffect.h"
#define FIREARROW_COUNT 200
class FireArrowWorld
{
public:
	FireArrowWorld();
	~FireArrowWorld();

	void Initialize();
	void Destroy();
	void Update();
	void Battle(unit* enemy);
	void Render();
	void Fire(D3DXVECTOR3 _pos);
	void Make(D3DXVECTOR3 _pos);

	void Reset();

	float GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2);
	std::list<FireArrow*>& GetMFireArrowUsed(){ return mFireArrowUsed; }
	std::list<FireArrow*>& GetMFireArrowUnUsed(){ return mFireArrowUnUsed; }
private:
	std::list< FireArrow*> mFireArrowUsed;
	std::list< FireArrow*> mFireArrowUnUsed;
	FireArrow *fireArrowAll = nullptr;
	FireArrowEffect* fireArrowEffect = nullptr;
	int power = 0;
	float speed = 3;

	float startTime = 0;
	bool isStart = false;
	bool isFire = false;

	D3DXVECTOR3 pos;

public:
	bool GetIsStart(){ return isStart; }
	void SetIsStart(bool _isStart){	isStart = _isStart;}

};

