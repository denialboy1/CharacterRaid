#include "stdafx.h"
#include "Ray.h"


Ray::Ray()
{
}


Ray::~Ray()
{
}

Ray Ray::CalcRayFromSceenPoint(POINT mousePoint)
{
	D3DVIEWPORT9 viewPort;
	GameManager::GetDevice()->GetViewport(&viewPort);
	D3DXMATRIXA16 projection;
	GameManager::GetDevice()->GetTransform(D3DTS_PROJECTION, &projection);

	Ray resultRay;

	//����Ʈ�� ���������� ���� ����
	resultRay.direction.x = ( ( 2.0f * mousePoint.x ) / viewPort.Width - 1.0f ) / projection(0,0);
	resultRay.direction.y = ( ( -2.0f * mousePoint.y ) / viewPort.Height + 1.0f ) / projection(1,1);
	resultRay.direction.z = 1.0f;

	D3DXMATRIXA16 view, inverseView;
	GameManager::GetDevice()->GetTransform(D3DTS_VIEW, &view);
	D3DXMatrixInverse(&inverseView, nullptr, &view);

	//�� ��Ʈ������ ���� ����(������ ��ġ�� ������ ������)
	D3DXVec3TransformCoord(&resultRay.origin, &resultRay.origin, &inverseView);			//��ġ
	D3DXVec3TransformNormal(&resultRay.direction, &resultRay.direction, &inverseView);	//����
	D3DXVec3Normalize(&resultRay.direction, &resultRay.direction);

	return resultRay;
}

bool Ray::IsPicked(const BoundingShere* sphere)
{
	if ( sphere )
	{
		D3DXVECTOR3 lengthVector = sphere->center - origin;
		float lengthSquare = D3DXVec3LengthSq(&lengthVector);
		float radiusSquare = sphere->radius * sphere->radius;
		if ( lengthSquare < radiusSquare )
		{
			return true;	//������ �� �ȿ��� ���۵ȴ�.
		}

		float s = D3DXVec3Dot(&lengthVector, &direction);
		if ( s < 0 )
		{
			//������ �������� ���� �ۿ� �ִ�.
			//�� ������ ������ 90���� �Ѿ��.
			// == ���� �������� �������� �ʴ´�.
			return false;
		}

		float mSquare = lengthSquare - s * s;	//��Ÿ����� ������ �̿��� m�� ���Ѵ�.
		if ( mSquare > radiusSquare )
		{
			//m�� ���� ���������� ũ�� �̰͵� �������� �������� �ʴ´�.
			return false;
		}
		else
		{
			//m�� ���� ���������� �۴ٸ� ������ ������.
			return true;
		}
	}

	return false;
}