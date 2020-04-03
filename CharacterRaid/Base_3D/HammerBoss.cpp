#include "stdafx.h"
#include "HammerBoss.h"


HammerBoss::HammerBoss()
{
}


HammerBoss::~HammerBoss()
{
}


void HammerBoss::Initialize()
{
	unit::Initialize();
	scale.x = 0.03f;
	scale.y = 0.03f;
	scale.z = 0.03f;

	mesh->Initialize("HammerBoss/", "�ظӻ��.X", scale);
	//mesh->GetCollisionSphere()->GetBoundingSphere().center.y = 5;
	//mesh->GetCollisionSphere()->GetBoundingSphere().radius = 50;
	
	if (HammerBossBodySphere == nullptr)
	{
		HammerBossBodySphere = new Collider_Sphere;
		HammerBossBodySphere->Initialize(D3DXVECTOR3(0, 0, 0), 6);
	}
	mesh->SetAnimationIndex(HammerBossState);
	ChangeMotion(STAND);
	HammerBossBodySphere->SetWireRender(true);

	if (_bigMissile == nullptr)
	{
		_bigMissile = new bigMissile;
		_bigMissile->Initialize();
	}

	if (hpBar == nullptr){
		hpBar = new bossBar;
		hpBar->Initialize(10000, 10000);
		hp = hpMax = 10000;
		mp = 0;
	}

	obb = new cOBB;
	obb->Setup(mesh);

}
void HammerBoss::Destroy()
{
	unit::Destroy();
	//mesh->GetCollisionSphere()->Destroy();
	SAFE_DELETE(HammerBossBodySphere);
	_bigMissile->Destroy();
	
}
void HammerBoss::Update()//float _timer)
{
	unit::Update();

	HammerBossBodySphere->GetBoundingSphere().center = mesh->GetCollisionSphere()->GetBoundingSphere().center;
	HammerBossBodySphere->Update();
	_bigMissile->Update();
	obb->Update(&obbWorld);
	D3DXVECTOR3 pos = position;
	pos.y = 13;
	if (hpBar){
		hpBar->Update(GameManager::Get().GetCamera()->GetEyePosition(), pos);
		hpBar->SetCurrentHp(hp);
		hpBar->SetCurrentMp(mp);
	}
}
void HammerBoss::Render()
{
	mesh->UpdateAndRender();
	//HammerBossBodySphere->Render();
	_bigMissile->Render();
	//obb->DebugRender(D3DCOLOR_XRGB(255, 0, 0));
	if (hpBar) hpBar->Render();
}

void HammerBoss::Battle(unit& enemy)
{
	if (Collision::IsSphereToSphere(enemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), HammerBossBodySphere->GetBoundingSphere()))
	{
		enemy.SetHp(enemy.GetHp() - 2);
		//�÷��̾� �Ǳ��־��ָ��
	}
	if (Collision::IsSphereToSphere(enemy.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), _bigMissile->GetMissileBoomSphere()->GetBoundingSphere()))
	{
		//�÷��̾� �Ǳ��־��ָ�� 
		enemy.SetHp(enemy.GetHp() - 10);
	}
}
void HammerBoss::ChangeMotion(HAMMERBOSS_STATE _BossState)
{
	if (action)
		removeAction();
	HammerBossState = _BossState;
	mesh->SetAnimationIndex(HammerBossState);
	mesh->GetAnimController()->SetTrackPosition(0, 0);

	LPD3DXANIMATIONSET animSet = nullptr;							//�ִϸ��̼� ������ �޾��� ����
	mesh->GetAnimController()->GetAnimationSet(HammerBossState, &animSet);	//��ϵ� �ִϸ��̼ǿ��� animSet������ ������ ���
	aniTime = animSet->GetPeriod();									//�ִϸ��̼� �ð����� ���� 
	startTimer = timeGetTime();										//���� �ð� ����
	SAFE_RELEASE(animSet);
}

float HammerBoss::GetAngle(D3DXVECTOR3 v1, D3DXVECTOR3 v2)
{
	D3DXVECTOR3 a(0, 0, 1);
	D3DXVECTOR3 b = v2 - v1;

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&b);
	float dot = D3DXVec3Dot(&a, &b);

	// �ð�������� �ݽð�������� �Ǻ�
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &b);
	if (cross.y < 0)
	{
		dot *= -1;		// �ݽð� �����̴�. �׷��� ������ �ݴ��
	}

	float angle = acos(dot / (aLength * bLength));	//acos�� 0~180�� ������ ���� ���´�.

	//���� 180�� �̻����� �Ǻ�
	D3DXVECTOR3 c(1, 0, 0);	//a�� 90�� ��ŭ ���� ����
	bool over180 = false;
	if (D3DXVec3Dot(&b, &c) < 0.0f)	// c,b�� 90�� �̻��̸� a,b�� 180�� �̻��̶�� �Ҹ�
	{
		over180 = true;
	}

	//180�� �̻��̸� 180���� ������
	if (over180)
	{
		angle += D3DX_PI;
	}

	return angle;
}
void HammerBoss::Action(float _timer)
{


	switch (HammerBossState)
	{
	case HammerBoss::STAND:
		//ChangeMotion(STAND);
		break;
	case HammerBoss::WALK:  //����
		break;
	case HammerBoss::PATTERN_1:
		break;
	case HammerBoss::PATTERN_2:
		break;
	case HammerBoss::PATTERN_3: //����
		break;
	case HammerBoss::ULTIMATE_PATTERN:
		break;
	default:
		break;
	}
}