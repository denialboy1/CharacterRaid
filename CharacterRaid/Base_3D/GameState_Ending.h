#pragma once
#include "GameState.h"
#include "QuestNode.h"
#include "Ending_UI.h"
class GameState_Ending : public GameState
{
public:
	GameState_Ending();
	virtual ~GameState_Ending();

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Reset() override;
	virtual void Update() override;
	virtual void Render() override;

	virtual HRESULT OnEnterState() override;
	virtual void OnLeaveState() override;

	virtual LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

protected:
	QuestNode* questNodeStart = nullptr;
	QuestNode* questNodeEnd = nullptr;

	Ending_UI* ending = nullptr;
};

