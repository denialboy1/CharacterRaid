#pragma once
#include "SkillObject.h"

class ShieldBash :
	public SkillObject
{
public:

	enum EFFECT_STATE
	{
		BIRTH,
		DEATH,
		STAND,
		FIRE,
		STATE_NUM
	};

	ShieldBash();
	~ShieldBash();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	void ChangeMotion(EFFECT_STATE _state);

	inline void SetIsAnimInit(bool _IsAnimInit){ IsAnimInit = _IsAnimInit; }
private:
	EFFECT_STATE state = BIRTH;
	bool IsAnimInit = false;
};

