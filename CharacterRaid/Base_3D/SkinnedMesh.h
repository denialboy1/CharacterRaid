#pragma once
#include "AllocateHierarchy.h"

class SkinnedMesh
{
	//friend class SkinnedMeshManager;	// �̷��� �ϸ� SkinnedMeshManager�� SkinnedMesh�� private�� ������� ��� �� �� �ְ� �ȴ�.

public:
	SkinnedMesh();
	~SkinnedMesh();

	void Initialize(char* path, char* fileName,D3DXVECTOR3 scale);	// ���ϴ� ������ Ŭ�δ� �ϴ� �Լ�
	void Destroy();
	void UpdateAndRender();

	void SetAnimationIndex(int index);	// ��� �� �ִϸ��̼� ����
	void SetRandomTrackPosition();		// �׽�Ʈ��(�ִϸ��̼� ��� ��ġ�� �����ϰ� ����)


	void Load(char* path, char* fileName);	//���� X���� �θ��� �Լ�. SkinnedMeshManager�ȿ����� ��� �� ��

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
	// �ϳ��� ����(������ ����)
	Bone* rootFrame = nullptr;
	DWORD workingPaletteSize = 0;
	D3DXMATRIX* workingPalette = nullptr;
	LPD3DXEFFECT effect = nullptr;

	// ��ü���� ������ �־�� �� ��
	LPD3DXANIMATIONCONTROLLER animController = nullptr;
	D3DXMATRIXA16 world;
	//�浹
	Collider_Sphere boundingSphere = Collider_Sphere();
	Collider_Box boundingBox = Collider_Box();

	bool isSphereShow = false;
	bool isBoundingBoxShow = false;
	// Ŭ�� �Ȱ��� �������� ǥ�ÿ�
	bool isClone = false;
		
	// ��Ÿ ���������� �ʿ��� �Լ���
	void Update(Bone* current, D3DXMATRIXA16* parentMatrix);
	void Render(Bone* bone);
	void SetupBoneMatrixPointers(Bone* bone);	//�� �ʱ�ȭ

	LPD3DXEFFECT LoadEffect(char* fileName);	//����Ʈ �θ��� �Լ�. �ڼ��Ѱ� ���̴���	

	D3DXVECTOR3 min = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 max = D3DXVECTOR3(0, 0, 0);
	
};

