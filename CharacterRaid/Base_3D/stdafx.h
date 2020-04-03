#pragma once
#include <Windows.h>
#include <Windowsx.h>

#include <assert.h>

#include <list>
#include <map>
#include <vector>
#include <string>

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "MemoryLeakCheck.h"

#include "FVF.h"
#include "Triangle.h"
#include "BoundingVolume.h"
#include "Collider_Sphere.h"
#include "Collider_Box.h"
#include "cOBB.h"
#include "Billboard.h"

#include "FrustumCulling.h"

#include "Camera.h"
#include "Pyramid.h"

#include "QuestNode.h"

#include "UI_Base.h"
#include "UI_Functions.h"
#include "UI_Button.h"
#include "UI_Image.h"
#include "UI_Text.h"
#include "UI_Quest.h"

#include "Score_UI.h"
#include "Opening_UI.h"
#include "Select_UI.h"

#include "RandomUtil.h"
#include "Collision.h"
#include "Ray.h"

#include "MaterialTexture.h"
#include "ObjFileGroup.h"
#include "ObjLoader.h"
#include "Obj.h"

#include "AseFrame.h"
#include "AseLoader.h"

#include "GameObject.h"
#include "ActionBase.h"
#include "ActionMove.h"
#include "ActionSequence.h"
#include "ActionRotate.h"

#include "SkinnedMesh.h"

#include "Stage.h"
#include "unit.h"

#include "SkinnedMeshManager.h"
#include "UI_Manager.h"
#include "GameStateManager.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "KeyboardManager.h"
#include "SkillManager.h"
#include "EffectManager.h"
#include "iniDataManager.h"
#include "soundManager.h"

#include "CalcScore.h"

#pragma comment(lib, "winmm.lib")


LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

static const WCHAR WINDOW_CLASS_NAME[] = L"Win32App";
static const WCHAR WINDOW_TITLE_CAPTION[] = L"SGA 3D";

static const unsigned int RESOLUTION_X = 1600;
static const unsigned int RESOLUTION_Y = 900;

static bool isDebug = false;

template<typename T>
ULONG SAFE_RELEASE(T& object)
{
	ULONG result = 0;
	if ( object )
	{
		result = object->Release();
		object = nullptr;
	}
	return result;
}

template<typename T>
void SAFE_DELETE(T& object)
{
	if ( object )
	{
		object->Destroy();
		delete object;
		object = nullptr;
	}
}

template<typename T>
void SAFE_ARRAY_DELETE(T& object, UINT32 arrayCount)
{
	if ( object )
	{
		for ( int i = 0; i < arrayCount; ++i )
		{
			object[i]->Destroy();
		}
		delete [] object;
		object = nullptr;
	}
}

template<typename T>
void SAFE_DELETE_ARRAY_ONLY(T& object)
{
	if ( object )
	{
		delete [] object;
		object = nullptr;
	}
}

struct ST_PC_VERTEX
{
	D3DXVECTOR3 p;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

