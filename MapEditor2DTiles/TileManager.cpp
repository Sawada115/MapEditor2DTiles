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
#include "TileManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

// �ÓI�ϐ��̏�����
const int TileManager::TILE_TYPE_NUM = 5;
const int TileManager::TILE_SIZE = 30;
const int TileManager::PALLET_SIZE_X = 10;
const int TileManager::PALLET_SIZE_Y = 8;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
TileManager::TileManager()
{
}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] ���݂��Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
TileManager::~TileManager()
{
}



//----------------------------------------------------------------------
//! @brief ����������
//!
//! @param[in] 1�Ԗڂ̃^�C�����W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TileManager::Initialize(Vector2 tilePos)
{
	// �^�C���̎�ނƃ^�C����
	int tileID[TILE_TYPE_NUM] =
	{
		1,4,9,9,4
	};

	// �^�C���̍��v�������߂�
	int tileNum = 0;
	for (int i = 0; i < TILE_TYPE_NUM; i++)
		tileNum += tileID[i];

	m_palletTiles.resize(tileNum);

	// �^�C���̍쐬
	int count = 0;
	for (int i = 0; i < TILE_TYPE_NUM; i++)
	{
		for (int j = 0; j < tileID[i]; j++)
		{
			Vector2 pos(tilePos.x + TILE_SIZE * (count % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(count / PALLET_SIZE_Y));
			if (tileID[i] == 1)
				m_palletTiles[count].initialize(1, 1, pos);
			else
				m_palletTiles[count].initialize(i, j + 1, pos);
			count++;
		}
	}
	
	// �����W�ݒ�
	for (int i = 0; i < count; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_Y));
		m_palletTiles[i].setPosition(pos);
	}
}



//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TileManager::Draw()
{
	for (auto itr = m_palletTiles.begin(); itr != m_palletTiles.end(); itr++)
		(*itr).draw();
}



//----------------------------------------------------------------------
//! @brief �J�[�\���ʒu�̃^�C����I������
//!
//! @param[in] ���WX ���WY
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TileManager::TileSelect(int posX, int posY)
{
	int tileHalfSize = TILE_SIZE / 2;

	for (auto itr = m_palletTiles.begin(); itr != m_palletTiles.end(); itr++)
	{
		Vector2 tilePos = (*itr).getPos();

		if (tilePos.x + tileHalfSize >= posX &&
			tilePos.x - tileHalfSize <= posX &&
			tilePos.y + tileHalfSize >= posY &&
			tilePos.y - tileHalfSize <= posY)
		{
			m_selectTile = 0;
		}
	}
}



//----------------------------------------------------------------------
//! @brief �I�𒆂̃^�C�����擾
//!
//! @param[in] 
//!
//! @return 
//----------------------------------------------------------------------
Tile TileManager::GetSelectTile()
{
	return Tile();
}
