#pragma once
class Heal
{
public:
	Heal();
	~Heal();

	void Initialize();
	void Destroy();
	void Update(D3DXVECTOR3 pos);
	void Render();

	void Start(D3DXVECTOR3 pos);
private:
	Billboard* heal = nullptr;
};

