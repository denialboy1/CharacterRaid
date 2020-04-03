#pragma once

#include <Windows.h>
#include <set>
#include <list>
#include <map>
#include <vector>

class AStarNode
{
public:
	enum ASTAR_NODE_TYPE
	{
		EMPTY = 0,
		BLOCK,
		START,
		DEST
	};

	int index = -1;
	int	row = -1;
	int	col = -1;
	int parentIndex = -1;

	float f = 0.0f;
	float g = 0.0f;
	float h = 0.0f;	
	
	ASTAR_NODE_TYPE nodeType = EMPTY;
};

enum DIRECTION
{
	LEFT = 0,
	RIGHT, 
	UP,
	DOWN,
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN,
	NUM_OF_DIRECTION
};

class AStar
{
public:
	AStar();
	~AStar();

	void Initialize();
	void Destroy();

	void PathFind(std::list<int>& out);

private:
	const char* ASTAR_PATH_DIRECTORY = "./Data/Path/";
	AStarNode* nodeArray = nullptr;
	UINT nodeCount = 0;
	UINT lineCount = 0;

	const float DISTANCE = 1.0f;
	float DISTANCE_DIAGONAL = 1.4f;

	std::set<int> openSet;
	std::set<int> closeSet;

	void LoadData(char* fileName = nullptr);

	AStarNode* FindNode(AStarNode::ASTAR_NODE_TYPE type);
	float CalcHeuristic(AStarNode* start, AStarNode* dest);
	AStarNode* FindMinFNodeAtOpenlist();
	void Extend(AStarNode* center, AStarNode* dest);
	AStarNode* GetAroundNode(AStarNode* target, DIRECTION dir);
	bool IsInSet(int index, bool open = false);
	float GetDistance(DIRECTION dir);

	inline int MakeIndex(int row, int col){ return row*lineCount + col; };
	
};

