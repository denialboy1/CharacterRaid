#include "stdafx.h"
#include "ArtifactTab.h"


ArtifactTab::ArtifactTab()
{
}


ArtifactTab::~ArtifactTab()
{
}

void ArtifactTab::Initialize(Item* _item)
{
	if (item == nullptr){
		item = new Item;
		item->artifact = _item->artifact;
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

	if (tabOut == nullptr){
		tabOut = new UI_Button;
		tabOut->SetTexture("./상점/TabOutNormal.png", "./상점/TabOutOver.png", "./상점/TabOutClick.png");
		tabOut->OnClick = std::bind(&UI_Functions::ButtonCancel, std::ref(UI_Manager::Get().func), tabOut, item);
		tabOut->SetPosition(565, 15, 0);
		this->AddChild(tabOut);
	}

	//blink
	if (blink == nullptr){
		blink = new UI_Image;
		blink->SetTexture("./상점/artifact_blink2.png");
		blink->SetPosition(54, 54, 0);
		this->AddChild(blink);
	}

	if (blinkName == nullptr){
		blinkName = new UI_Text;
		blinkName->SetFont(font);
		blinkName->SetPosition(140, 30, 0);
		blinkName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		blinkName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		blinkName->SetSize(200, 100);
		blinkName->SetText("마법사 목걸이");
		this->AddChild(blinkName);
	}

	if (blinkDesc == nullptr){
		blinkDesc = new UI_Text;
		blinkDesc->SetFont(font2);
		blinkDesc->SetPosition(180, 100, 0);
		blinkDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		blinkDesc->SetTextFormat(DT_WORDBREAK);
		blinkDesc->SetSize(1000, 120);
		blinkDesc->SetText("블링크를 사용할 수 있다.\n(아티팩트는 한개만 소유가능)");
		this->AddChild(blinkDesc);
	}

	if (blinkCheck == nullptr){
		blinkCheck = new UI_Image;
		blinkCheck->SetTexture("./상점/checkOn_over.png");
		blinkCheck->SetPosition(510, 90, 0);
		blinkCheck->SetShow(false);
		this->AddChild(blinkCheck);
	}

	if (blinkUnCheck == nullptr){
		blinkUnCheck = new UI_Button;
		blinkUnCheck->SetTexture("./상점/checkOff_normal.png", "./상점/checkOff_over.png", "./상점/checkOn_click.png");
		blinkUnCheck->OnClick = std::bind(&UI_Functions::ButtonCheck, std::ref(UI_Manager::Get().func), blinkUnCheck, item, BLINK);
		blinkUnCheck->SetPosition(510, 90, 0);
		blinkUnCheck->SetShow(true);
		this->AddChild(blinkUnCheck);
	}

	//invincible
	if (invincible == nullptr){
		invincible = new UI_Image;
		invincible->SetTexture("./상점/artifact_invincible2.png");
		invincible->SetPosition(54, 54+100, 0);
		this->AddChild(invincible);
	}

	if (invincibleName == nullptr){
		invincibleName = new UI_Text;
		invincibleName->SetFont(font);
		invincibleName->SetPosition(140, 30 + 100, 0);
		invincibleName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		invincibleName->SetSize(200, 100);
		invincibleName->SetText("절대반지");
		this->AddChild(invincibleName);
	}

	if (invincibleDesc == nullptr){
		invincibleDesc = new UI_Text;
		invincibleDesc->SetFont(font2);
		invincibleDesc->SetPosition(180, 100 + 100, 0);
		invincibleDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleDesc->SetTextFormat(DT_WORDBREAK);
		invincibleDesc->SetSize(1000, 120);
		invincibleDesc->SetText("1.5초간 무적상태가 된다.\n(아티팩트는 한개만 소유가능)");
		this->AddChild(invincibleDesc);
	}

	if (invincibleUnCheck == nullptr){
		invincibleUnCheck = new UI_Button;
		invincibleUnCheck->SetTexture("./상점/checkOff_normal.png", "./상점/checkOff_over.png", "./상점/checkOn_click.png");
		invincibleUnCheck->OnClick = std::bind(&UI_Functions::ButtonCheck, std::ref(UI_Manager::Get().func), invincibleUnCheck, item, INVINCIBLE);
		invincibleUnCheck->SetPosition(510, 190, 0);
		invincibleUnCheck->SetShow(true);
		this->AddChild(invincibleUnCheck);
	}

	if (invincibleCheck == nullptr){
		invincibleCheck = new UI_Image;
		invincibleCheck->SetTexture("./상점/checkOn_over.png");
		invincibleCheck->SetPosition(510, 190, 0);
		invincibleCheck->SetShow(false);
		this->AddChild(invincibleCheck);
	}

	//speed
	if (speed == nullptr){
		speed = new UI_Image;
		speed->SetTexture("./상점/artifact_speed2.png");
		speed->SetPosition(54, 54 + 100 + 100, 0);
		this->AddChild(speed);
	}

	if (speedName == nullptr){
		speedName = new UI_Text;
		speedName->SetFont(font);
		speedName->SetPosition(140, 30 + 100 + 100, 0);
		speedName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		speedName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		speedName->SetSize(200, 100);
		speedName->SetText("스피드부츠");
		this->AddChild(speedName);
	}

	if (speedDesc == nullptr){
		speedDesc = new UI_Text;
		speedDesc->SetFont(font2);
		speedDesc->SetPosition(180, 100 + 100 + 100, 0);
		speedDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		speedDesc->SetTextFormat(DT_WORDBREAK);
		speedDesc->SetSize(1000, 120);
		speedDesc->SetText("3초간 이동속도가 상승한다.\n(아티팩트는 한개만 소유가능)");
		this->AddChild(speedDesc);
	}

	if (speedUnCheck == nullptr){
		speedUnCheck = new UI_Button;
		speedUnCheck->SetTexture("./상점/checkOff_normal.png", "./상점/checkOff_over.png", "./상점/checkOn_click.png");
		speedUnCheck->OnClick = std::bind(&UI_Functions::ButtonCheck, std::ref(UI_Manager::Get().func), speedUnCheck, item, SPEEDUP);
		speedUnCheck->SetPosition(510, 290, 0);
		speedUnCheck->SetShow(true);
		this->AddChild(speedUnCheck);
	}

	if (speedCheck == nullptr){
		speedCheck = new UI_Image;
		speedCheck->SetTexture("./상점/checkOn_over.png");
		speedCheck->SetPosition(510, 290, 0);
		speedCheck->SetShow(false);
		this->AddChild(speedCheck);
	}

	position.x = 950;
	position.y = 10;
}

void ArtifactTab::Update()
{
	if (isShow != true)
	{
		return;
	}
	
	switch (item->artifact){
	case BLINK:
		blinkCheck->SetShow(true);
		blinkUnCheck->SetShow(false);
		invincibleCheck->SetShow(false);
		invincibleUnCheck->SetShow(true);
		speedCheck->SetShow(false);
		speedUnCheck->SetShow(true);
		break;
	case INVINCIBLE:
		blinkCheck->SetShow(false);
		blinkUnCheck->SetShow(true);
		invincibleCheck->SetShow(true);
		invincibleUnCheck->SetShow(false);
		speedCheck->SetShow(false);
		speedUnCheck->SetShow(true);
		break;
	case SPEEDUP:
		blinkCheck->SetShow(false);
		blinkUnCheck->SetShow(true);
		invincibleCheck->SetShow(false);
		invincibleUnCheck->SetShow(true);
		speedCheck->SetShow(true);
		speedUnCheck->SetShow(false);
		break;
	}
	UI_Base::Update();
}

void ArtifactTab::Render()
{
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();
}

LRESULT ArtifactTab::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

void ArtifactTab::Destroy(){
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
}