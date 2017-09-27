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
const int TileManager::TILE_TYPE_NUM = 27;
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
	m_palletTiles.resize(TILE_TYPE_NUM);

	// �^�C���̍쐬
	for (int i = 0; i < TILE_TYPE_NUM; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_X));
		m_palletTiles[i].initialize(i, pos);
	}

	m_grid.initialize(L"Resources/TileFlame.png");
	m_selectGrid.initialize(L"Resources/TileFlameRed.png");
	m_selectTile = 0;
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
	// �^�C���̕`��
	for (auto itr = m_palletTiles.begin(); itr != m_palletTiles.end(); itr++)
		(*itr).draw();

	// �O���b�h�̕`��
	Vector2 tilePos = m_palletTiles[0].getPos();
	for (int i = 0; i < PALLET_SIZE_X*PALLET_SIZE_Y; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_X));
		if (i == m_selectTile)
		{
			m_selectGrid.setPosition(pos);
			m_selectGrid.draw();
		}
		else
		{
			m_grid.setPosition(pos);
			m_grid.draw();
		}
	}
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

	for (int i = 0; i < (int)m_palletTiles.size(); i++)
	{
		Vector2 tilePos = m_palletTiles[i].getPos();

		if (tilePos.x + tileHalfSize >= posX &&
			tilePos.x - tileHalfSize <= posX &&
			tilePos.y + tileHalfSize >= posY &&
			tilePos.y - tileHalfSize <= posY)
		{
			m_selectTile = i;
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
Tile* TileManager::GetSelectTile()
{
	Tile* tile = new Tile();
	int num = m_palletTiles[m_selectTile].getNum();

	tile->initialize(num);

	return tile;
}
