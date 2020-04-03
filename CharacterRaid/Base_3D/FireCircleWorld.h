#pragma once
#include "FireCircle.h"

class FireCircleWorld
{
public:
	FireCircleWorld();
	~FireCircleWorld();

	void Initialize();
	void Make();
	void Update();
	void Render();
	void Destroy();

	std::list<FireCircle*>& GetFireCircle(){ return mFireCircle; }
	std::list<FireCircle*>& GetUnFireCircle(){ return mUnFireCircle; }
private:
	std::list<FireCircle*> mFireCircle;
	std::list<FireCircle*> mUnFireCircle;
	FireCircle* fireCircleAll = nullptr;
};

