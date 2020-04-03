#pragma once
#include "SkillObject.h"
class NuClear : public SkillObject
{
public:
	//enum NUCLEAR_STATE
	//{
	//	FIRE,
	//	REMOVE,
	//};

	NuClear();
	~NuClear();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();

	Collider_Sphere* BoomSphere;
	//void ChangeMotion(NUCLEAR_STATE _state);
	bool getNuke() { return Nuke; }
	void setNuke(bool _Nuke) { Nuke = _Nuke; }
	void positionSet(D3DXVECTOR3 pickingPosition);
	void NuClearMove();
	void NuClearMoveRender();
	bool Nuke;

	float& GetNukeX(){ return NukeX; }
	void SetNukeX(float _NukeX){ NukeX = _NukeX; }

	float& GetNukeZ(){ return NukeZ; }
	void SetNukeZ(float _NukeZ){ NukeZ = _NukeZ; }

	float& GetNukeY(){ return NukeY; }
	void SetNukeY(float _NukeY){ NukeY = _NukeY; }

	Collider_Sphere* GetBoomSphere() { return BoomSphere; }
	void SetBoomSphere(Collider_Sphere* _BoomSphere) { BoomSphere = _BoomSphere; }

	D3DXVECTOR3 GetBoomSpherePos() { return BoomSpherePos; }
	void SetBoomSpherePos(D3DXVECTOR3 _BoomSpherePos) { BoomSpherePos = _BoomSpherePos; }

private:
	
	
	//애니메이션 실행관련 변수
	float startTimer = 0.0f;
	float aniTime = 0.0f;
	float NukeY;
	float NukeX;
	float NukeZ;
	float NukeBoomTimer;
	bool IsNukeBoomTimerOn;
	bool IsNukeBoomShereOn;
	D3DXVECTOR3 BoomSpherePos;


};

