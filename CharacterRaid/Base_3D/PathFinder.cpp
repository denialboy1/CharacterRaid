#include "stdafx.h"
#include "PathFinder.h"


PathFinder::PathFinder()
{
}


PathFinder::~PathFinder()
{
}

void PathFinder::Initialize(char* dataFile /*= nullptr*/)
{
	Dijkstra::Initialize(dataFile);
	//데이터 파싱

	char fullPath[1024];
	char* directory = "./Data/Path/";
	
	for (int i = 0; i < 12; i++){
		fullPath[i] = directory[i];
	}
	for (int i = 0; i < strlen(dataFile); i++){
		fullPath[i + 12] = dataFile[i];
		fullPath[i + 13] = '\0';
	}

	FILE* file = nullptr;
	fopen_s(&file, fullPath, "r");


	int pathIndex = 0;
	int boxIndex = 0;
	if (file != nullptr){
		while (!feof(file)){
			char temp[512];
			fgets(temp, 512, file);

			if (temp[0] == 'p'){
				if (temp[1] == 'c'){
					int count;
					sscanf_s(temp, "%*s %d", &count);
					path.resize(count);
					pathIndex = 0;
				}
				else{
					float x, y, z;
					sscanf_s(temp, "%*s %f %f %f", &x, &y, &z);
					path[pathIndex] = new PathNode;
					path[pathIndex]->Initialize(D3DXVECTOR3(x, y, z));
					pathIndex++;
				}
			}

			if (temp[0] == 'b'){
				if (temp[1] == 'c'){
					int count;
					sscanf_s(temp, "%*s %d", &count);
					barricades.resize(count);
					boxIndex = 0;
				}
				else{
					float x, y, z,r;
					sscanf_s(temp, "%*s %f %f %f %f", &x, &y, &z,&r);
					barricades[boxIndex] = new Barricade;
					barricades[boxIndex]->Initialize(D3DXVECTOR3(x, y, z),r);
					boxIndex++;
				}
			}
		}
	}

	for (int i = 0;i< path.size(); i++){
		for (int j = 0; j<path.size(); j++){
			edgeCost[i][j] = 0.0f;
		}
	}

	for (int i = 0; i < path.size(); ++i)
	{
		for (int j = i + 1; j < path.size(); ++j)
		{
			const D3DXVECTOR3& start = path[i]->GetPosition();
			const D3DXVECTOR3& end = path[j]->GetPosition();	
			bool isCollision = CheckBarricadeCollision(start, end); 

			if ( isCollision == false )
			{
				D3DXVECTOR3 distance = ( end - start );
				float cost = D3DXVec3Length(&distance);
				edgeCost[i][j] = cost;				
				edgeCost[j][i] = cost;
				FVF_PositionColor edgeStart = FVF_PositionColor(start, D3DCOLOR_XRGB(255,0,0));
				edgeStart.pos.y += 0.01f;
				FVF_PositionColor edgeEnd = FVF_PositionColor(end, D3DCOLOR_XRGB(255, 0, 0));
				edgeEnd.pos.y += 0.01f;
				edgeLine.push_back(edgeStart);
				edgeLine.push_back(edgeEnd);
			}
			else
			{
				edgeCost[i][j] = INFINITY_DISTANCE;				
				edgeCost[j][i] = INFINITY_DISTANCE;
			}
		}
	}

	lineCount = (UINT)(edgeLine.size() * 0.5f);
}

void PathFinder::Destroy()
{
	for (auto iter = path.begin(); iter != path.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	path.clear();

	for (auto iter = barricades.begin(); iter != barricades.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	barricades.clear();
}

void PathFinder::Render()
{
	for (auto iter = path.begin(); iter != path.end(); ++iter)
	{
		PathNode* pathNode = *iter;
		if (pathNode)
		{
			pathNode->Render();
		}
	}
	if (drawEdgeLine)
	{
		GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, false);
		D3DXMATRIX world;
		D3DXMatrixIdentity(&world);
		GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
		GameManager::GetDevice()->SetFVF(FVF_PositionColor::FVF);
		GameManager::GetDevice()->DrawPrimitiveUP(
			D3DPT_LINELIST,
			lineCount,
			&edgeLine[0],
			sizeof(FVF_PositionColor));
		GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);
	}

	for (auto iter = barricades.begin(); iter != barricades.end(); ++iter)
	{
		Barricade* barricade = *iter;
		if (barricade)
		{
			barricade->Render();
		}
	}
}

bool PathFinder::CheckBarricadeCollision(const D3DXVECTOR3& start, const D3DXVECTOR3& end)
{
	bool collision = false;

	Ray ray;
	ray.origin = start;
	ray.direction = ( end - start );
	float startToEndLength = D3DXVec3LengthSq(&ray.direction);
	D3DXVec3Normalize(&ray.direction, &ray.direction);

	for ( int i = 0; i < BARRICADE_COUNT; ++i )
	{
		Barricade* barricade = barricades[i];
		bool isPick = ray.IsPicked(barricade->GetBoundingSphere());	//장해물과 피킹 체크
		if ( isPick )
		{
			D3DXVECTOR3 startToBarricade = barricade->GetPosition() - start;
			float startToBarricadeLength = D3DXVec3LengthSq(&startToBarricade);
			if ( startToBarricadeLength < startToEndLength )	//바리케이트까지의 거리가 목표지점까지의 거리보다 더 짧다.
			{
				//장해물이 더 앞에 있다.
				collision = true;
				break;
			}
			else
			{
				//장해물이 더 멀리 있다.
				D3DXVECTOR3 endToBarricade = barricade->GetPosition() - end;
				float endToBarricadeLength = D3DXVec3LengthSq(&startToBarricade);
				if ( endToBarricadeLength < barricade->GetRadius() * barricade->GetRadius() )
				{
					//하지만 반지름 범위안에 들어간다.
					collision = true;
					break;
				}				
			}
		}
	}

	return collision;
}

int PathFinder::FindNearestPathNode(const D3DXVECTOR3& position)
{
	int nearestNodeIndex = -1;
	float nearestDistance = INFINITY_DISTANCE;


	for ( int i = 0; i < PATH_NODE_COUNT; ++i )
	{
		PathNode* node = path[i];
		const D3DXVECTOR3& nodePosition = node->GetPosition();

		bool isCollision = CheckBarricadeCollision(position, nodePosition);
		if ( isCollision == false )
		{
			//장해물에 가려지지 않았다.
			D3DXVECTOR3 v = ( nodePosition - position );
			float distance = D3DXVec3LengthSq(&v);
			if ( distance < nearestDistance )
			{
				nearestDistance = distance;
				nearestNodeIndex = i;
			}			
		}
	}
	return nearestNodeIndex;
}

void PathFinder::PathOptimize(std::list<int>& pathList, const D3DXVECTOR3& start, const D3DXVECTOR3& end)
{
	//시작점 자르기
	int startIndex = pathList.front();
	for ( auto iter = ++pathList.cbegin(); iter != pathList.cend(); ++iter )
	{
		bool isCollision = CheckBarricadeCollision(start, path[*iter]->GetPosition());
		if ( isCollision == false )
		{
			startIndex = *iter;
		}
		else
		{
			break;
		}
	}
	while ( pathList.front() != startIndex )
	{
		pathList.pop_front();
	}

	//도착점 자르기
	int endIndex = pathList.back();
	for ( auto iter = pathList.crbegin(); iter != pathList.crend(); ++iter )
	{
		int num = *iter;
		bool isCollision = CheckBarricadeCollision(end, path[*iter]->GetPosition());
		if ( isCollision == false )
		{
			endIndex = *iter;
		}
		else
		{
			break;
		}
	}
	while ( pathList.back() != endIndex )
	{
		pathList.pop_back();
	}

}