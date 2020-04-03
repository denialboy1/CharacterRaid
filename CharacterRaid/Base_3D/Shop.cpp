#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
{
}


Shop::~Shop()
{
}

void Shop::Initialize(){


	//플레이어 아이템 받아오기
	if (item == nullptr){
		item = new Item;
	}

	DataLoad();

	if (usedItemTab == nullptr){
		usedItemTab = new UsedItemTab;
		usedItemTab->Initialize();
	}

	if (artifactTab == nullptr){
		artifactTab = new ArtifactTab;
		artifactTab->Initialize(item);
	}

	if (skillTab == nullptr){
		skillTab = new SkillTab;
		skillTab->Initialize(item, character);
	}

	if (supportSkillTap == nullptr){
		supportSkillTap = new SupportSkillTap;
		supportSkillTap->Initialize(item, character);
	}

	if (stateTab == nullptr){
		stateTab = new StateTab;
		stateTab->Initialize(item);
	}

	if (lifeTab == nullptr){
		lifeTab = new LifeTab;
		lifeTab->Initialize(item, character);
	}


	
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
	ZeroMemory(&font_desc, sizeof(D3DXFONT_DESC));
	font_desc.Height = 20;
	font_desc.Width = 6;
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
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc, &font2);

	//폰트 생성
	ZeroMemory(&font_desc, sizeof(D3DXFONT_DESC));
	font_desc.Height = 40;
	font_desc.Width = 18;
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
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc, &font3);

	

	if (background == nullptr){
		background = new UI_Image;
		background->SetTexture("./상점/상점배경.png");
		background->SetPosition(0, 0, 0);
		this->size = background->GetSize();
		this->AddChild(background);
	}

	if (menu == nullptr){
		menu = new UI_Image;
		menu->SetTexture("./상점/상점메뉴2.png");
		menu->SetPosition(65, 250, 0);
		this->AddChild(menu);
	}

	if (menu2 == nullptr){
		menu2 = new UI_Image;
		menu2->SetTexture("./상점/상점메뉴2.png");
		menu2->SetPosition(825, 250, 0);
		this->AddChild(menu2);
	}

	if (shopName == nullptr){
		shopName = new UI_Image;
		shopName->SetTexture("./상점/상점간판.png");
		shopName->SetPosition(575, 100, 0);
		shopName->SetID(IMAGE_BACKGROUND);
		this->AddChild(shopName);
	}

	if (bag == nullptr){
		bag = new UI_Image;
		bag->SetTexture("./상점/상점아이템창.png");
		bag->SetPosition(200, 260, 0);
		this->AddChild(bag);
	}

	if (bagImage == nullptr){
		bagImage = new UI_Image;
		bagImage->SetTexture("./상점/bag.png");
		bagImage->SetPosition(130, 270, 0);
		this->AddChild(bagImage);
	}

	if (hpCount == nullptr){
		hpCount = new UI_Text;
		hpCount->SetFont(font);
		hpCount->SetPosition(245, 275, 0);
		hpCount->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpCount->SetTextFormat(DT_WORDBREAK);
		hpCount->SetSize(1000, 120);
		char str[4];
		_itoa_s(item->hpPotion, str, 10);	
		hpCount->SetText(str);
		this->AddChild(hpCount);
	}

	if (mpCount == nullptr){
		mpCount = new UI_Text;
		mpCount->SetFont(font);
		mpCount->SetPosition(298, 275, 0);
		mpCount->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpCount->SetTextFormat(DT_WORDBREAK);
		mpCount->SetSize(1000, 120);
		char str[4];
		_itoa_s(item->mpPotion, str, 10);
		mpCount->SetText(str);
		this->AddChild(mpCount);
	}

	if (attackCount == nullptr){
		attackCount = new UI_Text;
		attackCount->SetFont(font);
		attackCount->SetPosition(351, 275, 0);
		attackCount->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackCount->SetTextFormat(DT_WORDBREAK);
		attackCount->SetSize(1000, 120);
		char str[4];
		_itoa_s(item->attackBuff, str, 10);
		attackCount->SetText(str);
		this->AddChild(attackCount);
	}

	if (armorCount == nullptr){
		armorCount = new UI_Text;
		armorCount->SetFont(font);
		armorCount->SetPosition(410, 275, 0);
		armorCount->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		armorCount->SetTextFormat(DT_WORDBREAK);
		armorCount->SetSize(1000, 120);
		char str[4];
		_itoa_s(item->armorBuff, str, 10);
		armorCount->SetText(str);
		this->AddChild(armorCount);
	}

	if (revengeCount == nullptr){
		revengeCount = new UI_Text;
		revengeCount->SetFont(font);
		revengeCount->SetPosition(463, 275, 0);
		revengeCount->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		revengeCount->SetTextFormat(DT_WORDBREAK);
		revengeCount->SetSize(1000, 120);
		char str[4];
		_itoa_s(item->revenge, str, 10);
		revengeCount->SetText(str);
		this->AddChild(revengeCount);
	}

	if (invincibleCount == nullptr){
		invincibleCount = new UI_Text;
		invincibleCount->SetFont(font);
		invincibleCount->SetPosition(514, 275, 0);
		invincibleCount->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleCount->SetTextFormat(DT_WORDBREAK);
		invincibleCount->SetSize(1000, 120);
		char str[4];
		_itoa_s(item->invincible, str, 10);
		invincibleCount->SetText(str);
		this->AddChild(invincibleCount);
	}

	if (ilife == nullptr){
		switch (character){
		case 1:
			ilife = new UI_Image;
			ilife->SetTexture("./상점/노바.png");
			ilife->SetPosition(127, 350, 0);
			this->AddChild(ilife);
			break;
		case 2:
			ilife = new UI_Image;
			ilife->SetTexture("./상점/요한나1.png");
			ilife->SetPosition(127, 350, 0);
			this->AddChild(ilife);
			break;
		case 3:
			ilife = new UI_Image;
			ilife->SetTexture("./상점/제이나1.png");
			ilife->SetPosition(127, 350, 0);
			this->AddChild(ilife);
			break;
		}
		
		
	}

	if (imoney == nullptr){
		imoney = new UI_Image;
		imoney->SetTexture("./상점/돈.png");
		imoney->SetPosition(130,700, 0);
		this->AddChild(imoney);
	}

	if (stateImage == nullptr){
		stateImage = new UI_Image;
		stateImage->SetTexture("./상점/스탯창배경.png");
		stateImage->SetPosition(200, 360, 0);
		this->AddChild(stateImage);
	}

	if (lv == nullptr){
		lv = new UI_Text;
		lv->SetFont(font);
		lv->SetPosition(250, 380, 0);
		lv->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		lv->SetTextFormat(DT_WORDBREAK);
		lv->SetSize(1000, 120);
		char str[128] = "LV : ";
		char str2[128];
		_itoa_s(level, str2, 10);						//캐릭터 레벨 받아오기
		strcat_s(str, str2);
		lv->SetText(str);
		this->AddChild(lv);
	}

	if (lifes == nullptr){
		lifes = new UI_Text;
		lifes->SetFont(font);
		lifes->SetPosition(450, 380, 0);
		lifes->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		lifes->SetTextFormat(DT_WORDBREAK);
		lifes->SetSize(1000, 120);
		char str[128] = "LIFE : ";
		char str2[128];
		_itoa_s(item->life, str2, 10);						//캐릭터 라이프
		strcat_s(str, str2);
		lifes->SetText(str);
		this->AddChild(lifes);
	}


	if (attack == nullptr){
		attack = new UI_Text;
		attack->SetFont(font);
		attack->SetPosition(250, 430, 0);
		attack->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attack->SetTextFormat(DT_WORDBREAK);
		attack->SetSize(1000, 120);
		char str[128] = "공격력 : ";
		char str2[128];
		_itoa_s(stateAttack, str2, 10);						//캐릭터 공격력 스탯 받아오기
		strcat_s(str, str2);
		attack->SetText(str);
		this->AddChild(attack);
	}

	if (armor == nullptr){
		armor = new UI_Text;
		armor->SetFont(font);
		armor->SetPosition(450, 430, 0);
		armor->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		armor->SetTextFormat(DT_WORDBREAK);
		armor->SetSize(1000, 120);
		char str[128] = "방어력 : ";
		char str2[128];
		_itoa_s(stateArmor, str2, 10);					//캐릭터 방어력 스탯 받아오기
		strcat_s(str, str2);
		armor->SetText(str);
		this->AddChild(armor);
	}

	if (speed == nullptr){
		speed = new UI_Text;
		speed->SetFont(font);
		speed->SetPosition(250, 480, 0);
		speed->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		speed->SetTextFormat(DT_WORDBREAK);
		speed->SetSize(1000, 120);
		char str[128] = "이동속도 : ";
		char str2[128];
		_itoa_s(stateSpeed, str2, 10);					//캐릭터 이동속도 스탯 받아오기
		strcat_s(str, str2);
		speed->SetText(str);
		this->AddChild(speed);
	}

	if (learnSkill == nullptr){
		learnSkill = new UI_Text;
		learnSkill->SetFont(font);
		learnSkill->SetPosition(250, 530, 0);
		learnSkill->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		learnSkill->SetTextFormat(DT_WORDBREAK);
		learnSkill->SetSize(1000, 120);
		learnSkill->SetText("강화된 스킬 : ");
		this->AddChild(learnSkill);
	}

	if (currentArtifact == nullptr){
		currentArtifact = new UI_Text;
		currentArtifact->SetFont(font);
		currentArtifact->SetPosition(250, 580, 0);
		currentArtifact->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		currentArtifact->SetTextFormat(DT_WORDBREAK);
		currentArtifact->SetSize(1000, 120);
		currentArtifact->SetText("아티팩트 : ");
		this->AddChild(currentArtifact);
	}

	if (totalMoney == nullptr){
		totalMoney = new UI_Text;
		totalMoney->SetFont(font3);
		totalMoney->SetPosition(230, 720, 0);
		totalMoney->SetTextColor(D3DCOLOR_XRGB(255, 255, 0));
		totalMoney->SetTextFormat(DT_WORDBREAK);
		totalMoney->SetSize(1000, 120);
		char str1[128];
		_itoa_s(money, str1, 10);					//현재금액 받아와야함
		totalMoney->SetText(str1);
		this->AddChild(totalMoney);
	}

	if (usedItem == nullptr){
		usedItem = new UI_Button;
		usedItem->SetTexture("./상점/UsedItem_Normal.png", "./상점/UsedItem_Over.png", "./상점/UsedItem_Click.png");
		usedItem->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), usedItem, SHOP_USED_ITEM);
		usedItem->SetPosition(1000, 270, 0);
		this->AddChild(usedItem);
	}

	if (artifact == nullptr){
		artifact = new UI_Button;
		artifact->SetTexture("./상점/Artifact_normal.png", "./상점/Artifact_over.png", "./상점/Artifact_click.png");
		artifact->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), artifact, SHOP_ARTIFACT);
		artifact->SetPosition(1000, 350, 0);
		this->AddChild(artifact);
	}

	


	if (skill == nullptr){
		skill = new UI_Button;
		skill->SetTexture("./상점/SkillUpgrade_normal.png", "./상점/SkillUpgrade_over.png", "./상점/SkillUpgrade_click.png");
		skill->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), skill, SHOP_SKILL);
		skill->SetPosition(1000, 430, 0);
		this->AddChild(skill);
	}

	if (supportSkill == nullptr){
		supportSkill = new UI_Button;
		supportSkill->SetTexture("./상점/SupportSkillUpgrade_normal.png", "./상점/SupportSkillUpgrade_over.png", "./상점/SupportSkillUpgrade_click.png");
		supportSkill->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), supportSkill, SHOP_SUPPORT_SKILL);
		supportSkill->SetPosition(1000, 510, 0);
		this->AddChild(supportSkill);
	}

	if (state == nullptr){
		state = new UI_Button;
		state->SetTexture("./상점/state_normal.png", "./상점/state_over.png", "./상점/state_click.png");
		state->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), state, SHOP_STATE);
		state->SetPosition(1000, 590, 0);
		this->AddChild(state);
	}

	if (lifeBuy == nullptr){
		lifeBuy = new UI_Button;
		lifeBuy->SetTexture("./상점/life_normal.png", "./상점/life_over.png", "./상점/life_click.png");
		lifeBuy->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), state, SHOP_LIFE);
		lifeBuy->SetPosition(1000, 670, 0);
		this->AddChild(lifeBuy);
	}

	if (out == nullptr){
		out = new UI_Button;
		out->SetTexture("./상점/out_normal.png", "./상점/out_over.png", "./상점/out_click.png");
		out->OnClick = std::bind(&UI_Functions::ButtonShopStep, std::ref(UI_Manager::Get().func), state, SHOP_QUIT);
		out->SetPosition(1000, 750, 0);
		this->AddChild(out);
	}


	if (imgBlink == nullptr){
		imgBlink = new UI_Image;
		imgBlink->SetTexture("./상점/artifact_blink3.png");
		imgBlink->SetPosition(375, 575, 0);
		imgBlink->SetShow(false);
		this->AddChild(imgBlink);
	}

	if (imgInvincible == nullptr){
		imgInvincible = new UI_Image;
		imgInvincible->SetTexture("./상점/artifact_invincible3.png");
		imgInvincible->SetPosition(375, 575, 0);
		imgInvincible->SetShow(false);
		this->AddChild(imgInvincible);
	}

	if (imgSpeedUp == nullptr){
		imgSpeedUp = new UI_Image;
		imgSpeedUp->SetTexture("./상점/artifact_speed3.png");
		imgSpeedUp->SetPosition(375, 575, 0);
		imgSpeedUp->SetShow(false);
		this->AddChild(imgSpeedUp);
	}

	switch (character){
	case 1:
		imgSniperSkill = new UI_Image;
		imgSniperSkill->SetTexture("./상점/저격3.jpg");
		imgSniperSkill->SetPosition(375, 575, 0);
		imgSniperSkill->SetShow(false);
		this->AddChild(imgSniperSkill);

		imgHyperionSkill = new UI_Image;
		imgHyperionSkill->SetTexture("./상점/히페리온3.jpg");
		imgHyperionSkill->SetPosition(375, 575, 0);
		imgHyperionSkill->SetShow(false);
		this->AddChild(imgHyperionSkill);

		imgPowerUpSkill = new UI_Image;
		imgPowerUpSkill->SetTexture("./상점/강인한문양3.jpg");
		imgPowerUpSkill->SetPosition(375, 575, 0);
		imgPowerUpSkill->SetShow(false);
		this->AddChild(imgPowerUpSkill);

		imgNuclearSkill = new UI_Image;
		imgNuclearSkill->SetTexture("./상점/핵3.jpg");
		imgNuclearSkill->SetPosition(375, 575, 0);
		imgNuclearSkill->SetShow(false);
		this->AddChild(imgNuclearSkill);

		break;
	case 2:
		imgArmorSkill = new UI_Image;
		imgArmorSkill->SetTexture("./상점/강철피부3.png");
		imgArmorSkill->SetPosition(375, 575, 0);
		imgArmorSkill->SetShow(false);
		this->AddChild(imgArmorSkill);

		imgAttackSkill = new UI_Image;
		imgAttackSkill->SetTexture("./상점/규탄3.png");
		imgAttackSkill->SetPosition(375, 575, 0);
		imgAttackSkill->SetShow(false);
		this->AddChild(imgAttackSkill);

		
		break;
	case 3:
		imgIceSkill = new UI_Image;
		imgIceSkill->SetTexture("./상점/얼음소환3.jpg");
		imgIceSkill->SetPosition(375, 575, 0);
		imgIceSkill->SetShow(false);
		this->AddChild(imgIceSkill);

		imgIceFireSkill = new UI_Image;
		imgIceFireSkill->SetTexture("./상점/얼음발사3.jpg");
		imgIceFireSkill->SetPosition(375, 575, 0);
		imgIceFireSkill->SetShow(false);
		this->AddChild(imgIceFireSkill);

		imgIcePowerSkill = new UI_Image;
		imgIcePowerSkill->SetTexture("./상점/마나재생3.jpg");
		imgIcePowerSkill->SetPosition(375, 575, 0);
		imgIcePowerSkill->SetShow(false);
		this->AddChild(imgIcePowerSkill);

		imgIceWorldSkill = new UI_Image;
		imgIceWorldSkill->SetTexture("./상점/아이스월드3.jpg");
		imgIceWorldSkill->SetPosition(375, 575, 0);
		imgIceWorldSkill->SetShow(false);
		this->AddChild(imgIceWorldSkill);

		break;
	}

	imgCommonHpSkill = new UI_Image;
	imgCommonHpSkill->SetTexture("./상점/회복스킬2.png");
	imgCommonHpSkill->SetPosition(375, 575, 0);
	imgCommonHpSkill->SetShow(false);
	this->AddChild(imgCommonHpSkill);

	imgCommonMpSkill = new UI_Image;
	imgCommonMpSkill->SetTexture("./상점/마나회복2.png");
	imgCommonMpSkill->SetPosition(375, 575, 0);
	imgCommonMpSkill->SetShow(false);
	this->AddChild(imgCommonMpSkill);




	
}

void Shop::Destroy(){
	SAFE_DELETE(usedItemTab);
	SAFE_DELETE(artifactTab);
	SAFE_DELETE(skillTab);
	SAFE_DELETE(supportSkillTap);
	SAFE_DELETE(stateTab);
	SAFE_DELETE(lifeTab);
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
	SAFE_RELEASE(font3);
	delete item;
}
void Shop::Update(){
	if (isShow != true)
	{
		return;
	}
	UI_Base::Update();

	if (lv){
		char str[128] = "LV : ";
		char str2[128];
		int temp = level;
		_itoa_s(temp, str2, 10);
		strcat_s(str, str2);
		lv->SetText(str);
	}

	if (lifes){
		char str[128] = "LIFE : ";
		char str2[128];
		_itoa_s(item->life, str2, 10);
		strcat_s(str, str2);
		lifes->SetText(str);
	}

	if (attack){
		char str[128] = "공격력 : ";
		char str2[128];
		int atk = stateAttack + item->atk;
		_itoa_s(atk, str2, 10);						
		strcat_s(str, str2);
		attack->SetText(str);
	}

	if (armor){
		char str[128] = "방어력 : ";
		char str2[128];
		int def = stateArmor + item->def;
		_itoa_s(def, str2, 10);
		strcat_s(str, str2);
		armor->SetText(str);
	}

	if (speed){
		char str[128] = "이동속도 : ";
		char str2[128];
		int move = stateSpeed + item->move;
		_itoa_s(move, str2, 10);
		strcat_s(str, str2);
		speed->SetText(str);
	}

	if (totalMoney){
		char str[128];
		_itoa_s(money, str, 10);
		totalMoney->SetText(str);
	}

	if (hpCount){
		char str[128];
		_itoa_s(item->hpPotion, str, 10);
		hpCount->SetText(str);
	}

	if (mpCount){
		char str[128];
		_itoa_s(item->mpPotion, str, 10);
		mpCount->SetText(str);
	}

	if (attackCount){
		char str[128];
		_itoa_s(item->attackBuff, str, 10);
		attackCount->SetText(str);
	}

	if (armorCount){
		char str[128];
		_itoa_s(item->armorBuff, str, 10);
		armorCount->SetText(str);
	}

	if (revengeCount){
		char str[128];
		_itoa_s(item->revenge, str, 10);
		revengeCount->SetText(str);
	}

	if (invincibleCount){
		char str[128];
		_itoa_s(item->invincible, str, 10);
		invincibleCount->SetText(str);
	}

	if (invincibleCount){
		char str[128];
		_itoa_s(item->invincible, str, 10);
		invincibleCount->SetText(str);
	}


	//캐릭터 배운 스킬
	int count = 0;
	switch (character){
	case 1:
		if (item->sniperSkillLearn){
			if (imgSniperSkill){
				imgSniperSkill->SetShow(true);
				imgSniperSkill->SetPosition(403, 530, 0);
				count++;
			}
		}
		if (item->hyperionSkillLearn){
			if (imgHyperionSkill){
				imgHyperionSkill->SetShow(true);
				imgHyperionSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}
		if (item->powerUpSkillLearn){
			if (imgPowerUpSkill){
				imgPowerUpSkill->SetShow(true);
				imgPowerUpSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}
		if (item->nuclearSkillLearn){
			if (imgNuclearSkill){
				imgNuclearSkill->SetShow(true);
				imgNuclearSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}

		break;
	case 2:
		if (item->armorSkillLearn){
			if (imgArmorSkill){
				imgArmorSkill->SetShow(true);
				imgArmorSkill->SetPosition(403, 530, 0);
				count++;
			}
		}
		if (item->attackSkillLearn){
			if (imgAttackSkill){
				imgAttackSkill->SetShow(true);
				imgAttackSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}
		break;
	case 3:
		if (item->iceSkillLearn){
			if (imgIceSkill){
				imgIceSkill->SetShow(true);
				imgIceSkill->SetPosition(403, 530, 0);
				count++;
			}
		}
		if (item->iceFireSkillLearn){
			if (imgIceFireSkill){
				imgIceFireSkill->SetShow(true);
				imgIceFireSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}
		if (item->icePowerSkillLearn){
			if (imgIcePowerSkill){
				imgIcePowerSkill->SetShow(true);
				imgIcePowerSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}
		if (item->iceWorldSkillLearn){
			if (imgIceWorldSkill){
				imgIceWorldSkill->SetShow(true);
				imgIceWorldSkill->SetPosition(403 + 40 * count, 530, 0);
				count++;
			}
		}
		break;
	}

	if (item->commonHpSkillLearn){
		if (imgCommonHpSkill){
			imgCommonHpSkill->SetShow(true);
			imgCommonHpSkill->SetPosition(403 + 40 * count, 530, 0);
			count++;
		}
	}
	if (item->commonMpSkillLearn){
		if (imgCommonMpSkill){
			imgCommonMpSkill->SetShow(true);
			imgCommonMpSkill->SetPosition(403 + 40 * count, 530, 0);
			count++;
		}
	}

	//아티펙트

	switch (item->artifact){
	case BLINK:
		if (imgBlink){
			imgBlink->SetShow(true);
			imgInvincible->SetShow(false);
			imgSpeedUp->SetShow(false);
		}
		break;
	case INVINCIBLE:
		if (imgInvincible){
			imgBlink->SetShow(false);
			imgInvincible->SetShow(true);
			imgSpeedUp->SetShow(false);
		}
		break;
	case SPEEDUP:
		if (imgSpeedUp){
			imgSpeedUp->SetShow(true);
			imgInvincible->SetShow(false);
			imgBlink->SetShow(false);
		}
		break;
	}

	switch (shopStep){
	case SHOP_NORMAL:
		break;
	case SHOP_USED_ITEM:
		usedItemTab->Update();
		break;
	case SHOP_ARTIFACT:
		artifactTab->Update();
		break;
	case SHOP_SKILL:
		skillTab->Update();
		break;
	case SHOP_SUPPORT_SKILL:
		supportSkillTap->Update();
		break;
	case SHOP_STATE:
		stateTab->Update();
		break;
	case SHOP_LIFE:
		lifeTab->Update();
		break;
	case SHOP_QUIT:
		DataSave();
		switch (stage){
		case 1:
			GameStateManager::Get().ChangeGameState(GameStateType::STATE_LOADING1);
			break;
		case 2:
			GameStateManager::Get().ChangeGameState(GameStateType::STATE_LOADING2);
			break;
		case 3:
			GameStateManager::Get().ChangeGameState(GameStateType::STATE_LOADING3);
			break;
		}
		break;
	}

}
void Shop::Render(){
	if (isShow != true)
	{
		return;
	}
	UI_Base::Render();

	switch (shopStep){
	case SHOP_NORMAL:
		break;
	case SHOP_USED_ITEM:
		usedItemTab->Render();
		break;
	case SHOP_ARTIFACT:
		artifactTab->Render();
		break;
	case SHOP_SKILL:
		skillTab->Render();
		break;
	case SHOP_SUPPORT_SKILL:
		supportSkillTap->Render();
		break;
	case SHOP_STATE:
		stateTab->Render();
		break;
	case SHOP_LIFE:
		lifeTab->Render();
		break;
	case SHOP_QUIT:
		break;
	}
}

LRESULT Shop::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT result = 0;
	
	switch (shopStep){
	case SHOP_NORMAL:
		if (result == 0){
			result = usedItem->InputProc(hWnd, message, wParam, lParam);
		}
		if (result == 0){
			result = artifact->InputProc(hWnd, message, wParam, lParam);
		}
		if (result == 0){
			result = skill->InputProc(hWnd, message, wParam, lParam);
		}
		if (result == 0){
			result = supportSkill->InputProc(hWnd, message, wParam, lParam);
		}
		if (result == 0){
			result = state->InputProc(hWnd, message, wParam, lParam);
		}
		if (result == 0){
			result = lifeBuy->InputProc(hWnd, message, wParam, lParam);
		}
		if (result == 0){
			result = out->InputProc(hWnd, message, wParam, lParam);
		}

		break;
	case SHOP_USED_ITEM:
		usedItemTab->InputProc(hWnd, message, wParam, lParam);
		break;
	case SHOP_ARTIFACT:
		artifactTab->InputProc(hWnd, message, wParam, lParam);
		break;
	case SHOP_SKILL:
		skillTab->InputProc(hWnd, message, wParam, lParam);
		break;
	case SHOP_SUPPORT_SKILL:
		supportSkillTap->InputProc(hWnd, message, wParam, lParam);
		break;
	case SHOP_STATE:
		stateTab->InputProc(hWnd, message, wParam, lParam);
		break;
	case SHOP_LIFE:
		lifeTab->InputProc(hWnd, message, wParam, lParam);
		break;
	case SHOP_QUIT:
		break;
	}

	
	
	return result;
}

void Shop::DataLoad(){
	stage = iniDataManager::Get().loadDataInterger("player", "Player", "stage");
	
	character = iniDataManager::Get().loadDataInterger("player", "Player", "Character");

	item->life = iniDataManager::Get().loadDataInterger("player", "Player", "Life");
	level = iniDataManager::Get().loadDataInterger("player", "Player", "LV");
	exp = iniDataManager::Get().loadDataInterger("player", "Player", "Exp");
	hp = iniDataManager::Get().loadDataInterger("player", "Player", "HP");
	mp = iniDataManager::Get().loadDataInterger("player", "Player", "MP");
	stateAttack = iniDataManager::Get().loadDataInterger("player", "Player", "Attack");
	stateArmor = iniDataManager::Get().loadDataInterger("player", "Player", "Armor");
	stateSpeed = iniDataManager::Get().loadDataInterger("player", "Player", "Life");

	money = iniDataManager::Get().loadDataInterger("player", "Item", "Money");
	item->hpPotion = iniDataManager::Get().loadDataInterger("player", "Item", "HpPotion");
	item->mpPotion = iniDataManager::Get().loadDataInterger("player", "Item", "MpPotion");
	item->attackBuff = iniDataManager::Get().loadDataInterger("player", "Item", "PowerHerb");
	item->armorBuff = iniDataManager::Get().loadDataInterger("player", "Item", "ArmorPotion");
	item->revenge = iniDataManager::Get().loadDataInterger("player", "Item", "StunDagger");
	item->invincible = iniDataManager::Get().loadDataInterger("player", "Item", "Invincible");

	item->blink = iniDataManager::Get().loadDataInterger("player", "Item", "Neckles");
	item->invincibleA = iniDataManager::Get().loadDataInterger("player", "Item", "Ring");
	item->speedUp = iniDataManager::Get().loadDataInterger("player", "Item", "boots");

	if (item->blink) item->artifact = BLINK;
	if (item->invincibleA) item->artifact = INVINCIBLE;
	if (item->speedUp) item->artifact = SPEEDUP;

	switch (character){
	case 1:
		item->sniperSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "Sniper");
		item->hyperionSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "Hyperion");
		item->powerUpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "PowerUp");
		item->nuclearSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "Nuclear");
		break;
	case 2:
		item->armorSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "ArmorBuff");
		item->attackSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "AttackBuff");
		break;
	case 3:
		item->iceSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "Ice");
		item->iceFireSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "IceFire");
		item->icePowerSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "MpRegen");
		item->iceWorldSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "IceWorld");
		break;
	}
	

	item->commonHpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "SupportHp");
	item->commonMpSkillLearn = iniDataManager::Get().loadDataInterger("player", "Item", "SupportMp");
}

void Shop::DataSave(){
	char str[128];

	_itoa_s(character, str, 10);
	iniDataManager::Get().addData("Player", "Character", str);
	_itoa_s(item->life, str, 10);
	iniDataManager::Get().addData("Player", "Life", str);
	_itoa_s(level, str, 10);
	iniDataManager::Get().addData("Player", "LV", str);
	_itoa_s(exp, str, 10);
	iniDataManager::Get().addData("Player", "Exp", str);
	_itoa_s(hp, str, 10);
	iniDataManager::Get().addData("Player", "HP", str);
	_itoa_s(mp, str, 10);
	iniDataManager::Get().addData("Player", "MP", str);
	_itoa_s(stateAttack, str, 10);
	iniDataManager::Get().addData("Player", "Attack", str);
	_itoa_s(stateArmor, str, 10);
	iniDataManager::Get().addData("Player", "Armor", str);
	_itoa_s(stateSpeed, str, 10);
	iniDataManager::Get().addData("Player", "Speed", str);

	_itoa_s(money, str, 10);
	iniDataManager::Get().addData("Item", "Money", str);
	_itoa_s(item->hpPotion, str, 10);
	iniDataManager::Get().addData("Item", "HpPotion", str);
	_itoa_s(item->mpPotion, str, 10);
	iniDataManager::Get().addData("Item", "MpPotion", str);
	_itoa_s(item->attackBuff, str, 10);
	iniDataManager::Get().addData("Item", "PowerHerb", str);
	_itoa_s(item->armorBuff, str, 10);
	iniDataManager::Get().addData("Item", "ArmorPotion", str);
	_itoa_s(item->revenge, str, 10);
	iniDataManager::Get().addData("Item", "StunDagger", str);
	_itoa_s(item->invincible, str, 10);
	iniDataManager::Get().addData("Item", "Invincible", str);

	switch (item->artifact){
	case 0:
		iniDataManager::Get().addData("Item", "Neckles", "1");
		break;
	case 1:
		iniDataManager::Get().addData("Item", "Ring", "1");
		break;
	case 2:
		iniDataManager::Get().addData("Item", "boots", "1");
		break;
	}
	
	
	

	//노바
	_itoa_s(item->sniperSkill, str, 10);
	iniDataManager::Get().addData("Item", "Sniper", str);
	_itoa_s(item->hyperionSkill, str, 10);
	iniDataManager::Get().addData("Item", "Hyperion", str);
	_itoa_s(item->powerUpSkill, str, 10);
	iniDataManager::Get().addData("Item", "PowerUp", str);
	_itoa_s(item->nuclearSkill, str, 10);
	iniDataManager::Get().addData("Item", "Nuclear", str);


	//요한나
	_itoa_s(item->armorSkillUp, str, 10);
	iniDataManager::Get().addData("Item", "ArmorBuff", str);
	_itoa_s(item->attackSkillUp, str, 10);
	iniDataManager::Get().addData("Item", "AttackBuff", str);

	//제이나
	_itoa_s(item->iceSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "Ice", str);
	_itoa_s(item->iceFireSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "IceFire", str);
	_itoa_s(item->icePowerSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "MpRegen", str);
	_itoa_s(item->iceWorldSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "IceWorld", str);

	_itoa_s(item->commonHpSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "SupportHp", str);
	_itoa_s(item->commonMpSkillLearn, str, 10);
	iniDataManager::Get().addData("Item", "SupportMp", str);

	iniDataManager::Get().iniSave("player");
}