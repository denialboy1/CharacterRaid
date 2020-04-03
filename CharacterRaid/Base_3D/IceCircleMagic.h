#pragma once
#include "IceCircle.h"

class IceCircleMagic
{
public:
	IceCircleMagic();
	~IceCircleMagic();

	void Make();
	void Destroy();
	void Update();
	void Render();

private:
	IceCircle* iceCircle = nullptr;
};

