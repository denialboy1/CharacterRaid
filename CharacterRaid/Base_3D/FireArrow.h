#pragma once
#include "SkillObject.h"
class FireArrow : public SkillObject
{
	
public:
	enum ICE_STATE{ BIRTH, DEATH, STAND, FIRE, FIND_ANGLE, MOVE, STATE_NUM };

	FireArrow();
	~FireArrow();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	void ChangeMotion(ICE_STATE _state);
	void FindDirection();
	void FindAngle(D3DXVECTOR3 _startPos, D3DXVECTOR3 _goal, float _startAngle);
	void Move();
	void Reset();
private:
	ICE_STATE state = BIRTH;

	//애니메이션 실행관련 변수
	float startTimer = 0.0f;
	float aniTime = 0.0f;

	//궁극기 전용 얼음 확인
	bool isUltimate = false;

	bool isUsed = false;


	//방향찾기
	D3DXVECTOR3 start = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 goal = D3DXVECTOR3(0, 0, 0);

	float passedTime = 0.0f;
	float durationTime = 3.0f;

	float passedTime1 = 0.0f;
	float durationTime1 = 3.0f;

	float goalAngle = 0.0f;
	float startAngle = 0.0f;
public:
	void SetFindAngle(){ state = FIND_ANGLE; }
	void SetMove(){ state = MOVE; }
	void SetStand(){ state = STAND; }
	void SetIsUltimate(bool _isUltimate){ isUltimate = _isUltimate; }
	bool GetIsUltimate(){ return isUltimate; }
	void SetIsUsed(bool _isUsed){ isUsed = _isUsed; }
	bool GetIsUsed(){ return isUsed; }
};

