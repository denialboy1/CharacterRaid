#pragma once
#include "UI_Base.h"

enum OPENING_STEP
{
	OPENING_NORMAL = 0,
	OPENING_TO_SELECT
};

class Opening_UI:public UI_Base
{
public:
	Opening_UI();
	virtual ~Opening_UI();

	virtual void Render() override;
	
	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void Initialize();
	void Destroy();
	void Update();
	bool GetOpenByStartNode(){ return openByStartNode; }
	//void SetTitle(char* title);
	//void SetDescription(char* desc);
	//void SetQuestStep(QUEST_STEP step);
	void SetOpenByStartNode(bool startNode){ openByStartNode = startNode; }
	//void ReadData(char* inputFileName);

	enum CHILD_TYPE
	{
		IMAGE_BACKGROUND = 0,
		BUTTON_OK,
		IMAGE_TITLE,
		IMAGE_TITLEBOARD
	};

	bool isDrag = false;
	POINT prevMouse;
	bool openByStartNode = true;
	OPENING_STEP openingStep = OPENING_NORMAL;

	UI_Image* backGround = nullptr;
	UI_Image* title = nullptr;
	UI_Button* enter = nullptr;
	//int TimeOut = 0;
	//char TimeText[128];
	//
	//int LostHPOut = 0;
	//char LostHPText[128];
};

