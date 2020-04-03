#include "stdafx.h"
#include "UI_Manager.h"


UI_Manager::UI_Manager()
{
}


UI_Manager::~UI_Manager()
{
}

void UI_Manager::Initialize()
{
	Destroy();

	//��Ʈ ����
	D3DXFONT_DESC font_desc;
	ZeroMemory(&font_desc, sizeof(D3DXFONT_DESC));
	font_desc.Height = 50;
	font_desc.Width = 25;
	font_desc.Weight = FW_NORMAL;
	font_desc.MipLevels = D3DX_DEFAULT;
	font_desc.Italic = false;
	font_desc.CharSet = DEFAULT_CHARSET;
	font_desc.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc.Quality = DEFAULT_QUALITY;
	font_desc.PitchAndFamily = FF_DONTCARE;
	//wcscpy_s(font_desc.FaceName, L"�޸�����ü");	//�۲� ��Ÿ��
	AddFontResource(L"./Data/Font/kodia.ttf");
	wcscpy_s(font_desc.FaceName, L"kodia");
	D3DXCreateFontIndirect(GameManager::GetDevice(), &font_desc, &font);
	


	D3DXCreateSprite(GameManager::GetDevice(), &sprite);
}

void UI_Manager::Destroy()
{
	SAFE_RELEASE(sprite);
	SAFE_RELEASE(font);

	SAFE_DELETE(root);
}

void UI_Manager::Update()
{
	if ( root )
	{
		root->Update();
	}
}

void UI_Manager::Render()
{
	if ( root )
	{
		root->Render();
	}
}

LRESULT UI_Manager::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	if ( root )
	{
		result = root->InputProc(hWnd, message, wParam, lParam);
	}
	return result;
}