#pragma once
#include "GameObject.h"
#include "SkinnedMesh.h"

class SkillObject : public GameObject
{
public:
	SkillObject();
	~SkillObject();

	virtual void Initialize();
	virtual void Destroy();
	virtual void Update();
	virtual void Render();

	inline void SetSpeed(float _speed){ speed = _speed; }
	inline void SetDamage(float _damage){ damage = _damage; }
	inline SkinnedMesh* GetMesh(){ return mesh; }
	inline cOBB* GetObbBox(){ return obbBox; }
	inline Collider_Sphere* GetSphere(){ return sphere; }

protected:
	float damage;
	float speed;
	SkinnedMesh* mesh = nullptr;

	Collider_Sphere* sphere = nullptr;
	cOBB* obbBox = nullptr;
};
