#pragma once
#include "GameState.h"
#include "QuestNode.h"

class GameState_Opening:public GameState
{
public:
	GameState_Opening();
	virtual ~GameState_Opening();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

protected:

	Opening_UI* title = nullptr;

};

