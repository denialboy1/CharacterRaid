#include "stdafx.h"
#include "iniDataManager.h"


iniDataManager::iniDataManager()
{
}


iniDataManager::~iniDataManager()
{
}

HRESULT iniDataManager::init()
{
	return S_OK;
}
void iniDataManager::release()
{

}

//save function
void iniDataManager::addData(const char* subject, const char* title, const char* value)
{
	string str;
	str = value;

	tagIniData iniData;
	iniData.subject = subject;
	iniData.title = title;
	iniData.value = str;

	//arrIniData vIniData;
	//vIniData.push_back(iniData);

	_vIniData.push_back(iniData);
}

void iniDataManager::iniSave(char* fileName)
{
	char str[256];
	char dir[128];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	//���� ���� ��θ� str�� ����
	GetCurrentDirectoryA(256, str);
	strncat_s(str, 256, dir, 254);

	for (int i = 0; i < _vIniData.size(); i++)
	{
		WritePrivateProfileStringA(_vIniData[i].subject,
			_vIniData[i].title.c_str(), _vIniData[i].value.c_str(), str);

		
	}

	_vIniData.clear();
}

//�б� �Լ�
string iniDataManager::loadDataString(const char* fileName, const char* subject, const char* title)
{
	char str[256];
	char dir[128];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectoryA(256, str);
	strncat_s(str, 256, dir, 254);

	char data[64] = { NULL };
	GetPrivateProfileStringA(subject, title, "", data, 64, str);
	
	
	return data;
}

// ������ �ҷ����� �Ծ�
int iniDataManager::loadDataInterger(const char* fileName, const char* subject, const char* title)
{
	char str[256];
	char dir[128];

	ZeroMemory(dir, sizeof(dir));
	sprintf_s(dir, "\\%s.ini", fileName);

	GetCurrentDirectoryA(256, str);
	strncat_s(str, 256, dir, 254);

	
	return GetPrivateProfileIntA(subject, title, 0, str);
}