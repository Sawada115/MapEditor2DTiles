//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   TileManager.cpp
//!
//! @brief  �^�C���}�l�[�W���[�N���X
//!
//! @date   ���t�@2017/09/27
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include "pch.h"
#include "MapOutPut.h"
#include <iostream> 
#include <string>
#include <fstream>  
#include <sstream>  

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// �ÓI�ϐ��̏�����
const int MapOutPut::BUTTON_SIZE_X = 75;
const int MapOutPut::BUTTON_SIZE_Y = 25;



//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �T�C�Y
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
MapOutPut::MapOutPut()
	:UI_Buttan(Vector2(150, 50))
{

}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] ���݂��Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
MapOutPut::~MapOutPut()
{
}



//----------------------------------------------------------------------
//! @brief ����������
//!
//! @param[in] �{�^�����W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void MapOutPut::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{
	UI_Buttan::initialize(L"Resources/OutPutButton.png",buttonPos);
}

/// <summary>
/// �{�^�����������Ƃ��̏���
/// </summary>
void MapOutPut::toActivate()
{

}






//----------------------------------------------------------------------
//! @brief �^�C���f�[�^���o��
//!
//! @param[in] ���C���[�ԍ� �o�̓f�[�^ �}�b�v�̉���
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void MapOutPut::OutPutCsv(HWND hWnd,int layerNum,std::vector<Tile*> tileData,Vector2 mapSize)
{
	//HWND hWnd = NULL;
	static OPENFILENAME     ofn;
	static TCHAR            szPath[MAX_PATH];	// �����t�H���_�ʒu
	static TCHAR            szFile[MAX_PATH];   // �I�������t�@�C���� Static�Ȃ̂Ŋ֐��O�ł������Ă��邪�C���������ĂԂƎ��ʁB
	static TCHAR            szFileName[MAX_PATH];	// �����t�H���_�ʒu
	static char				szFname[MAX_PATH];  // �o�͗p�̃t�@�C���� char�̕��������₷�����Ƃ�����


	if (szPath[0] == TEXT('\0')) {
		GetCurrentDirectory(MAX_PATH, szPath);
	}
	if (ofn.lStructSize == 0) {
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrInitialDir = szPath;       // �����t�H���_�ʒu
		ofn.lpstrFile = szFile;				// �I���t�@�C���i�[
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrFilter =
			TEXT("���ׂẴt�@�C��(*.*)\0*.*\0");
		ofn.lpstrTitle = TEXT("�t�@�C����I�����܂��B");
		ofn.Flags = OFN_FILEMUSTEXIST;
		ofn.lpstrFileTitle = szFileName;
		ofn.nMaxFileTitle = MAX_PATH;
	}
	if (GetSaveFileName(&ofn)) {
		MessageBox(hWnd, szFileName, TEXT("�t�@�C�����J��"), MB_OK);
	}
	else {
		// cancelled
		//return "saved_image.bmp";
	}

	//// �t�@�C�����J��
	//string fileName = "MapDate";
	//string layerName = "Layer" + std::to_string(layerNum);

	//ofstream ofs(fileName + layerName + ".csv");
	//
	//if (ofs)
	//{
	//	// �}�b�v�̏c���E�������o��
	//	ofs << mapSize.x << "," << mapSize.y << endl;

	//	int count = 0;
	//	for (auto itr = tileData.begin(); itr != tileData.end(); itr++)
	//	{
	//		count++;
	//		// �f�[�^���܂Ƃ߂�
	//		int data = ((*itr)->getNum() + 1) * 10 + (int)(*itr)->getColision();
	//		// �f�[�^�̏����o��
	//		ofs << data << ",";
	//		// ���s����
	//		if (count >= mapSize.x)
	//		{
	//			count = 0;
	//			ofs << endl;
	//		}
	//	}
	//}
	//return;
}



vector<MapOutPut::TileData> MapOutPut::InPutCsv(std::string fileName)
{
	// �t�@�C�����J��
	ifstream ifs(fileName + ".csv");
	string str;
	int i = 0;

	vector<TileData> tileData;

	if (ifs)
	{
		string token;
		Vector2 mapSize;

		// �}�b�v�T�C�Y�̓ǂݍ���
		if (getline(ifs, str))
		{
			istringstream stream(str);
			getline(stream, token, ',');
			mapSize.x = atoi(token.c_str());
			getline(stream, token, ',');
			mapSize.y = atoi(token.c_str());
		}

		tileData.resize(mapSize.x * mapSize.y);
		// �^�C���f�[�^�̓ǂݍ���
		while (getline(ifs, str))
		{
			istringstream stream(str);
			while (getline(stream, token, ','))
			{
				int num = atoi(token.c_str());
				tileData[i].imageType = num / 10;
				tileData[i].isColision = num % 10;
				i++;
			}
		}
	}
	return tileData;
}

//----------------------------------------------------------------------
//! @brief �o�̓{�^������
//!
//! @param[in] ���WX ���WY
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
bool MapOutPut::isPressed(int posX, int posY )
{
	if (UI_Buttan::isPressed(posX, posY))
	{
		return true;
	}
	return false;

}
