#include "stdafx.h"
#include "Stage1.h"


Stage1::Stage1()
{
}


Stage1::~Stage1()
{
}


void Stage1::Initialize(float _width, float _height, char* fileName){
	Stage::Initialize(_width, _height, fileName);


	//vMineral.resize(21);
	//
	//vMineral[0] = new StructureObject;
	//vMineral[0]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[0]->SetPosition(D3DXVECTOR3(36, 0, -22));
	//
	//vMineral[1] = new StructureObject;
	//vMineral[1]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[1]->SetPosition(D3DXVECTOR3(35, 0, -20));
	//vMineral[1]->SetAngle(0.2f);
	//
	//vMineral[2] = new StructureObject;
	//vMineral[2]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[2]->SetPosition(D3DXVECTOR3(35, 0, -18));
	//vMineral[2]->SetAngle(D3DX_PI);
	//
	//vMineral[3] = new StructureObject;
	//vMineral[3]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[3]->SetPosition(D3DXVECTOR3(35, 0, -16));
	//vMineral[3]->SetAngle(0.2f + D3DX_PI);
	//
	//vMineral[4] = new StructureObject;
	//vMineral[4]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[4]->SetPosition(D3DXVECTOR3(35, 0, -14));
	//vMineral[4]->SetAngle(-D3DX_PI / 2);
	//
	//vMineral[5] = new StructureObject;
	//vMineral[5]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[5]->SetPosition(D3DXVECTOR3(34.5, 0, -12));
	//vMineral[5]->SetAngle(0.15 - D3DX_PI / 2);
	//
	//vMineral[6] = new StructureObject;
	//vMineral[6]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[6]->SetPosition(D3DXVECTOR3(34.2, 0, -10));
	//vMineral[6]->SetAngle(-D3DX_PI / 2);
	//
	//vMineral[7] = new StructureObject;
	//vMineral[7]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[7]->SetPosition(D3DXVECTOR3(34.1, 0, -8));
	//vMineral[7]->SetAngle(D3DX_PI / 2);
	//
	//vMineral[8] = new StructureObject;
	//vMineral[8]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[8]->SetPosition(D3DXVECTOR3(33.8, 0, -6));
	//vMineral[8]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[9] = new StructureObject;
	//vMineral[9]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[9]->SetPosition(D3DXVECTOR3(33.8, 0, -4));
	//vMineral[9]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[10] = new StructureObject;
	//vMineral[10]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[10]->SetPosition(D3DXVECTOR3(33.8, 0, -2));
	//vMineral[10]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[11] = new StructureObject;
	//vMineral[11]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[11]->SetPosition(D3DXVECTOR3(33.8, 0, 0));
	//vMineral[11]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[12] = new StructureObject;
	//vMineral[12]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[12]->SetPosition(D3DXVECTOR3(33.6, 0, 2));
	//vMineral[12]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[13] = new StructureObject;
	//vMineral[13]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[13]->SetPosition(D3DXVECTOR3(33.4, 0,4));
	//vMineral[13]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[14] = new StructureObject;
	//vMineral[14]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[14]->SetPosition(D3DXVECTOR3(33.2, 0, 6));
	//vMineral[14]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[15] = new StructureObject;
	//vMineral[15]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[15]->SetPosition(D3DXVECTOR3(33, 0, 8));
	//vMineral[15]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[16] = new StructureObject;
	//vMineral[16]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[16]->SetPosition(D3DXVECTOR3(33, 0, 10));
	//vMineral[16]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[17] = new StructureObject;
	//vMineral[17]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[17]->SetPosition(D3DXVECTOR3(32.8, 0, 12));
	//vMineral[17]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[18] = new StructureObject;
	//vMineral[18]->Initialize("Stucture/", "Mineral2.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[18]->SetPosition(D3DXVECTOR3(32.6, 0, 14));
	//vMineral[18]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[19] = new StructureObject;
	//vMineral[19]->Initialize("Stucture/", "Mineral3.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[19]->SetPosition(D3DXVECTOR3(32.2, 0, 16));
	//vMineral[19]->SetAngle(0.15 + D3DX_PI / 2);
	//
	//vMineral[20] = new StructureObject;
	//vMineral[20]->Initialize("Stucture/", "Mineral1.X", D3DXVECTOR3(2, 2, 2));
	//vMineral[20]->SetPosition(D3DXVECTOR3(32.4, 0, 18));
	//vMineral[20]->SetAngle(D3DX_PI / 2);

	vFactory.resize(2);

	//Àûµé ³ª¿À´Â ¿ÀºêÁ§Æ®
	vFactory[0] = new StructureObject;
	vFactory[0]->Initialize("Stucture/", "Factory.X", D3DXVECTOR3(4, 4, 4));
	vFactory[0]->SetPosition(D3DXVECTOR3(30, 0, -27));
	vFactory[0]->GetMesh()->SetAnimationIndex(1);

	vFactory[1] = new StructureObject;
	vFactory[1]->Initialize("Stucture/", "Factory.X", D3DXVECTOR3(4, 4, 4));
	vFactory[1]->SetPosition(D3DXVECTOR3(-30, 0, -27));
	vFactory[1]->GetMesh()->SetAnimationIndex(1);

	vTechLab.resize(2);

	vTechLab[0] = new StructureObject;
	vTechLab[0]->Initialize("Stucture/", "TechLab.X", D3DXVECTOR3(4, 4, 4));
	vTechLab[0]->SetAngle(0.8);
	vTechLab[0]->SetPosition(D3DXVECTOR3(17, 0, -24));
	vTechLab[0]->GetMesh()->SetAnimationIndex(1);

	vTechLab[1] = new StructureObject;
	vTechLab[1]->Initialize("Stucture/", "TechLab.X", D3DXVECTOR3(4, 4, 4));
	vTechLab[1]->SetAngle(3.3);
	vTechLab[1]->SetPosition(D3DXVECTOR3(-17, 0, -24));
	vTechLab[1]->GetMesh()->SetAnimationIndex(1);


	CommandCenter = new StructureObject;
	CommandCenter->Initialize("Stucture/", "CommandCenter.X", D3DXVECTOR3(4, 4, 4));
	CommandCenter->SetPosition(D3DXVECTOR3(0, 0, -29));
	CommandCenter->GetMesh()->SetAnimationIndex(3);


	vTurret.resize(2);

	vTurret[0] = new StructureObject;
	vTurret[0]->Initialize("Stucture/", "LongTurret.X", D3DXVECTOR3(5, 5, 5));
	vTurret[0]->SetAngle(0.1);
	vTurret[0]->SetPosition(D3DXVECTOR3(43.5, 0, -24));
	vTurret[0]->GetMesh()->SetAnimationIndex(1);

	vTurret[1] = new StructureObject;
	vTurret[1]->Initialize("Stucture/", "LongTurret.X", D3DXVECTOR3(5, 5, 5));
	vTurret[1]->SetAngle(-0.1);
	vTurret[1]->SetPosition(D3DXVECTOR3(-43.5, 0, -24));
	vTurret[1]->GetMesh()->SetAnimationIndex(1);

	//vSupplyDepot.resize(8);
	////¿Þ
	//vSupplyDepot[0] = new StructureObject;
	//vSupplyDepot[0]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[0]->SetPosition(D3DXVECTOR3(44, 0, -15));
	//vSupplyDepot[0]->GetMesh()->SetAnimationIndex(0);
	//
	//vSupplyDepot[1] = new StructureObject;
	//vSupplyDepot[1]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[1]->SetPosition(D3DXVECTOR3(44, 0, -4));
	//vSupplyDepot[1]->GetMesh()->SetAnimationIndex(0);
	//
	//vSupplyDepot[2] = new StructureObject;
	//vSupplyDepot[2]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[2]->SetPosition(D3DXVECTOR3(44, 0, 7));
	//vSupplyDepot[2]->GetMesh()->SetAnimationIndex(0);
	//
	//vSupplyDepot[3] = new StructureObject;
	//vSupplyDepot[3]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[3]->SetPosition(D3DXVECTOR3(44, 0, 18));
	//vSupplyDepot[3]->GetMesh()->SetAnimationIndex(0);
	//
	////¿À¸¥
	//vSupplyDepot[4] = new StructureObject;
	//vSupplyDepot[4]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[4]->SetPosition(D3DXVECTOR3(-44, 0, -15));
	//vSupplyDepot[4]->GetMesh()->SetAnimationIndex(0);
	//
	//vSupplyDepot[5] = new StructureObject;
	//vSupplyDepot[5]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[5]->SetPosition(D3DXVECTOR3(-44, 0, -4));
	//vSupplyDepot[5]->GetMesh()->SetAnimationIndex(0);
	//
	//vSupplyDepot[6] = new StructureObject;
	//vSupplyDepot[6]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[6]->SetPosition(D3DXVECTOR3(-44, 0, 7));
	//vSupplyDepot[6]->GetMesh()->SetAnimationIndex(0);
	//
	//vSupplyDepot[7] = new StructureObject;
	//vSupplyDepot[7]->Initialize("Stucture/", "SupplyDepot.X", D3DXVECTOR3(2.3, 2.3, 2.3));
	//vSupplyDepot[7]->SetPosition(D3DXVECTOR3(-44, 0, 18));
	//vSupplyDepot[7]->GetMesh()->SetAnimationIndex(0);

	vMetalWall.resize(20);

	//¸ÞÅ» ¿ÞÂÊ º®
	vMetalWall[0] = new StructureObject;
	vMetalWall[0]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[0]->SetPosition(D3DXVECTOR3(44, 0, -15));
	vMetalWall[0]->SetAngle(4.7);
	vMetalWall[0]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[1] = new StructureObject;
	vMetalWall[1]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[1]->SetPosition(D3DXVECTOR3(44, 0, -7.5));
	vMetalWall[1]->SetAngle(4.7);
	vMetalWall[1]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[2] = new StructureObject;
	vMetalWall[2]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[2]->SetPosition(D3DXVECTOR3(44, 0, 0));
	vMetalWall[2]->SetAngle(4.7);
	vMetalWall[2]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[3] = new StructureObject;
	vMetalWall[3]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[3]->SetPosition(D3DXVECTOR3(44, 0, 7.5));
	vMetalWall[3]->SetAngle(4.7);
	vMetalWall[3]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[4] = new StructureObject;
	vMetalWall[4]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[4]->SetPosition(D3DXVECTOR3(44, 0, 15));
	vMetalWall[4]->SetAngle(4.7);
	vMetalWall[4]->GetMesh()->SetAnimationIndex(0);

	//¸ÞÅ»º® ¿À¸¥ÂÊ
	vMetalWall[5] = new StructureObject;
	vMetalWall[5]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[5]->SetPosition(D3DXVECTOR3(-44, 0, -15));
	vMetalWall[5]->SetAngle(1.6);
	vMetalWall[5]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[6] = new StructureObject;
	vMetalWall[6]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[6]->SetPosition(D3DXVECTOR3(-44, 0, -7.5));
	vMetalWall[6]->SetAngle(1.6);
	vMetalWall[6]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[7] = new StructureObject;
	vMetalWall[7]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[7]->SetPosition(D3DXVECTOR3(-44, 0, 0));
	vMetalWall[7]->SetAngle(1.6);
	vMetalWall[7]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[8] = new StructureObject;
	vMetalWall[8]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[8]->SetPosition(D3DXVECTOR3(-44, 0, 7.5));
	vMetalWall[8]->SetAngle(1.6);
	vMetalWall[8]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[9] = new StructureObject;
	vMetalWall[9]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[9]->SetPosition(D3DXVECTOR3(-44, 0, 15));
	vMetalWall[9]->SetAngle(1.6);
	vMetalWall[9]->GetMesh()->SetAnimationIndex(0);

	///¹Ø¿¡ ¸ÞÅ»º®

	vMetalWall[10] = new StructureObject;
	vMetalWall[10]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[10]->SetPosition(D3DXVECTOR3(37, 0, 23));
	vMetalWall[10]->SetAngle(3.16);
	vMetalWall[10]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[11] = new StructureObject;
	vMetalWall[11]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[11]->SetPosition(D3DXVECTOR3(29, 0, 23));
	vMetalWall[11]->SetAngle(3.16);
	vMetalWall[11]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[12] = new StructureObject;
	vMetalWall[12]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[12]->SetPosition(D3DXVECTOR3(21, 0, 23));
	vMetalWall[12]->SetAngle(3.16);
	vMetalWall[12]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[13] = new StructureObject;
	vMetalWall[13]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[13]->SetPosition(D3DXVECTOR3(13, 0, 23));
	vMetalWall[13]->SetAngle(3.15);
	vMetalWall[13]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[14] = new StructureObject;
	vMetalWall[14]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[14]->SetPosition(D3DXVECTOR3(5, 0, 23));
	vMetalWall[14]->SetAngle(3.15);
	vMetalWall[14]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[15] = new StructureObject;
	vMetalWall[15]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[15]->SetPosition(D3DXVECTOR3(-3, 0, 23));
	vMetalWall[15]->SetAngle(3.15);
	vMetalWall[15]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[16] = new StructureObject;
	vMetalWall[16]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[16]->SetPosition(D3DXVECTOR3(-11, 0, 23));
	vMetalWall[16]->SetAngle(3.15);
	vMetalWall[16]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[17] = new StructureObject;
	vMetalWall[17]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[17]->SetPosition(D3DXVECTOR3(-19, 0, 23));
	vMetalWall[17]->SetAngle(3.15);
	vMetalWall[17]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[18] = new StructureObject;
	vMetalWall[18]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[18]->SetPosition(D3DXVECTOR3(-27, 0, 23));
	vMetalWall[18]->SetAngle(3.15);
	vMetalWall[18]->GetMesh()->SetAnimationIndex(0);

	vMetalWall[19] = new StructureObject;
	vMetalWall[19]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	vMetalWall[19]->SetPosition(D3DXVECTOR3(-35, 0, 23));
	vMetalWall[19]->SetAngle(3.15);
	vMetalWall[19]->GetMesh()->SetAnimationIndex(0);


	//vMetalWall[5] = new StructureObject;
	//vMetalWall[5]->Initialize("Stucture/", "METALWALL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	//vMetalWall[5]->SetPosition(D3DXVECTOR3(44, 0, 22.5));
	//vMetalWall[5]->SetAngle(4.7);
	//vMetalWall[5]->GetMesh()->SetAnimationIndex(0);
	vMetalWallCorner.resize(2);

	vMetalWallCorner[0] = new StructureObject;
	vMetalWallCorner[0]->Initialize("Stucture/", "METALWALLCORNER.X", D3DXVECTOR3(0.03, 0.03, 0.03));
	vMetalWallCorner[0]->SetPosition(D3DXVECTOR3(44, 0, 22.5));
	vMetalWallCorner[0]->GetMesh()->SetAnimationIndex(0);

	vMetalWallCorner[1] = new StructureObject;
	vMetalWallCorner[1]->Initialize("Stucture/", "METALWALLCORNER.X", D3DXVECTOR3(0.03, 0.03, 0.03));
	vMetalWallCorner[1]->SetPosition(D3DXVECTOR3(-43.5, 0, 22.5));
	vMetalWallCorner[1]->SetAngle(4.8);
	vMetalWallCorner[1]->GetMesh()->SetAnimationIndex(0);

	//¹Ì³×¶ö
	//vSupplyDepot[7] = new StructureObject;
	//vSupplyDepot[7]->Initialize("Stucture/", "MINERAL.X", D3DXVECTOR3(0.02, 0.02, 0.02));
	//vSupplyDepot[7]->SetPosition(D3DXVECTOR3(-44, 0, 18));
	//vSupplyDepot[7]->GetMesh()->SetAnimationIndex(0);


}
void Stage1::Destroy(){
	Stage::Destroy();


	for (int i = 0; i < vMineral.size(); i++){
		SAFE_DELETE(vMineral[i]);
	}
	vMineral.clear();

	for (int i = 0; i < vFactory.size(); i++){
		SAFE_DELETE(vFactory[i]);
	}
	vFactory.clear();

	for (int i = 0; i < vTechLab.size(); i++){
		SAFE_DELETE(vTechLab[i]);
	}
	vTechLab.clear();

	for (int i = 0; i < vTurret.size(); i++){
		SAFE_DELETE(vTurret[i]);
	}
	vTurret.clear();

	//for (int i = 0; i < vSupplyDepot.size(); i++){
	//	SAFE_DELETE(vSupplyDepot[i]);
	//}
	vSupplyDepot.clear();

	for (int i = 0; i < vMetalWall.size(); i++){
		SAFE_DELETE(vMetalWall[i]);
	}
	vMetalWall.clear();

	for (int i = 0; i < vMetalWallCorner.size(); i++){
		SAFE_DELETE(vMetalWallCorner[i]);
	}
	vMetalWallCorner.clear();


	SAFE_DELETE(CommandCenter);


}
void Stage1::Update(){
	for (int i = 0; i < vMineral.size(); i++){
		vMineral[i]->Update();
	}
	for (int i = 0; i < vFactory.size(); i++){
		vFactory[i]->Update();
	}
	for (int i = 0; i < vTechLab.size(); i++){
		vTechLab[i]->Update();
	}
	for (int i = 0; i < vTurret.size(); i++){
		vTurret[i]->Update();
	}
	//for (int i = 0; i < vSupplyDepot.size(); i++){
	//	vSupplyDepot[i]->Update();
	//}

	for (int i = 0; i < vMetalWall.size(); i++){
		vMetalWall[i]->Update();
	}

	for (int i = 0; i < vMetalWallCorner.size(); i++){
		vMetalWallCorner[i]->Update();
	}
	CommandCenter->Update();


}
void Stage1::Render(){
	Stage::Render();
	for (int i = 0; i < vMineral.size(); i++){
		vMineral[i]->Render();
	}
	for (int i = 0; i < vFactory.size(); i++){
		vFactory[i]->Render();
	}
	for (int i = 0; i < vTechLab.size(); i++){
		vTechLab[i]->Render();
	}
	for (int i = 0; i < vTurret.size(); i++){
		vTurret[i]->Render();
	}
	//for (int i = 0; i < vSupplyDepot.size(); i++){
	//	vSupplyDepot[i]->Render();
	//}
	for (int i = 0; i < vMetalWall.size(); i++){
		vMetalWall[i]->Render();
	}

	for (int i = 0; i < vMetalWallCorner.size(); i++){
		vMetalWallCorner[i]->Render();
	}

	CommandCenter->Render();

}