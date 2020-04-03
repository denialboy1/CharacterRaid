#pragma once
#include "GameState.h"
#include <string>
#include <vector>
#include "UI_Loading.h"
using namespace std;

//로딩 아이템 종류
enum LOADING_KIND
{
	LOADING_KIND_TEXTURE_00,
	LOADING_KIND_MESH_00,
};

//리소스 구조체
struct tagResource
{
	string keyName;
	char* fileName;
	char* path;

	const WCHAR* wFileName;
};


class loadItem
{
private:
	LOADING_KIND _kind;
	tagResource _resource;

public:
	//이미지
	HRESULT initForTexture(char* fileName);
	HRESULT initForMesh(char* path,char* fileName);


	LOADING_KIND getLoadingKind() { return _kind; }
	tagResource getResource() { return _resource; }

	loadItem();
	~loadItem();
};


#define LOADING_FRAME_TIMER 10

class loading : public GameState
{
private:
	typedef vector<loadItem*> arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItemIter;

private:
	arrLoadItem _vLoadItem;

	int _current = 0;

	UI_Loading* ui = nullptr;
	
public:
	virtual void Initialize()override;		//필요 데이터 생성
	virtual void Destroy()override;			//생성한 데이터 삭제
	virtual void Reset() override;
	virtual void Update()override;			//데이터 갱신
	virtual void Render()override;			//데이터를 기반으로 그리기

	virtual HRESULT OnEnterState()override;	//이 state가 시작될때 실행될 함수
	virtual void OnLeaveState()override;	//이 state에서 나갈때 실행될 함수

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//텍스쳐
	void loadTexture(char* fileName);

	//메쉬
	void loadMesh(char* path, char* fileName);

	//로딩이 되는 중이면 true, 다되면 false
	BOOL loadNext();

	vector<loadItem*> getLoadItem(void) { return _vLoadItem; }

	loading();
	~loading();
};

