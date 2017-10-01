//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapOutOut.cpp
//!
//! @brief  �}�b�v�o�̓N���X
//!
//! @date   ���t�@2017/10/01
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
	// �t�@�C�����̍쐬 (���͂����t�@�C�����{Layer�{���C���[�ԍ��{.csv)
	TCHAR layeNum[MAX_PATH];
	TCHAR filePath[MAX_PATH];
	wsprintf(layeNum, TEXT("%d"), layerNum);
	memset(filePath, NULL, MAX_PATH);

	wcscat(filePath, m_filePath);
	wcscat(filePath, _T("Layer"));
	wcscat(filePath, layeNum);
	wcscat(filePath, _T(".csv"));

	// �t�@�C�����J��
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
			if (count >= mapSize.y)
			{
				count = 0;
				ofs << endl;
			}
		}
	}
	return;
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



//----------------------------------------------------------------------
//! @brief �ۑ����ݒ�
//!
//! @param[in] �Ȃ�
//!
//! @return �ݒ�ł�����
//----------------------------------------------------------------------
bool MapOutPut::SetSaveFilePath()
{	
	// �_�C�A���O���J��
	bool result = GetSaveFileName(&m_ofn);
	// �t�H���_�ʒu�����ɖ߂�
	SetCurrentDirectory(m_folderPath);
	return result;
}