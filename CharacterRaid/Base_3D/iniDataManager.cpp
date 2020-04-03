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

	//현재 파일 경로를 str로 저장
	GetCurrentDirectoryA(256, str);
	strncat_s(str, 256, dir, 254);

	for (int i = 0; i < _vIniData.size(); i++)
	{
		WritePrivateProfileStringA(_vIniData[i].subject,
			_vIniData[i].title.c_str(), _vIniData[i].value.c_str(), str);

		
	}

	_vIniData.clear();
}

//읽기 함수
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

// 정수형 불러오는 함쑤
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