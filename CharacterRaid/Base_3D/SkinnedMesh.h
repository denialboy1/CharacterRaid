#pragma once
#include "AllocateHierarchy.h"

class SkinnedMesh
{
	//friend class SkinnedMeshManager;	// 이렇게 하면 SkinnedMeshManager는 SkinnedMesh의 private도 마음대로 사용 할 수 있게 된다.

public:
	SkinnedMesh();
	~SkinnedMesh();

	void Initialize(char* path, char* fileName,D3DXVECTOR3 scale);	// 원하는 파일을 클로닝 하는 함수
	void Destroy();
	void UpdateAndRender();

	void SetAnimationIndex(int index);	// 재생 될 애니메이션 세팅
	void SetRandomTrackPosition();		// 테스트용(애니메이션 재생 위치를 랜덤하게 세팅)


	void Load(char* path, char* fileName);	//실제 X파일 부르는 함수. SkinnedMeshManager안에서만 사용 할 것

	inline LPD3DXANIMATIONCONTROLLER GetAnimController(){ return animController; }
	inline Collider_Sphere* GetCollisionSphere() { return &boundingSphere; }

	inline Collider_Box* GetCollisionBox(){ return &boundingBox; }

	inline void SetWorld(D3DXMATRIXA16& _world){ world = _world; }

	inline D3DXVECTOR3 GetMin(){ return min; }
	inline D3DXVECTOR3 GetMax(){ return max; }
	inline void SetMin(D3DXVECTOR3 _min){ min = _min; }
	inline void SetMax(D3DXVECTOR3 _max){ max = _max; }
	inline Bone* FindBone(char* boneName);
	inline void SetisSphereShow(bool _isShpereShow){ isSphereShow = _isShpereShow; }

	inline void SetIsBoundingBoxShow(bool _isBoundingBoxShow){ isBoundingBoxShow = _isBoundingBoxShow; }
	inline void SetBoundingBoxMinMax(D3DXVECTOR3 _min, D3DXVECTOR3 _max){ boundingBox.Initialize(_min, _max); }
private:
	// 하나만 생성(원본과 공유)
	Bone* rootFrame = nullptr;
	DWORD workingPaletteSize = 0;
	D3DXMATRIX* workingPalette = nullptr;
	LPD3DXEFFECT effect = nullptr;

	// 객체마다 가지고 있어야 할 것
	LPD3DXANIMATIONCONTROLLER animController = nullptr;
	D3DXMATRIXA16 world;
	//충돌
	Collider_Sphere boundingSphere = Collider_Sphere();
	Collider_Box boundingBox = Collider_Box();

	bool isSphereShow = false;
	bool isBoundingBoxShow = false;
	// 클론 된건지 원본인지 표시용
	bool isClone = false;
		
	// 기타 내부적으로 필요한 함수들
	void Update(Bone* current, D3DXMATRIXA16* parentMatrix);
	void Render(Bone* bone);
	void SetupBoneMatrixPointers(Bone* bone);	//본 초기화

	LPD3DXEFFECT LoadEffect(char* fileName);	//이펙트 부르는 함수. 자세한건 쉐이더때	

	D3DXVECTOR3 min = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 max = D3DXVECTOR3(0, 0, 0);
	
};

