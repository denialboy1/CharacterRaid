#pragma once

#include "Collider_Sphere.h"
#include "Collider_Box.h"
#include "cOBB.h"

class ActionBase;
class ActionSequence;
class GameObject
{
public:	
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Destroy();
	virtual void Update();	
	virtual void Render() = 0;

	inline const D3DXVECTOR3& GetPosition(){ return position; }
	inline D3DXVECTOR3* GetPositionAdress(){ return &position; }
	inline void SetPosition(const D3DXVECTOR3& pos){ position = pos; }
	inline void SetDirection(const D3DXVECTOR3& dir){ direction = dir; }
	inline D3DXVECTOR3 GetDirection(){ return direction; }
	inline void SetAngle(const float angle){ rotationAngle = angle; }
	inline void SetScale(D3DXVECTOR3 _scale){ scale = _scale; }
	inline float GetAngle(){ return rotationAngle; }

	inline void SetAction(ActionBase* _action){ action = _action; }	
	inline ActionBase* GetAction(){ return action; }
protected:
	D3DXVECTOR3 scale = D3DXVECTOR3(1, 1, 1);
	D3DXVECTOR3	position = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3	direction = D3DXVECTOR3(0, 0, 0);
	float rotationAngle = 0.0f;

	ActionBase* action = nullptr;
	ActionSequence* sequence = nullptr;
	D3DXMATRIXA16 world;
	D3DXMATRIXA16 obbWorld;
};

