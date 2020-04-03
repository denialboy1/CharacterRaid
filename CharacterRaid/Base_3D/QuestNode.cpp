#include "stdafx.h"
#include "QuestNode.h"


QuestNode::QuestNode()
{
}


QuestNode::~QuestNode()
{
}

void QuestNode::Initialize(D3DXVECTOR3& pos, D3DXVECTOR3& size)
{
	position = pos;
	localPivot = D3DXVECTOR3(0, size.y * 0.5f, 0);

	float sizeLength = D3DXVec3Length(&size);
	boundingSphere.radius = sizeLength * 0.5f;
	boundingSphere.center = position + localPivot;
	

	D3DXCreateBox(GameManager::GetDevice(), size.x, size.y, size.z, &node, nullptr);
	D3DXCreateSphere(GameManager::GetDevice(), boundingSphere.radius, 16, 8, &boundingSphereMesh, nullptr);

	D3DXMatrixIdentity(&world);

	D3DXMATRIX local;
	D3DXMatrixTranslation(&local, localPivot.x, localPivot.y, localPivot.z);
	world *= local;

	D3DXMATRIX translation;
	D3DXMatrixTranslation(&translation, position.x, position.y, position.z);
	world *= translation;
	
	D3DXMatrixIdentity(&boundingWorld);
	D3DXMATRIX boundingRotation, boundingTranslation;
	D3DXMatrixRotationX(&boundingRotation, D3DX_PI * 0.5f);
	D3DXMatrixTranslation(&boundingTranslation, boundingSphere.center.x, boundingSphere.center.y, boundingSphere.center.z);
	boundingWorld *= ( boundingRotation * boundingTranslation );

	ZeroMemory(&material, sizeof(D3DMATERIAL9));
	material.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	material.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	material.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
}

void QuestNode::Destroy()
{
	SAFE_RELEASE(boundingSphereMesh);
	SAFE_RELEASE(node);
}

void QuestNode::Render()
{
	GameManager::GetDevice()->SetTexture(0, nullptr);
	GameManager::GetDevice()->SetMaterial(&material);
	if ( node )
	{
		GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);
		GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
		node->DrawSubset(0);
	}
	if ( showBoundingSphere && boundingSphereMesh )
	{
		GameManager::GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);
		GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &boundingWorld);
		boundingSphereMesh->DrawSubset(0);
		GameManager::GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	}
}

LRESULT QuestNode::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch ( message )
	{
		case WM_LBUTTONDOWN:
			{
				POINT mousePoint;
				mousePoint.x = GET_X_LPARAM(lParam);
				mousePoint.y = GET_Y_LPARAM(lParam);
				Ray ray = Ray::CalcRayFromSceenPoint(mousePoint);

				bool isPicked = ray.IsPicked(&boundingSphere);
				if ( isPicked )
				{
					UI_Quest* ui = (UI_Quest*)UI_Manager::Get().GetRoot();
					if ( questStartNode || ui->GetQuestStep() != QUEST_NOT_ACCEPT )
					{
						ui->SetOpenByStartNode(questStartNode);
						ui->SetShow(true);
					}
					result = WM_LBUTTONDOWN;
				}				
			}
			break;
	}
	return result;
}