#pragma once
#include <list>
#include <vector>
class DijkstraNode
{
public:
	DijkstraNode(){};
	~DijkstraNode(){};
	
	int nodeID = -1;
	int prevNodeID = -1;		//�ִ� ����϶� ���� ����� ID
	
	float cost = 1000000000.0f;	//���۳�忡�� �� ������ ���µ� �ʿ��� ���( �뷫 ����� �Ⱦ� ū ���� )
	bool visited = false;		//�� ��带 �湮�ߴ��� ���ߴ���
};

class Dijkstra
{
public:
	Dijkstra();
	~Dijkstra();

	virtual void Initialize(char* dataFile = nullptr);
	void PathFind(std::list<int>& out, int start, int end);

protected:
	const float INFINITY_DISTANCE = 1000000000.0f;

	static const UINT NODE_COUNT = 32;
	std::vector<std::vector<float>> edgeCost;

	DijkstraNode node[NODE_COUNT];
};
