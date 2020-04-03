#pragma once
#include <bitset>

#define KEYMAX 256

class KeyboardManager
{
public:
	KeyboardManager();
	~KeyboardManager();

	static KeyboardManager& Get(){
		static KeyboardManager instance;
		return instance;
	}

	HRESULT Initialize();
	void Destroy();

	//키 다운
	bool IsOnceKeyDown(int key);
	//키 업
	bool IsOnceKeyUp(int key);
	//키 지속적으로 누름
	bool IsStayKeyDown(int key);
	//키 토글
	bool IsToggleKey(int key);

	std::bitset<KEYMAX> getKeyUp(){ return keyUp; }
	std::bitset<KEYMAX> getKeyDown(){ return keyDown; }

	void SetKeyDown(int key, bool state){ keyDown.set(key, state); }
	void SetKeyUp(int key, bool state){ keyUp.set(key, state); }
private:
	std::bitset<KEYMAX> keyUp;
	std::bitset<KEYMAX> keyDown;

};

