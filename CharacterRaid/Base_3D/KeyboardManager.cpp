#include "stdafx.h"
#include "KeyboardManager.h"


KeyboardManager::KeyboardManager()
{
}


KeyboardManager::~KeyboardManager()
{
}

HRESULT KeyboardManager::Initialize(){
	for (int i = 0; i < KEYMAX; i++){
		this->getKeyUp().set(i, false);
		this->getKeyDown().set(i, false);
	}

	return S_OK;
}
void KeyboardManager::Destroy(){

}

//키 다운
bool KeyboardManager::IsOnceKeyDown(int key){
	if (GetAsyncKeyState(key) & 0x8000){
		if (!this->getKeyDown()[key])
		{
			this->SetKeyDown(key, true);
			return true;
		}
	}
	else this->SetKeyDown(key, false);

	return false;
}
//키 업
bool KeyboardManager::IsOnceKeyUp(int key){
	if (GetAsyncKeyState(key) & 0x8000) this->SetKeyUp(key, true);
	else{
		if (this->getKeyUp()[key]){
			this->SetKeyUp(key, false);
			return true;
		}
	}
	return false;
}
//키 지속적으로 누름
bool KeyboardManager::IsStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) && 0x800)return true;
	return false;
}
//키 토글
bool KeyboardManager::IsToggleKey(int key){
	if (GetKeyState(key) & 0x001)return true;
	return false;
}