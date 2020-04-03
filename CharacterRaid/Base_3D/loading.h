#pragma once
#include "GameState.h"
#include <string>
#include <vector>
#include "UI_Loading.h"
using namespace std;

//�ε� ������ ����
enum LOADING_KIND
{
	LOADING_KIND_TEXTURE_00,
	LOADING_KIND_MESH_00,
};

//���ҽ� ����ü
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
	//�̹���
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
	virtual void Initialize()override;		//�ʿ� ������ ����
	virtual void Destroy()override;			//������ ������ ����
	virtual void Reset() override;
	virtual void Update()override;			//������ ����
	virtual void Render()override;			//�����͸� ������� �׸���

	virtual HRESULT OnEnterState()override;	//�� state�� ���۵ɶ� ����� �Լ�
	virtual void OnLeaveState()override;	//�� state���� ������ ����� �Լ�

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//�ؽ���
	void loadTexture(char* fileName);

	//�޽�
	void loadMesh(char* path, char* fileName);

	//�ε��� �Ǵ� ���̸� true, �ٵǸ� false
	BOOL loadNext();

	vector<loadItem*> getLoadItem(void) { return _vLoadItem; }

	loading();
	~loading();
};

