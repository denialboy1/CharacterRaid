#pragma once

class Camera
{
public:
	Camera();
	virtual ~Camera();

	void Initialize(D3DXVECTOR3* target = nullptr);
	void Destroy();
	void Update();

	LRESULT CameraInputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	inline void SetLookTarget(D3DXVECTOR3* target){ lookTarget = target;  }
	inline void SetDistance(float distance){ camDistance = distance; }
	inline D3DXVECTOR3 GetEyePosition(){ return eyePosition; }

	D3DXMATRIXA16 matView;
private:
	D3DXVECTOR3 eyePosition = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 lookAt = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 upVector = D3DXVECTOR3(0, 1, 0);

	float camRotX = 0.5;		//radian
	float camRotY = 0.0f;
	float camDistance =40.0f;
	
	bool isDrag = false;
	POINT prevMousePos;

	D3DXVECTOR3* lookTarget = nullptr;

	
};

