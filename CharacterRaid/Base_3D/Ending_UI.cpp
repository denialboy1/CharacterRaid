#include "stdafx.h"
#include "Ending_UI.h"


Ending_UI::Ending_UI()
{
}


Ending_UI::~Ending_UI()
{
}

void Ending_UI::Initialize()
{
	UI_Image* backGround = new UI_Image;
	backGround->SetTexture("./UI/Ending.jpg");
	backGround->SetPosition(0, 0, 0);
	backGround->SetSize(1600, 900);
	this->size = backGround->GetSize();
	this->AddChild(backGround);

	UI_Text* TitleText = new UI_Text;
	TitleText->SetFont(UI_Manager::GetFont());
	TitleText->SetSize(600, 100);
	TitleText->SetPosition((backGround->GetSize().x - TitleText->GetSize().x) / 2, 120, 0);
	TitleText->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
	TitleText->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
	TitleText->SetID(TEXT_TITLE);
	this->AddChild(TitleText);

	UI_Text* DescText = new UI_Text;
	DescText->SetFont(UI_Manager::GetFont());
	DescText->SetPosition(600, 400, 0);
	DescText->SetSize(312, 300);
	DescText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
	DescText->SetTextFormat(DT_LEFT | DT_VCENTER | DT_WORDBREAK);

	DescText->SetID(TEXT_DESC);
	this->AddChild(DescText);

	UI_Button* buttonOK = new UI_Button;
	buttonOK->SetTexture("UI/Button_Up.png", "UI/Button_Ov er.png", "UI/Button_Down.png");
	buttonOK->SetPosition((backGround->GetSize().x) / 2, backGround->GetSize().y - 120, 0);
	buttonOK->SetID(BUTTON_OK);
	buttonOK->OnClick = std::bind(&UI_Functions::ButtonStep, std::ref(UI_Manager::Get().func), buttonOK, SCORE_TO_SELECT);
	this->AddChild(buttonOK);

	//ReadData("./Data/TXT/Data.txt");

	isShow = true;


	CalcScore* calc = new CalcScore;
	sprintf_s(Stage1, "Stage1 Rank");
	Stage1Rank = new UI_Image;
	
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage1", "Rank").c_str(), "S") == 0)
	{
		
		Stage1Rank->SetTexture("./UI/Rank_S.png");
		Stage1Rank->SetPosition(800, 250, 0);
		Stage1Rank->SetSize(130, 120);
		Stage1Rank->SetShow(false);
		this->size = Stage1Rank->GetSize();
		this->AddChild(Stage1Rank);
	}

	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage1", "Rank").c_str(), "A") == 0)
	
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Score", "Rank").c_str(), "A") == 0)
	
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage1", "Rank").c_str(), "A") == 0)
	{
		Stage1Rank->SetTexture("./UI/Rank_A.png");
		Stage1Rank->SetPosition(400, 250, 0);
		Stage1Rank->SetSize(130, 120);
		Stage1Rank->SetShow(false);
		this->size = Stage1Rank->GetSize();
		this->AddChild(Stage1Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage1", "Rank").c_str(), "B") == 0)
	{
		Stage1Rank->SetTexture("./UI/Rank_B.png");
		Stage1Rank->SetPosition(800, 250, 0);
		Stage1Rank->SetSize(130, 120);
		Stage1Rank->SetShow(false);
		this->size = Stage1Rank->GetSize();
		this->AddChild(Stage1Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage1", "Rank").c_str(), "C") == 0)
	{
		Stage1Rank->SetTexture("./UI/Rank_C.png");
		Stage1Rank->SetPosition(800, 250, 0);
		Stage1Rank->SetSize(130, 120);
		Stage1Rank->SetShow(false);
		this->size = Stage1Rank->GetSize();
		this->AddChild(Stage1Rank);
	}


	sprintf_s(Stage2, "Stage2 Rank");
	Stage2Rank = new UI_Image;
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage2", "Rank").c_str(), "S") == 0){
		Stage2Rank->SetTexture("./UI/Rank_S.png");
		Stage2Rank->SetPosition(800, 400, 0);
		Stage2Rank->SetSize(130, 120);
		Stage2Rank->SetShow(false);
		this->size = Stage2Rank->GetSize();
		this->AddChild(Stage2Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage2", "Rank").c_str(), "A") == 0){
		Stage2Rank->SetTexture("./UI/Rank_A.png");
		Stage2Rank->SetPosition(800, 400, 0);
		Stage2Rank->SetSize(130, 120);
		Stage2Rank->SetShow(false);
		this->size = Stage2Rank->GetSize();
		this->AddChild(Stage2Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage2", "Rank").c_str(), "B") == 0){
		Stage2Rank->SetTexture("./UI/Rank_B.png");
		Stage2Rank->SetPosition(800, 400, 0);
		Stage2Rank->SetSize(130, 120);
		Stage2Rank->SetShow(false);
		this->size = Stage2Rank->GetSize();
		this->AddChild(Stage2Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage2", "Rank").c_str(), "C") == 0){
		Stage2Rank->SetTexture("./UI/Rank_C.png");
		Stage2Rank->SetPosition(800, 400, 0);
		Stage2Rank->SetSize(130, 120);
		Stage2Rank->SetShow(false);
		this->size = Stage2Rank->GetSize();
		this->AddChild(Stage2Rank);
	}


	sprintf_s(Stage3, "Stage3 Rank");
	Stage3Rank = new UI_Image;
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage3", "Rank").c_str(), "S") == 0){
		Stage3Rank->SetTexture("./UI/Rank_S.png");
		Stage3Rank->SetPosition(800, 550, 0);
		Stage3Rank->SetSize(130, 120);
		Stage3Rank->SetShow(false);
		this->size = Stage3Rank->GetSize();
		this->AddChild(Stage3Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage3", "Rank").c_str(), "A") == 0){
		Stage3Rank->SetTexture("./UI/Rank_A.png");
		Stage3Rank->SetPosition(800, 550, 0);
		Stage3Rank->SetSize(130, 120);
		Stage3Rank->SetShow(false);
		this->size = Stage3Rank->GetSize();
		this->AddChild(Stage3Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage3", "Rank").c_str(), "B") == 0){
		
		Stage3Rank->SetTexture("./UI/Rank_B.png");
		Stage3Rank->SetPosition(800, 550, 0);
		Stage3Rank->SetSize(130, 120);
		Stage3Rank->SetShow(false);
		this->size = Stage3Rank->GetSize();
		this->AddChild(Stage3Rank);
	}
	if (strcmp(iniDataManager::Get().loadDataString("Score", "Stage3", "Rank").c_str(), "C") == 0){
		Stage3Rank->SetTexture("./UI/Rank_C.png");
		Stage3Rank->SetPosition(800, 550, 0);
		Stage3Rank->SetSize(130, 120);
		Stage3Rank->SetShow(false);
		this->size = Stage3Rank->GetSize();
		this->AddChild(Stage3Rank);
	}
}
void Ending_UI::Update()
{
	if (isShow != true)
	{
		return;
	}
	switch (EndingStep)
	{
	case SCORE_NORMAL:
		break;
	case SCORE_TO_SELECT:
		GameStateManager::Get().ChangeGameState(STATE_SELECT);
		break;
	}
	Stage1Rank->SetShow(true);
	Stage2Rank->SetShow(true);
	Stage3Rank->SetShow(true);
	UI_Base::Update();
}
void Ending_UI::Render()
{
	if (isShow != true)
	{
		return;
	}
	RECT rc = { 150, 300, 550, 450 };
	UI_Manager::GetFont()->DrawTextA(NULL, Stage1, strlen(Stage1), &rc, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

	RECT rc2 = { 150, 450, 550, 550 };
	UI_Manager::GetFont()->DrawTextA(NULL, Stage2, strlen(Stage2), &rc2, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

	RECT rc3 = { 150, 600, 550, 550 };
	UI_Manager::GetFont()->DrawTextA(NULL, Stage3, strlen(Stage3), &rc3, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

	UI_Base::Render();
}

void Ending_UI::SetTitle(char* title)
{
	UI_Text* titleUI = (UI_Text*)GetChildByID(TEXT_TITLE);
	titleUI->SetText(title);
}

void Ending_UI::SetDescription(char* desc)
{
	UI_Text* descUI = (UI_Text*)GetChildByID(TEXT_DESC);
	descUI->SetText(desc);

	
	//UI_Image* StageTotalRank = new UI_Image;
	//StageTotalRank->SetTexture("./UI/Rank_S.png");
	//StageTotalRank->SetPosition(0, 0, 0);
	//StageTotalRank->SetSize(1600, 900);
	//this->size = StageTotalRank->GetSize();
	//this->AddChild(StageTotalRank);

}

//void Score_UI::SetQuestStep(QUEST_STEP step)
//{
//	switch (step)
//	{
//	case QUEST_NOT_ACCEPT:
//		SetDescription("왼쪽 블럭을 클릭해보자.");
//		break;
//	case QUEST_ACCEPT:
//		SetDescription("왼쪽 블럭을 클릭해보자.\n(진행중)");
//		break;
//	case QUEST_DONE:
//		SetDescription("이 퀘스트는 완료되었음.");
//		break;
//	default:
//		break;
//	}
//	questStep = step;
//}

LRESULT Ending_UI::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (isShow != true)
	{
		return 0;
	}

	LRESULT result = 0;
	result = UI_Base::InputProc(hWnd, message, wParam, lParam);
	if (result == 0)
	{
		RECT rect = { (int)world._41, (int)world._42, (int)(world._41 + size.x), (int)(world._42 + size.y) };
		switch (message)
		{
		case WM_LBUTTONDOWN:
		{
			POINT mousePoint;
			mousePoint.x = GET_X_LPARAM(lParam);
			mousePoint.y = GET_Y_LPARAM(lParam);
			if (mousePoint.x > rect.left && mousePoint.x < rect.right
				&& mousePoint.y > rect.top && mousePoint.y < rect.bottom)
			{
				//눌러졌다. 드래그 시작
				prevMouse.x = mousePoint.x;
				prevMouse.y = mousePoint.y;
				//isDrag = true;

				result = WM_LBUTTONDOWN;
			}
		}
		break;
		case WM_LBUTTONUP:
		{
			isDrag = false;
		}
		break;
		case WM_RBUTTONDOWN:
		{
			POINT mousePoint;
			mousePoint.x = GET_X_LPARAM(lParam);
			mousePoint.y = GET_Y_LPARAM(lParam);
			if (mousePoint.x > rect.left && mousePoint.x < rect.right
				&& mousePoint.y > rect.top && mousePoint.y < rect.bottom)
			{
				result = WM_RBUTTONDOWN;
			}
		}
		break;
		case WM_MOUSEMOVE:
		{
			POINT mousePoint;
			mousePoint.x = GET_X_LPARAM(lParam);
			mousePoint.y = GET_Y_LPARAM(lParam);

			if (isDrag == true)
			{
				position.x += (float)(mousePoint.x - prevMouse.x);
				position.y += (float)(mousePoint.y - prevMouse.y);

				prevMouse.x = mousePoint.x;
				prevMouse.y = mousePoint.y;
			}
		}
		break;
		}

	}
	return result;
}

void Ending_UI::ReadData(char* inputFileName/* = nullptr*/)
{
	char filename[256] = "\0";
	if (inputFileName != nullptr)
	{
		strcpy_s(filename, inputFileName);
	}
	else
	{
		strcpy_s(filename, ". / Data / TXT / Data.txt");
	}


	FILE* fp = nullptr;
	fopen_s(&fp, filename, "r");
	if (fp != nullptr)
	{
		char line[256];
		while (fgets(line, 256, fp) != nullptr)
		{
			//파싱
			char* command = nullptr;
			char* parameter = nullptr;

			char* context = nullptr;
			char seperator[] = " :\n\0";
			command = strtok_s(line, seperator, &context);
			if (command != nullptr)
			{
				parameter = strtok_s(nullptr, seperator, &context);

				//파싱한 명령어들 처리
				if (strcmp("Time", command) == 0)
				{
					//TimeOut = (atoi(parameter));
				}
				else if (strcmp("LostHP", command) == 0)
				{
					//LostHPOut = (atoi(parameter));
				}
			}

		}
		fclose(fp);
	}
}