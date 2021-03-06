#include "stdafx.h"
#include "SkinnedMesh.h"
#include "AllocateHierarchy.h"


SkinnedMesh::SkinnedMesh()
{
}

SkinnedMesh::~SkinnedMesh()
{
}

void SkinnedMesh::Initialize(char* path, char* fileName,D3DXVECTOR3 _scale)
{
	// 원본 정보를 찾아서 나에게 복사
	SkinnedMesh* original = SkinnedMeshManager::Get().GetOriginal(path, fileName);

	rootFrame = original->rootFrame;
	workingPaletteSize = original->workingPaletteSize;
	workingPalette = original->workingPalette;
	effect = original->effect;
	boundingSphere = original->boundingSphere;
	min = original->min;
	max = original->max;

	D3DXMATRIXA16 scale;
	D3DXMatrixIdentity(&scale);
	D3DXMatrixScaling(&scale, _scale.x, _scale.y, _scale.z);


	D3DXVec3TransformCoord(&min, &min, &scale);
	D3DXVec3TransformCoord(&max, &max, &scale);

	boundingSphere.GetBoundingSphere().center = (min + max) / 2.0f;
	boundingSphere.GetBoundingSphere().radius = D3DXVec3Length(&(min - max)) / 4.8f;

	boundingSphere.Initialize(boundingSphere.GetBoundingSphere().center, boundingSphere.GetBoundingSphere().radius);
	boundingSphere.SetWireRender(true);

	boundingBox.Initialize(min, max);
	// 에니메이션은 따로 돌아야 하니 클론
	original->animController->CloneAnimationController(
		original->animController->GetMaxNumAnimationOutputs(),
		original->animController->GetMaxNumAnimationSets(),
		original->animController->GetMaxNumTracks(),
		original->animController->GetMaxNumEvents(),
		&animController);

	isClone = true;
}

void SkinnedMesh::Destroy()
{
	if ( isClone == false )
	{ 
		// 이것은 공유하는 부분이므로 원본 삭제시만 사용
		AllocateHierarchy ah;
		D3DXFrameDestroy((LPD3DXFRAME)rootFrame, &ah);
		SAFE_DELETE_ARRAY_ONLY(workingPalette);
		SAFE_RELEASE(effect);
	}
	
	// 이건 클론별로 다 따로 가지므로 일일이 삭제
	SAFE_RELEASE(animController);
	boundingSphere.Destroy();
	boundingBox.Destroy();

}

void SkinnedMesh::UpdateAndRender()
{
	//rootFrame을 공유하기 때문에 본 업데이트가 일어난 후 즉시 그리는 수 밖에 없다
	if ( animController )
	{
		animController->AdvanceTime(GameManager::GetTick(), nullptr);
	}

	if ( rootFrame )
	{
		Update(rootFrame, &world);
		Render(rootFrame);
	}
	else{
		boundingSphere.GetBoundingSphere().center.x = world._41;
		boundingSphere.GetBoundingSphere().center.y = world._42;
		boundingSphere.GetBoundingSphere().center.z = world._43;
	}

	boundingSphere.GetBoundingSphere().center.x = world._41;
	boundingSphere.GetBoundingSphere().center.y = world._42;
	boundingSphere.GetBoundingSphere().center.z = world._43;


	boundingSphere.Update();

	boundingBox.SetPosition(D3DXVECTOR3(world._41, world._42, world._43));
	boundingBox.Update();
}

void SkinnedMesh::Update(Bone* current, D3DXMATRIXA16* parentMatrix)
{
	//재귀적으로 모든 프레임(본)에 대해서 실행.
	current->CombinedTransformationMatrix = current->TransformationMatrix;
	if ( parentMatrix )
	{
		current->CombinedTransformationMatrix = current->CombinedTransformationMatrix * ( *parentMatrix );
	}

	if ( current->pFrameSibling )	//형제
	{
		Update((Bone*)current->pFrameSibling, parentMatrix);
	}

	if ( current->pFrameFirstChild )	//첫번째 자식
	{
		Update((Bone*)current->pFrameFirstChild, &( current->CombinedTransformationMatrix ));
	}
}

void SkinnedMesh::Render(Bone* current)
{
	assert(current);

	// 각 프레임의 메시 컨테이너에 있는 pSkinInfo를 이용하여 영향받는 모든 
	// 프레임의 매트릭스를 boneMatrixPointers에 연결한다.
	if ( current->pMeshContainer )
	{
		BoneMesh* boneMesh = (BoneMesh*)current->pMeshContainer;

		// get bone combinations
		LPD3DXBONECOMBINATION pBoneCombos =
			(LPD3DXBONECOMBINATION)( boneMesh->bufferBoneCombos->GetBufferPointer() );

		D3DXMATRIXA16 matViewProj, matView, matProj;
		GameManager::GetDevice()->GetTransform(D3DTS_VIEW, &matView);
		GameManager::GetDevice()->GetTransform(D3DTS_PROJECTION, &matProj);
		matViewProj = matView * matProj;

		D3DXMATRIXA16 mView, mInvView;
		GameManager::GetDevice()->GetTransform(D3DTS_VIEW, &mView);
		D3DXMatrixInverse(&mInvView, 0, &mView);
		D3DXVECTOR3 vEye = D3DXVECTOR3(0, 0, 0);
		D3DXVec3TransformCoord(&vEye, &vEye, &mInvView);

		// for each palette
		for ( DWORD dwAttrib = 0; dwAttrib < boneMesh->numAttrGroups; ++dwAttrib )
		{
			// set each transform into the palette
			for ( DWORD dwPalEntry = 0; dwPalEntry < boneMesh->numPaletteEntries; ++dwPalEntry )
			{
				DWORD dwMatrixIndex = pBoneCombos[dwAttrib].BoneId[dwPalEntry];
				if ( dwMatrixIndex != UINT_MAX )
				{
					workingPalette[dwPalEntry] =
						boneMesh->boneOffsetMatrices[dwMatrixIndex] *
						( *boneMesh->boneMatrixPointers[dwMatrixIndex] );
				}
			}

			// set the matrix palette into the effect
			effect->SetMatrixArray("amPalette",
				workingPalette,
				boneMesh->numPaletteEntries);

			effect->SetMatrix("g_mViewProj", &matViewProj);
			effect->SetVector("vLightDiffuse", &D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f));
			effect->SetVector("vWorldLightPos", &D3DXVECTOR4(500.0f, 500.0f, 500.0f, 1.0f));
			effect->SetVector("vWorldCameraPos", &D3DXVECTOR4(vEye, 1.0f));
			effect->SetVector("vMaterialAmbient", &D3DXVECTOR4(0.53f, 0.53f, 0.53f, 0.53f));
			effect->SetVector("vMaterialDiffuse", &D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f));

			// we're pretty much ignoring the materials we got from the x-file; just set
			// the texture here
			effect->SetTexture("g_txScene", boneMesh->textures[pBoneCombos[dwAttrib].AttribId]);

			// set the current number of bones; this tells the effect which shader to use
			effect->SetInt("CurNumBones", boneMesh->maxNumFaceInfls - 1);

			// set the technique we use to draw
			effect->SetTechnique("Skinning20");

			UINT uiPasses, uiPass;

			// run through each pass and draw
			effect->Begin(&uiPasses, 0);
			for ( uiPass = 0; uiPass < uiPasses; ++uiPass )
			{
				effect->BeginPass(uiPass);
				boneMesh->workingMesh->DrawSubset(dwAttrib);
				effect->EndPass();
			}
			effect->End();
		}
	}

	//재귀적으로 모든 프레임(본)에 대해서 실행.
	if ( current->pFrameSibling )
	{
		Render((Bone*)current->pFrameSibling);
	}

	if ( current->pFrameFirstChild )
	{
		Render((Bone*)current->pFrameFirstChild);
	}
}

void SkinnedMesh::SetAnimationIndex(int index)
{
	//애니메이션 변경
	if ( !animController )
		return;

	LPD3DXANIMATIONSET animSet = nullptr;
	animController->GetAnimationSet(index, &animSet);
	animController->SetTrackAnimationSet(0, animSet);
	SAFE_RELEASE(animSet);
}

void SkinnedMesh::SetRandomTrackPosition()
{
	//랜덤으로  애니메이션 시작점 조절
	animController->SetTrackPosition(0, ( rand() % 100 ) / 10.0f);
}

void SkinnedMesh::Load(char* path, char* fileName)
{
	effect = LoadEffect("./Data/Shader/MultiAnimation.hpp");

	int paletteSize = 0;
	effect->GetInt("MATRIX_PALETTE_SIZE", &paletteSize);

	AllocateHierarchy ah;
	ah.SetDirectory(path);
	ah.SetDefaultPaletteSize(paletteSize);
	
	char fullPath[512];
	strcpy_s(fullPath, path);
	strcat_s(fullPath, fileName);
	HRESULT result = D3DXLoadMeshHierarchyFromXA(
		fullPath,
		D3DXMESH_MANAGED,
		GameManager::GetDevice(),
		&ah,
		NULL,
		(LPD3DXFRAME*)&rootFrame,
		&animController);

	if ( workingPalette )
		delete[] workingPalette;

	workingPaletteSize = ah.GetMaxPaletteSize();
	workingPalette = new D3DXMATRIX[workingPaletteSize];

	min = ah.GetMin();
	max = ah.GetMax();

	boundingSphere.GetBoundingSphere().center = (ah.GetMin() + ah.GetMax()) / 2.0f;
	boundingSphere.GetBoundingSphere().radius = D3DXVec3Length(&(ah.GetMin() - ah.GetMax()));

	if ( workingPalette == NULL )
	{
		workingPaletteSize = 0;
	}

	if ( rootFrame )
		SetupBoneMatrixPointers(rootFrame);
}

LPD3DXEFFECT SkinnedMesh::LoadEffect(char* fileName)
{
	LPD3DXEFFECT pEffect = NULL;

	D3DXMACRO mac[2] =
	{
		{ "MATRIX_PALETTE_SIZE_DEFAULT", "35" },
		{ NULL, NULL }
	};

	D3DCAPS9 caps;
	D3DXMACRO *pmac = NULL;
	GameManager::GetDevice()->GetDeviceCaps(&caps);
	if ( caps.VertexShaderVersion > D3DVS_VERSION(1, 1) )
		pmac = mac;

	DWORD dwShaderFlags = 0;

#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DXSHADER_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

#ifdef DEBUG_VS
	dwShaderFlags |= D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT;
#endif
#ifdef DEBUG_PS
	dwShaderFlags |= D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT;
#endif

	ID3DXBuffer* pBuffer = NULL;
	if ( FAILED(D3DXCreateEffectFromFileA(GameManager::GetDevice(),
		fileName,
		pmac,
		NULL,
		dwShaderFlags,
		NULL,
		&pEffect,
		&pBuffer)) )
	{
		// if creation fails, and debug information has been returned, output debug info
		if ( pBuffer )
		{
			OutputDebugStringA((char*)pBuffer->GetBufferPointer());
			SAFE_RELEASE(pBuffer);
		}

		return NULL;
	}

	return pEffect;
}

void SkinnedMesh::SetupBoneMatrixPointers(Bone* bone)
{
	assert(bone);

	// 각 프레임의 메시 컨테이너에 있는 pSkinInfo를 이용하여 영향받는 모든 
	// 프레임의 매트릭스를 boneMatrixPointers에 연결한다.
	if ( bone->pMeshContainer )
	{
		BoneMesh* boneMesh = (BoneMesh*)bone->pMeshContainer;
		if ( boneMesh->pSkinInfo )
		{
			LPD3DXSKININFO pSkinInfo = boneMesh->pSkinInfo;
			// pSkinInfo->GetNumBones() 으로 영향받는 본의 개수를 찾음.
			// pSkinInfo->GetBoneName(i) 로 i번 프레임의 이름을 찾음
			// D3DXFrameFind(루트 프레임, 프레임 이름) 로 프레임을 찾음.
			// 찾아서 월드매트릭스를 걸어줘라.
			DWORD dwNumBones = pSkinInfo->GetNumBones();
			for ( DWORD i = 0; i < dwNumBones; ++i )
			{
				LPCSTR boneName = pSkinInfo->GetBoneName(i);
				if ( boneName == nullptr || strlen(boneName) == 0 )
					continue;
				Bone* influence = (Bone*)D3DXFrameFind(rootFrame, boneName);
				boneMesh->boneMatrixPointers[i] = &( influence->CombinedTransformationMatrix );
			}
		}
	}

	//재귀적으로 모든 프레임에 대해서 실행.
	if ( bone->pFrameSibling )
	{
		SetupBoneMatrixPointers((Bone*)bone->pFrameSibling);
	}

	if ( bone->pFrameFirstChild )
	{
		SetupBoneMatrixPointers((Bone*)bone->pFrameFirstChild);
	}
}

Bone* SkinnedMesh::FindBone(char* boneName){
	return (Bone*)D3DXFrameFind(rootFrame, boneName);
}

