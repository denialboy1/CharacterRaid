#pragma once
#include <vector>

//데이터 구조체
struct tagIniData
{
	const char* subject;	//항목
	string title;		//항목안에 소제목
	string value;		//소제목의 값
};

class iniDataManager 
{
private:
	typedef vector<tagIniData> arrIniData;
	typedef vector<tagIniData>::iterator arrIniDataIter;

	typedef vector<arrIniData> arrIniDatas;
	typedef vector<arrIniData>::iterator arrIniDatasIter;


private:
	arrIniData _vIniData;

public:
	static iniDataManager& Get(){
		static iniDataManager Instance;
		return Instance;
	}

	HRESULT init();
	void release();

	//save function
	void addData(const char* subject, const char* title, const char* value);
	void iniSave(char* fileName);

	//읽기 함수
	string loadDataString(const char* fileName, const char* subject, const char* title);

	// 정수형 불러오는 함쑤
	int loadDataInterger(const char* fileName, const char* subject, const char* title);

	iniDataManager();
	~iniDataManager();
};

