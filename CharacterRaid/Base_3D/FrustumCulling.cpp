#include "StdAfx.h"
#include "FrustumCulling.h"


FrustumCulling::FrustumCulling()
{
}


FrustumCulling::~FrustumCulling()
{
}

void FrustumCulling::Initialize()
{
	//프로젝션 하는 공간
	projectionSpacePointArray.clear();
	projectionSpacePointArray.resize(8);
	projectionSpacePointArray[0] = D3DXVECTOR3(-1,-1, 0);	
	projectionSpacePointArray[1] = D3DXVECTOR3(-1,-1, 1);	
	projectionSpacePointArray[2] = D3DXVECTOR3( 1,-1, 1);	
	projectionSpacePointArray[3] = D3DXVECTOR3( 1,-1, 0);	
	projectionSpacePointArray[4] = D3DXVECTOR3(-1, 1, 0);	
	projectionSpacePointArray[5] = D3DXVECTOR3(-1, 1, 1);	
	projectionSpacePointArray[6] = D3DXVECTOR3( 1, 1, 1);	
	projectionSpacePointArray[7] = D3DXVECTOR3( 1, 1, 0);	

	frustumPlaneArray.clear();
	frustumPlaneArray.resize(6);
}

void FrustumCulling::Update()
{
	D3DXMATRIXA16 projection, view;
	GameManager::GetDevice()->GetTransform(D3DTS_PROJECTION, &projection);
	GameManager::GetDevice()->GetTransform(D3DTS_VIEW, &view);

	std::vector<D3DXVECTOR3> frustum(8);
	for ( size_t i = 0; i < projectionSpacePointArray.size(); ++i )
	{
		D3DXVec3Unproject(
			&frustum[i],					//연산 결과가 들어갈 곳
			&projectionSpacePointArray[i],	//변환할 점
			nullptr,						//뷰포트(필요없음)
			&projection,					//프로젝션
			&view,							//뷰
			nullptr);						//월드(필요없음)
	}

	D3DXPlaneFromPoints(&frustumPlaneArray[0], &frustum[0], &frustum[3], &frustum[2]);	//아래
	D3DXPlaneFromPoints(&frustumPlaneArray[1], &frustum[7], &frustum[6], &frustum[2]);	//오른쪽
	D3DXPlaneFromPoints(&frustumPlaneArray[2], &frustum[6], &frustum[5], &frustum[1]);	//far
	D3DXPlaneFromPoints(&frustumPlaneArray[3], &frustum[5], &frustum[4], &frustum[0]);	//왼쪽
	D3DXPlaneFromPoints(&frustumPlaneArray[4], &frustum[4], &frustum[7], &frustum[3]);	//near
	D3DXPlaneFromPoints(&frustumPlaneArray[5], &frustum[5], &frustum[6], &frustum[7]);	//위
}

bool FrustumCulling::IsInFrustum(BoundingShere* boundingSphere)
{
	for ( size_t i = 0; i < frustumPlaneArray.size(); ++i )
	{
		//D3DXPlaneDotCoord 계산 결과는 평면과 점 사이의 거리
		if ( D3DXPlaneDotCoord(&frustumPlaneArray[i], &boundingSphere->center) > boundingSphere->radius )
		{
			//프러스텀 밖에 있다.		
			return false;
		}
	}
	return true;
}
