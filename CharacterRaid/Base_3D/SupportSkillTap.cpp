#include "stdafx.h"
#include "SupportSkillTap.h"


SupportSkillTap::SupportSkillTap()
{
}


SupportSkillTap::~SupportSkillTap()
{
}

void SupportSkillTap::Initialize(Item* _item, int _character)
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

	for (int i = 0; i < 2; i++){
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

	//hp회복
	if (hp == nullptr){
		hp = new UI_Image;
		hp->SetTexture("./상점/회복스킬.PNG");
		hp->SetPosition(54, 54, 0);
		this->AddChild(hp);
	}

	if (hpName == nullptr){
		hpName = new UI_Text;
		hpName->SetFont(font);
		hpName->SetPosition(150, 30, 0);
		hpName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
		hpName->SetSize(200, 100);
		hpName->SetText("체력회복 증가");
		this->AddChild(hpName);
	}

	if (hpDesc == nullptr){
		hpDesc = new UI_Text;
		hpDesc->SetFont(font2);
		hpDesc->SetPosition(180, 110, 0);
		hpDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpDesc->SetTextFormat(DT_WORDBREAK);
		hpDesc->SetSize(1000, 120);
		hpDesc->SetText("체력회복이 250추가 한다");
		this->AddChild(hpDesc);
	}

	if (hpPrice == nullptr){
		hpPrice = new UI_Text;
		hpPrice->SetFont(font2);
		hpPrice->SetPosition(350, 70, 0);
		hpPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpPrice->SetTextFormat(DT_WORDBREAK);
		hpPrice->SetSize(1000, 120);
		hpPrice->SetText("가격 : 1000");
		this->AddChild(hpPrice);
	}

	if (hpCheck == nullptr){
		hpCheck = new UI_Image;
		hpCheck->SetTexture("./상점/checkOn_over.png");
		hpCheck->SetPosition(510, 90, 0);
		hpCheck->SetShow(false);
		this->AddChild(hpCheck);
	}

	if (hpUnCheck == nullptr){
		hpUnCheck = new UI_Button;
		hpUnCheck->SetTexture("./상점/checkOff_normal.png", "./상점/checkOff_over.png", "./상점/checkOn_click.png");
		hpUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), hpUnCheck, &item->commonHpSkill);
		hpUnCheck->SetPosition(510, 90, 0);
		hpUnCheck->SetShow(true);
		this->AddChild(hpUnCheck);
	}

	//mp회복
	if (mp == nullptr){
		mp = new UI_Image;
		mp->SetTexture("./상점/마나회복.PNG");
		mp->SetPosition(54, 54+100, 0);
		this->AddChild(mp);
	}

	if (mpName == nullptr){
		mpName = new UI_Text;
		mpName->SetFont(font);
		mpName->SetPosition(150, 30 + 100, 0);
		mpName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
		mpName->SetSize(200, 100);
		mpName->SetText("마나회복 증가");
		this->AddChild(mpName);
	}

	if (mpDesc == nullptr){
		mpDesc = new UI_Text;
		mpDesc->SetFont(font2);
		mpDesc->SetPosition(180, 110 + 100, 0);
		mpDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpDesc->SetTextFormat(DT_WORDBREAK);
		mpDesc->SetSize(1000, 120);
		mpDesc->SetText("마나회복이 150추가 한다");
		this->AddChild(mpDesc);
	}

	if (mpPrice == nullptr){
		mpPrice = new UI_Text;
		mpPrice->SetFont(font2);
		mpPrice->SetPosition(350, 70 + 100, 0);
		mpPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpPrice->SetTextFormat(DT_WORDBREAK);
		mpPrice->SetSize(1000, 120);
		mpPrice->SetText("가격 : 1000");
		this->AddChild(mpPrice);
	}

	if (mpCheck == nullptr){
		mpCheck = new UI_Image;
		mpCheck->SetTexture("./상점/checkOn_over.png");
		mpCheck->SetPosition(510, 90 + 100, 0);
		mpCheck->SetShow(false);
		this->AddChild(mpCheck);
	}

	if (mpUnCheck == nullptr){
		mpUnCheck = new UI_Button;
		mpUnCheck->SetTexture("./상점/checkOff_normal.png", "./상점/checkOff_over.png", "./상점/checkOn_click.png");
		mpUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), mpUnCheck, &item->commonMpSkill);
		mpUnCheck->SetPosition(510, 90 + 100, 0);
		mpUnCheck->SetShow(true);
		this->AddChild(mpUnCheck);
	}

	position.x = 950;
	position.y = 10;
}

void SupportSkillTap::Update()
{
	if (isShow != true)
	{
		return;
	}

	if (item->commonHpSkillLearn || item->commonHpSkill){
		hpCheck->SetShow(true);
		hpUnCheck->SetShow(false);
	}
	else{
		hpCheck->SetShow(false);
		hpUnCheck->SetShow(true);
	}

	if (item->commonMpSkillLearn || item->commonMpSkill){
		mpCheck->SetShow(true);
		mpUnCheck->SetShow(false);
	}
	else{
		mpCheck->SetShow(false);
		mpUnCheck->SetShow(true);
	}


	UI_Base::Update();
}

void SupportSkillTap::Render()
{
	if (isShow != true)
	{
		return;
	}
	
	UI_Base::Render();
}

LRESULT SupportSkillTap::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

void SupportSkillTap::Destroy(){
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
}