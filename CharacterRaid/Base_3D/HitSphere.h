#pragma once
#include "SkillObject.h"
class HitSphere :
	public SkillObject
{
public:
	HitSphere();
	~HitSphere();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	void FindDirection();
	void FindAngle(D3DXVECTOR3 _startPos, D3DXVECTOR3 _goal, float _startAngle);
	void Reset();
private:
	float startTimer = 0.0f;
	float aniTime = 0.0f;

	bool isUsed = false;

	D3DXVECTOR3 start = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 goal = D3DXVECTOR3(0, 0, 0);

	float passedTime = 0.0f;
	float durationTime = 3.0f;
	
	float passedTime1 = 0.0f;
	float durationTime1 = 3.0f;
	
	float goalAngle = 0.0f;
	float startAngle = 0.0f;

public:
	void SetIsUsed(bool _isUsed){ isUsed = _isUsed; }
	bool GetIsUsed(){ return isUsed; }
};

