#pragma once
class blinkEffect
{
public:
	blinkEffect();
	~blinkEffect();

	void Initialize();
	void Destroy();
	void Update();
	void Render();

	void Start(D3DXVECTOR3 pos);

	Billboard* GetIsBlink(){ return blink; }
private:
	Billboard* blink = nullptr;
};

