//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapInPut.cpp
//!
//! @brief  �}�b�v�ǂݍ��݃N���X
//!
//! @date   ���t�@2017/10/01
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include "pch.h"
#include "MapInPut.h"
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
const int MapInPut::BUTTON_SIZE_X = 75;
const int MapInPut::BUTTON_SIZE_Y = 25;



//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �T�C�Y
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
MapInPut::MapInPut()
	:UI_Buttan(Vector2(BUTTON_SIZE_X, BUTTON_SIZE_Y))
{

}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] ���݂��Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
MapInPut::~MapInPut()
{
}



//----------------------------------------------------------------------
//! @brief ����������
//!
//! @param[in] �{�^�����W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void MapInPut::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{
	UI_Buttan::initialize(L"Resources/InPutButton.png", buttonPos);

	// �_�C�A���O�ݒ�
	GetCurrentDirectory(MAX_PATH, m_folderPath);
	memset(&m_ofn, 0, sizeof(OPENFILENAME));
	memset(m_filePath, NULL, MAX_PATH);
	memset(m_fileName, NULL, MAX_PATH);

	m_ofn.lStructSize = sizeof(OPENFILENAME);
	m_ofn.hwndOwner = NULL;
	m_ofn.lpstrInitialDir = m_folderPath;       // �����t�H���_�ʒu
	m_ofn.lpstrFile = m_filePath;				// �I���t�@�C���i�[
	m_ofn.nMaxFile = MAX_PATH;
	m_ofn.lpstrFilter = TEXT("CSV(�J���}��؂�)(*.csv)\0*.csv");
	m_ofn.lpstrTitle = TEXT("�t�@�C�����J��");
	m_ofn.Flags = OFN_FILEMUSTEXIST;
	m_ofn.lpstrFileTitle = m_fileName;			// ���̓t�@�C����
	m_ofn.nMaxFileTitle = MAX_PATH;
}

/// <summary>
/// �{�^�����������Ƃ��̏���
/// </summary>
void MapInPut::toActivate()
{

}



//----------------------------------------------------------------------
//! @brief �}�b�v��ǂݍ���
//!
//! @param[in] �ǂݍ��񂾃f�[�^���󂯎��ϐ�
//!
//! @return �ݒ�ł�����
//----------------------------------------------------------------------
void MapInPut::InPutCsv(MakedMap* map)
{
	// �t�@�C�����J��
	m_ofn;
	ifstream ifs(m_ofn.lpstrFile);
	string str;
	int i = 0;

	Vector2 mapSize;

	if (ifs)
	{
		string token;

		// �}�b�v�T�C�Y�̓ǂݍ���
		if (getline(ifs, str))
		{
			istringstream stream(str);
			getline(stream, token, ',');
			mapSize.x = atoi(token.c_str());
			getline(stream, token, ',');
			mapSize.y = atoi(token.c_str());
			map->mapReSize(mapSize.x, mapSize.y);
		}

		vector<TileData> tileData;
		tileData.resize(mapSize.x*mapSize.y);

		// �^�C���f�[�^�̓ǂݍ���
		while (getline(ifs, str))
		{
			istringstream stream(str);
			while (getline(stream, token, ','))
			{
				int num = atoi(token.c_str());
				tileData[i].imageType = num / 10 - 1;
				tileData[i].isColision = num % 10;
				i++;
			}
		}

		for (int i = 0; i < (int)tileData.size(); i++)
		{
			int tileID[2] = { i / mapSize.y,i % (int)mapSize.y };
			Tile* tile = new Tile();
			tile->initialize(tileData[i].imageType);
			tile->setColision(tileData[i].isColision);
			map->changTile(tileID, tile);
		}
	}
}



//----------------------------------------------------------------------
//! @brief �o�̓{�^������
//!
//! @param[in] ���WX ���WY
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
bool MapInPut::isPressed(int posX, int posY)
{
	if (UI_Buttan::isPressed(posX, posY))
	{
		return true;
	}
	return false;
}



//----------------------------------------------------------------------
//! @brief �J���t�@�C���ݒ�
//!
//! @param[in] �Ȃ�
//!
//! @return �ݒ�ł�����
//----------------------------------------------------------------------
bool MapInPut::SetOpenFilePath()
{
	// �_�C�A���O���J��
	bool result = GetOpenFileName(&m_ofn);
	
	// �t�H���_�ʒu�����ɖ߂�
	SetCurrentDirectory(m_folderPath);
	return result;
}
