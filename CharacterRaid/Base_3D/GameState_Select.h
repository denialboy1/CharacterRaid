#pragma once
#include "GameState.h"

class GameState_Select:public GameState
{
public:
	GameState_Select();
	virtual ~GameState_Select();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

protected:
	Select_UI* select = nullptr;
};

