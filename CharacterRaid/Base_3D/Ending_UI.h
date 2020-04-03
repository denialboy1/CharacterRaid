#pragma once
#include "UI_Base.h"

enum ENDING_STEP
{
	ENDING_NORMAL = 0,
	ENDING_TO_SELECT
};


class Ending_UI :
	public UI_Base
{
public:
	Ending_UI();
	virtual ~Ending_UI();

	virtual void Render() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize();
	void Update();
	bool GetOpenByStartNode(){ return openByStartNode; }
	void SetTitle(char* title);
	void SetDescription(char* desc);
	//void SetQuestStep(QUEST_STEP step);
	void SetOpenByStartNode(bool startNode){ openByStartNode = startNode; }
	void ReadData(char* inputFileName);

protected:
	enum CHILD_TYPE
	{
		IMAGE_BACKGROUND = 0,
		TEXT_TITLE,
		TEXT_DESC,
		BUTTON_OK,
		BUTTON_CANCEL,
		RANK_1
	};

	bool isDrag = false;
	POINT prevMouse;
	bool openByStartNode = true;
	SCORE_STEP EndingStep = SCORE_NORMAL;
	//int TimeOut = 0;
	char Stage1[128];
	char Stage2[128];
	char Stage3[128];

	float Stage1Out = 0;
	float Stage2Out = 0;
	float Stage3Out = 0;

	char* rankOut;
	char* rankOut2;
	char* rankOut3;
	//int LostHPOut = 0;
	//char LostHPText[128];

	UI_Image* Stage1Rank = nullptr;
	UI_Image* Stage2Rank = nullptr;
	UI_Image* Stage3Rank = nullptr;
};

