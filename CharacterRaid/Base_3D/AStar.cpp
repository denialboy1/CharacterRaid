#include "stdafx.h"
#include "AStar.h"


AStar::AStar()
{
}


AStar::~AStar()
{
}

void AStar::Initialize()
{
	LoadData();
	DISTANCE_DIAGONAL = sqrtf(DISTANCE + DISTANCE);
}

void AStar::Destroy()
{
	if ( nodeArray )
	{
		delete[] nodeArray;
	}
	nodeArray = nullptr;	
}

void AStar::PathFind(std::list<int>& out)
{
	AStarNode* startNode = FindNode(AStarNode::ASTAR_NODE_TYPE::START);
	AStarNode* destNode = FindNode(AStarNode::ASTAR_NODE_TYPE::DEST);

	if ( startNode && destNode )
	{
		startNode->g = 0.0f;
		startNode->h = CalcHeuristic(startNode, destNode);
		startNode->f = startNode->g + startNode->h;

		openSet.insert(startNode->index);		//�켱 ���� ����. ������� open����Ʈ�� ����
		
		while ( true )
		{
			AStarNode* minFNode = FindMinFNodeAtOpenlist();	//open����Ʈ�� �ִ°� �� f���� ���� ������ ã�´�.
			if ( minFNode == nullptr )
			{
				break; // �� ����( open����Ʈ�� ����� )
			}
			openSet.erase(minFNode->index);		//f���� ���� ���� ���� open����Ʈ���� ���� close����Ʈ�� �ִ´�.
			closeSet.insert(minFNode->index);
			
			if ( minFNode == destNode )
			{
				break; // �� ã��
			}
			
			Extend(minFNode, destNode);	//Ȯ��
		}

		// ��� ����
		out.clear();
		int tempIndex = destNode->index;
		while ( tempIndex != -1 )	//��ǥ �������� �θ� ������ ���󰡸鼭 out����Ʈ �ϼ�
		{
			out.push_front(tempIndex);
			tempIndex = nodeArray[tempIndex].parentIndex;
		}

		if ( out.front() != startNode->index )
		{
			out.clear();	//Ȥ�ó� �𸣴� Ȯ�� ����
		}
	}
}

void AStar::LoadData(char* fileName /*= nullptr*/)
{
	char fullPath[1024];
	strcpy_s(fullPath, ASTAR_PATH_DIRECTORY);
	if ( fileName != nullptr )
	{
		strcat_s(fullPath, fileName);
	}
	else
	{
		strcat_s(fullPath, "Astar.txt");
	}

	FILE* fp = nullptr;
	fopen_s(&fp, fullPath, "r");
	if ( fp != nullptr )
	{
		lineCount = 0;	//���� �� ��(���� ���δ� ���ٰ� ����)
		std::vector<char> fileData;
		while ( true )
		{
			char c = fgetc(fp);
			
			if ( c < 33 )
			{
				++lineCount;

				if ( feof(fp) )
				{
					break;
				}

				continue;
			}

			fileData.push_back(c);
		}
		fclose(fp);

		//Ȥ�ó� ������ ����
		if ( nodeArray )
		{
			delete[] nodeArray;
		}

		//�ӽ� ������(char�� ASTAR_NODE_TYPE��)
		std::map<char, AStarNode::ASTAR_NODE_TYPE> typeConvert;
		typeConvert['E'] = AStarNode::ASTAR_NODE_TYPE::EMPTY;
		typeConvert['B'] = AStarNode::ASTAR_NODE_TYPE::BLOCK;
		typeConvert['S'] = AStarNode::ASTAR_NODE_TYPE::START;
		typeConvert['D'] = AStarNode::ASTAR_NODE_TYPE::DEST;

		nodeCount = fileData.size();
		nodeArray = new AStarNode[nodeCount];
		for ( UINT i = 0; i < nodeCount; ++i )
		{
			nodeArray[i].index = i;
			nodeArray[i].row = i / lineCount;
			nodeArray[i].col = i % lineCount;
			nodeArray[i].nodeType = typeConvert[fileData[i]];			
		}
	}
}

AStarNode* AStar::FindNode(AStarNode::ASTAR_NODE_TYPE type)
{
	AStarNode* find = nullptr;
	for ( UINT i = 0; i < nodeCount; ++i )
	{
		if ( nodeArray[i].nodeType == type )
		{
			find = &nodeArray[i];
			break;
		}		
	}
	return find;
}

float AStar::CalcHeuristic(AStarNode* start, AStarNode* dest)
{
	return (float)(abs(start->row - dest->row) + abs(start->col - dest->col));
}

AStarNode* AStar::FindMinFNodeAtOpenlist()
{
	float minF = 1000000000.0f;
	AStarNode* minFNode = nullptr;

	for ( auto iter = openSet.cbegin(); iter != openSet.cend(); ++iter )
	{		
		int index = *iter;
		if ( nodeArray[index].f < minF )
		{			
			minF = nodeArray[index].f;
			minFNode = &nodeArray[index];
		}
	}

	return minFNode;
}

void AStar::Extend(AStarNode* center, AStarNode* dest)
{
	for (int i = 0; i < DIRECTION::NUM_OF_DIRECTION; ++i)
	{
		AStarNode* around = GetAroundNode(center, (DIRECTION)i);
		if (around != nullptr)
		{
			if (IsInSet(around->index, true))
			{
				//���� ��尡 open����Ʈ�� �־��� ���
				float distance = center->g + GetDistance((DIRECTION)i);
				if (around->g > distance)								//centerNode�� ���ļ� ���°� �� ������ ����
				{
					around->parentIndex = center->index;				//�θ� centerNode�� �ϰ� g�� ����(h�� ������ ���� ��ġ�Ƿ� ������ �ʴ´�)
					around->g = distance;
					around->f = around->g + around->h;
				}
			}
			else
			{
				//open����Ʈ�� ���� ���̸� f,g,h�� �ְ� open����Ʈ�� �߰�
				around->parentIndex = center->index;
				around->g = center->g + GetDistance((DIRECTION)i);
				around->h = CalcHeuristic(around, dest);
				around->f = around->g + around->h;
				openSet.insert(around->index);
			}
		}
	}
}

AStarNode* AStar::GetAroundNode(AStarNode* target, DIRECTION dir)
{
	AStarNode* result = nullptr;
	int aroundRow = 0;
	int aroundCol = 0;

	switch ( dir )
	{
		case LEFT:
			{
				aroundCol = -1;				
			}
			break;
		case RIGHT:
			{				
				aroundCol = 1;
			}
			break;
		case UP:
			{
				aroundRow = -1;
			}
			break;
		case DOWN:
			{
				aroundRow = 1;
			}
			break;
		case LEFT_UP:
			{
				aroundCol = -1;
				aroundRow = 1;				
			}
			break;
		case LEFT_DOWN:
			{
				aroundCol = -1;
				aroundRow = -1;				
			}
			break;
		case RIGHT_UP:
			{
				aroundCol = 1;
				aroundRow = -1;				
			}
			break;
		case RIGHT_DOWN:
			{
				aroundCol = 1;
				aroundRow = 1;				
			}
			break;
		default:
			break;
	}

	aroundRow += target->row;
	aroundCol += target->col;

	int indexRow = MakeIndex(aroundRow, target->col);
	int indexCol = MakeIndex(target->row, aroundCol);
	int index = MakeIndex(aroundRow, aroundCol);
	if (aroundRow >= (int)0 && aroundRow < (int)lineCount
		&& aroundCol >= (int)0 && aroundCol < (int)lineCount)
	{
		result = &nodeArray[index];
		if (nodeArray[index].nodeType == AStarNode::ASTAR_NODE_TYPE::BLOCK)
		{
			result = nullptr;
		}
		else if (nodeArray[indexRow].nodeType == AStarNode::ASTAR_NODE_TYPE::BLOCK)	//�𼭸� �κ� üũ
		{
			result = nullptr;
		}
		else if (nodeArray[indexCol].nodeType == AStarNode::ASTAR_NODE_TYPE::BLOCK)
		{
			result = nullptr;
		}
	}
	
	if (IsInSet(index, false))	//close����Ʈ�� �ִ°Ÿ� ��ŵ
	{
		result = nullptr;
	}

	return result;
}

bool AStar::IsInSet(int index, bool open /*= false*/)
{
	bool result = false;
	if (open)
	{
		result = (openSet.find(index) != openSet.cend());
	}
	else
	{
		result = (closeSet.find(index) != closeSet.cend());
	}

	return result;
}

float AStar::GetDistance(DIRECTION dir)
{
	float result = 0.0f;
	switch (dir)
	{
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			result = DISTANCE;
			break;
		case LEFT_UP:
		case LEFT_DOWN:
		case RIGHT_UP:
		case RIGHT_DOWN:
			result = DISTANCE_DIAGONAL;
			break;
		default:
			break;
	}
	return result;
}