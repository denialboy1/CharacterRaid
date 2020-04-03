#pragma once
#include "SkillObject.h"
class napalmBoom : public SkillObject
{
public:
	napalmBoom();
	~napalmBoom();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void Render();
};

