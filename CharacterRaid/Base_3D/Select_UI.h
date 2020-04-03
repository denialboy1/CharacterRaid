#pragma once
#include "UI_Base.h"

enum SELECT_STEP
{
	SELECT_NORMAL = 0,
	SELECT_NOVA,
	SELECT_JOHANNA,
	SELECT_JAINA
};

class Select_UI :
	public UI_Base
{
public:
	Select_UI();
	virtual ~Select_UI();

	void Initialize();
	void Destroy();
	void Update();
	void Render();
	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	void SetSelectStep(SELECT_STEP _selectStep){ selectStep = _selectStep; }

	bool GetOpenByStartNode(){ return openByStartNode; }
	void SetTitle(char* title);
	void SetDescription(char* desc);
	void SetQuestStep(QUEST_STEP step);
	void SetOpenByStartNode(bool startNode){ openByStartNode = startNode; }
	//void ReadData(char* inputFileName);

	enum CHILD_TYPE
	{
		IMAGE_BACKGROUND = 0,
		TEXT_TITLE,
		TEXT_INTRO,
		BUTTON_NOVA,
		BUTTON_JOHANNA,
		BUTTON_JAINA
	};

private:

	bool isDrag = false;
	POINT prevMouse;
	bool openByStartNode = true;
	SELECT_STEP selectStep = SELECT_NORMAL;
	UI_Image* backGround = nullptr;
	UI_Button* nova = nullptr;
	UI_Button* johanna = nullptr;
	UI_Button* jaina = nullptr;
	UI_Text* intro = nullptr;

	char Text[1024];
};

