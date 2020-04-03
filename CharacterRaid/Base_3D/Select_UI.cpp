#include "stdafx.h"
#include "Select_UI.h"


Select_UI::Select_UI()
{
}


Select_UI::~Select_UI()
{
}

void Select_UI::Initialize()
{
	backGround = new UI_Image;
	backGround->SetTexture("./상점/선택창배경.png");
	backGround->SetPosition(0, 0, 0);
	backGround->SetSize(1600, 900);
	this->size = backGround->GetSize();
	this->AddChild(backGround);

	//노바 버튼
	nova = new UI_Button;
	nova->SetTexture("UI/Nova_Button_Up.png", "UI/Nova_Button_Over.png", "UI/Nova_Button_Down.png");
	nova->SetPosition(155, 40, 0);
	nova->SetID(BUTTON_NOVA);
	nova->OnClick = std::bind(&UI_Functions::ButtonSelectStep, std::ref(UI_Manager::Get().func), nova,SELECT_NOVA);
	this->AddChild(nova);

	//요한나 버튼
	johanna = new UI_Button;
	johanna->SetTexture("UI/Johanna_Button_Up.png", "UI/Johanna_Button_Over.png", "UI/Johanna_Button_Down.png");
	johanna->SetPosition(155+430, 40, 0);
	johanna->SetID(BUTTON_JOHANNA);
	johanna->OnClick = std::bind(&UI_Functions::ButtonSelectStep, std::ref(UI_Manager::Get().func), johanna,SELECT_JOHANNA);
	this->AddChild(johanna);

	//제이나 버튼
	jaina = new UI_Button;
	jaina->SetTexture("UI/Jaina_Button_Up.png", "UI/Jaina_Button_Over.png", "UI/Jaina_Button_Down.png");
	jaina->SetPosition(155+430*2, 40, 0);
	jaina->SetID(BUTTON_JAINA);
	jaina->OnClick = std::bind(&UI_Functions::ButtonSelectStep, std::ref(UI_Manager::Get().func), jaina,SELECT_JAINA);
	this->AddChild(jaina);

	intro = new UI_Text;
	intro->SetFont(UI_Manager::GetFont());
	intro->SetPosition(150, 680, 0);
	intro->SetSize(1400, 300);
	intro->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
	intro->SetTextFormat(DT_LEFT | DT_TOP | DT_WORDBREAK);
	intro->SetText(Text);
	intro->SetID(TEXT_INTRO);
	this->AddChild(intro);


	isShow = true;
}
void Select_UI::Update()
{
	if (isShow != true){
		return;
	}

	if (nova->GetState() == STATE_OVER)
	{
		intro->SetText("노바\n라이플을 이용한 원거리 공격을 구사합니다. 긴 사거리가 특징입니다.\n난이도 : ★★★★☆");
		intro->SetShow(true);
	}
	else if (johanna->GetState() == STATE_OVER)
	{
		intro->SetText("요한나\n철퇴를 이용한 강력한 근접공격을 하며 높은 방어력이 특징입니다.\n난이도 : ★★★★★");
		intro->SetShow(true);
	}
	else if (jaina->GetState() == STATE_OVER)
	{
		intro->SetText("제이나\n강력한 얼음마법을 구사하는 마법사입니다. 순간 화력이 강력한것이 특징입니다.\n 난이도 : ★★★★☆");
		intro->SetShow(true);
	}
	else{
		intro->SetShow(false);
	}

	
	switch (selectStep)
	{
	case SELECT_NORMAL:
		break;
	case SELECT_NOVA:
		iniDataManager::Get().addData("Player", "Stage", "1");

		iniDataManager::Get().addData("Player", "Character", "1");
		iniDataManager::Get().addData("Player", "Life", "1");
		iniDataManager::Get().addData("Player", "LV", "1");
		iniDataManager::Get().addData("Player", "Exp", "0");
		iniDataManager::Get().addData("Player", "HP", "500");
		iniDataManager::Get().addData("Player", "MP", "500");
		iniDataManager::Get().addData("Player", "Attack", "10");
		iniDataManager::Get().addData("Player", "Armor", "0");
		iniDataManager::Get().addData("Player", "Speed", "3");

		iniDataManager::Get().addData("Item", "Money", "100000");
		iniDataManager::Get().addData("Item", "HpPotion", "0");
		iniDataManager::Get().addData("Item", "MpPotion", "0");
		iniDataManager::Get().addData("Item", "PowerHerb", "0");
		iniDataManager::Get().addData("Item", "ArmorPotion", "0");
		iniDataManager::Get().addData("Item", "StunDagger", "0");
		iniDataManager::Get().addData("Item", "Invincible", "0");

		iniDataManager::Get().addData("Item", "Neckles", "0");
		iniDataManager::Get().addData("Item", "Ring", "0");
		iniDataManager::Get().addData("Item", "boots", "0");

		//노바
		iniDataManager::Get().addData("Item", "Sniper", "1");
		iniDataManager::Get().addData("Item", "Hyperion", "0");
		iniDataManager::Get().addData("Item", "PowerUp", "0");
		iniDataManager::Get().addData("Item", "Nuclear", "0");

		//요한나
		iniDataManager::Get().addData("Item", "ArmorBuff", "0");
		iniDataManager::Get().addData("Item", "AttackBuff", "0");

		//제이나
		iniDataManager::Get().addData("Item", "Ice", "0");
		iniDataManager::Get().addData("Item", "IceFire", "0");
		iniDataManager::Get().addData("Item", "MpRegen", "0");
		iniDataManager::Get().addData("Item", "IceWorld", "0");

		iniDataManager::Get().addData("Item", "SupportHp", "1");
		iniDataManager::Get().addData("Item", "SupportMp", "0");

		iniDataManager::Get().iniSave("player");
		GameStateManager::Get().ChangeGameState(STATE_SHOP);
		
		break;
	case SELECT_JOHANNA:
		iniDataManager::Get().addData("Player", "Stage", "2");

		iniDataManager::Get().addData("Player", "Character", "2");
		iniDataManager::Get().addData("Player", "Life", "1");
		iniDataManager::Get().addData("Player", "LV", "1");
		iniDataManager::Get().addData("Player", "Exp", "0");
		iniDataManager::Get().addData("Player", "HP", "800");
		iniDataManager::Get().addData("Player", "MP", "400");
		iniDataManager::Get().addData("Player", "Attack", "15");
		iniDataManager::Get().addData("Player", "Armor", "5");
		iniDataManager::Get().addData("Player", "Speed", "3");

		iniDataManager::Get().addData("Item", "Money", "100000");
		iniDataManager::Get().addData("Item", "HpPotion", "0");
		iniDataManager::Get().addData("Item", "MpPotion", "0");
		iniDataManager::Get().addData("Item", "PowerHerb", "0");
		iniDataManager::Get().addData("Item", "ArmorPotion", "0");
		iniDataManager::Get().addData("Item", "StunDagger", "0");
		iniDataManager::Get().addData("Item", "Invincible", "0");

		iniDataManager::Get().addData("Item", "Neckles", "0");
		iniDataManager::Get().addData("Item", "Ring", "0");
		iniDataManager::Get().addData("Item", "boots", "0");

		//노바
		iniDataManager::Get().addData("Item", "Sniper", "0");
		iniDataManager::Get().addData("Item", "Hyperion", "0");
		iniDataManager::Get().addData("Item", "PowerUp", "0");
		iniDataManager::Get().addData("Item", "Nuclear", "0");

		//요한나
		iniDataManager::Get().addData("Item", "ArmorBuff", "0");
		iniDataManager::Get().addData("Item", "AttackBuff", "0");

		//제이나
		iniDataManager::Get().addData("Item", "Ice", "0");
		iniDataManager::Get().addData("Item", "IceFire", "0");
		iniDataManager::Get().addData("Item", "MpRegen", "0");
		iniDataManager::Get().addData("Item", "IceWorld", "0");

		iniDataManager::Get().addData("Item", "SupportHp", "0");
		iniDataManager::Get().addData("Item", "SupportMp", "0");

		iniDataManager::Get().iniSave("player");
		GameStateManager::Get().ChangeGameState(STATE_SHOP);
		break;
	case SELECT_JAINA:
		iniDataManager::Get().addData("Player", "Stage", "1");

		iniDataManager::Get().addData("Player", "Character", "3");
		iniDataManager::Get().addData("Player", "Life", "1");
		iniDataManager::Get().addData("Player", "LV", "1");
		iniDataManager::Get().addData("Player", "Exp", "0");
		iniDataManager::Get().addData("Player", "HP", "500");
		iniDataManager::Get().addData("Player", "MP", "500");
		iniDataManager::Get().addData("Player", "Attack", "10");
		iniDataManager::Get().addData("Player", "Armor", "0");
		iniDataManager::Get().addData("Player", "Speed", "3");

		iniDataManager::Get().addData("Item", "Money", "100000");
		iniDataManager::Get().addData("Item", "HpPotion", "0");
		iniDataManager::Get().addData("Item", "MpPotion", "0");
		iniDataManager::Get().addData("Item", "PowerHerb", "0");
		iniDataManager::Get().addData("Item", "ArmorPotion", "0");
		iniDataManager::Get().addData("Item", "StunDagger", "0");
		iniDataManager::Get().addData("Item", "Invincible", "0");

		iniDataManager::Get().addData("Item", "Neckles", "0");
		iniDataManager::Get().addData("Item", "Ring", "0");
		iniDataManager::Get().addData("Item", "boots", "0");

		//노바
		iniDataManager::Get().addData("Item", "Sniper", "0");
		iniDataManager::Get().addData("Item", "Hyperion", "0");
		iniDataManager::Get().addData("Item", "PowerUp", "0");
		iniDataManager::Get().addData("Item", "Nuclear", "0");

		//요한나
		iniDataManager::Get().addData("Item", "ArmorBuff", "0");
		iniDataManager::Get().addData("Item", "AttackBuff", "0");

		//제이나
		iniDataManager::Get().addData("Item", "Ice", "0");
		iniDataManager::Get().addData("Item", "IceFire", "0");
		iniDataManager::Get().addData("Item", "MpRegen", "0");
		iniDataManager::Get().addData("Item", "IceWorld", "0");

		iniDataManager::Get().addData("Item", "SupportHp", "0");
		iniDataManager::Get().addData("Item", "SupportMp", "0");

		iniDataManager::Get().iniSave("player");
		GameStateManager::Get().ChangeGameState(STATE_SHOP);
		break;
	}
	UI_Base::Update();

}
void Select_UI::Destroy(){
	UI_Base::Destroy();
}
void Select_UI::Render()
{
	if (isShow != true)
	{
		return;
	}
	

	if (nova->GetState() == STATE_OVER)
	{
		RECT rc = { 500, 800, 550, 450 };
		UI_Manager::GetFont()->DrawTextA(NULL, Text, strlen(Text), &rc, DT_TOP | DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
		int a=0;
	}
	
	
	UI_Base::Render();
}


LRESULT Select_UI::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (isShow != true)
	{
		return 0;
	}

	LRESULT result = 0;
	result = UI_Base::InputProc(hWnd, message, wParam, lParam);
	return result;
}

//void Select_UI::ReadData(char* inputFileName/* = nullptr*/)
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