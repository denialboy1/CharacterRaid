#include "stdafx.h"
#include "loading.h"

loadItem::loadItem(){}
loadItem::~loadItem(){}

HRESULT loadItem::initForTexture(char* fileName)
{
	_kind = LOADING_KIND_TEXTURE_00;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.fileName = fileName;

	return S_OK;
}

HRESULT loadItem::initForMesh(char* path, char* fileName)
{
	_kind = LOADING_KIND_MESH_00;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.path = path;
	_resource.fileName = fileName;

	return S_OK;
}


loading::loading()
{
}


loading::~loading()
{
}

void loading::Initialize()
{
	if (ui == nullptr){
		ui = new UI_Loading;
		ui->Initialize();
	}
}


void loading::loadTexture(char* fileName)
{
	loadItem* item = new loadItem;
	item->initForTexture(fileName);
	_vLoadItem.push_back(item);
}

void loading::loadMesh(char* path, char* fileName)
{
	loadItem* item = new loadItem;
	item->initForMesh(path,fileName);
	_vLoadItem.push_back(item);
}

void loading::Destroy()
{
	SAFE_DELETE(ui);
}

void loading::Update()
{

	if (ui) {
	//	ui->GetBar()->
		ui->Update();
	}
}

void loading::Render()
{
	if (ui) ui->Render();
}



//로딩이 되는 중이면 true, 다되면 false
BOOL loading::loadNext()
{
	//현재 아이템 갯수가 벡터 사이즈 이상 넘어가면 -> 로딩이 끝났다
	if (_current >= _vLoadItem.size() - 1)
	{
		return false;
	}

	//로딩중
	loadItem* item = _vLoadItem[_current];

	switch (item->getLoadingKind())
	{
	case LOADING_KIND_TEXTURE_00:
	{
		tagResource textureResource = item->getResource();
		TextureManager::GetTexture(textureResource.fileName);
	}
	break;
	case LOADING_KIND_MESH_00:
	{
		tagResource meshResource = item->getResource();
		SkinnedMeshManager::Get().GetOriginal(meshResource.path, meshResource.fileName);
	}
	break;
	}
	//카운트 == 로딩률
	_current++;

	return true;
}

HRESULT loading::OnEnterState(){
	Initialize();

	return S_OK;
}
void loading::OnLeaveState(){
	Destroy();
}

LRESULT loading::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){


	return S_OK;
}

void loading::Reset(){
	;
}
