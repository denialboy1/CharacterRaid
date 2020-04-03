#pragma once
class InvincibleEffect
{
public:
	InvincibleEffect();
	~InvincibleEffect();

	void Initialize();
	void Destroy();
	void Update(D3DXVECTOR3 pos);
	void Render();

	void Start(D3DXVECTOR3 pos);

	void SetIsStart(bool _isStart){ isStart = _isStart; }
private:
	Billboard* shield = nullptr;

	bool isStart = false;

	
};

