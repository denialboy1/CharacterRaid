#pragma once
#include "GameObject.h"
#include "SkinnedMesh.h"
class StructureObject : public GameObject
{
public:
	StructureObject();
	~StructureObject();

	virtual void Initialize(char* path, char* fileName, D3DXVECTOR3 scale);
	virtual void Destroy();
	virtual void Update();
	virtual void Render();

	SkinnedMesh* GetMesh() { return mesh; }
	Collider_Sphere* GetSphere() { return sphere; }
private:
	SkinnedMesh* mesh = nullptr;
	Collider_Sphere* sphere = nullptr;


};

