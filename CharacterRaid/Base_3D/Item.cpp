#include "stdafx.h"
#include "Item.h"


Item::Item()
{
}


Item::~Item()
{
}

bool Item::BuyHp(){
	if (hpPotion<5){
		hpPotion++;
		return true;
	}
	else{
		return false;
	}
}
bool Item::BuyMp(){
	if (mpPotion<5){
		mpPotion++;
		return true;
	}
	else{
		return false;
	}
}

bool Item::BuyAttackBuff(){
	if (attackBuff<5){
		attackBuff++;
		return true;
	}
	else{
		return false;
	}
}

bool Item::BuyArmorBuff(){
	if (armorBuff<5){
		armorBuff++;
		return true;
	}
	else{
		return false;
	}
}

bool Item::BuyRevenge(){
	if (revenge<5){
		revenge++;
		return true;
	}
	else{
		return false;
	}
}

bool Item::BuyInvincible(){
	if (invincible<5){
		invincible++;
		return true;
	}
	else{
		return false;
	}
}

bool Item::UseHpPotion(){
	if (hpPotion>0){
		hpPotion--;
		return true;
	}
	else{
		return false;
	}
}

bool Item::UseMpPotion(){
	if (mpPotion>0){
		mpPotion--;
		return true;
	}
	else{
		return false;
	}
}

bool Item::UseAttackBuff(){
	if (attackBuff>0){
		attackBuff--;
		return true;
	}
	else{
		return false;
	}
}

bool Item::UseArmorBuff(){
	if (armorBuff>0){
		armorBuff--;
		return true;
	}
	else{
		return false;
	}
}

bool Item::UseRevenge(){
	if (revenge>0){
		revenge--;
		return true;
	}
	else{
		return false;
	}
}

bool Item::UseInvincible(){
	if (invincible>0){
		invincible--;
		return true;
	}
	else{
		return false;
	}
}