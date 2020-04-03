#include "stdafx.h"
#include "UI_Interface.h"


UI_Interface::UI_Interface()
{
}


UI_Interface::~UI_Interface()
{
}

void UI_Interface::Initialize()
{
	isNova = false;
	isJaina = false;
	isJohanna = false;
	isBlink = false;
	isRing = false;
	isBoots = false;
	CurrentHp = 0;

	
	
	



	D3DXFONT_DESC font_desc;
	ZeroMemory(&font_desc, sizeof(D3DXFONT_DESC));
	font_desc.Height = 12;
	font_desc.Width = 7;
	font_desc.Weight = FW_NORMAL;
	font_desc.MipLevels = D3DX_DEFAULT;
	font_desc.Italic = false;
	font_desc.CharSet = DEFAULT_CHARSET;
	font_desc.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc.Quality = DEFAULT_QUALITY;
	font_desc.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc.FaceName, L"kodia");	//글꼴 스타일
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc, &font);

	//폰트 생성
	D3DXFONT_DESC font_desc2;
	ZeroMemory(&font_desc2, sizeof(D3DXFONT_DESC));
	font_desc2.Height = 40;
	font_desc2.Width = 15;
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

	D3DXFONT_DESC font_desc3;
	ZeroMemory(&font_desc3, sizeof(D3DXFONT_DESC));
	font_desc3.Height = 36;
	font_desc3.Width = 21;
	font_desc3.Weight = FW_NORMAL;
	font_desc3.MipLevels = D3DX_DEFAULT;
	font_desc3.Italic = false;
	font_desc3.CharSet = DEFAULT_CHARSET;
	font_desc3.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc3.Quality = DEFAULT_QUALITY;
	font_desc3.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc3.FaceName, L"kodia");	//글꼴 스타일
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc3, &font3);

	if (calcScore == nullptr){
		calcScore = new CalcScore;
	}

	if (HpBar == nullptr)
	{
		HpBar = new UI_Image;
		HpBar->SetSize(300, 300);
		HpBar->SetTexture("./UI/hpmp/hpbar-1.png");
		HpBar->SetPosition(249, 719, 0);
		//this->size = HpBar->GetSize();
		HpBar->SetSize(300, 300);
		this->AddChild(HpBar);


	}

	if (MpBar == nullptr)
	{
		MpBar = new UI_Image;
		MpBar->SetTexture("./UI/hpmp/mpbar.png");
		MpBar->SetPosition(1185, 719, 0);
		this->size = MpBar->GetSize();
		this->AddChild(MpBar);

	}


	if (EXP == nullptr)
	{
		EXP = new UI_Image;
		EXP->SetTexture("./UI/hpmp/경험치바-3.png");
		EXP->SetPosition(426, 716, 0);
		this->size = EXP->GetSize();
		this->AddChild(EXP);
	}


	if (backGround == nullptr)
	{
		backGround = new UI_Image;
		backGround->SetTexture("./UI/bossRaidUI-3.png");
		backGround->SetPosition(90, 650, 0);
		this->size = backGround->GetSize();
		this->AddChild(backGround);

	}
	if (BasicAttack == nullptr)
	{
		BasicAttack = new UI_Image;
		BasicAttack->SetTexture("./UI/skill/평타.png");
		BasicAttack->SetPosition(731.5, 811, 0);
		this->size = BasicAttack->GetSize();
		this->AddChild(BasicAttack);
	}

	if (Move == nullptr)
	{
		Move = new UI_Image;
		Move->SetTexture("./UI/skill/무브.png");
		Move->SetPosition(804, 811, 0);
		this->size = Move->GetSize();
		this->AddChild(Move);
	}

	if (Stop == nullptr)
	{
		Stop = new UI_Image;
		Stop->SetTexture("./UI/skill/중지.png");
		Stop->SetPosition(878, 811, 0);
		this->size = Stop->GetSize();
		this->AddChild(Stop);
	}
	//////////////노바꺼///////////////////
	if (NovaQSkill == nullptr)
	{
		NovaQSkill = new UI_Image;
		NovaQSkill->SetTexture("./UI/skill/저격-1.png");
		NovaQSkill->SetPosition(432, 811, 0);
		NovaQSkill->SetShow(false);
		this->size = NovaQSkill->GetSize();
		this->AddChild(NovaQSkill);
	}

	if (NovaWSkill == nullptr)
	{
		NovaWSkill = new UI_Image;
		NovaWSkill->SetTexture("./UI/skill/히페리온 지원사격.png");
		NovaWSkill->SetPosition(506, 811, 0);
		NovaWSkill->SetShow(false);
		this->size = NovaWSkill->GetSize();
		this->AddChild(NovaWSkill);
	}

	if (NovaESkill == nullptr)
	{
		NovaESkill = new UI_Image;
		NovaESkill->SetTexture("./UI/skill/강인한문양.png");
		NovaESkill->SetPosition(580, 811, 0);
		this->size = NovaESkill->GetSize();
		NovaESkill->SetShow(false);
		this->AddChild(NovaESkill);
	}

	if (NovaRSkill == nullptr)
	{
		NovaRSkill = new UI_Image;
		NovaRSkill->SetTexture("./UI/skill/핵수정본-1.png");
		NovaRSkill->SetPosition(654, 811, 0);
		NovaRSkill->SetShow(false);
		this->size = NovaRSkill->GetSize();
		this->AddChild(NovaRSkill);
	}
	////////////////////////////////////////

	//////////////////제이나 스킬/////////
	if (JainaQSkill == nullptr)
	{
		JainaQSkill = new UI_Image;
		JainaQSkill->SetTexture("./UI/skill/제이나 얼음 발사.png");
		JainaQSkill->SetPosition(432, 811, 0);
		JainaQSkill->SetShow(false);
		this->size = JainaQSkill->GetSize();
		this->AddChild(JainaQSkill);
	}
	if (JainaWSkill == nullptr)
	{
		JainaWSkill = new UI_Image;
		JainaWSkill->SetTexture("./UI/skill/제이나 얼음소환.png");
		JainaWSkill->SetPosition(506, 811, 0);
		JainaWSkill->SetShow(false);
		this->size = JainaWSkill->GetSize();
		this->AddChild(JainaWSkill);
	}
	if (JainaESkill == nullptr)
	{
		JainaESkill = new UI_Image;
		JainaESkill->SetTexture("./UI/skill/제이나 마나재생.png");
		JainaESkill->SetPosition(580, 811, 0);
		JainaESkill->SetShow(false);
		this->size = JainaESkill->GetSize();
		this->AddChild(JainaESkill);
	}
	if (JainaRSkill == nullptr)
	{
		JainaRSkill = new UI_Image;
		JainaRSkill->SetTexture("./UI/skill/제이나 120개얼음.png");
		JainaRSkill->SetPosition(654, 811, 0);
		JainaRSkill->SetShow(false);
		this->size = JainaRSkill->GetSize();
		this->AddChild(JainaRSkill);
	}
	//////////////////////////////////////

	

	//////////////////조한나 스킬//////////////
	if (JohannaQSkill == nullptr)
	{
		JohannaQSkill = new UI_Image;
		JohannaQSkill->SetTexture("./UI/skill/징벌.png");
		JohannaQSkill->SetPosition(432, 811, 0);
		JohannaQSkill->SetShow(false);
		this->size = JohannaQSkill->GetSize();
		this->AddChild(JohannaQSkill);
	}
	if (JohannaWSkill == nullptr)
	{
		JohannaWSkill = new UI_Image;
		JohannaWSkill->SetTexture("./UI/skill/규탄.png");
		JohannaWSkill->SetPosition(506, 811, 0);
		JohannaWSkill->SetShow(false);
		this->size = JohannaWSkill->GetSize();
		this->AddChild(JohannaWSkill);
	}
	if (JohannaESkill == nullptr)
	{
		JohannaESkill = new UI_Image;
		JohannaESkill->SetTexture("./UI/skill/강철피부.png");
		JohannaESkill->SetPosition(580, 811, 0);
		JohannaESkill->SetShow(false);
		this->size = JohannaESkill->GetSize();
		this->AddChild(JohannaESkill);
	}
	if (JohannaRSkill == nullptr)
	{
		JohannaRSkill = new UI_Image;
		JohannaRSkill->SetTexture("./UI/skill/빛나는방패.png");
		JohannaRSkill->SetPosition(654, 811, 0);
		JohannaRSkill->SetShow(false);
		this->size = JohannaRSkill->GetSize();
		this->AddChild(JohannaRSkill);
	}
	//////////////////////////////////////
	
	//////////////////보조 스킬//////////////
	if (supportQ == nullptr)
	{
		supportQ = new UI_Image;
		supportQ->SetTexture("./UI/skill/회복.png");
		supportQ->SetPosition(432, 811, 0);
		supportQ->SetShow(false);
		this->size = supportQ->GetSize();
		this->AddChild(supportQ);
	}
	if (supportW == nullptr)
	{
		supportW = new UI_Image;
		supportW->SetTexture("./UI/skill/마나회복.png");
		supportW->SetPosition(506, 811, 0);
		supportW->SetShow(false);
		this->size = supportW->GetSize();
		this->AddChild(supportW);
	}
	if (supportE == nullptr)
	{
		supportE = new UI_Image;
		supportE->SetTexture("./UI/skill/블링크.png");
		supportE->SetPosition(580, 811, 0);
		supportE->SetShow(false);
		this->size = supportE->GetSize();
		this->AddChild(supportE);
	}
	if (supportR == nullptr)
	{
		supportR = new UI_Image;
		supportR->SetTexture("./UI/skill/무적.png");
		supportR->SetPosition(654, 811, 0);
		supportR->SetShow(false);
		this->size = supportR->GetSize();
		this->AddChild(supportR);
	}
	//////////////////////////////////////


	/////////////////아이템칸////////////////
	if (HpPotion == nullptr)
	{
		HpPotion = new UI_Image;
		HpPotion->SetTexture("./UI/item/HP물약.png");
		HpPotion->SetPosition(432, 734, 0);
		this->size = HpPotion->GetSize();
		this->AddChild(HpPotion);
	}

	if (MpPotion == nullptr)
	{
		MpPotion = new UI_Image;
		MpPotion->SetTexture("./UI/item/MP물약.png");
		MpPotion->SetPosition(506, 734, 0);
		this->size = MpPotion->GetSize();
		this->AddChild(MpPotion);
	}

	if (PowerHerb == nullptr)
	{
		PowerHerb = new UI_Image;
		PowerHerb->SetTexture("./UI/item/파워허브.png");
		PowerHerb->SetPosition(580, 734, 0);
		this->size = PowerHerb->GetSize();
		this->AddChild(PowerHerb);
	}

	if (ArmourPotion == nullptr)
	{
		ArmourPotion = new UI_Image;
		ArmourPotion->SetTexture("./UI/item/아머포션.png");
		ArmourPotion->SetPosition(654, 734, 0);
		this->size = ArmourPotion->GetSize();
		this->AddChild(ArmourPotion);
	}

	if (StunSword == nullptr)
	{
		StunSword = new UI_Image;
		StunSword->SetTexture("./UI/item/스턴용 단검.png");
		StunSword->SetPosition(731.5, 734, 0);
		this->size = StunSword->GetSize();
		this->AddChild(StunSword);
	}

	if (InvincibilityScroll == nullptr)
	{
		InvincibilityScroll = new UI_Image;
		InvincibilityScroll->SetTexture("./UI/item/무적주문서.png");
		InvincibilityScroll->SetPosition(804, 734, 0);
		this->size = InvincibilityScroll->GetSize();
		this->AddChild(InvincibilityScroll);
	}
	//////////////////////////////////////////

	////////////////스코어 타이머///////////////
	if (Score == nullptr)
	{
		Score = new UI_Text;
		Score->SetFont(font3);
		Score->SetPosition(960, 751, 0);
		Score->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		Score->SetTextFormat(DT_WORDBREAK);
		Score->SetSize(500, 120);
		char str1[128] = "SCORE : ";
		char str2[128];
		_itoa_s(calcScore->GetSC().score, str2, 10);				
		strcat_s(str1, str2);
		Score->SetText(str1);
		this->AddChild(Score);

	}
	//////////////////////////////////////////


	///////////////////////아티펙트///////////
	if (Blink == nullptr)
	{
		Blink = new UI_Image;
		Blink->SetTexture("./UI/atifact/블리읔.png");
		Blink->SetPosition(878, 734, 0);
		Blink->SetShow(false);
		this->size = Blink->GetSize();
		this->AddChild(Blink);
	}

	if (Ring == nullptr)
	{
		Ring = new UI_Image;
		Ring->SetTexture("./UI/atifact/무적반지.png");
		Ring->SetPosition(878, 734, 0);
		Ring->SetShow(false);
		this->size = Ring->GetSize();
		this->AddChild(Ring);
	}

	if (Boots == nullptr)
	{
		Boots = new UI_Image;
		Boots->SetTexture("./UI/atifact/전광석화.png");
		Boots->SetPosition(878, 734, 0);
		Boots->SetShow(false);
		this->size = Boots->GetSize();
		this->AddChild(Boots);
	}
	///////////////////////////////////////////


	//아이템 카운트/////
	if (hpPotionText == nullptr){
		hpPotionText = new UI_Text;
		hpPotionText->SetFont(font2);
		hpPotionText->SetPosition(475, 735, 0);
		hpPotionText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		hpPotionText->SetTextFormat(DT_WORDBREAK);
		hpPotionText->SetSize(1000, 120);
		char str[16] = "";
		_itoa_s(hpPotionCount, str, 10);
		hpPotionText->SetText(str);
		this->AddChild(hpPotionText);
	}

	//아이템 카운트/////
	if (mpPotionText == nullptr){
		mpPotionText = new UI_Text;
		mpPotionText->SetFont(font2);
		mpPotionText->SetPosition(550, 735, 0);
		mpPotionText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		mpPotionText->SetTextFormat(DT_WORDBREAK);
		mpPotionText->SetSize(1000, 120);
		char str[16] = "";
		_itoa_s(mpPotionCount, str, 10);
		mpPotionText->SetText(str);
		this->AddChild(mpPotionText);
	}

	//아이템 카운트/////
	if (attackBuffText == nullptr){
		attackBuffText = new UI_Text;
		attackBuffText->SetFont(font2);
		attackBuffText->SetPosition(623, 735, 0);
		attackBuffText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		attackBuffText->SetTextFormat(DT_WORDBREAK);
		attackBuffText->SetSize(1000, 120);
		char str[16] = "";
		_itoa_s(attacBuffCount, str, 10);
		attackBuffText->SetText(str);
		this->AddChild(attackBuffText);
	}

	//아이템 카운트/////
	if (armorBuffText == nullptr){
		armorBuffText = new UI_Text;
		armorBuffText->SetFont(font2);
		armorBuffText->SetPosition(697, 735, 0);
		armorBuffText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		armorBuffText->SetTextFormat(DT_WORDBREAK);
		armorBuffText->SetSize(1000, 120);
		char str[16] = "";
		_itoa_s(armorBuffCount, str, 10);
		armorBuffText->SetText(str);
		this->AddChild(armorBuffText);
	}

	//아이템 카운트/////
	if (revengeText == nullptr){
		revengeText = new UI_Text;
		revengeText->SetFont(font2);
		revengeText->SetPosition(775, 735, 0);
		revengeText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		revengeText->SetTextFormat(DT_WORDBREAK);
		revengeText->SetSize(1000, 120);
		char str[16] = "";
		_itoa_s(revengeCount, str, 10);
		revengeText->SetText(str);
		this->AddChild(revengeText);
	}

	//아이템 카운트/////
	if (invincibleText == nullptr){
		invincibleText = new UI_Text;
		invincibleText->SetFont(font2);
		invincibleText->SetPosition(847, 735, 0);
		invincibleText->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		invincibleText->SetTextFormat(DT_WORDBREAK);
		invincibleText->SetSize(1000, 120);
		char str[16] = "";
		_itoa_s(invincibleCount, str, 10);
		invincibleText->SetText(str);
		this->AddChild(invincibleText);
	}

	//타이머
	if (timer == nullptr){
		timer = new UI_Text;
		timer->SetFont(font3);
		timer->SetPosition(550, 800, 0);
		timer->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		timer->SetTextFormat(DT_CENTER | DT_WORDBREAK);
		timer->SetSize(1000, 120);
		char str[16] = "00 : 00";
		_itoa_s(invincibleCount, str, 10);
		invincibleText->SetText(str);
		this->AddChild(timer);
	}

	if (coolTimeBox1 == nullptr)
	{
		coolTimeBox1 = new UI_Image;
		coolTimeBox1->SetTexture("./UI/coolTimeBox.png");
		coolTimeBox1->SetPosition(432, 810, 0);
		coolTimeBox1->SetShow(false);
		this->size = coolTimeBox1->GetSize();
		this->AddChild(coolTimeBox1);
	}
	
	if (coolTimeBox2 == nullptr)
	{
		coolTimeBox2 = new UI_Image;
		coolTimeBox2->SetTexture("./UI/coolTimeBox.png");
		coolTimeBox2->SetPosition(506, 810, 0);
		coolTimeBox2->SetShow(false);
		this->size = coolTimeBox2->GetSize();
		this->AddChild(coolTimeBox2);
	}

	if (coolTimeBox3 == nullptr)
	{
		coolTimeBox3 = new UI_Image;
		coolTimeBox3->SetTexture("./UI/coolTimeBox.png");
		coolTimeBox3->SetPosition(580, 810, 0);
		coolTimeBox3->SetShow(false);
		this->size = coolTimeBox3->GetSize();
		this->AddChild(coolTimeBox3);
	}

	if (coolTimeBox4 == nullptr)
	{
		coolTimeBox4 = new UI_Image;
		coolTimeBox4->SetTexture("./UI/coolTimeBox.png");
		coolTimeBox4->SetPosition(654, 810, 0);
		coolTimeBox4->SetShow(false);
		this->size = coolTimeBox4->GetSize();
		this->AddChild(coolTimeBox4);
	}




	if (JainaSkillECoolTime == nullptr)
	{
		JainaSkillECoolTime = new UI_Text;
		JainaSkillECoolTime->SetFont(font3);
		JainaSkillECoolTime->SetPosition(600, 820, 0);
		JainaSkillECoolTime->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		JainaSkillECoolTime->SetTextFormat(DT_WORDBREAK);
		JainaSkillECoolTime->SetSize(1000, 120);
		if (_jaina){
			char str[20] = "";
			_itoa_s((int)_jaina->GeteSkillCoolTimer(), str, 10);
			JainaSkillECoolTime->SetText(str);
		}
		this->AddChild(JainaSkillECoolTime);
	}
	if (JainaSkillRCoolTime == nullptr)
	{
		JainaSkillRCoolTime = new UI_Text;
		JainaSkillRCoolTime->SetFont(font3);
		JainaSkillRCoolTime->SetPosition(680, 820, 0);
		JainaSkillRCoolTime->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		JainaSkillRCoolTime->SetTextFormat(DT_WORDBREAK);
		JainaSkillRCoolTime->SetSize(1000, 120);
		if (_jaina){
			char str[20] = "";
			_itoa_s((int)_jaina->GetrSkillCoolTimer(), str, 10);
			JainaSkillRCoolTime->SetText(str);
		}
		this->AddChild(JainaSkillRCoolTime);
	}

	/**/
	if (AtifactCoolTime == nullptr)
	{
		AtifactCoolTime = new UI_Text;
		AtifactCoolTime->SetFont(font3);
		AtifactCoolTime->SetPosition(600, 500, 0);
		AtifactCoolTime->SetTextColor(D3DCOLOR_XRGB(255, 255, 255));
		AtifactCoolTime->SetTextFormat(DT_WORDBREAK);
		AtifactCoolTime->SetSize(1000, 120);
		char str[20] = "";
		_itoa_s(0, str, 10);
		AtifactCoolTime->SetText(str);
		AtifactCoolTime->SetShow(false);
		this->AddChild(AtifactCoolTime);
	}

}
void UI_Interface::Destroy()
{
	UI_Base::Destroy();
	SAFE_RELEASE(font);
	SAFE_RELEASE(font2);
	SAFE_RELEASE(font3);
	delete calcScore;
}
void UI_Interface::Update()
{
	//아이템 설정
	if (hpPotionText){
		char str[16] = "";
		_itoa_s(hpPotionCount, str, 10);
		hpPotionText->SetText(str);
	}
	if (mpPotionText){
		char str[16] = "";
		_itoa_s(mpPotionCount, str, 10);
		mpPotionText->SetText(str);
	}
	if (attackBuffText){
		char str[16] = "";
		_itoa_s(attacBuffCount, str, 10);
		attackBuffText->SetText(str);
	}
	if (armorBuffText){
		char str[16] = "";
		_itoa_s(armorBuffCount, str, 10);
		armorBuffText->SetText(str);
	}
	if (revengeText){
		char str[16] = "";
		_itoa_s(revengeCount, str, 10);
		revengeText->SetText(str);
	}
	if (invincibleText){
		char str[16] = "";
		_itoa_s(invincibleCount, str, 10);
		invincibleText->SetText(str);
	}

	////////////합칠때 설정해주면됨///////////
	HpBar->SetDeleteY((hpMax - hp)/hpMax * 171);
	HpBar->SetPosition(249, 719 + HpBar->GetDeleteY(), 0);
	HpBar->Update();

	MpBar->SetDeleteY((mpMax - mp) / mpMax * 171);
	MpBar->SetPosition(1185, 719 + MpBar->GetDeleteY(), 0);
	MpBar->Update();

	EXP->SetSize(0, 10);
	//EXP->SetDeleteX(100);
	//EXP->SetPosition(426 + EXP->GetDeleteX(), 716, 0);
	EXP->Update();

	if (isBlink)
	{
		if (Blink)
		{
			Blink->SetShow(true);
			Ring->SetShow(false);
			Boots->SetShow(false);
		}
	}

	if (isRing)
	{
		if (Ring)
		{
			Blink->SetShow(false);
			Ring->SetShow(true);
			Boots->SetShow(false);

		}
	}

	if (isBoots)
	{
		if (Boots)
		{
			Blink->SetShow(false);
			Ring->SetShow(false);
			Boots->SetShow(true);
		}
	}

	if (supportSkillSwitch){
		coolTimeBox1->SetShow(false);
		coolTimeBox2->SetShow(false);
		coolTimeBox3->SetShow(false);
		coolTimeBox4->SetShow(false);

		supportQ->SetShow(true);
		supportW->SetShow(true);
		supportE->SetShow(true);
		supportR->SetShow(true);

		JainaQSkill->SetShow(false);
		JainaWSkill->SetShow(false);
		JainaESkill->SetShow(false);
		JainaRSkill->SetShow(false);

		if (supportQCount == 0) coolTimeBox1->SetShow(true);
		if (supportWCount == 0) coolTimeBox2->SetShow(true);
		if (supportECount == 0) coolTimeBox3->SetShow(true);
		if (supportRCount == 0) coolTimeBox4->SetShow(true);
	}
	else{
		coolTimeBox1->SetShow(false);
		coolTimeBox2->SetShow(false);
		coolTimeBox3->SetShow(false);
		coolTimeBox4->SetShow(false);

		JainaQSkill->SetShow(true);
		JainaWSkill->SetShow(true);
		JainaESkill->SetShow(true);
		JainaRSkill->SetShow(true);

		supportQ->SetShow(false);
		supportW->SetShow(false);
		supportE->SetShow(false);
		supportR->SetShow(false);

	}
	////////////////////////////////////////

	switch (iniDataManager::Get().loadDataInterger("player", "Player", "Character")){
	case 1:
		NovaQSkill->SetShow(true);
		NovaWSkill->SetShow(true);
		NovaESkill->SetShow(true);
		NovaRSkill->SetShow(true);
		break;
	case 2:
		JohannaQSkill->SetShow(true);
		JohannaWSkill->SetShow(true);
		JohannaESkill->SetShow(true);
		JohannaRSkill->SetShow(true);
		break;
	case 3:
		JainaQSkill->SetShow(true);
		JainaWSkill->SetShow(true);
		JainaESkill->SetShow(true);
		JainaRSkill->SetShow(true);
		break;
	}
	UI_Base::Update();

	if (Score){
		char str1[128] = "SCORE : ";
		char str2[128];
		_itoa_s(calcScore->GetSC().score, str2, 10);
		strcat_s(str1, str2);
		Score->SetText(str1);
	}

	if (timer)
	{
		char str1[128];
		char str2[128];
		_itoa_s(minute, str1, 10);
		_itoa_s(second, str2, 10);
		strcat_s(str1, " : ");
		strcat_s(str1, str2);
		timer->SetText(str1);
	}
	/*
	eSkillCoolTimeTimer = _jaina->GeteSkillCoolTimer();
	char str[20] = "";
	_itoa_s(eSkillCoolTimeTimer, str, 10);
	JainaSkillECoolTime->SetText(str);
	*/

	if (IsAtifactUseCoolTime)
	{
		AtifactUseCoolTime = 99;
		IsAtifactUnUse = true;
	}
	
	if (IsAtifactUnUse)
	{
		AtifactUseCoolTime--;
	}
	if (AtifactUseCoolTime == 0)
	{
		IsAtifactUnUse = false;
	}

	if (_jaina && !supportSkillSwitch){
		if (JainaSkillECoolTime){
			char str[20] = "";
			int a = 15 - (int)((timeGetTime() - _jaina->GeteSkillCoolTimer()) * 0.001f);
			if (a < 0) a = 0;
			else if(a > 15) a = 15;
			_itoa_s(a, str, 10);
			if (a == 0){
				JainaSkillECoolTime->SetShow(false);
				coolTimeBox3->SetShow(false);
			}
			else {
				JainaSkillECoolTime->SetShow(true);
				coolTimeBox3->SetShow(true);
			}
			JainaSkillECoolTime->SetText(str);
		}

		if (JainaSkillRCoolTime){
			char str[20] = "";
			int a = 7 - (int)((timeGetTime() - _jaina->GetrSkillCoolTimer()) * 0.001f);
			if (a < 0) a = 0;
			else if (a > 7) a = 7;
			_itoa_s(a, str, 10);
			if (a == 0){
				JainaSkillRCoolTime->SetShow(false);
				coolTimeBox4->SetShow(false);
			}
			else {
				JainaSkillRCoolTime->SetShow(true);
				coolTimeBox4->SetShow(true);
			}
			JainaSkillRCoolTime->SetText(str);
		}
	}
	char str[20] = "";
	_itoa_s(AtifactUseCoolTime, str, 10);
	AtifactCoolTime->SetText(str);
}
void UI_Interface::Render()
{
	HpBar->Render();

	MpBar->Render();

	EXP->Render();
	UI_Base::Render();

}

LRESULT UI_Interface::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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

