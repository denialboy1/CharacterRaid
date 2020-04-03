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

	int mapSize = -1;	//�Ѻ��� �� ��(ũ��)
	int tileCount = -1;	//�Ѻ��� ��� Ÿ���� ������
	int vertexCount = -1;	//���� ����
	int triangleCount = -1; //�ﰢ�� ����

	std::vector<D3DXVECTOR3> vertex;	//���� ��ġ ����

	LPDIRECT3DVERTEXBUFFER9 vertexBuffer = nullptr;
	LPDIRECT3DINDEXBUFFER9 indexBuffer = nullptr;
	
	D3DMATERIAL9 material;
	LPDIRECT3DTEXTURE9 texture = nullptr;	

	D3DXMATRIXA16 world;
};

