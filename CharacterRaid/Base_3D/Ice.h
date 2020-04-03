#pragma once
#include "SkillObject.h"
class Ice : public SkillObject
{
public:
	enum ICE_STATE{ BIRTH, DEATH, STAND,FIRE,FIND_ANGLE,MOVE, STATE_NUM };

	Ice();
	~Ice();

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

	//�ִϸ��̼� ������� ����
	float startTimer = 0.0f;
	float aniTime = 0.0f;

	//�ñر� ���� ���� Ȯ��
	bool isUltimate = false;

	bool isUsed = false;


	//����ã��
	D3DXVECTOR3 start = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 goal = D3DXVECTOR3(0, 0, 0);

	float passedTime = 0.0f;
	float durationTime = 3.0f;

	float passedTime1 = 0.0f;
	float durationTime1 = 3.0f;

	float goalAngle = 0.0f;
	float startAngle = 0.0f;
public :
	void SetState(ICE_STATE _state){ state = _state; }
	void SetIsUltimate(bool _isUltimate){ isUltimate = _isUltimate; }
	bool GetIsUltimate(){ return isUltimate; }
	void SetIsUsed(bool _isUsed){ isUsed = _isUsed; }
	bool GetIsUsed(){ return isUsed; }
};

