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
#include <WinBase.h>
#include <tchar.h>

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
	UI_Buttan::initialize(L"Resources/OutPutButton.png", buttonPos);

	// �_�C�A���O�ݒ�
	GetCurrentDirectory(MAX_PATH, m_folderPath);
	memset(&m_ofn, 0, sizeof(OPENFILENAME));
	memset(m_filePath,NULL, MAX_PATH);
	memset(m_fileName, NULL, MAX_PATH);

	m_ofn.lStructSize = sizeof(OPENFILENAME);
	m_ofn.hwndOwner = NULL;
	m_ofn.lpstrInitialDir = m_folderPath;       // �����t�H���_�ʒu
	m_ofn.lpstrFile = m_filePath;				// �I���t�@�C���i�[
	m_ofn.nMaxFile = MAX_PATH;
	m_ofn.lpstrFilter = TEXT("CSV(�J���}��؂�)(*.csv)\0*.csv");
	m_ofn.lpstrTitle = TEXT("���O��t���ĕۑ�");
	m_ofn.Flags = OFN_FILEMUSTEXIST;
	m_ofn.lpstrFileTitle = m_fileName;			// ���̓t�@�C����
	m_ofn.nMaxFileTitle = MAX_PATH;
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
void MapOutPut::OutPutCsv(int layerNum,std::vector<Tile*> tileData,Vector2 mapSize)
{
	// �t�@�C�����J��
	TCHAR layeName[MAX_PATH] = { _T(".csv") };
	TCHAR filePath[MAX_PATH];
	memset(filePath, NULL, MAX_PATH);
	wcscat(filePath, m_fileName);
	wcscat(filePath, layeName);

	ofstream ofs(filePath);
	
	if (ofs)
	{
		// �}�b�v�̏c���E�������o��
		ofs << mapSize.x << "," << mapSize.y << endl;

		int count = 0;
		for (auto itr = tileData.begin(); itr != tileData.end(); itr++)
		{
			count++;
			// �f�[�^���܂Ƃ߂�
			int data = ((*itr)->getNum() + 1) * 10 + (int)(*itr)->getColision();
			// �f�[�^�̏����o��
			ofs << data << ",";
			// ���s����
			if (count >= mapSize.x)
			{
				count = 0;
				ofs << endl;
			}
		}
	}
	return;
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

bool MapOutPut::SetSaveFilePath()
{	
	// �_�C�A���O���J��
	return GetSaveFileName(&m_ofn);
}
