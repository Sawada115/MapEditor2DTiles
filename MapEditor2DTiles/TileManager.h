//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   TileManager.h
//!
//! @brief  �^�C���}�l�[�W���[�N���X
//!
//! @date   ���t�@2017/09/27
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include "Tile.h"
#include <vector>


// �N���X�̐錾
class TileManager
{
	// �ÓI�ϐ��̐錾
private:
	static const int TILE_TYPE_NUM;		// �^�C���̎�ސ�
	static const int TILE_SIZE;			// �^�C���̃T�C�Y
	static const int PALLET_SIZE_X;		// �p���b�g�̉���
	static const int PALLET_SIZE_Y;		// �p���b�g�̏c��

public:
	// �R���X�g���N�^
	TileManager();
	// �f�X�g���N�^
	~TileManager();

	// ����������
	void Initialize(DirectX::SimpleMath::Vector2 tile1Pos);
	// �`�揈��
	void Draw();

	// �J�[�\���ʒu�̃^�C����I��
	void TileSelect(int posX, int posY);
	// �I�𒆂̃^�C�����擾
	Tile* GetSelectTile();
private:
	std::vector<Tile> m_palletTiles;			// �p���b�g��̃^�C��
	Obj2d m_grid;								// �O���b�h�摜
	Obj2d m_selectGrid;							// �I�𒆃p�l���̃O���b�h�摜
	int m_selectTile;							// �I�𒆂̃^�C��
};

