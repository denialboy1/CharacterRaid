#pragma once
#include "GameObject.h"
class QuestNode :
	public GameObject
{
public:
	QuestNode();
	virtual ~QuestNode();

	void Initialize(D3DXVECTOR3& pos, D3DXVECTOR3& size);
	virtual void Destroy() override;
	virtual void Render() override;

	LRESULT InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	inline bool GetQuestStartNode(){ return questStartNode; }
	inline void SetQuestStartNode(bool start){ questStartNode = start; }

protected:
	BoundingShere boundingSphere = BoundingShere(D3DXVECTOR3(0, 0, 0), 1.0f);
	LPD3DXMESH node = nullptr;
	LPD3DXMESH boundingSphereMesh = nullptr;

	D3DXMATRIX world;
	D3DXMATRIX boundingWorld;
	D3DXVECTOR3 localPivot = D3DXVECTOR3(0, 0, 0);
	D3DMATERIAL9 material;

	bool showBoundingSphere = true;
	bool questStartNode = false;
};

