#include "stdafx.h"
#include "Stage3.h"


Stage3::Stage3()
{
}


Stage3::~Stage3()
{
}

void Stage3::Initialize(float _width, float _height, char* fileName){
	Stage::Initialize(_width, _height, fileName);

	vWall.resize(8);

	vWall[0] = new StructureObject;
	vWall[0]->Initialize("HellWall1/", "wall7.X", D3DXVECTOR3(0.03, 0.02, 0.045));
	vWall[0]->SetPosition(D3DXVECTOR3(-44, 0, -15.5));

	vWall[1] = new StructureObject;
	vWall[1]->Initialize("HellWall1/", "wall8.X", D3DXVECTOR3(0.03, 0.02, 0.045));
	vWall[1]->SetPosition(D3DXVECTOR3(-44, 0, 15.5));
	vWall[1]->SetAngle(0.2f);

	vWall[2] = new StructureObject;
	vWall[2]->Initialize("HellWall1/", "wall7.X", D3DXVECTOR3(0.03, 0.02, 0.045));
	vWall[2]->SetPosition(D3DXVECTOR3(44, 0, 15.5));
	vWall[2]->SetAngle(D3DX_PI);

	vWall[3] = new StructureObject;
	vWall[3]->Initialize("HellWall1/", "wall8.X", D3DXVECTOR3(0.03, 0.02, 0.045));
	vWall[3]->SetPosition(D3DXVECTOR3(44, 0, -15.5));
	vWall[3]->SetAngle(0.2f + D3DX_PI);
	
	vWall[4] = new StructureObject;
	vWall[4]->Initialize("HellWall1/", "wall7.X", D3DXVECTOR3(0.03, 0.02, 0.06));
	vWall[4]->SetPosition(D3DXVECTOR3(19, 0, -29));
	vWall[4]->SetAngle(-D3DX_PI/2);

	vWall[5] = new StructureObject;
	vWall[5]->Initialize("HellWall1/", "wall8.X", D3DXVECTOR3(0.03, 0.02, 0.06));
	vWall[5]->SetPosition(D3DXVECTOR3(-19, 0, -29));
	vWall[5]->SetAngle(0.15- D3DX_PI/2);

	vWall[6] = new StructureObject;
	vWall[6]->Initialize("HellWall1/", "wall7.X", D3DXVECTOR3(0.03, 0.02, 0.06));
	vWall[6]->SetPosition(D3DXVECTOR3(-19, 0, 29));
	vWall[6]->SetAngle(D3DX_PI / 2);

	vWall[7] = new StructureObject;
	vWall[7]->Initialize("HellWall1/", "wall8.X", D3DXVECTOR3(0.03, 0.02, 0.06));
	vWall[7]->SetPosition(D3DXVECTOR3(19.5, 0, 29));
	vWall[7]->SetAngle(0.15 + D3DX_PI / 2);

	vTeleport.resize(24);
	
	vTeleport[0] = new Billboard;
	vTeleport[0]->Initialize(D3DXVECTOR3(-45, 2, 0), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[0]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[1] = new Billboard;
	vTeleport[1]->Initialize(D3DXVECTOR3(-45, 2, 3), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[1]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[2] = new Billboard;
	vTeleport[2]->Initialize(D3DXVECTOR3(-45, 2, -3), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[2]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[3] = new Billboard;
	vTeleport[3]->Initialize(D3DXVECTOR3(45, 2, 0), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[3]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[4] = new Billboard;
	vTeleport[4]->Initialize(D3DXVECTOR3(45, 2, 3), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[4]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[5] = new Billboard;
	vTeleport[5]->Initialize(D3DXVECTOR3(45, 2, -3), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[5]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[6] = new Billboard;
	vTeleport[6]->Initialize(D3DXVECTOR3(0, 2, 31.5), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[6]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[7] = new Billboard;
	vTeleport[7]->Initialize(D3DXVECTOR3(3, 2, 31.5), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[7]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[8] = new Billboard;
	vTeleport[8]->Initialize(D3DXVECTOR3(-3, 2, 31.5), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[8]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[9] = new Billboard;
	vTeleport[9]->Initialize(D3DXVECTOR3(0, 2, -30), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[9]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[10] = new Billboard;
	vTeleport[10]->Initialize(D3DXVECTOR3(3, 2, -30), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[10]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[11] = new Billboard;
	vTeleport[11]->Initialize(D3DXVECTOR3(-3, 2, -30), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[11]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[12] = new Billboard;
	vTeleport[12]->Initialize(D3DXVECTOR3(-38.5, 2, -24), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[12]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[13] = new Billboard;
	vTeleport[13]->Initialize(D3DXVECTOR3(-35.5, 2, -25), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[13]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[14] = new Billboard;
	vTeleport[14]->Initialize(D3DXVECTOR3(-32.5, 2, -26), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[14]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[15] = new Billboard;
	vTeleport[15]->Initialize(D3DXVECTOR3(38.5, 2, 25), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[15]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[16] = new Billboard;
	vTeleport[16]->Initialize(D3DXVECTOR3(35.5, 2, 26), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[16]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[17] = new Billboard;
	vTeleport[17]->Initialize(D3DXVECTOR3(32.5, 2, 27), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[17]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[18] = new Billboard;
	vTeleport[18]->Initialize(D3DXVECTOR3(38.5, 2, -24), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[18]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[19] = new Billboard;
	vTeleport[19]->Initialize(D3DXVECTOR3(35.5, 2, -25), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[19]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[20] = new Billboard;
	vTeleport[20]->Initialize(D3DXVECTOR3(32.5, 2, -26), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[20]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[21] = new Billboard;
	vTeleport[21]->Initialize(D3DXVECTOR3(-38.5, 2, 26), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[21]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[22] = new Billboard;
	vTeleport[22]->Initialize(D3DXVECTOR3(-35.5, 2, 27), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[22]->SetTexture(TextureManager::GetTexture("fire_004.png"));

	vTeleport[23] = new Billboard;
	vTeleport[23]->Initialize(D3DXVECTOR3(-32.5, 2, 28), D3DXVECTOR3(2, 2, 2), 4, 4);
	vTeleport[23]->SetTexture(TextureManager::GetTexture("fire_004.png"));


	vTeleportCollision.resize(40);


	///3시
	vTeleportCollision[0] = new Collider_Sphere;
	vTeleportCollision[0]->Initialize(vTeleport[0]->GetPos() + D3DXVECTOR3(0, -2, 0), 1);
	vTeleportCollision[0]->SetWireRender(true);

	vTeleportCollision[1] = new Collider_Sphere;
	vTeleportCollision[1]->Initialize(vTeleport[0]->GetPos() + D3DXVECTOR3(0,-2,2), 1);
	vTeleportCollision[1]->SetWireRender(true);

	vTeleportCollision[2] = new Collider_Sphere;
	vTeleportCollision[2]->Initialize(vTeleport[0]->GetPos() - D3DXVECTOR3(0, 2, 2), 1);
	vTeleportCollision[2]->SetWireRender(true);

	vTeleportCollision[3] = new Collider_Sphere;
	vTeleportCollision[3]->Initialize(vTeleport[0]->GetPos() - D3DXVECTOR3(0, 2, 4), 1);
	vTeleportCollision[3]->SetWireRender(true);


	//9시
	vTeleportCollision[4] = new Collider_Sphere;
	vTeleportCollision[4]->Initialize(vTeleport[3]->GetPos() + D3DXVECTOR3(0, -2, 0), 1);
	vTeleportCollision[4]->SetWireRender(true);

	vTeleportCollision[5] = new Collider_Sphere;
	vTeleportCollision[5]->Initialize(vTeleport[3]->GetPos() + D3DXVECTOR3(0, -2, 2), 1);
	vTeleportCollision[5]->SetWireRender(true);

	vTeleportCollision[6] = new Collider_Sphere;
	vTeleportCollision[6]->Initialize(vTeleport[3]->GetPos() - D3DXVECTOR3(0, 2, 2), 1);
	vTeleportCollision[6]->SetWireRender(true);

	vTeleportCollision[7] = new Collider_Sphere;
	vTeleportCollision[7]->Initialize(vTeleport[3]->GetPos() - D3DXVECTOR3(0, 2, 4), 1);
	vTeleportCollision[7]->SetWireRender(true);

	//6시
	vTeleportCollision[8] = new Collider_Sphere;
	vTeleportCollision[8]->Initialize(vTeleport[6]->GetPos() + D3DXVECTOR3(1, -2, -1), 1);
	vTeleportCollision[8]->SetWireRender(true);

	vTeleportCollision[9] = new Collider_Sphere;
	vTeleportCollision[9]->Initialize(vTeleport[6]->GetPos() + D3DXVECTOR3(3, -2, -1), 1);
	vTeleportCollision[9]->SetWireRender(true);

	vTeleportCollision[10] = new Collider_Sphere;
	vTeleportCollision[10]->Initialize(vTeleport[6]->GetPos() - D3DXVECTOR3(1, 2, 1), 1);
	vTeleportCollision[10]->SetWireRender(true);

	vTeleportCollision[11] = new Collider_Sphere;
	vTeleportCollision[11]->Initialize(vTeleport[6]->GetPos() - D3DXVECTOR3(3, 2, 1), 1);
	vTeleportCollision[11]->SetWireRender(true);

	//12시
	vTeleportCollision[12] = new Collider_Sphere;
	vTeleportCollision[12]->Initialize(vTeleport[9]->GetPos() + D3DXVECTOR3(1, -2, -1), 1);
	vTeleportCollision[12]->SetWireRender(true);

	vTeleportCollision[13] = new Collider_Sphere;
	vTeleportCollision[13]->Initialize(vTeleport[9]->GetPos() + D3DXVECTOR3(3, -2, -1), 1);
	vTeleportCollision[13]->SetWireRender(true);

	vTeleportCollision[14] = new Collider_Sphere;
	vTeleportCollision[14]->Initialize(vTeleport[9]->GetPos() - D3DXVECTOR3(1, 2, 1), 1);
	vTeleportCollision[14]->SetWireRender(true);

	vTeleportCollision[15] = new Collider_Sphere;
	vTeleportCollision[15]->Initialize(vTeleport[9]->GetPos() - D3DXVECTOR3(3, 2, 1), 1);
	vTeleportCollision[15]->SetWireRender(true);

	//1시
	vTeleportCollision[16] = new Collider_Sphere;
	vTeleportCollision[16]->Initialize(vTeleport[12]->GetPos() + D3DXVECTOR3(-2, -2, 0.5), 1);
	vTeleportCollision[16]->SetWireRender(true);

	vTeleportCollision[17] = new Collider_Sphere;
	vTeleportCollision[17]->Initialize(vTeleport[12]->GetPos() + D3DXVECTOR3(0, -2, -0.5), 1);
	vTeleportCollision[17]->SetWireRender(true);

	vTeleportCollision[18] = new Collider_Sphere;
	vTeleportCollision[18]->Initialize(vTeleport[12]->GetPos() + D3DXVECTOR3(2, -2, -1.5), 1);
	vTeleportCollision[18]->SetWireRender(true);

	vTeleportCollision[19] = new Collider_Sphere;
	vTeleportCollision[19]->Initialize(vTeleport[12]->GetPos() + D3DXVECTOR3(4, -2, -2.5), 1);
	vTeleportCollision[19]->SetWireRender(true);

	vTeleportCollision[20] = new Collider_Sphere;
	vTeleportCollision[20]->Initialize(vTeleport[12]->GetPos() + D3DXVECTOR3(6, -2, -3), 1);
	vTeleportCollision[20]->SetWireRender(true);

	vTeleportCollision[21] = new Collider_Sphere;
	vTeleportCollision[21]->Initialize(vTeleport[12]->GetPos() + D3DXVECTOR3(8, -2, -3.5), 1);
	vTeleportCollision[21]->SetWireRender(true);

	//7시
	vTeleportCollision[22] = new Collider_Sphere;
	vTeleportCollision[22]->Initialize(vTeleport[15]->GetPos() + D3DXVECTOR3(-2, -2, 0.5), 1);
	vTeleportCollision[22]->SetWireRender(true);

	vTeleportCollision[23] = new Collider_Sphere;
	vTeleportCollision[23]->Initialize(vTeleport[15]->GetPos() + D3DXVECTOR3(0, -2, -0.5), 1);
	vTeleportCollision[23]->SetWireRender(true);

	vTeleportCollision[24] = new Collider_Sphere;
	vTeleportCollision[24]->Initialize(vTeleport[15]->GetPos() + D3DXVECTOR3(2, -2, -1.5), 1);
	vTeleportCollision[24]->SetWireRender(true);

	vTeleportCollision[25] = new Collider_Sphere;
	vTeleportCollision[25]->Initialize(vTeleport[15]->GetPos() - D3DXVECTOR3(4, 2, -1.5), 1);
	vTeleportCollision[25]->SetWireRender(true);

	vTeleportCollision[26] = new Collider_Sphere;
	vTeleportCollision[26]->Initialize(vTeleport[15]->GetPos() - D3DXVECTOR3(6, 2, -2), 1);
	vTeleportCollision[26]->SetWireRender(true);

	vTeleportCollision[27] = new Collider_Sphere;
	vTeleportCollision[27]->Initialize(vTeleport[15]->GetPos() - D3DXVECTOR3(8, 2, -2.5), 1);
	vTeleportCollision[27]->SetWireRender(true);

	//11시
	vTeleportCollision[28] = new Collider_Sphere;
	vTeleportCollision[28]->Initialize(vTeleport[18]->GetPos() + D3DXVECTOR3(2, -2, 0), 1);
	vTeleportCollision[28]->SetWireRender(true);

	vTeleportCollision[29] = new Collider_Sphere;
	vTeleportCollision[29]->Initialize(vTeleport[18]->GetPos() + D3DXVECTOR3(0, -2, -1), 1);
	vTeleportCollision[29]->SetWireRender(true);

	vTeleportCollision[30] = new Collider_Sphere;
	vTeleportCollision[30]->Initialize(vTeleport[18]->GetPos() + D3DXVECTOR3(-2, -2, -1.5), 1);
	vTeleportCollision[30]->SetWireRender(true);

	vTeleportCollision[31] = new Collider_Sphere;
	vTeleportCollision[31]->Initialize(vTeleport[18]->GetPos() + D3DXVECTOR3(-4, -2, -2), 1);
	vTeleportCollision[31]->SetWireRender(true);

	vTeleportCollision[32] = new Collider_Sphere;
	vTeleportCollision[32]->Initialize(vTeleport[18]->GetPos() + D3DXVECTOR3(-6, -2, -2.5), 1);
	vTeleportCollision[32]->SetWireRender(true);

	vTeleportCollision[33] = new Collider_Sphere;
	vTeleportCollision[33]->Initialize(vTeleport[18]->GetPos() + D3DXVECTOR3(-8, -2, -3), 1);
	vTeleportCollision[33]->SetWireRender(true);

	//5시
	vTeleportCollision[34] = new Collider_Sphere;
	vTeleportCollision[34]->Initialize(vTeleport[21]->GetPos() + D3DXVECTOR3(3.5, -2, 0.7), 1);
	vTeleportCollision[34]->SetWireRender(true);

	vTeleportCollision[35] = new Collider_Sphere;
	vTeleportCollision[35]->Initialize(vTeleport[21]->GetPos() + D3DXVECTOR3(1.5, -2, 0), 1);
	vTeleportCollision[35]->SetWireRender(true);

	vTeleportCollision[36] = new Collider_Sphere;
	vTeleportCollision[36]->Initialize(vTeleport[21]->GetPos() + D3DXVECTOR3(-0.5, -2, -0.7), 1);
	vTeleportCollision[36]->SetWireRender(true);

	vTeleportCollision[37] = new Collider_Sphere;
	vTeleportCollision[37]->Initialize(vTeleport[21]->GetPos() + D3DXVECTOR3(-2.5, -2, -1.4), 1);
	vTeleportCollision[37]->SetWireRender(true);

	vTeleportCollision[38] = new Collider_Sphere;
	vTeleportCollision[38]->Initialize(vTeleport[21]->GetPos() - D3DXVECTOR3(-5.5, 2, -1.5), 1);
	vTeleportCollision[38]->SetWireRender(true);

	vTeleportCollision[39] = new Collider_Sphere;
	vTeleportCollision[39]->Initialize(vTeleport[21]->GetPos() - D3DXVECTOR3(-7.5, 2, -2), 1);
	vTeleportCollision[39]->SetWireRender(true);

	if (path == nullptr){
		path = new PathFinder;
		path->Initialize("stage3.txt");
	}
}
void Stage3::Destroy(){
	Stage::Destroy();

	for (int i = 0; i < vWall.size(); i++){
		SAFE_DELETE(vWall[i]);
	}
	vWall.clear();

	for (int i = 0; i < vTeleport.size(); i++){
		SAFE_DELETE(vTeleport[i]);
	}
	vTeleport.clear();

	for (int i = 0; i < vTeleportCollision.size(); i++){
		SAFE_DELETE(vTeleportCollision[i]);
	}
	vTeleportCollision.clear();

	if (path) SAFE_DELETE(path);
}
void Stage3::Update(player& _player){
	for (int i = 0; i < vWall.size(); i++){
		vWall[i]->Update();
	}

	for (int i = 0; i < vTeleport.size(); i++){
		vTeleport[i]->Update(GameManager::Get().GetCamera()->GetEyePosition());
	}

	for (int i = 0; i < vTeleportCollision.size(); i++){
		vTeleportCollision[i]->Update();
	}

	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[0]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[1]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[2]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[3]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(40, 0, 0));
		_player.removeAction();
		_player.SetIsIdle(true);
	}

	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[4]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[5]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[6]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[7]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(-40, 0, 0));
		_player.removeAction();
		_player.SetIsIdle(true);
	}

	//6시
	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[8]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[9]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[10]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[11]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(0, 0, -27));
		_player.removeAction();
		_player.SetIsIdle(true);
	}

	//12시
	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[12]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[13]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[14]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[15]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(0, 0, 27));
		_player.removeAction();
		_player.SetIsIdle(true);
	}


	//1시
	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[16]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[17]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[18]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[19]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[20]->GetBoundingSphere()) || 
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[21]->GetBoundingSphere()) ){
		_player.SetPosition(D3DXVECTOR3(34, 0, 20));
		_player.removeAction();
		_player.SetIsIdle(true);
	}

	//7시
	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[22]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[23]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[24]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[25]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[26]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[27]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(-34, 0, -20));
		_player.removeAction();
		_player.SetIsIdle(true);
	}

	//11시
	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[28]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[29]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[30]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[31]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[32]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[33]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(-34, 0, 20));
		_player.removeAction();
		_player.SetIsIdle(true);
	}


	//5시
	if (Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[34]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[35]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[36]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[37]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[38]->GetBoundingSphere()) ||
		Collision::IsSphereToSphere(_player.GetSkinedMesh()->GetCollisionSphere()->GetBoundingSphere(), vTeleportCollision[39]->GetBoundingSphere())){
		_player.SetPosition(D3DXVECTOR3(34, 0, -20));
		_player.removeAction();
		_player.SetIsIdle(true);
	}

	
}
void Stage3::Render(){
	Stage::Render();
	
	for (int i = 0; i < vWall.size(); i++){
		vWall[i]->Render();
	}

	for (int i = 0; i < vTeleport.size(); i++){
		vTeleport[i]->Render();
	}

	//for (int i = 0; i < vTeleportCollision.size(); i++){
	//	vTeleportCollision[i]->Render();
	//}
	//if (path) path->Render();

	
}