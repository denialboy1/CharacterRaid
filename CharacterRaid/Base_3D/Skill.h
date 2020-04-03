#pragma once
class Skill
{
public:
	Skill(){}
	~Skill(){}

protected:
	float coolTime;
	float castingTime;
	float durationTime;
	int MPConsumption;
};

