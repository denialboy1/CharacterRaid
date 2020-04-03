#pragma once
class TileBillboard
{
public:
	TileBillboard();
	~TileBillboard();

	void Initialize(D3DXVECTOR3 _pos, D3DXVECTOR3 _size, int _frameX, int _frameY);
	void Destroy();
	void Update(D3DXVECTOR3 cameraPos);
	void Render();

	void SetTextureFrame();

private:
	//프레임 관련 변수
	int frameX = 0, frameY = 0;
	int currentFrame = 0;
	float frameCount = 0;
	float frameSpeed = 0.1f;

	int maxFrame = 0;

	//재생 관련
	bool isPlay = false;
	FVF_PositionTexture m_Vertex[6];

	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vScale;
	D3DXVECTOR3 m_vRot;
	D3DXVECTOR3 m_vDir;

	D3DXMATRIXA16 m_Rot;
	D3DXMATRIXA16 m_Scale;
	D3DXMATRIXA16 m_Translation;
	D3DXMATRIXA16 m_World;

	D3DMATERIAL9 material;
	LPDIRECT3DTEXTURE9 texture = nullptr;

public:
	//getter,setter
	inline D3DXVECTOR3 GetPos(){ return m_vPos; }
	inline void SetPos(D3DXVECTOR3 _pos){ m_vPos = _pos; }
	inline D3DXVECTOR3 GetRotate(){ return m_vRot; }
	inline void SetRotate(D3DXVECTOR3 _rotate){ m_vRot = _rotate; }
	inline D3DXVECTOR3 GetScale(){ return m_vScale; }
	inline void SetScale(D3DXVECTOR3 _scale){ m_vScale = _scale; }

	void SetTexture(LPDIRECT3DTEXTURE9 _texture){ texture = _texture; }

	void SetIsPlay(bool _isPlay){ isPlay = _isPlay; }
	bool GetIsPlay(){ return isPlay; }
	void SetFrameSpeed(float _frameSpeed){ frameSpeed = _frameSpeed; }
	void SetFrameX(int _frameX){ frameX = _frameX; }
	void SetFrameY(int _frameY){ frameY = _frameY; }
};

