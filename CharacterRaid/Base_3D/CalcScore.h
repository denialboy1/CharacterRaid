#pragma once
#include <vector>

struct scStruct
{
	float time;
	int LostHP;		//�ǰ�Ƚ��
	float score;
	char rank[4];
};
class CalcScore
{
public:
	CalcScore();
	~CalcScore();

	void Calculation(float _time, int _LostHP);
	void ScoreSave();
	scStruct GetSC(){ return sc; }
private:
	scStruct sc;
};