#include "stdafx.h"
#include "SkillTab.h"


SkillTab::SkillTab()
{
}


SkillTab::~SkillTab()
{
}


void SkillTab::Initialize(Item* _item,int _character)
{
	//���߿� ����ĳ���������� ���� ����
	character = _character;

	if (item == nullptr){
		item = new Item;
		item->artifact = _item->artifact;

		
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
		buy->OnClick = std::bind(&UI_Functions::ButtonBuy, std::ref(UI_Manager::Get().func), buy, item);
		buy->SetPosition(200, 750, 0);
		this->AddChild(buy);
	}

	switch (character){
	case 1:
		for (int i = 0; i < 4; i++){
			list[i] = new UI_Image;
			list[i]->SetTexture("./����/list.png");
			list[i]->SetPosition(50, 50 + i * 100, 0);
			this->AddChild(list[i]);
		}
		
		break;
	case 2:
		for (int i = 0; i < 2; i++){
			list[i] = new UI_Image;
			list[i]->SetTexture("./����/list.png");
			list[i]->SetPosition(50, 50 + i * 100, 0);
			this->AddChild(list[i]);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++){
			list[i] = new UI_Image;
			list[i]->SetTexture("./����/list.png");
			list[i]->SetPosition(50, 50 + i * 100, 0);
			this->AddChild(list[i]);
		}
		break;
		
	}

	if (tabOut == nullptr){
		tabOut = new UI_Button;
		tabOut->SetTexture("./����/TabOutNormal.png", "./����/TabOutOver.png", "./����/TabOutClick.png");
		tabOut->OnClick = std::bind(&UI_Functions::ButtonCancel, std::ref(UI_Manager::Get().func), tabOut, item);
		tabOut->SetPosition(565, 15, 0);
		this->AddChild(tabOut);
	}

	switch (character){
	case 1:
		//���
		//��������
		if (sniper == nullptr){
			sniper = new UI_Image;
			sniper->SetTexture("./����/����2.jpg");
			sniper->SetPosition(54, 54 , 0);
			this->AddChild(sniper);
		}

		if (sniperName == nullptr){
			sniperName = new UI_Text;
			sniperName->SetFont(font);
			sniperName->SetPosition(150, 30 , 0);
			sniperName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			sniperName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			sniperName->SetSize(200, 100);
			sniperName->SetText("���� ��ȭ");
			this->AddChild(sniperName);
		}

		if (sniperDesc == nullptr){
			sniperDesc = new UI_Text;
			sniperDesc->SetFont(font2);
			sniperDesc->SetPosition(180, 110 , 0);
			sniperDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			sniperDesc->SetTextFormat(DT_WORDBREAK);
			sniperDesc->SetSize(1000, 120);
			sniperDesc->SetText("���� ��ų �������� 200�߰��Ѵ�");
			this->AddChild(sniperDesc);
		}

		if (sniperPrice == nullptr){
			sniperPrice = new UI_Text;
			sniperPrice->SetFont(font2);
			sniperPrice->SetPosition(350, 70 , 0);
			sniperPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			sniperPrice->SetTextFormat(DT_WORDBREAK);
			sniperPrice->SetSize(1000, 120);
			sniperPrice->SetText("���� : 2500");
			this->AddChild(sniperPrice);
		}

		if (sniperCheck == nullptr){
			sniperCheck = new UI_Image;
			sniperCheck->SetTexture("./����/checkOn_over.png");
			sniperCheck->SetPosition(510, 90, 0);
			sniperCheck->SetShow(false);
			this->AddChild(sniperCheck);
		}

		if (sniperUnCheck == nullptr){
			sniperUnCheck = new UI_Button;
			sniperUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			sniperUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), sniperUnCheck, &item->sniperSkill);
			sniperUnCheck->SetPosition(510, 90 , 0);
			sniperUnCheck->SetShow(true);
			this->AddChild(sniperUnCheck);
		}

		//���丮��
		if (hyperion == nullptr){
			hyperion = new UI_Image;
			hyperion->SetTexture("./����/���丮��2.jpg");
			hyperion->SetPosition(54, 54 + 100, 0);
			this->AddChild(hyperion);
		}

		if (hyperionName == nullptr){
			hyperionName = new UI_Text;
			hyperionName->SetFont(font);
			hyperionName->SetPosition(150, 30 + 100, 0);
			hyperionName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			hyperionName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			hyperionName->SetSize(200, 100);
			hyperionName->SetText("���丮�� ��ȭ");
			this->AddChild(hyperionName);
		}

		if (hyperionDesc == nullptr){
			hyperionDesc = new UI_Text;
			hyperionDesc->SetFont(font2);
			hyperionDesc->SetPosition(180, 110 + 100, 0);
			hyperionDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			hyperionDesc->SetTextFormat(DT_WORDBREAK);
			hyperionDesc->SetSize(1000, 120);
			hyperionDesc->SetText("���丮�� ��ų �������� 400�߰��Ѵ�");
			this->AddChild(hyperionDesc);
		}

		if (hyperionPrice == nullptr){
			hyperionPrice = new UI_Text;
			hyperionPrice->SetFont(font2);
			hyperionPrice->SetPosition(350, 70 + 100, 0);
			hyperionPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			hyperionPrice->SetTextFormat(DT_WORDBREAK);
			hyperionPrice->SetSize(1000, 120);
			hyperionPrice->SetText("���� : 3000");
			this->AddChild(hyperionPrice);
		}

		if (hyperionCheck == nullptr){
			hyperionCheck = new UI_Image;
			hyperionCheck->SetTexture("./����/checkOn_over.png");
			hyperionCheck->SetPosition(510, 90 + 100, 0);
			hyperionCheck->SetShow(false);
			this->AddChild(hyperionCheck);
		}

		if (hyperionUnCheck == nullptr){
			hyperionUnCheck = new UI_Button;
			hyperionUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			hyperionUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), hyperionUnCheck, &item->hyperionSkill);
			hyperionUnCheck->SetPosition(510, 90 + 100, 0);
			hyperionUnCheck->SetShow(true);
			this->AddChild(hyperionUnCheck);
		}

		//�����ѹ������
		if (powerUp == nullptr){
			powerUp = new UI_Image;
			powerUp->SetTexture("./����/�����ѹ���2.jpg");
			powerUp->SetPosition(54, 54 + 100 + 100, 0);
			this->AddChild(powerUp);
		}

		if (powerUpName == nullptr){
			powerUpName = new UI_Text;
			powerUpName->SetFont(font);
			powerUpName->SetPosition(150, 30 + 100 + 100, 0);
			powerUpName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			powerUpName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			powerUpName->SetSize(200, 100);
			powerUpName->SetText("�����ѹ��� ��ȭ");
			this->AddChild(powerUpName);
		}

		if (powerUpDesc == nullptr){
			powerUpDesc = new UI_Text;
			powerUpDesc->SetFont(font2);
			powerUpDesc->SetPosition(180, 110 + 100 + 100, 0);
			powerUpDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			powerUpDesc->SetTextFormat(DT_WORDBREAK);
			powerUpDesc->SetSize(1000, 120);
			powerUpDesc->SetText("���ݷ��� 200�߰� �Ѵ�");
			this->AddChild(powerUpDesc);
		}

		if (powerUpPrice == nullptr){
			powerUpPrice = new UI_Text;
			powerUpPrice->SetFont(font2);
			powerUpPrice->SetPosition(350, 70 + 100 + 100, 0);
			powerUpPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			powerUpPrice->SetTextFormat(DT_WORDBREAK);
			powerUpPrice->SetSize(1000, 120);
			powerUpPrice->SetText("���� : 2000");
			this->AddChild(powerUpPrice);
		}

		if (powerUpCheck == nullptr){
			powerUpCheck = new UI_Image;
			powerUpCheck->SetTexture("./����/checkOn_over.png");
			powerUpCheck->SetPosition(510, 90 + 100 + 100, 0);
			powerUpCheck->SetShow(false);
			this->AddChild(powerUpCheck);
		}

		if (powerUpUnCheck == nullptr){
			powerUpUnCheck = new UI_Button;
			powerUpUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			powerUpUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), powerUpUnCheck, &item->powerUpSkill);
			powerUpUnCheck->SetPosition(510, 90 + 100 + 100, 0);
			powerUpUnCheck->SetShow(true);
			this->AddChild(powerUpUnCheck);
		}

		//��
		if (nuclear == nullptr){
			nuclear = new UI_Image;
			nuclear->SetTexture("./����/��2.jpg");
			nuclear->SetPosition(54, 54 + 100 + 100 + 100, 0);
			this->AddChild(nuclear);
		}

		if (nuclearName == nullptr){
			nuclearName = new UI_Text;
			nuclearName->SetFont(font);
			nuclearName->SetPosition(150, 30 + 100 + 100 + 100, 0);
			nuclearName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			nuclearName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			nuclearName->SetSize(200, 100);
			nuclearName->SetText("�� ��ȭ");
			this->AddChild(nuclearName);
		}

		if (nuclearDesc == nullptr){
			nuclearDesc = new UI_Text;
			nuclearDesc->SetFont(font2);
			nuclearDesc->SetPosition(180, 110 + 100 + 100 + 100, 0);
			nuclearDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			nuclearDesc->SetTextFormat(DT_WORDBREAK);
			nuclearDesc->SetSize(1000, 120);
			nuclearDesc->SetText("�� ��ų �������� 500 �߰��Ѵ�");
			this->AddChild(nuclearDesc);
		}

		if (nuclearPrice == nullptr){
			nuclearPrice = new UI_Text;
			nuclearPrice->SetFont(font2);
			nuclearPrice->SetPosition(350, 70 + 100 + 100 + 100, 0);
			nuclearPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			nuclearPrice->SetTextFormat(DT_WORDBREAK);
			nuclearPrice->SetSize(1000, 120);
			nuclearPrice->SetText("���� : 4000");
			this->AddChild(nuclearPrice);
		}

		if (nuclearCheck == nullptr){
			nuclearCheck = new UI_Image;
			nuclearCheck->SetTexture("./����/checkOn_over.png");
			nuclearCheck->SetPosition(510, 90 + 100 + 100 + 100, 0);
			nuclearCheck->SetShow(false);
			this->AddChild(nuclearCheck);
		}

		if (nuclearUnCheck == nullptr){
			nuclearUnCheck = new UI_Button;
			nuclearUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			nuclearUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), nuclearUnCheck, &item->nuclearSkill );
			nuclearUnCheck->SetPosition(510, 90 + 100 + 100 + 100, 0);
			nuclearUnCheck->SetShow(true);
			this->AddChild(nuclearUnCheck);
		}

		break;

case 2:
	//���ѳ�
	//��ö�Ǻ�
	if (armorBuff == nullptr){
		armorBuff = new UI_Image;
		armorBuff->SetTexture("./����/��ö�Ǻ�2.PNG");
		armorBuff->SetPosition(54, 54, 0);
		this->AddChild(armorBuff);
	}

	if (armorBuffName == nullptr){
		armorBuffName = new UI_Text;
		armorBuffName->SetFont(font);
		armorBuffName->SetPosition(150, 30, 0);
		armorBuffName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		armorBuffName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
		armorBuffName->SetSize(200, 100);
		armorBuffName->SetText("��ö�Ǻ� ��ȭ");
		this->AddChild(armorBuffName);
	}

	if (armorBuffDesc == nullptr){
		armorBuffDesc = new UI_Text;
		armorBuffDesc->SetFont(font2);
		armorBuffDesc->SetPosition(180, 110, 0);
		armorBuffDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		armorBuffDesc->SetTextFormat(DT_WORDBREAK);
		armorBuffDesc->SetSize(1000, 120);
		armorBuffDesc->SetText("������ 150�߰� �Ѵ�");
		this->AddChild(armorBuffDesc);
	}

	if (armorBuffPrice == nullptr){
		armorBuffPrice = new UI_Text;
		armorBuffPrice->SetFont(font2);
		armorBuffPrice->SetPosition(350, 70, 0);
		armorBuffPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		armorBuffPrice->SetTextFormat(DT_WORDBREAK);
		armorBuffPrice->SetSize(1000, 120);
		armorBuffPrice->SetText("���� : 2500");
		this->AddChild(armorBuffPrice);
	}

	if (armorCheck == nullptr){
		armorCheck = new UI_Image;
		armorCheck->SetTexture("./����/checkOn_over.png");
		armorCheck->SetPosition(510, 90, 0);
		armorCheck->SetShow(false);
		this->AddChild(armorCheck);
	}

	if (armorUnCheck == nullptr){
		armorUnCheck = new UI_Button;
		armorUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
		armorUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), armorUnCheck, &item->armorSkillUp);
		armorUnCheck->SetPosition(510, 90, 0);
		armorUnCheck->SetShow(true);
		this->AddChild(armorUnCheck);
	}

	//��ź
	if (attackBuff == nullptr){
		attackBuff = new UI_Image;
		attackBuff->SetTexture("./����/��ź2.PNG");
		attackBuff->SetPosition(54, 54 + 100, 0);
		this->AddChild(attackBuff);
	}

	if (attackBuffName == nullptr){
		attackBuffName = new UI_Text;
		attackBuffName->SetFont(font);
		attackBuffName->SetPosition(150, 30 + 100, 0);
		attackBuffName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
		attackBuffName->SetSize(200, 100);
		attackBuffName->SetText("��ź ��ȭ");
		this->AddChild(attackBuffName);
	}

	if (attackBuffDesc == nullptr){
		attackBuffDesc = new UI_Text;
		attackBuffDesc->SetFont(font2);
		attackBuffDesc->SetPosition(180, 110 + 100, 0);
		attackBuffDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffDesc->SetTextFormat(DT_WORDBREAK);
		attackBuffDesc->SetSize(1000, 120);
		attackBuffDesc->SetText("���ݷ��� 150�߰� �Ѵ�");
		this->AddChild(attackBuffDesc);
	}

	if (attackBuffPrice == nullptr){
		attackBuffPrice = new UI_Text;
		attackBuffPrice->SetFont(font2);
		attackBuffPrice->SetPosition(350, 70 + 100, 0);
		attackBuffPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffPrice->SetTextFormat(DT_WORDBREAK);
		attackBuffPrice->SetSize(1000, 120);
		attackBuffPrice->SetText("���� : 2500");
		this->AddChild(attackBuffPrice);
	}

	if (attackCheck == nullptr){
		attackCheck = new UI_Image;
		attackCheck->SetTexture("./����/checkOn_over.png");
		attackCheck->SetPosition(510, 90 + 100, 0);
		attackCheck->SetShow(false);
		this->AddChild(attackCheck);
	}

	if (attackUnCheck == nullptr){
		attackUnCheck = new UI_Button;
		attackUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
		attackUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), attackUnCheck, &item->attackSkillUp);
		attackUnCheck->SetPosition(510, 90 + 100, 0);
		attackUnCheck->SetShow(true);
		this->AddChild(attackUnCheck);
	}

	break;
		
	case 3:
		//���̳�
		
		if (ice == nullptr){
			ice = new UI_Image;
			ice->SetTexture("./����/������ȯ2.jpg");
			ice->SetPosition(54, 54, 0);
			this->AddChild(ice);
		}

		if (iceName == nullptr){
			iceName = new UI_Text;
			iceName->SetFont(font);
			iceName->SetPosition(150, 30, 0);
			iceName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			iceName->SetSize(200, 100);
			iceName->SetText("���� ��ȯ ��ȭ");
			this->AddChild(iceName);
		}

		if (iceDesc == nullptr){
			iceDesc = new UI_Text;
			iceDesc->SetFont(font2);
			iceDesc->SetPosition(180, 110, 0);
			iceDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceDesc->SetTextFormat(DT_WORDBREAK);
			iceDesc->SetSize(1000, 120);
			iceDesc->SetText("������ 2�� ��ȯ�Ѵ�.");
			this->AddChild(iceDesc);
		}

		if (icePrice == nullptr){
			icePrice = new UI_Text;
			icePrice->SetFont(font2);
			icePrice->SetPosition(350, 70, 0);
			icePrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			icePrice->SetTextFormat(DT_WORDBREAK);
			icePrice->SetSize(1000, 120);
			icePrice->SetText("���� : 2000");
			this->AddChild(icePrice);
		}

		if (iceCheck == nullptr){
			iceCheck = new UI_Image;
			iceCheck->SetTexture("./����/checkOn_over.png");
			iceCheck->SetPosition(510, 90, 0);
			iceCheck->SetShow(false);
			this->AddChild(iceCheck);
		}

		if (iceUnCheck == nullptr){
			iceUnCheck = new UI_Button;
			iceUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			iceUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), iceUnCheck, &item->iceSkill);
			iceUnCheck->SetPosition(510, 90, 0);
			iceUnCheck->SetShow(true);
			this->AddChild(iceUnCheck);
		}

		//�����߻�
		if (iceFire == nullptr){
			iceFire = new UI_Image;
			iceFire->SetTexture("./����/�����߻�2.jpg");
			iceFire->SetPosition(54, 54 + 100, 0);
			this->AddChild(iceFire);
		}

		if (iceFireName == nullptr){
			iceFireName = new UI_Text;
			iceFireName->SetFont(font);
			iceFireName->SetPosition(150, 30 + 100, 0);
			iceFireName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceFireName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			iceFireName->SetSize(200, 100);
			iceFireName->SetText("�����߻�");
			this->AddChild(iceFireName);
		}

		if (iceFireDesc == nullptr){
			iceFireDesc = new UI_Text;
			iceFireDesc->SetFont(font2);
			iceFireDesc->SetPosition(180, 110 + 100, 0);
			iceFireDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceFireDesc->SetTextFormat(DT_WORDBREAK);
			iceFireDesc->SetSize(1000, 120);
			iceFireDesc->SetText("������ ���󰡴� �ӵ��� �����Ѵ�.");
			this->AddChild(iceFireDesc);
		}

		if (iceFirePrice == nullptr){
			iceFirePrice = new UI_Text;
			iceFirePrice->SetFont(font2);
			iceFirePrice->SetPosition(350, 70 + 100, 0);
			iceFirePrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceFirePrice->SetTextFormat(DT_WORDBREAK);
			iceFirePrice->SetSize(1000, 120);
			iceFirePrice->SetText("���� : 2000");
			this->AddChild(iceFirePrice);
		}

		if (iceFireCheck == nullptr){
			iceFireCheck = new UI_Image;
			iceFireCheck->SetTexture("./����/checkOn_over.png");
			iceFireCheck->SetPosition(510, 90 + 100, 0);
			iceFireCheck->SetShow(false);
			this->AddChild(iceFireCheck);
		}

		if (iceFireUnCheck == nullptr){
			iceFireUnCheck = new UI_Button;
			iceFireUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			iceFireUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), iceFireUnCheck, &item->iceFireSkill);
			iceFireUnCheck->SetPosition(510, 90 + 100, 0);
			iceFireUnCheck->SetShow(true);
			this->AddChild(iceFireUnCheck);
		}

		//������ȭ
		if (icePower == nullptr){
			icePower = new UI_Image;
			icePower->SetTexture("./����/�������2.jpg");
			icePower->SetPosition(54, 54 + 100 + 100, 0);
			this->AddChild(icePower);
		}

		if (icePowerName == nullptr){
			icePowerName = new UI_Text;
			icePowerName->SetFont(font);
			icePowerName->SetPosition(150, 30 + 100 + 100, 0);
			icePowerName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			icePowerName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			icePowerName->SetSize(200, 100);
			icePowerName->SetText("������� ��ȭ");
			this->AddChild(icePowerName);
		}

		if (icePowerDesc == nullptr){
			icePowerDesc = new UI_Text;
			icePowerDesc->SetFont(font2);
			icePowerDesc->SetPosition(180, 110 + 100 + 100, 0);
			icePowerDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			icePowerDesc->SetTextFormat(DT_WORDBREAK);
			icePowerDesc->SetSize(1000, 120);
			icePowerDesc->SetText("����ȸ���� 300 �����Ѵ�.");
			this->AddChild(icePowerDesc);
		}

		if (icePowerPrice == nullptr){
			icePowerPrice = new UI_Text;
			icePowerPrice->SetFont(font2);
			icePowerPrice->SetPosition(350, 70 + 100 + 100, 0);
			icePowerPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			icePowerPrice->SetTextFormat(DT_WORDBREAK);
			icePowerPrice->SetSize(1000, 120);
			icePowerPrice->SetText("���� : 2000");
			this->AddChild(icePowerPrice);
		}

		if (icePowerCheck == nullptr){
			icePowerCheck = new UI_Image;
			icePowerCheck->SetTexture("./����/checkOn_over.png");
			icePowerCheck->SetPosition(510, 90 + 100 + 100, 0);
			icePowerCheck->SetShow(false);
			this->AddChild(icePowerCheck);
		}

		if (icePowerUnCheck == nullptr){
			icePowerUnCheck = new UI_Button;
			icePowerUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			icePowerUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), icePowerUnCheck, &item->icePowerSkill);
			icePowerUnCheck->SetPosition(510, 90 + 100 + 100, 0);
			icePowerUnCheck->SetShow(true);
			this->AddChild(icePowerUnCheck);
		}

		//���̽�����
		if (iceWorld == nullptr){
			iceWorld = new UI_Image;
			iceWorld->SetTexture("./����/���̽�����2.jpg");
			iceWorld->SetPosition(54, 54 + 100 + 100 + 100, 0);
			this->AddChild(iceWorld);
		}

		if (iceWorldName == nullptr){
			iceWorldName = new UI_Text;
			iceWorldName->SetFont(font);
			iceWorldName->SetPosition(150, 30 + 100 + 100 + 100, 0);
			iceWorldName->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceWorldName->SetTextFormat(DT_WORDBREAK | DT_VCENTER);
			iceWorldName->SetSize(200, 100);
			iceWorldName->SetText("���̽�����");
			this->AddChild(iceWorldName);
		}

		if (iceWorldDesc == nullptr){
			iceWorldDesc = new UI_Text;
			iceWorldDesc->SetFont(font2);
			iceWorldDesc->SetPosition(180, 110 + 100 + 100 + 100, 0);
			iceWorldDesc->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceWorldDesc->SetTextFormat(DT_WORDBREAK);
			iceWorldDesc->SetSize(1000, 120);
			iceWorldDesc->SetText("���� ��ȯ������ 150���� �����Ѵ�");
			this->AddChild(iceWorldDesc);
		}

		if (iceWorldPrice == nullptr){
			iceWorldPrice = new UI_Text;
			iceWorldPrice->SetFont(font2);
			iceWorldPrice->SetPosition(350, 70 + 100 + 100 + 100, 0);
			iceWorldPrice->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
			iceWorldPrice->SetTextFormat(DT_WORDBREAK);
			iceWorldPrice->SetSize(1000, 120);
			iceWorldPrice->SetText("���� : 4000");
			this->AddChild(iceWorldPrice);
		}

		if (iceWorldCheck == nullptr){
			iceWorldCheck = new UI_Image;
			iceWorldCheck->SetTexture("./����/checkOn_over.png");
			iceWorldCheck->SetPosition(510, 90 + 100 + 100 + 100, 0);
			iceWorldCheck->SetShow(false);
			this->AddChild(iceWorldCheck);
		}

		if (iceWorldUnCheck == nullptr){
			iceWorldUnCheck = new UI_Button;
			iceWorldUnCheck->SetTexture("./����/checkOff_normal.png", "./����/checkOff_over.png", "./����/checkOn_click.png");
			iceWorldUnCheck->OnClick = std::bind(&UI_Functions::ButtonSkillCheck, std::ref(UI_Manager::Get().func), iceWorldUnCheck, &item->iceWorldSkill);
			iceWorldUnCheck->SetPosition(510, 90 + 100 + 100 + 100, 0);
			iceWorldUnCheck->SetShow(true);
			this->AddChild(iceWorldUnCheck);
		}


		break;

	}
	position.x = 950;
	position.y = 10;
}

void SkillTab::Update()
{
	switch (character){
	
	case 1:
		if (item->sniperSkillLearn || item->sniperSkill){
			sniperCheck->SetShow(true);
			sniperUnCheck->SetShow(false);
		}
		else{
			sniperCheck->SetShow(false);
			sniperUnCheck->SetShow(true);
		}

		if (item->hyperionSkillLearn || item->hyperionSkill){
			hyperionCheck->SetShow(true);
			hyperionUnCheck->SetShow(false);
		}
		else{
			hyperionCheck->SetShow(false);
			hyperionUnCheck->SetShow(true);
		}

		if (item->powerUpSkillLearn || item->powerUpSkill){
			powerUpCheck->SetShow(true);
			powerUpUnCheck->SetShow(false);
		}
		else{
			powerUpCheck->SetShow(false);
			powerUpUnCheck->SetShow(true);
		}

		if (item->nuclearSkillLearn || item->nuclearSkill){
			nuclearCheck->SetShow(true);
			nuclearUnCheck->SetShow(false);
		}
		else{
			nuclearCheck->SetShow(false);
			nuclearUnCheck->SetShow(true);
		}
		break;

	case 2:
		if (item->armorSkillLearn || item->armorSkillUp){
			armorCheck->SetShow(true);
			armorUnCheck->SetShow(false);
		}
		else{
			armorCheck->SetShow(false);
			armorUnCheck->SetShow(true);
		}

		if (item->attackSkillLearn || item->attackSkillUp){
			attackCheck->SetShow(true);
			attackUnCheck->SetShow(false);
		}
		else{
			attackCheck->SetShow(false);
			attackUnCheck->SetShow(true);
		}
		break;
	case 3:
		if (item->iceSkillLearn || item->iceSkill){
			iceCheck->SetShow(true);
			iceUnCheck->SetShow(false);
		}
		else{
			iceCheck->SetShow(false);
			iceUnCheck->SetShow(true);
		}

		if (item->iceFireSkillLearn || item->iceFireSkill){
			iceFireCheck->SetShow(true);
			iceFireUnCheck->SetShow(false);
		}
		else{
			iceFireCheck->SetShow(false);
			iceFireUnCheck->SetShow(true);
		}

		if (item->icePowerSkillLearn || item->icePowerSkill){
			icePowerCheck->SetShow(true);
			icePowerUnCheck->SetShow(false);
		}
		else{
			icePowerCheck->SetShow(false);
			icePowerUnCheck->SetShow(true);
		}

		if (item->iceWorldSkillLearn || item->iceWorldSkill){
			iceWorldCheck->SetShow(true);
			iceWorldUnCheck->SetShow(false);
		}
		else{
			iceWorldCheck->SetShow(false);
			iceWorldUnCheck->SetShow(true);
		}
		break;
	}

	if (isShow != true)
	{
		return;
	}

	UI_Base::Update();
}

void SkillTab::Render()
{
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();
}

LRESULT SkillTab::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

void SkillTab::Destroy(){
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
}