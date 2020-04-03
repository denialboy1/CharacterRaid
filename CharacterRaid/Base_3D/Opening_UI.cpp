#include "stdafx.h"
#include "Opening_UI.h"


Opening_UI::Opening_UI()
{
}


Opening_UI::~Opening_UI()
{
}

void Opening_UI::Initialize()
{
	backGround = new UI_Image;
	backGround->SetTexture("./UI/Opening.jpg");
	backGround->SetPosition(0, 0, 0);
	backGround->SetSize(1600, 900);
	this->size = backGround->GetSize();
	this->AddChild(backGround);

	//UI_Image* board = new UI_Image;
	//board->SetTexture("./UI/Title.png");
	//board->SetPosition((backGround->GetSize().x - board->GetSize().x) / 2, 180, -1);
	//board->SetSize(1218, 141);
	//this->size = board->GetSize();
	//this->AddChild(board);

	title = new UI_Image;
	title->SetTexture("./UI/TitleText.png");
	title->SetPosition((backGround->GetSize().x-title->GetSize().x)/2, 100, 0);
	title->SetSize(1350, 226);
	this->size = title->GetSize();
	this->AddChild(title);

	enter = new UI_Button;
	enter->SetTexture("UI/PlayButton_Up.png", "UI/PlayButton_Over.png", "UI/PlayButton_Down.png");
	enter->SetPosition((backGround->GetSize().x-enter->GetSize().x) / 2, backGround->GetSize().y - 250, 0);
	enter->SetID(BUTTON_OK);
	enter->OnClick = std::bind(&UI_Functions::ButtonStep, std::ref(UI_Manager::Get().func), enter,OPENING_TO_SELECT);
	this->AddChild(enter);

	isShow = true;
}
void Opening_UI::Update()
{
	if (isShow != true)
	{
		return;
	}
	switch (openingStep)
	{
	case OPENING_NORMAL:
		break;
	case OPENING_TO_SELECT:
		//GameStateManager::Get().ChangeGameState(STATE_SELECT);
		break;
	}

	UI_Base::Update();
}
void Opening_UI::Render()
{
	if (isShow != true)
	{
		return;
	}
	//RECT rc = { 500, 400, 550, 450 };
	//UI_Manager::GetFont()->DrawTextA(NULL, TimeText, strlen(TimeText), &rc, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	//
	//RECT rc2 = { 500, 500, 550, 550 };
	//UI_Manager::GetFont()->DrawTextA(NULL, LostHPText, strlen(LostHPText), &rc2, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

	UI_Base::Render();
}

void Opening_UI::Destroy(){
	UI_Base::Destroy();
	UI_Manager::Get().SetRoot(nullptr);
}
//void Opening_UI::SetTitle(char* title)
//{
//	UI_Text* titleUI = (UI_Text*)GetChildByID(TEXT_TITLE);
//	titleUI->SetText(title);
//}
//
//void Opening_UI::SetDescription(char* desc)
//{
//	UI_Text* descUI = (UI_Text*)GetChildByID(TEXT_DESC);
//	descUI->SetText(desc);
//
//	//sprintf_s(TimeText, "Time : %d", TimeOut);
//	//
//	//sprintf_s(LostHPText, "LostHP : %d", LostHPOut);
//
//}

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

LRESULT Opening_UI::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

//void Opening_UI::ReadData(char* inputFileName/* = nullptr*/)
//{
//	char filename[256] = "\0";
//	if (inputFileName != nullptr)
//	{
//		strcpy_s(filename, inputFileName);
//	}
//	else
//	{
//		strcpy_s(filename, ". / Data / TXT / Data.txt");
//	}
//
//
//	FILE* fp = nullptr;
//	fopen_s(&fp, filename, "r");
//	if (fp != nullptr)
//	{
//		char line[256];
//		while (fgets(line, 256, fp) != nullptr)
//		{
//			//파싱
//			char* command = nullptr;
//			char* parameter = nullptr;
//
//			char* context = nullptr;
//			char seperator[] = " :\n\0";
//			command = strtok_s(line, seperator, &context);
//			if (command != nullptr)
//			{
//				parameter = strtok_s(nullptr, seperator, &context);
//
//				//파싱한 명령어들 처리
//				if (strcmp("Time", command) == 0)
//				{
//					TimeOut = (atoi(parameter));
//				}
//				else if (strcmp("LostHP", command) == 0)
//				{
//					LostHPOut = (atoi(parameter));
//				}
//			}
//
//		}
//		fclose(fp);
//	}
//}