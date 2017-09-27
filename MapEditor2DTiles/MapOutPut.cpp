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

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
MapOutPut::MapOutPut()
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
//! @brief �^�C���f�[�^���o��
//!
//! @param[in] �o�̓f�[�^ �}�b�v�̉���
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void MapOutPut::OutPutCsv(std::vector<Tile*> tileData,int mapSizeX)
{
	// �t�@�C�����J��
	ofstream ofs("MapData.csv");
	
	if (ofs)
	{
		int count = 0;
		for (auto itr = tileData.begin(); itr != tileData.end(); itr++)
		{
			count++;
			// �f�[�^���܂Ƃ߂�
			int data = ((*itr)->getNum() + 1) * 10 + (int)(*itr)->getColision();
			// �f�[�^�̏����o��
			ofs << data << ",";
			// ���s����
			if (count >= mapSizeX)
			{
				count = 0;
				ofs << endl;
			}
		}
	}
	return;
}
