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

	//Ű �ٿ�
	bool IsOnceKeyDown(int key);
	//Ű ��
	bool IsOnceKeyUp(int key);
	//Ű ���������� ����
	bool IsStayKeyDown(int key);
	//Ű ���
	bool IsToggleKey(int key);

	std::bitset<KEYMAX> getKeyUp(){ return keyUp; }
	std::bitset<KEYMAX> getKeyDown(){ return keyDown; }

	void SetKeyDown(int key, bool state){ keyDown.set(key, state); }
	void SetKeyUp(int key, bool state){ keyUp.set(key, state); }
private:
	std::bitset<KEYMAX> keyUp;
	std::bitset<KEYMAX> keyDown;

};

