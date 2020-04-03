#include "stdafx.h"
#include "CalcScore.h"


CalcScore::CalcScore()
{
}


CalcScore::~CalcScore()
{
}

void CalcScore::Calculation(float _time, int _LostHP)
{
	
	ZeroMemory(&sc, sizeof(scStruct));
	sc.time = _time;
	sc.LostHP= _LostHP;

	//점수계산
	sc.score = 100 - (sc.time / 5) - (sc.LostHP);

	//랭크 계산
	if (sc.score <= 100 || sc.score >= 80)
	{
		strcpy_s(sc.rank, "S");
	}
	else if (sc.score < 80 || sc.score >= 60)
	{
		strcpy_s(sc.rank, "A");
	}
	else if (sc.score < 60 || sc.score >= 40)
	{
		strcpy_s(sc.rank, "B");
	}
	else if (sc.score < 40 || sc.score >= 20)
	{
		strcpy_s(sc.rank, "C");
	}
	else
	{
		strcpy_s(sc.rank, "F");
	}

	
	

}

void CalcScore::ScoreSave(){
	switch (iniDataManager::Get().loadDataInterger("player", "Player", "Stage")){
	case 1:
		iniDataManager::Get().addData("Stage1", "Time", sc.rank);
		iniDataManager::Get().addData("Stage1", "LostHp", sc.rank);
		iniDataManager::Get().addData("Stage1", "Score", sc.rank);
		iniDataManager::Get().addData("Stage1", "Rank", sc.rank);

		iniDataManager::Get().addData("Stage2", "Time", "0");
		iniDataManager::Get().addData("Stage2", "LostHp", "0");
		iniDataManager::Get().addData("Stage2", "Score", "0");
		iniDataManager::Get().addData("Stage2", "Rank", "0");

		iniDataManager::Get().addData("Stage3", "Time", "0");
		iniDataManager::Get().addData("Stage3", "LostHp", "0");
		iniDataManager::Get().addData("Stage3", "Score", "0");
		iniDataManager::Get().addData("Stage3", "Rank", "0");
		break;
	case 2:
		iniDataManager::Get().addData("Stage1", "Time", iniDataManager::Get().loadDataString("Score", "Score", "Time").c_str());
		iniDataManager::Get().addData("Stage1", "LostHp", iniDataManager::Get().loadDataString("Score", "Score", "LostHp").c_str());
		iniDataManager::Get().addData("Stage1", "Score", iniDataManager::Get().loadDataString("Score", "Score", "Score").c_str());
		iniDataManager::Get().addData("Stage1", "Rank", iniDataManager::Get().loadDataString("Score", "Score", "Rank").c_str());

		iniDataManager::Get().addData("Stage2", "Time", sc.rank);
		iniDataManager::Get().addData("Stage2", "LostHp", sc.rank);
		iniDataManager::Get().addData("Stage2", "Score", sc.rank);
		iniDataManager::Get().addData("Stage2", "Rank", sc.rank);

		iniDataManager::Get().addData("Stage3", "Time", "0");
		iniDataManager::Get().addData("Stage3", "LostHp", "0");
		iniDataManager::Get().addData("Stage3", "Score", "0");
		iniDataManager::Get().addData("Stage3", "Rank", "0");
		break;
	case 3:
		iniDataManager::Get().addData("Stage1", "Time", iniDataManager::Get().loadDataString("Score", "Score", "Time").c_str());
		iniDataManager::Get().addData("Stage1", "LostHp", iniDataManager::Get().loadDataString("Score", "Score", "LostHp").c_str());
		iniDataManager::Get().addData("Stage1", "Score", iniDataManager::Get().loadDataString("Score", "Score", "Score").c_str());
		iniDataManager::Get().addData("Stage1", "Rank", iniDataManager::Get().loadDataString("Score", "Score", "Rank").c_str());

		iniDataManager::Get().addData("Stage2", "Time", iniDataManager::Get().loadDataString("Score", "Score", "Time").c_str());
		iniDataManager::Get().addData("Stage2", "LostHp", iniDataManager::Get().loadDataString("Score", "Score", "LostHp").c_str());
		iniDataManager::Get().addData("Stage2", "Score", iniDataManager::Get().loadDataString("Score", "Score", "Score").c_str());
		iniDataManager::Get().addData("Stage2", "Rank", iniDataManager::Get().loadDataString("Score", "Score", "Rank").c_str());

		iniDataManager::Get().addData("Stage3", "Time", sc.rank);
		iniDataManager::Get().addData("Stage3", "LostHp", sc.rank);
		iniDataManager::Get().addData("Stage3", "Score", sc.rank);
		iniDataManager::Get().addData("Stage3", "Rank", sc.rank);
		
		break;
	}

	iniDataManager::Get().iniSave("Score");
}