#include "stdafx.h"
#include "UsedItemTab.h"


UsedItemTab::UsedItemTab()
{
}


UsedItemTab::~UsedItemTab()
{
}
void UsedItemTab::Initialize()
{
	if (item == nullptr){
		item = new Item;
	}
	
	isShow = true;

	//��Ʈ ����
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
	wcscpy_s(font_desc.FaceName, L"simple");	//�۲� ��Ÿ��
	//AddFontResource(L"./Data/Font/kodia.ttf");
	//wcscpy_s(font_desc.FaceName, L"kodia");
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc, &font);

	//��Ʈ ����
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
	wcscpy_s(font_desc2.FaceName, L"simple2");	//�۲� ��Ÿ��
	//AddFontResource(L"./Data/Font/umberto.ttf");
	//wcscpy_s(font_desc.FaceName, L"umberto");
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc2, &font2);

	if (background == nullptr){
		background = new UI_Image;
		background->SetTexture("./����/ItemTab.png");
		background->SetPosition(0, 0, 0);
		this->size = background->GetSize();
		this->AddChild(background);
	}

	if (buy == nullptr){
		buy = new UI_Button;
		buy->SetTexture("./����/buy_normal.png", "./����/buy_over.png", "./����/buy_click.png");
		buy->OnClick = std::bind(&UI_Functions::ButtonBuy, std::ref(UI_Manager::Get().func), buy,item);
		buy->SetPosition(200, 750, 0);
		this->AddChild(buy);
	}

	for (int i = 0; i < 6; i++){
		list[i] = new UI_Image;
		list[i]->SetTexture("./����/list.png");
		list[i]->SetPosition(50, 50 + i*100, 0);
		this->AddChild(list[i]);
	}

	if (tabOut == nullptr){
		tabOut = new UI_Button;
		tabOut->SetTexture("./����/TabOutNormal.png", "./����/TabOutOver.png", "./����/TabOutClick.png");
		tabOut->OnClick = std::bind(&UI_Functions::ButtonCancel, std::ref(UI_Manager::Get().func), tabOut, item);
		tabOut->SetPosition(565, 15, 0);
		this->AddChild(tabOut);
	}

	//hp
	if (hpPotion == nullptr){
		hpPotion = new UI_Image;
		hpPotion->SetTexture("./����/hpPotion2.png");
		hpPotion->SetPosition(54, 54, 0);
		this->AddChild(hpPotion);
	}

	if (hpName == nullptr){
		hpName = new UI_Text;
		hpName->SetFont(font);
		hpName->SetPosition(90, 30, 0);
		hpName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
		hpName->SetSize(200, 100);
		hpName->SetText("HP ����");
		this->AddChild(hpName);
	}
	
	if (hpDesc == nullptr){
		hpDesc = new UI_Text;
		hpDesc->SetFont(font2);
		hpDesc->SetPosition(180, 110, 0);
		hpDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpDesc->SetTextFormat(DT_WORDBREAK);
		hpDesc->SetSize(1000, 120);
		hpDesc->SetText("ü���� 1500 ȸ���Ѵ�");
		this->AddChild(hpDesc);
	}
	
	if (hpPrice == nullptr){
		hpPrice = new UI_Text;
		hpPrice->SetFont(font2);
		hpPrice->SetPosition(350, 70, 0);
		hpPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpPrice->SetTextFormat(DT_WORDBREAK);
		hpPrice->SetSize(1000, 120);
		hpPrice->SetText("���� : 1000");
		this->AddChild(hpPrice);
	}

	if (hpNum == nullptr){
		hpNum = new UI_Text;
		hpNum->SetFont(font2);
		hpNum->SetPosition(480, 115, 0);
		hpNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpNum->SetTextFormat(DT_WORDBREAK);
		hpNum->SetSize(1000, 120);
		hpNum->SetText("x0");		//�������� ������ ������
		this->AddChild(hpNum);
	}

	if (hpUp == nullptr){
		hpUp = new UI_Button;
		hpUp->SetTexture("./����/up_normal.png", "./����/up_over.png", "./����/up_click.png");
		hpUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), hpUp,&item->hpPotion);
		hpUp->SetPosition(510, 60, 0);
		this->AddChild(hpUp);
	}

	if (hpDown == nullptr){
		hpDown = new UI_Button;
		hpDown->SetTexture("./����/down_normal.png", "./����/down_over.png", "./����/down_click.png");
		hpDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), hpDown, &item->hpPotion);
		hpDown->SetPosition(510, 110, 0);
		this->AddChild(hpDown);
	}

	//mp
	if (mpPotion == nullptr){
		mpPotion = new UI_Image;
		mpPotion->SetTexture("./����/mpPotion2.png");
		mpPotion->SetPosition(54, 54 + 100, 0);
		this->AddChild(mpPotion);
	}

	if (mpName == nullptr){
		mpName = new UI_Text;
		mpName->SetFont(font);
		mpName->SetPosition(90, 30 + 100, 0);
		mpName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpName->SetTextFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);
		mpName->SetSize(200, 100);
		mpName->SetText("MP ����");
		this->AddChild(mpName);
	}

	if (mpDesc == nullptr){
		mpDesc = new UI_Text;
		mpDesc->SetFont(font2);
		mpDesc->SetPosition(180, 110 + 100, 0);
		mpDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpDesc->SetTextFormat(DT_WORDBREAK);
		mpDesc->SetSize(1000, 120);
		mpDesc->SetText("������ 2000 ȸ���Ѵ�");
		this->AddChild(mpDesc);
	}

	if (mpPrice == nullptr){
		mpPrice = new UI_Text;
		mpPrice->SetFont(font2);
		mpPrice->SetPosition(350, 70 + 100, 0);
		mpPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpPrice->SetTextFormat(DT_WORDBREAK);
		mpPrice->SetSize(1000, 120);
		mpPrice->SetText("���� : 1200");
		this->AddChild(mpPrice);
	}

	if (mpNum == nullptr){
		mpNum = new UI_Text;
		mpNum->SetFont(font2);
		mpNum->SetPosition(480, 115 + 100, 0);
		mpNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpNum->SetTextFormat(DT_WORDBREAK);
		mpNum->SetSize(1000, 120);
		mpNum->SetText("x0");		//�������� ������ ������
		this->AddChild(mpNum);
	}

	if (mpUp == nullptr){
		mpUp = new UI_Button;
		mpUp->SetTexture("./����/up_normal.png", "./����/up_over.png", "./����/up_click.png");
		mpUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), mpUp, &item->mpPotion);
		mpUp->SetPosition(510, 60 + 100, 0);
		this->AddChild(mpUp);
	}

	if (mpDown == nullptr){
		mpDown = new UI_Button;
		mpDown->SetTexture("./����/down_normal.png", "./����/down_over.png", "./����/down_click.png");
		mpDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), mpDown, &item->mpPotion);
		mpDown->SetPosition(510, 110 + 100, 0);
		this->AddChild(mpDown);
	}

	//attackBuff
	if (attackBuff == nullptr){
		attackBuff = new UI_Image;
		attackBuff->SetTexture("./����/powerHerb2.png");
		attackBuff->SetPosition(54, 54 + 100 + 100, 0);
		this->AddChild(attackBuff);
	}

	if (attackBuffName == nullptr){
		attackBuffName = new UI_Text;
		attackBuffName->SetFont(font);
		attackBuffName->SetPosition(140, 30 + 100 + 100, 0);
		attackBuffName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		attackBuffName->SetSize(200, 100);
		attackBuffName->SetText("�Ŀ� ���");
		this->AddChild(attackBuffName);
	}

	if (attackBuffDesc == nullptr){
		attackBuffDesc = new UI_Text;
		attackBuffDesc->SetFont(font2);
		attackBuffDesc->SetPosition(180, 110 + 100 + 100, 0);
		attackBuffDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffDesc->SetTextFormat(DT_WORDBREAK);
		attackBuffDesc->SetSize(1000, 120);
		attackBuffDesc->SetText("10�ʵ��� ���ݷ��� 300���� ��Ų��");
		this->AddChild(attackBuffDesc);
	}

	if (attackBuffPrice == nullptr){
		attackBuffPrice = new UI_Text;
		attackBuffPrice->SetFont(font2);
		attackBuffPrice->SetPosition(350, 70 + 100 + 100, 0);
		attackBuffPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffPrice->SetTextFormat(DT_WORDBREAK);
		attackBuffPrice->SetSize(1000, 120);
		attackBuffPrice->SetText("���� : 2000");
		this->AddChild(attackBuffPrice);
	}

	if (attackBuffNum == nullptr){
		attackBuffNum = new UI_Text;
		attackBuffNum->SetFont(font2);
		attackBuffNum->SetPosition(480, 115 + 100 + 100, 0);
		attackBuffNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffNum->SetTextFormat(DT_WORDBREAK);
		attackBuffNum->SetSize(1000, 120);
		attackBuffNum->SetText("x0");		//�������� ������ ������
		this->AddChild(attackBuffNum);
	}

	if (attackBuffUp == nullptr){
		attackBuffUp = new UI_Button;
		attackBuffUp->SetTexture("./����/up_normal.png", "./����/up_over.png", "./����/up_click.png");
		attackBuffUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), attackBuffUp, &item->attackBuff);
		attackBuffUp->SetPosition(510, 60 + 100 + 100, 0);
		this->AddChild(attackBuffUp);
	} 

	if (attackBuffDown == nullptr){
		attackBuffDown = new UI_Button;
		attackBuffDown->SetTexture("./����/down_normal.png", "./����/down_over.png", "./����/down_click.png");
		attackBuffDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), attackBuffDown, &item->attackBuff);
		attackBuffDown->SetPosition(510, 110 + 100 + 100, 0);
		this->AddChild(attackBuffDown);
	}

	//defenceBuff
	if (defenceBuff == nullptr){
		defenceBuff = new UI_Image;
		defenceBuff->SetTexture("./����/ArmorPotion2.png");
		defenceBuff->SetPosition(54, 54 + 100 + 100 + 100, 0);
		this->AddChild(defenceBuff);
	}

	if (defenceBuffName == nullptr){
		defenceBuffName = new UI_Text;
		defenceBuffName->SetFont(font);
		defenceBuffName->SetPosition(140, 30 + 100 + 100 + 100, 0);
		defenceBuffName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defenceBuffName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		defenceBuffName->SetSize(200, 100);
		defenceBuffName->SetText("�Ƹ� ����");
		this->AddChild(defenceBuffName);
	}

	if (defenceBuffDesc == nullptr){
		defenceBuffDesc = new UI_Text;
		defenceBuffDesc->SetFont(font2);
		defenceBuffDesc->SetPosition(180, 110 + 100 + 100 + 100, 0);
		defenceBuffDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defenceBuffDesc->SetTextFormat(DT_WORDBREAK);
		defenceBuffDesc->SetSize(1000, 120);
		defenceBuffDesc->SetText("10�ʵ��� ������ 200���� ��Ų��");
		this->AddChild(defenceBuffDesc);
	}

	if (defenceBuffPrice == nullptr){
		defenceBuffPrice = new UI_Text;
		defenceBuffPrice->SetFont(font2);
		defenceBuffPrice->SetPosition(350, 70 + 100 + 100 + 100, 0);
		defenceBuffPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defenceBuffPrice->SetTextFormat(DT_WORDBREAK);
		defenceBuffPrice->SetSize(1000, 120);
		defenceBuffPrice->SetText("���� : 1500");
		this->AddChild(defenceBuffPrice);
	}

	if (defenceBuffNum == nullptr){
		defenceBuffNum = new UI_Text;
		defenceBuffNum->SetFont(font2);
		defenceBuffNum->SetPosition(480, 115 + 100 + 100 + 100, 0);
		defenceBuffNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		defenceBuffNum->SetTextFormat(DT_WORDBREAK);
		defenceBuffNum->SetSize(1000, 120);
		defenceBuffNum->SetText("x0");		//�������� ������ ������
		this->AddChild(defenceBuffNum);
	}

	if (defenceBuffUp == nullptr){
		defenceBuffUp = new UI_Button;
		defenceBuffUp->SetTexture("./����/up_normal.png", "./����/up_over.png", "./����/up_click.png");
		defenceBuffUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), defenceBuffUp, &item->armorBuff);
		defenceBuffUp->SetPosition(510, 60 + 100 + 100 + 100, 0);
		this->AddChild(defenceBuffUp);
	}

	if (defenceBuffDown == nullptr){
		defenceBuffDown = new UI_Button;
		defenceBuffDown->SetTexture("./����/down_normal.png", "./����/down_over.png", "./����/down_click.png");
		defenceBuffDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), defenceBuffDown, &item->armorBuff);
		defenceBuffDown->SetPosition(510, 110 + 100 + 100 + 100, 0);
		this->AddChild(defenceBuffDown);
	}

	//attack
	if (attack == nullptr){
		attack = new UI_Image;
		attack->SetTexture("./����/Attack2.png");
		attack->SetPosition(54, 54 + 100 + 100 + 100 + 100, 0);
		this->AddChild(attack);
	}

	if (attackName == nullptr){
		attackName = new UI_Text;
		attackName->SetFont(font);
		attackName->SetPosition(140, 30 + 100 + 100 + 100 + 100, 0);
		attackName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		attackName->SetSize(200, 100);
		attackName->SetText("���Ͽ� �ܰ�");
		this->AddChild(attackName);
	}

	if (attackDesc == nullptr){
		attackDesc = new UI_Text;
		attackDesc->SetFont(font2);
		attackDesc->SetPosition(180, 100 + 100 + 100 + 100 + 100, 0);
		attackDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackDesc->SetTextFormat(DT_WORDBREAK);
		attackDesc->SetSize(350, 120);
		attackDesc->SetText("Ÿ���õ� ��뿡�� �ٰ��� 3�ʰ� ������Ų��");
		this->AddChild(attackDesc);
	}

	if (attackPrice == nullptr){
		attackPrice = new UI_Text;
		attackPrice->SetFont(font2);
		attackPrice->SetPosition(350, 70 + 100 + 100 + 100 + 100, 0);
		attackPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackPrice->SetTextFormat(DT_WORDBREAK);
		attackPrice->SetSize(1000, 120);
		attackPrice->SetText("���� : 2500");
		this->AddChild(attackPrice);
	}

	if (attackNum == nullptr){
		attackNum = new UI_Text;
		attackNum->SetFont(font2);
		attackNum->SetPosition(480, 115 + 100 + 100 + 100 + 100, 0);
		attackNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackNum->SetTextFormat(DT_WORDBREAK);
		attackNum->SetSize(1000, 120);
		attackNum->SetText("x0");		//�������� ������ ������
		this->AddChild(attackNum);
	}

	if (attackUp == nullptr){
		attackUp = new UI_Button;
		attackUp->SetTexture("./����/up_normal.png", "./����/up_over.png", "./����/up_click.png");
		attackUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), attackUp, &item->revenge);
		attackUp->SetPosition(510, 60 + 100 + 100 + 100 + 100, 0);

		this->AddChild(attackUp);
	}

	if (attackDown == nullptr){
		attackDown = new UI_Button;
		attackDown->SetTexture("./����/down_normal.png", "./����/down_over.png", "./����/down_click.png");
		attackDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), attackDown, &item->revenge);
		attackDown->SetPosition(510, 110 + 100 + 100 + 100 + 100, 0);
		this->AddChild(attackDown);
	}

	//Invincible
	if (invincible == nullptr){
		invincible = new UI_Image;
		invincible->SetTexture("./����/dispell2.png");
		invincible->SetPosition(54, 54 + 100 + 100 + 100 + 100 + 100, 0);
		this->AddChild(invincible);
	}

	if (invincibleName == nullptr){
		invincibleName = new UI_Text;
		invincibleName->SetFont(font);
		invincibleName->SetPosition(140, 30 + 100 + 100 + 100 + 100 + 100, 0);
		invincibleName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleName->SetTextFormat(DT_VCENTER | DT_WORDBREAK);
		invincibleName->SetSize(200, 100);
		invincibleName->SetText("���� �ֹ���");
		this->AddChild(invincibleName);
	}

	if (invincibleDesc == nullptr){
		invincibleDesc = new UI_Text;
		invincibleDesc->SetFont(font2);
		invincibleDesc->SetPosition(180, 110 + 100 + 100 + 100 + 100 + 100, 0);
		invincibleDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleDesc->SetTextFormat(DT_WORDBREAK);
		invincibleDesc->SetSize(350, 120);
		invincibleDesc->SetText("3�ʰ� �������°� �ȴ�");
		this->AddChild(invincibleDesc);
	}

	if (invinciblePrice == nullptr){
		invinciblePrice = new UI_Text;
		invinciblePrice->SetFont(font2);
		invinciblePrice->SetPosition(350, 70 + 100 + 100 + 100 + 100 + 100, 0);
		invinciblePrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invinciblePrice->SetTextFormat(DT_WORDBREAK);
		invinciblePrice->SetSize(1000, 120);
		invinciblePrice->SetText("���� : 3000");
		this->AddChild(invinciblePrice);
	}

	if (invincibleNum == nullptr){
		invincibleNum = new UI_Text;
		invincibleNum->SetFont(font2);
		invincibleNum->SetPosition(480, 115 + 100 + 100 + 100 + 100 + 100, 0);
		invincibleNum->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleNum->SetTextFormat(DT_WORDBREAK);
		invincibleNum->SetSize(1000, 120);
		invincibleNum->SetText("x0");		//�������� ������ ������
		this->AddChild(invincibleNum);
	}

	if (invincibleUp == nullptr){
		invincibleUp = new UI_Button;
		invincibleUp->SetTexture("./����/up_normal.png", "./����/up_over.png", "./����/up_click.png");
		invincibleUp->OnClick = std::bind(&UI_Functions::ButtonUp, std::ref(UI_Manager::Get().func), invincibleUp, &item->invincible);
		invincibleUp->SetPosition(510, 60 + 100 + 100 + 100 + 100 + 100, 0);
		this->AddChild(invincibleUp);
	}

	if (invincibleDown == nullptr){
		invincibleDown = new UI_Button;
		invincibleDown->SetTexture("./����/down_normal.png", "./����/down_over.png", "./����/down_click.png");
		invincibleDown->OnClick = std::bind(&UI_Functions::ButtonDown, std::ref(UI_Manager::Get().func), invincibleDown, &item->invincible);
		invincibleDown->SetPosition(510, 110 + 100 + 100 + 100 + 100 + 100, 0);
		this->AddChild(invincibleDown);
	}

	position.x = 950;
	position.y = 10;
}

void UsedItemTab::Update()
{
	if (isShow != true)
	{
		return;
	}

	if (hpNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->hpPotion, str2, 10);
		strcat_s(str, str2);
		hpNum->SetText(str);
	}

	if (mpNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->mpPotion, str2, 10);
		strcat_s(str, str2);
		mpNum->SetText(str);
	}

	if (attackBuffNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->attackBuff, str2, 10);
		strcat_s(str, str2);
		attackBuffNum->SetText(str);
	}

	if (defenceBuffNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->armorBuff, str2, 10);
		strcat_s(str, str2);
		defenceBuffNum->SetText(str);
	}

	if (attackNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->revenge, str2, 10);
		strcat_s(str, str2);
		attackNum->SetText(str);
	}

	if (invincibleNum){
		char str[4] = "x";
		char str2[4];
		_itoa_s(item->invincible, str2, 10);
		strcat_s(str, str2);
		invincibleNum->SetText(str);
	}
	UI_Base::Update();
}

void UsedItemTab::Render()
{
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();
}

LRESULT UsedItemTab::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
				//��������. �巡�� ����
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

void UsedItemTab::Destroy(){
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
}