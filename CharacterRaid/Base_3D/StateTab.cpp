#include "stdafx.h"
#include "StateTab.h"


StateTab::StateTab()
{
}


StateTab::~StateTab()
{
}


void StateTab::Initialize(Item* _item)
{
	if (item == nullptr){
		item = new Item;
	}

	isShow = true;

	//폰트 생성
	D3DXFONT_DESC font_desc;
	ZeroMemory(&font_desc, sizeof(D3DXFONT_DESC));
	font_desc.Height = 30;
	font_desc.Width = 12;
	font_desc.Weight = FW_NORMAL;
	font_desc.MipLevels = D3DX_DEFAULT;
	font_desc.Italic = false;
	font_desc.CharSet = DEFAULT_CHARSET;
	font_desc.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc.Quality = DEFAULT_QUALITY;
	font_desc.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc.FaceName, L"simple");	//글꼴 스타일
	//AddFontResource(L"./Data/Font/kodia.ttf");
	//wcscpy_s(font_desc.FaceName, L"kodia");
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc, &font);

	//폰트 생성
	D3DXFONT_DESC font_desc2;
	ZeroMemory(&font_desc2, sizeof(D3DXFONT_DESC));
	font_desc2.Height = 20;
	font_desc2.Width = 9;
	font_desc2.Weight = FW_NORMAL;
	font_desc2.MipLevels = D3DX_DEFAULT;
	font_desc2.Italic = false;
	font_desc2.CharSet = DEFAULT_CHARSET;
	font_desc2.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc2.Quality = DEFAULT_QUALITY;
	font_desc2.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc2.FaceName, L"simple2");	//글꼴 스타일
	//AddFontResource(L"./Data/Font/umberto.ttf");
	//wcscpy_s(font_desc.FaceName, L"umberto");
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc2, &font2);

	if (background == nullptr){
		background = new UI_Image;
		background->SetTexture("./상점/ItemTab.png");
		background->SetPosition(0, 0, 0);
		this->size = background->GetSize();
		this->AddChild(background);
	}

	if (buy == nullptr){
		buy = new UI_Button;
		buy->SetTexture("./상점/buy_normal.png", "./상점/buy_over.png", "./상점/buy_click.png");
		buy->OnClick = std::bind(&UI_Functions::ButtonBuy, std::ref(UI_Manager::Get().func), buy, item);
		buy->SetPosition(200, 750, 0);
		this->AddChild(buy);
	}

	for (int i = 0; i < 3; i++){
		list[i] = new UI_Image;
		list[i]->SetTexture("./상점/list.png");
		list[i]->SetPosition(50, 50 + i * 100, 0);
		this->AddChild(list[i]);
	}

		tabOut = new UI_Button;
		tabOut->SetTexture("./상점/TabOutNormal.png", "./상점/TabOutOver.png", "./상점/TabOutClick.png");
		tabOut->OnClick = std::bind(&UI_Functions::ButtonCancel, std::ref(UI_Manager::Get().func), tabOut, item);
		tabOut->SetPosition(565, 15, 0);
		this->AddChild(tabOut);

	//atk
	if (atk == nullptr){
		atk = new UI_Image;
		atk->SetTexture("./상점/atk.png");
		atk->SetPosition(54, 54, 0);
		this->AddChild(atk);
	}

	if (atkName == nullptr){
		atkName = new UI_Text;
		atkName->SetFont(font);
		atkName->SetPosition(90, 30, 0);
		atkName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		atkName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
		atkName->SetSize(200, 100);
		atkName->SetText("공격력");
		this->AddChild(atkName);
	}

	if (atkDesc == nullptr){
		atkDesc = new UI_Text;
		atkDesc->SetFont(font2);
		atkDesc->SetPosition(180, 110, 0);
		atkDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		atkDesc->SetTextFormat(DT_WORDBREAK);
		atkDesc->SetSize(1000, 120);
		atkDesc->SetText("공격력이 1증가한다");
		this->AddChild(atkDesc);
	}

	if (atkPrice == nullptr){
		atkPrice = new UI_Text;
		atkPrice->SetFont(font2);
		atkPrice->SetPosition(350, 70, 0);
		atkPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		atkPrice->SetTextFormat(DT_WORDBREAK);
		atkPrice->SetSize(1000, 120);
		atkPrice->SetText("가격 : 100");
		this->AddChild(atkPrice);
	}

	if (atkNum == nullptr){
		atkNum = new UI_Text;
		atkNum->SetFont(font2);
		atkNum->SetPosition(480, 115, 0);
		atkNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		atkNum->SetTextFormat(DT_WORDBREAK);
		atkNum->SetSize(1000, 120);
		atkNum->SetText("x0");		//스테이지 연결후 재조정
		this->AddChild(atkNum);
	}

	if (atkUp == nullptr){
		atkUp = new UI_Button;
		atkUp->SetTexture("./상점/up_normal.png", "./상점/up_over.png", "./상점/up_click.png");
		atkUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), atkUp, &item->atk);
		atkUp->SetPosition(510, 60, 0);
		this->AddChild(atkUp);
	}

	if (atkDown == nullptr){
		atkDown = new UI_Button;
		atkDown->SetTexture("./상점/down_normal.png", "./상점/down_over.png", "./상점/down_click.png");
		atkDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), atkDown, &item->atk);
		atkDown->SetPosition(510, 110, 0);
		this->AddChild(atkDown);
	}

	//def
	if (def == nullptr){
		def = new UI_Image;
		def->SetTexture("./상점/armor.png");
		def->SetPosition(54, 54 + 100, 0);
		this->AddChild(def);
	}

	if (defName == nullptr){
		defName = new UI_Text;
		defName->SetFont(font);
		defName->SetPosition(90, 30 + 100, 0);
		defName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
		defName->SetSize(200, 100);
		defName->SetText("방어력");
		this->AddChild(defName);
	}

	if (defDesc == nullptr){
		defDesc = new UI_Text;
		defDesc->SetFont(font2);
		defDesc->SetPosition(180, 110 + 100, 0);
		defDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defDesc->SetTextFormat(DT_WORDBREAK);
		defDesc->SetSize(1000, 120);
		defDesc->SetText("방어력을 1증가한다");
		this->AddChild(defDesc);
	}

	if (defPrice == nullptr){
		defPrice = new UI_Text;
		defPrice->SetFont(font2);
		defPrice->SetPosition(350, 70 + 100, 0);
		defPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defPrice->SetTextFormat(DT_WORDBREAK);
		defPrice->SetSize(1000, 120);
		defPrice->SetText("가격 : 100");
		this->AddChild(defPrice);
	}

	if (defNum == nullptr){
		defNum = new UI_Text;
		defNum->SetFont(font2);
		defNum->SetPosition(480, 115 + 100, 0);
		defNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defNum->SetTextFormat(DT_WORDBREAK);
		defNum->SetSize(1000, 120);
		defNum->SetText("x0");		//스테이지 연결후 재조정
		this->AddChild(defNum);
	}

	if (defUp == nullptr){
		defUp = new UI_Button;
		defUp->SetTexture("./상점/up_normal.png", "./상점/up_over.png", "./상점/up_click.png");
		defUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), defUp, &item->def);
		defUp->SetPosition(510, 60 + 100, 0);
		this->AddChild(defUp);
	}

	if (defDown == nullptr){
		defDown = new UI_Button;
		defDown->SetTexture("./상점/down_normal.png", "./상점/down_over.png", "./상점/down_click.png");
		defDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), defDown, &item->def);
		defDown->SetPosition(510, 110 + 100, 0);
		this->AddChild(defDown);
	}

	//이속
	if (move == nullptr){
		move = new UI_Image;
		move->SetTexture("./상점/move.png");
		move->SetPosition(54, 54 + 100 + 100, 0);
		this->AddChild(move);
	}

	if (moveName == nullptr){
		moveName = new UI_Text;
		moveName->SetFont(font);
		moveName->SetPosition(100, 30 + 100 + 100, 0);
		moveName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		moveName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
		moveName->SetSize(200, 100);
		moveName->SetText("이동속도");
		this->AddChild(moveName);
	}

	if (moveDesc == nullptr){
		moveDesc = new UI_Text;
		moveDesc->SetFont(font2);
		moveDesc->SetPosition(180, 110 + 100 + 100, 0);
		moveDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		moveDesc->SetTextFormat(DT_WORDBREAK);
		moveDesc->SetSize(1000, 120);
		moveDesc->SetText("이동속도를 1증가한다");
		this->AddChild(moveDesc);
	}

	if (movePrice == nullptr){
		movePrice = new UI_Text;
		movePrice->SetFont(font2);
		movePrice->SetPosition(350, 70 + 100 + 100, 0);
		movePrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		movePrice->SetTextFormat(DT_WORDBREAK);
		movePrice->SetSize(1000, 120);
		movePrice->SetText("가격 : 100");
		this->AddChild(movePrice);
	}

	if (moveNum == nullptr){
		moveNum = new UI_Text;
		moveNum->SetFont(font2);
		moveNum->SetPosition(480, 115 + 100 + 100, 0);
		moveNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		moveNum->SetTextFormat(DT_WORDBREAK);
		moveNum->SetSize(1000, 120);
		moveNum->SetText("x0");		//스테이지 연결후 재조정
		this->AddChild(moveNum);
	}

	if (moveUp == nullptr){
		moveUp = new UI_Button;
		moveUp->SetTexture("./상점/up_normal.png", "./상점/up_over.png", "./상점/up_click.png");
		moveUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), moveUp, &item->move);
		moveUp->SetPosition(510, 60 + 100 + 100, 0);
		this->AddChild(moveUp);
	}

	if (moveDown == nullptr){
		moveDown = new UI_Button;
		moveDown->SetTexture("./상점/down_normal.png", "./상점/down_over.png", "./상점/down_click.png");
		moveDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), moveDown, &item->move);
		moveDown->SetPosition(510, 110 + 100 + 100, 0);
		this->AddChild(moveDown);
	}

	position.x = 950;
	position.y = 10;
}

void StateTab::Update()
{
	if (isShow != true)
	{
		return;
	}

	if (atkNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->atk, str2, 10);
		strcat_s(str, str2);
		atkNum->SetText(str);
	}

	if (defNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->def, str2, 10);
		strcat_s(str, str2);
		defNum->SetText(str);
	}

	if (moveNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->move, str2, 10);
		strcat_s(str, str2);
		moveNum->SetText(str);
	}

	UI_Base::Update();
}

void StateTab::Render()
{
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();
}

LRESULT StateTab::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (isShow != true)
	{
		return 0;
	}

	LRESULT result = 0;
	result = UI_Base::InputProc(hWnd, message, wParam, lParam);

	if (result == 0){
		result = buy->InputProc(hWnd, message, wParam, lParam);
	}

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
				isDrag = true;

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

void StateTab::Destroy(){
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
}