#pragma once
class HeightMap
{
public:
	HeightMap();
	~HeightMap();
	
	void Initialize(char* mapFileName, char* textureFileName);
	void Destroy();
	void Render();

	bool GetHeight(float& outHeight, float x, float z);
protected:
	const char* HEIGHTMAP_DIRECTORY = "./Data/HeightMap/";

	int mapSize = -1;	//한변의 줄 수(크기)
	int tileCount = -1;	//한변에 몇개의 타일이 들어가는지
	int vertexCount = -1;	//정점 개수
	int triangleCount = -1; //삼각형 개수

	std::vector<D3DXVECTOR3> vertex;	//정점 위치 정보

	LPDIRECT3DVERTEXBUFFER9 vertexBuffer = nullptr;
	LPDIRECT3DINDEXBUFFER9 indexBuffer = nullptr;
	
	D3DMATERIAL9 material;
	LPDIRECT3DTEXTURE9 texture = nullptr;	

	D3DXMATRIXA16 world;
};

