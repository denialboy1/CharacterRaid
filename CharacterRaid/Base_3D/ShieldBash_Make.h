#pragma once
#include "Skill.h"
#include "ShieldBash.h"

class ShieldBash_Make
{
public:
	ShieldBash_Make();
	~ShieldBash_Make();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Make(D3DXVECTOR3 position, float angle);

	void isInitAnim(bool ToF);

private:
	ShieldBash* shieldBash = nullptr;
};

