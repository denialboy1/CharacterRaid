#include "stdafx.h"
#include "ShieldBash_Make.h"


ShieldBash_Make::ShieldBash_Make()
{
}


ShieldBash_Make::~ShieldBash_Make()
{
}

void ShieldBash_Make::Initialize()
{
	shieldBash = new ShieldBash;
	shieldBash->Initialize();
}
void ShieldBash_Make::Destroy()
{
	shieldBash->Destroy();
}
void ShieldBash_Make::Update()
{
	shieldBash->Update();
}
void ShieldBash_Make::Render()
{
	shieldBash->Render();
}
void ShieldBash_Make::Make(D3DXVECTOR3 position, float angle)
{
	shieldBash->SetAngle(angle);
	
	D3DXVECTOR3 newPos = position - shieldBash->GetDirection() * 3;
	newPos.y += 1.5;
	shieldBash->SetPosition(newPos);
	shieldBash->Update();

}
void ShieldBash_Make::isInitAnim(bool ToF)
{
	shieldBash->SetIsAnimInit(ToF);
}