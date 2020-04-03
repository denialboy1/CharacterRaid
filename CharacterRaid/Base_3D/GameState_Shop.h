#pragma once
#include "GameState.h"
#include "Shop.h"

class GameState_Shop : public GameState
{
public:
	GameState_Shop();
	~GameState_Shop();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
private:
	Shop* shop = nullptr;
};

