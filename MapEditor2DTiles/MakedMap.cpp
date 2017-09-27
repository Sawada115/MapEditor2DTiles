/// <summary>
/// �T�v�@ ����}�b�v
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include "MakedMap.h"

using namespace DirectX::SimpleMath;

MakedMap::MakedMap()
{
}


MakedMap::~MakedMap()
{
}

/// <summary>
/// ������
/// </summary>
/// <param name="pos">�����ʒu</param>
void MakedMap::initialize(Vector2 pos)
{
	// �w�i�摜�̏�����
	Obj2d::initialize(L"Resources/BackImage1.png", pos);

	// �}�b�v�T�C�Y�̏�����
	GLID_V = 14;
	GLID_H = 19;

	// �}�b�v���̏�����
	m_tiles.resize(GLID_V);	// �c�̒�����ݒ�
	for (int i = 0; i < GLID_V; i++)
	{
		m_tiles[i].resize(GLID_H);// ���̒����̐ݒ�

		for (int j = 0; j < GLID_H; j++)
		{
			// �ʒu��ݒ�
			Vector2 glidPos = Vector2( (i*Tile::TILE_SIZE) - 195.0f,  (j*Tile::TILE_SIZE) - 270.0f) + m_screenPos;

			// �O���b�h�ƃ^�C���摜��
			m_tiles[i][j].glids.initialize(L"Resources/TileFlame.png", glidPos);
			m_tiles[i][j].tile.initialize(0, 0,glidPos);
		}
	}

	// �����I�����Ă��Ȃ����
	m_choiceTile[0] = 999;
	m_choiceTile[1] = 999;

}

/// <summary>
/// �`��
/// </summary>
void MakedMap::draw()
{
	// �w�i�摜
	Obj2d::draw();

	for (int i = 0; i < GLID_V; i++)
	{
		for (int j = 0; j < GLID_H; j++)
		{
			// �^�C���摜
			m_tiles[i][j].tile.draw();
			// �O���b�h
			m_tiles[i][j].glids.draw();
		}
	}
}

/// <summary>
/// �N���b�N���ꂽ�Ƃ�
/// </summary>
/// <param name="newTile">�^�C���̏��</param>
/// <param name="pos">�N���b�N���W</param>
void MakedMap::beClicked(Tile* newTile, DirectX::SimpleMath::Vector2 pos)
{
	// ��ԍ����
	DirectX::SimpleMath::Vector2 beginPos;

}
