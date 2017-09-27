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
	// �^�C�������f���[�g
	std::vector<std::vector<OneTileData>>::iterator it1;
	for (it1 = m_tiles.begin(); it1 != m_tiles.end(); it1++)
	{
		std::vector<OneTileData> ::iterator it2;
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			delete (*it2).tile;
		}
	}

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
	m_mapNum[0] = 19;
	m_mapNum[1] = 14;

	// �}�b�v���̏�����
	m_tiles.resize(m_mapNum[1]);	// �c�̒�����ݒ�
	for (int i = 0; i < m_mapNum[1]; i++)
	{
		m_tiles[i].resize(m_mapNum[0]);// ���̒����̐ݒ�

		for (int j = 0; j < m_mapNum[0]; j++)
		{
			// �ʒu��ݒ�
			Vector2 glidPos = Vector2( (i*Tile::TILE_SIZE) - 195.0f,  (j*Tile::TILE_SIZE) - 270.0f) + m_screenPos;

			// �O���b�h�ƃ^�C���摜��
			m_tiles[i][j].glids.initialize(L"Resources/TileFlame.png", glidPos);
			m_tiles[i][j].tile = new Tile();
			m_tiles[i][j].tile->initialize(0,glidPos);
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

	std::vector<std::vector<OneTileData>>::iterator it1;
	for (it1 = m_tiles.begin(); it1 != m_tiles.end(); it1++)
	{
		std::vector<OneTileData> ::iterator it2;
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			// �^�C���摜
			(*it2).tile->draw();
			// �O���b�h
			(*it2).glids.draw();

		}
	}

}

/// <summary>
/// �N���b�N���ꂽ�Ƃ�
/// </summary>
/// <param name="newTile">�^�C���̏��</param>
/// <param name="pos">�N���b�N���W</param>
void MakedMap::beClicked(Tile* newTile, DirectX::SimpleMath::Vector2 clickPos)
{
	// ��ԍ���̍��W
	DirectX::SimpleMath::Vector2 beginPos = m_screenPos - Vector2(210.0f, 285.0f);

	// �N���b�N���ꂽ�^�C���̈ʒu(V,H)
	int clickedTileID[2];

	// �N���b�N���ꂽ�ʒu��T��(��)
	int i = m_tiles.size();
	while (beginPos.x < clickPos.x && beginPos.x + i*Tile::TILE_SIZE > clickPos.x)
	{

		i--;
	}
	if (i >= m_tiles.size() || i < 0)
	{
		return;
	}
	clickedTileID[0] = i;

	// �N���b�N���ꂽ�ʒu��T��(�c)
	i = m_tiles[0].size();
	while (beginPos.y < clickPos.y && beginPos.y + i*Tile::TILE_SIZE > clickPos.y)
	{
		i--;
	}
	if (i >= m_tiles[0].size() || i < 0)
	{
		return;
	}
	clickedTileID[1] = i;

	// �I�������^�C����ύX����
	changTile(clickedTileID, newTile);
}

/// <summary>
/// �}�b�v�̃T�C�Y��ύX����
/// </summary>
/// <param name="sizeX">�����̑傫��</param>
/// <param name="sizeY">�c���̑傫��</param>
void MakedMap::setMapSize(int sizeX, int sizeY)
{
	m_mapNum[0] = sizeX; m_mapNum[1] = sizeY;

	// �}�b�v���̏�����
	m_tiles.resize(sizeX);	// �c�̒�����ݒ�
	for (int i = 0; i < sizeX; i++)
	{
		m_tiles[i].resize(sizeY);// ���̒����̐ݒ�
	}
}


/// <summary>
/// �I�������^�C����ύX����
/// </summary>
/// <param name="changeTileID">�ύX����^�C���̔ԍ�</param>
/// <param name="newTile">�V�����^�C��</param>
void MakedMap::changTile(int changeTileID[2], Tile* newTile)
{
	newTile->setPosition(m_tiles[changeTileID[0]][changeTileID[1]].tile->getPos());

	// �V�����^�C�����Z�b�g
	m_tiles[changeTileID[0]][changeTileID[1]].tile = newTile;
}
