#pragma once
#include "UI_Base.h"

enum SCORE_STEP
{
	SCORE_NORMAL = 0,
	SCORE_TO_SELECT
};


class Score_UI :
	public UI_Base
{
public:
	Score_UI();
	virtual ~Score_UI();

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
		BUTTON_CANCEL
	};

	bool isDrag = false;
	POINT prevMouse;
	bool openByStartNode = true;
	SCORE_STEP scoreStep = SCORE_NORMAL;
	int TimeOut = 0;
	char TimeText[128];

	int LostHPOut = 0;
	char LostHPText[128];
};

