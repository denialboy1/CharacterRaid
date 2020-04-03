#include "stdafx.h"
#include <assert.h>
#include "HeightMap.h"


HeightMap::HeightMap()
{
}


HeightMap::~HeightMap()
{
}

void HeightMap::Initialize(char* mapFileName, char* textureFileName)
{
	D3DXMatrixIdentity(&world);

	//�� ���� ������ �б�
	char fullPath[1024];
	strcpy_s(fullPath, HEIGHTMAP_DIRECTORY);
	strcat_s(fullPath, mapFileName);
	FILE* fp = nullptr;
	fopen_s(&fp, fullPath, "rb");	//���̳ʸ��� �б�
	if ( fp != nullptr )
	{
		fseek(fp, 0, SEEK_END);		//���� ������ �̵�
		vertexCount = ftell(fp);	//���� �������� ��ġ �޾ƿ���(= ���ϱ��� = ���� ����)
		fseek(fp, 0, SEEK_SET);		//���� ó������ �̵�
		
		mapSize = (int)sqrt(vertexCount + 0.0001f);	//���簢���̶�� ����( �ڿ� 0.0001�� float���̶� ������ 1�����°� ���� ���ؼ�)
		assert(vertexCount == mapSize * mapSize && "���� ���� ����� ������ ���ϸ� �ε��� �����մϴ�.");
		
		std::vector<unsigned char> fileData;	//0~255�ϱ�
		fileData.reserve(vertexCount);

		for ( int i = 0; i < vertexCount; ++i )
		{
			fileData.push_back(fgetc(fp));		//�� ����Ʈ�� �� ���
		}
		fclose(fp);

		tileCount = mapSize - 1;	//�Ѻ��� �簢�� ���� ����(���� 4���̸� 3ĭ�� ����. �������ϴϱ�)


		//���ؽ� �����
		std::vector<FVF_PositionNormalTexture> fvfVertex;
		fvfVertex.reserve(vertexCount);	//FVF����
		vertex.reserve(vertexCount);		//��ġ�� ����
		for ( int z = 0; z < mapSize; ++z )
		{
			for ( int x = 0; x < mapSize; ++x )
			{
				int index = z * mapSize + x;
				FVF_PositionNormalTexture v;
				v.pos = D3DXVECTOR3((float)x, fileData[index] * 0.1f, (float)-z);	//�� ����Ʈ�� �������� �������� ���� ����(�׳� ���� �ʹ� Ŀ�� 0.1����)
				v.normal = D3DXVECTOR3(0, 1, 0);					//����� �ӽ÷� ���� ������
				v.tex = D3DXVECTOR2(x / (float)tileCount, z / (float)tileCount);	//uv����(ĭ ������ �°�)

				fvfVertex.push_back(v);
				vertex.push_back(v.pos);
			}
		}
		for ( int z = 1; z < tileCount; ++z )	//��ְ� ����
		{
			for ( int x = 1; x < tileCount; ++x )
			{
				int index = z * mapSize + x;
				D3DXVECTOR3 left = vertex[index - 1];		//indx�ֺ� 4����(�¿� ���ٵ���)
				D3DXVECTOR3 right = vertex[index + 1];
				D3DXVECTOR3 front = vertex[index - mapSize];
				D3DXVECTOR3 rear = vertex[index + mapSize];
				D3DXVECTOR3 leftToRight = right - left;	//��->��  ���� ����
				D3DXVECTOR3 frontToRear = rear - front;	//����->�Ʒ��� ����  ����
				D3DXVECTOR3 normal;
				D3DXVec3Cross(&normal, &leftToRight, &frontToRear);	//�� ��� ��� ���� �ΰ� ũ�ν��ϸ� �����ΰ� ����
				D3DXVec3Normalize(&normal, &normal);		//��ֶ�����

				fvfVertex[index].normal = normal;
			}
		}

		//���ؽ� ���ۿ� �ε��� ���� �����
		
		//�ε��� ���ۿ� ������ ����
		//	0--1
		//	| /|
		//	|/ |
		//	2--3
		std::vector<DWORD> indexData;
		triangleCount = tileCount * tileCount * 2;
		indexData.reserve(triangleCount * 3);	//�ε��� ������ ũ�� = �ﰢ�� ���� * 3		
		for ( int z = 0; z < tileCount; ++z )
		{
			for ( int x = 0; x < tileCount; ++x )
			{
				//ĭ���� �ﰢ�� �ΰ���
				int _0 = ( x + 0 ) + ( z + 0 ) * mapSize;
				int _1 = ( x + 1 ) + ( z + 0 ) * mapSize;
				int _2 = ( x + 0 ) + ( z + 1 ) * mapSize;
				int _3 = ( x + 1 ) + ( z + 1 ) * mapSize;
				indexData.push_back(_0); indexData.push_back(_1); indexData.push_back(_2);
				indexData.push_back(_3); indexData.push_back(_2); indexData.push_back(_1);
			}
		}

		//���ؽ� ���� �����
		int bufferSize = fvfVertex.size() * sizeof(FVF_PositionNormalTexture);
		GameManager::GetDevice()->CreateVertexBuffer(
			bufferSize,
			0,
			FVF_PositionNormalTexture::FVF,
			D3DPOOL_MANAGED,
			&vertexBuffer,
			nullptr);
		LPVOID pV;
		vertexBuffer->Lock(0, 0, &pV, 0);		
		memcpy_s(pV, bufferSize, &fvfVertex[0], bufferSize);
		vertexBuffer->Unlock();

		//�ε��� ���� �����
		bufferSize = indexData.size() * sizeof(DWORD);
		GameManager::GetDevice()->CreateIndexBuffer(
			bufferSize,
			0,
			D3DFMT_INDEX32,
			D3DPOOL_MANAGED,
			&indexBuffer,
			nullptr);
		LPVOID pI;
		indexBuffer->Lock(0, 0, &pI, 0);
		memcpy_s(pI, bufferSize, &indexData[0], bufferSize);
		indexBuffer->Unlock();
		

		//��Ƽ���� ������ ����
		ZeroMemory(&material, sizeof(D3DMATERIAL9));
		material.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f); 
		material.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f); 
		material.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

		//�ؽ��� �ε�
		SAFE_RELEASE(texture);
		texture = TextureManager::GetTexture(textureFileName);
	}
}

void HeightMap::Destroy()
{
	SAFE_RELEASE(vertexBuffer);
	SAFE_RELEASE(indexBuffer);
	texture = nullptr;
}

void HeightMap::Render()
{
	GameManager::GetDevice()->SetTransform(D3DTS_WORLD, &world);
	GameManager::GetDevice()->SetRenderState(D3DRS_LIGHTING, true);
	GameManager::GetDevice()->SetMaterial(&material);
	GameManager::GetDevice()->SetTexture(0, texture);
	GameManager::GetDevice()->SetFVF(FVF_PositionNormalTexture::FVF);
	GameManager::GetDevice()->SetStreamSource(0, vertexBuffer, 0, sizeof(FVF_PositionNormalTexture));
	GameManager::GetDevice()->SetIndices(indexBuffer);
	GameManager::GetDevice()->DrawIndexedPrimitive(
		D3DPT_TRIANGLELIST,
		0,
		0,
		vertexCount,
		0,
		triangleCount);
}

bool HeightMap::GetHeight(float& outHeight, float x, float z)
{
	if ( x < 0 || z > 0 || x > mapSize || z < -mapSize )
	{
		return false;
	}

	int intX = (int)x;
	int intZ = (int)-z;
	
	//	0--1
	//  | /|
	//  |/ |
	//  2--3
	int _0 = ( intX + 0 ) + ( intZ + 0 ) * mapSize;	//�ε��� 4�� ���ϱ�
	int _1 = ( intX + 1 ) + ( intZ + 0 ) * mapSize;
	int _2 = ( intX + 0 ) + ( intZ + 1 ) * mapSize;
	int _3 = ( intX + 1 ) + ( intZ + 1 ) * mapSize;
	
	float fDeltaX = x - intX;		// �Ҽ��� �߶󳻱�
	float fDeltaZ = -z - intZ;
	
	if ( fDeltaX + fDeltaZ < 1 )	//0�� ������
	{
		D3DXVECTOR3 v0to1 = vertex[_1] - vertex[_0];
		D3DXVECTOR3 v0to2 = vertex[_2] - vertex[_0];
		v0to1 *= fDeltaX;
		v0to2 *= fDeltaZ;
		outHeight = ( v0to1 + v0to2 ).y + vertex[_0].y;
	}
	else    //3�� ������
	{
		fDeltaX = 1 - fDeltaX;
		fDeltaZ = 1 - fDeltaZ;
		D3DXVECTOR3 v3to1 = vertex[_1] - vertex[_3];
		D3DXVECTOR3 v3to2 = vertex[_2] - vertex[_3];
		v3to1 *= fDeltaZ;
		v3to2 *= fDeltaX;
		outHeight = ( v3to1 + v3to2 ).y + vertex[_3].y;
	}
	return true;
}
