#pragma once

#include "GameState.h"
#include "loading.h"

class GameState_Loading3 : public GameState
{
public:
	GameState_Loading3();
	~GameState_Loading3();

	void Initialize();
	void Destroy();
	void Update();
	void Reset();
	void Render();

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	loading* _loading = nullptr;
};

