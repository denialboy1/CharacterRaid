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

	//맵 파일 데이터 읽기
	char fullPath[1024];
	strcpy_s(fullPath, HEIGHTMAP_DIRECTORY);
	strcat_s(fullPath, mapFileName);
	FILE* fp = nullptr;
	fopen_s(&fp, fullPath, "rb");	//바이너리로 읽기
	if ( fp != nullptr )
	{
		fseek(fp, 0, SEEK_END);		//파일 끝으로 이동
		vertexCount = ftell(fp);	//파일 포인터의 위치 받아오기(= 파일길이 = 정점 개수)
		fseek(fp, 0, SEEK_SET);		//파일 처음으로 이동
		
		mapSize = (int)sqrt(vertexCount + 0.0001f);	//정사각형이라고 가정( 뒤에 0.0001은 float값이라 오차로 1빠지는걸 막기 위해서)
		assert(vertexCount == mapSize * mapSize && "가로 세로 사이즈가 동일한 파일만 로딩이 가능합니다.");
		
		std::vector<unsigned char> fileData;	//0~255니까
		fileData.reserve(vertexCount);

		for ( int i = 0; i < vertexCount; ++i )
		{
			fileData.push_back(fgetc(fp));		//한 바이트씩 다 담기
		}
		fclose(fp);

		tileCount = mapSize - 1;	//한변의 사각형 개수 저장(줄이 4줄이면 3칸이 나옴. 닫혀야하니까)


		//버텍스 만들기
		std::vector<FVF_PositionNormalTexture> fvfVertex;
		fvfVertex.reserve(vertexCount);	//FVF저장
		vertex.reserve(vertexCount);		//위치만 저장
		for ( int z = 0; z < mapSize; ++z )
		{
			for ( int x = 0; x < mapSize; ++x )
			{
				int index = z * mapSize + x;
				FVF_PositionNormalTexture v;
				v.pos = D3DXVECTOR3((float)x, fileData[index] * 0.1f, (float)-z);	//한 바이트씩 읽은것을 기준으로 높이 설정(그냥 쓰면 너무 커서 0.1곱함)
				v.normal = D3DXVECTOR3(0, 1, 0);					//노멀은 임시로 위를 보도록
				v.tex = D3DXVECTOR2(x / (float)tileCount, z / (float)tileCount);	//uv세팅(칸 개수에 맞게)

				fvfVertex.push_back(v);
				vertex.push_back(v.pos);
			}
		}
		for ( int z = 1; z < tileCount; ++z )	//노멀값 갱신
		{
			for ( int x = 1; x < tileCount; ++x )
			{
				int index = z * mapSize + x;
				D3DXVECTOR3 left = vertex[index - 1];		//indx주변 4방향(좌우 앞줄뒷줄)
				D3DXVECTOR3 right = vertex[index + 1];
				D3DXVECTOR3 front = vertex[index - mapSize];
				D3DXVECTOR3 rear = vertex[index + mapSize];
				D3DXVECTOR3 leftToRight = right - left;	//우->좌  방향 벡터
				D3DXVECTOR3 frontToRear = rear - front;	//윗줄->아래줄 방향  벡터
				D3DXVECTOR3 normal;
				D3DXVec3Cross(&normal, &leftToRight, &frontToRear);	//위 계산 결과 백터 두개 크로스하면 수직인거 나옴
				D3DXVec3Normalize(&normal, &normal);		//노멀라이즈

				fvfVertex[index].normal = normal;
			}
		}

		//버텍스 버퍼와 인덱스 버퍼 만들기
		
		//인덱스 버퍼용 데이터 생성
		//	0--1
		//	| /|
		//	|/ |
		//	2--3
		std::vector<DWORD> indexData;
		triangleCount = tileCount * tileCount * 2;
		indexData.reserve(triangleCount * 3);	//인덱스 버퍼의 크기 = 삼각형 개수 * 3		
		for ( int z = 0; z < tileCount; ++z )
		{
			for ( int x = 0; x < tileCount; ++x )
			{
				//칸마다 삼각형 두개씩
				int _0 = ( x + 0 ) + ( z + 0 ) * mapSize;
				int _1 = ( x + 1 ) + ( z + 0 ) * mapSize;
				int _2 = ( x + 0 ) + ( z + 1 ) * mapSize;
				int _3 = ( x + 1 ) + ( z + 1 ) * mapSize;
				indexData.push_back(_0); indexData.push_back(_1); indexData.push_back(_2);
				indexData.push_back(_3); indexData.push_back(_2); indexData.push_back(_1);
			}
		}

		//버텍스 버퍼 만들기
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

		//인덱스 버퍼 만들기
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
		

		//머티리얼 간단히 세팅
		ZeroMemory(&material, sizeof(D3DMATERIAL9));
		material.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f); 
		material.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f); 
		material.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

		//텍스쳐 로딩
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
	int _0 = ( intX + 0 ) + ( intZ + 0 ) * mapSize;	//인덱스 4개 구하기
	int _1 = ( intX + 1 ) + ( intZ + 0 ) * mapSize;
	int _2 = ( intX + 0 ) + ( intZ + 1 ) * mapSize;
	int _3 = ( intX + 1 ) + ( intZ + 1 ) * mapSize;
	
	float fDeltaX = x - intX;		// 소수점 잘라내기
	float fDeltaZ = -z - intZ;
	
	if ( fDeltaX + fDeltaZ < 1 )	//0에 가깝다
	{
		D3DXVECTOR3 v0to1 = vertex[_1] - vertex[_0];
		D3DXVECTOR3 v0to2 = vertex[_2] - vertex[_0];
		v0to1 *= fDeltaX;
		v0to2 *= fDeltaZ;
		outHeight = ( v0to1 + v0to2 ).y + vertex[_0].y;
	}
	else    //3에 가깝다
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
