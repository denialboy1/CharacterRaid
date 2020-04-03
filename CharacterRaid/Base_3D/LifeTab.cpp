#include "stdafx.h"
#include "LifeTab.h"


LifeTab::LifeTab()
{
}


LifeTab::~LifeTab()
{
}


void LifeTab::Initialize(Item* _item, int _character)
{
	if (item == nullptr){
		item = new Item;
	}

	isShow = true;

	character = _character;
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

	for (int i = 0; i < 1; i++){
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

	switch (character){
	case 1:
		//nova
		if (nova == nullptr){
			nova = new UI_Image;
			nova->SetTexture("./상점/노바2.png");
			nova->SetPosition(54, 54, 0);
			this->AddChild(nova);
		}

		if (novaName == nullptr){
			novaName = new UI_Text;
			novaName->SetFont(font);
			novaName->SetPosition(90, 30, 0);
			novaName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			novaName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
			novaName->SetSize(200, 100);
			novaName->SetText("노바");
			this->AddChild(novaName);
		}

		if (novaDesc == nullptr){
			novaDesc = new UI_Text;
			novaDesc->SetFont(font2);
			novaDesc->SetPosition(180, 110, 0);
			novaDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			novaDesc->SetTextFormat(DT_WORDBREAK);
			novaDesc->SetSize(1000, 120);
			novaDesc->SetText("라이프가 1증가한다");
			this->AddChild(novaDesc);
		}

		if (novaPrice == nullptr){
			novaPrice = new UI_Text;
			novaPrice->SetFont(font2);
			novaPrice->SetPosition(350, 70, 0);
			novaPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			novaPrice->SetTextFormat(DT_WORDBREAK);
			novaPrice->SetSize(1000, 120);
			novaPrice->SetText("가격 : 10000");
			this->AddChild(novaPrice);
		}

		if (novaNum == nullptr){
			novaNum = new UI_Text;
			novaNum->SetFont(font2);
			novaNum->SetPosition(480, 115, 0);
			novaNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			novaNum->SetTextFormat(DT_WORDBREAK);
			novaNum->SetSize(1000, 120);
			novaNum->SetText("x0");		//스테이지 연결후 재조정
			this->AddChild(novaNum);
		}

		if (novaUp == nullptr){
			novaUp = new UI_Button;
			novaUp->SetTexture("./상점/up_normal.png", "./상점/up_over.png", "./상점/up_click.png");
			novaUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), novaUp, &item->life);
			novaUp->SetPosition(510, 60, 0);
			this->AddChild(novaUp);
		}

		if (novaDown == nullptr){
			novaDown = new UI_Button;
			novaDown->SetTexture("./상점/down_normal.png", "./상점/down_over.png", "./상점/down_click.png");
			novaDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), novaDown, &item->life);
			novaDown->SetPosition(510, 110, 0);
			this->AddChild(novaDown);
		}
		
		break;
	case 2:
		//atk
		if (johanna == nullptr){
			johanna = new UI_Image;
			johanna->SetTexture("./상점/요한나2.png");
			johanna->SetPosition(54, 54, 0);
			this->AddChild(johanna);
		}

		if (johannaName == nullptr){
			johannaName = new UI_Text;
			johannaName->SetFont(font);
			johannaName->SetPosition(90, 30, 0);
			johannaName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			johannaName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
			johannaName->SetSize(200, 100);
			johannaName->SetText("요한나");
			this->AddChild(johannaName);
		}

		if (johannaDesc == nullptr){
			johannaDesc = new UI_Text;
			johannaDesc->SetFont(font2);
			johannaDesc->SetPosition(180, 110, 0);
			johannaDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			johannaDesc->SetTextFormat(DT_WORDBREAK);
			johannaDesc->SetSize(1000, 120);
			johannaDesc->SetText("라이프가 1증가한다");
			this->AddChild(johannaDesc);
		}

		if (johannaPrice == nullptr){
			johannaPrice = new UI_Text;
			johannaPrice->SetFont(font2);
			johannaPrice->SetPosition(350, 70, 0);
			johannaPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			johannaPrice->SetTextFormat(DT_WORDBREAK);
			johannaPrice->SetSize(1000, 120);
			johannaPrice->SetText("가격 : 10000");
			this->AddChild(johannaPrice);
		}

		if (johannaNum == nullptr){
			johannaNum = new UI_Text;
			johannaNum->SetFont(font2);
			johannaNum->SetPosition(480, 115, 0);
			johannaNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			johannaNum->SetTextFormat(DT_WORDBREAK);
			johannaNum->SetSize(1000, 120);
			johannaNum->SetText("x0");		//스테이지 연결후 재조정
			this->AddChild(johannaNum);
		}

		if (johannaUp == nullptr){
			johannaUp = new UI_Button;
			johannaUp->SetTexture("./상점/up_normal.png", "./상점/up_over.png", "./상점/up_click.png");
			johannaUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), johannaUp, &item->life);
			johannaUp->SetPosition(510, 60, 0);
			this->AddChild(johannaUp);
		}

		if (johannaDown == nullptr){
			johannaDown = new UI_Button;
			johannaDown->SetTexture("./상점/down_normal.png", "./상점/down_over.png", "./상점/down_click.png");
			johannaDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), johannaDown, &item->life);
			johannaDown->SetPosition(510, 110, 0);
			this->AddChild(johannaDown);
		}
		break;
	case 3:
		//atk
		if (jaina == nullptr){
			jaina = new UI_Image;
			jaina->SetTexture("./상점/제이나2.png");
			jaina->SetPosition(54, 54, 0);
			this->AddChild(jaina);
		}

		if (jainaName == nullptr){
			jainaName = new UI_Text;
			jainaName->SetFont(font);
			jainaName->SetPosition(90, 30, 0);
			jainaName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			jainaName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
			jainaName->SetSize(200, 100);
			jainaName->SetText("제이나");
			this->AddChild(jainaName);
		}

		if (jainaDesc == nullptr){
			jainaDesc = new UI_Text;
			jainaDesc->SetFont(font2);
			jainaDesc->SetPosition(180, 110, 0);
			jainaDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			jainaDesc->SetTextFormat(DT_WORDBREAK);
			jainaDesc->SetSize(1000, 120);
			jainaDesc->SetText("라이프가 1증가한다");
			this->AddChild(jainaDesc);
		}

		if (jainaPrice == nullptr){
			jainaPrice = new UI_Text;
			jainaPrice->SetFont(font2);
			jainaPrice->SetPosition(350, 70, 0);
			jainaPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			jainaPrice->SetTextFormat(DT_WORDBREAK);
			jainaPrice->SetSize(1000, 120);
			jainaPrice->SetText("가격 : 10000");
			this->AddChild(jainaPrice);
		}

		if (jainaNum == nullptr){
			jainaNum = new UI_Text;
			jainaNum->SetFont(font2);
			jainaNum->SetPosition(480, 115, 0);
			jainaNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			jainaNum->SetTextFormat(DT_WORDBREAK);
			jainaNum->SetSize(1000, 120);
			jainaNum->SetText("x0");		//스테이지 연결후 재조정
			this->AddChild(jainaNum);
		}

		if (jainaUp == nullptr){
			jainaUp = new UI_Button;
			jainaUp->SetTexture("./상점/up_normal.png", "./상점/up_over.png", "./상점/up_click.png");
			jainaUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), jainaUp, &item->life);
			jainaUp->SetPosition(510, 60, 0);
			this->AddChild(jainaUp);
		}

		if (jainaDown == nullptr){
			jainaDown = new UI_Button;
			jainaDown->SetTexture("./상점/down_normal.png", "./상점/down_over.png", "./상점/down_click.png");
			jainaDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), jainaDown, &item->life);
			jainaDown->SetPosition(510, 110, 0);
			this->AddChild(jainaDown);
		}
		break;
	}


	position.x = 950;
	position.y = 10;
}

void LifeTab::Update()
{
	if (isShow != true)
	{
		return;
	}


	switch (character){
	case 1:
		if (johannaNum){
			char str[4] = "x";
			char str2[4];
			_itoa_s(item->life, str2, 10);
			strcat_s(str, str2);
			johannaNum->SetText(str);
		}
		break;
	case 2:
		if (novaNum){
			char str[4] = "x";
			char str2[4];
			_itoa_s(item->life, str2, 10);
			strcat_s(str, str2);
			novaNum->SetText(str);
		}
		break;
	case 3:
		if (jainaNum){
			char str[4] = "x";
			char str2[4];
			_itoa_s(item->life, str2, 10);
			strcat_s(str, str2);
			jainaNum->SetText(str);
		}
		break;
	}

	UI_Base::Update();
}

void LifeTab::Render()
{
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();
}

LRESULT LifeTab::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

void LifeTab::Destroy(){
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
}
