/// <summary>
/// �T�v�@ ����}�b�v
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include "MakedMap.h"

using namespace DirectX::SimpleMath;

// �`�悷��^�C���̐�
const int MakedMap::DRAW_TILE_NUM_X = 14;
const int MakedMap::DRAW_TILE_NUM_Y = 17;


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
	m_mapNum[0] = DRAW_TILE_NUM_X;
	m_mapNum[1] = DRAW_TILE_NUM_Y;

	// �`��̍���̃^�C��
	m_drawBeginTile[0] = 0;
	m_drawBeginTile[1] = 0;

	// �}�b�v���̏�����
	m_tiles.resize(m_mapNum[1]);	// �c�̒�����ݒ�
	for (int i = 0; i < m_mapNum[1]; i++)
	{
		m_tiles[i].resize(m_mapNum[0]);// ���̒����̐ݒ�

		for (int j = 0; j < m_mapNum[0]; j++)
		{
			// �ʒu��ݒ�
			Vector2 glidPos = Vector2( (j*Tile::TILE_SIZE) - 195.0f,  (i*Tile::TILE_SIZE) - 270.0f) + m_screenPos;

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

	//std::vector<std::vector<OneTileData>>::iterator it1;
	//for (it1 = m_tiles.begin() + m_drawBeginTile[0]; it1 != m_tiles.end() + DRAW_TILE_NUM_X; it1++)
	//{
	//	std::vector<OneTileData> ::iterator it2;
	//	for (it2 = (*it1).begin() + m_drawBeginTile[0]; it2 != (*it1).end() + DRAW_TILE_NUM_Y; it2++)
	//	{
	//		// �^�C���摜
	//		(*it2).tile->draw();
	//		// �O���b�h
	//		(*it2).glids.draw();
	//	}
	//}

	// �c���[�v
	for (int i = m_drawBeginTile[1]; i < m_drawBeginTile[0] + DRAW_TILE_NUM_Y; i++)
	{
		// �T�C�Y���������ꍇ�͓r���Ń��[�v�𔲂���
		if (i >= m_tiles.size())break;

		// �����[�v
		for (int j = m_drawBeginTile[0]; j < m_drawBeginTile[1] + DRAW_TILE_NUM_X; j++)
		{
			// �T�C�Y���������ꍇ�͓r���Ń��[�v�𔲂���
			if (j >= m_tiles[i].size())break;

			// �`�悷��
			m_tiles[i][j].tile->draw();
			m_tiles[i][j].glids.draw();
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
	int i = m_tiles[0].size();
	while (beginPos.x < clickPos.x && beginPos.x + i*Tile::TILE_SIZE > clickPos.x)
	{
		i--;
	}
	// �}�b�v�O�Ȃ炷���I���A
	if (i >= m_tiles[0].size() || i < 0)
	{
		return;
	}
	clickedTileID[0] = i;

	// �N���b�N���ꂽ�ʒu��T��(�c)
	i = m_tiles.size();
	while (beginPos.y < clickPos.y && beginPos.y + i*Tile::TILE_SIZE > clickPos.y)
	{
		i--;
	}
	if (i >= m_tiles.size() || i < 0)
	{
		return;
	}
	clickedTileID[1] = i;

	// �I�������^�C����ύX����
	changTile(clickedTileID, newTile);
}


/// <summary>
/// /// <summary>
/// �^�C���f�[�^�̎擾
/// </summary>
/// <returns>�S�^�C���f�[�^</returns>
std::vector<Tile*> MakedMap::GetAllTileData()
{
	std::vector<Tile*> tileData;

	// �}�b�v�T�C�Y�̎擾
	Vector2 size((int)m_tiles[0].size(), (int)m_tiles.size());
	int dataNum = size.x * size.y;

	// �^�C���f�[�^�����o��
	tileData.resize(dataNum);
	for (int i = 0; i < dataNum; i++)
		tileData[i] = m_tiles[i % (int)size.y][i / (int)size.y].tile;

	return tileData;
}

/// <summary>
/// �}�b�v�T�C�Y�̎擾
/// </summary>
/// <returns>�}�b�v�T�C�Y</returns>
DirectX::SimpleMath::Vector2 MakedMap::GetMapSize()
{
	// �}�b�v�T�C�Y�̎擾
	Vector2 size((int)m_tiles[0].size(), (int)m_tiles.size());
	return size;
}

/// <summary>
/// �I�������^�C����ύX����
/// </summary>
/// <param name="changeTileID">�ύX����^�C���̔ԍ�</param>
/// <param name="newTile">�V�����^�C��</param>
void MakedMap::changTile(int changeTileID[2], Tile* newTile)
{
	newTile->setPosition(m_tiles[changeTileID[1]][changeTileID[0]].tile->getPos());

	// �V�����^�C�����Z�b�g
	m_tiles[changeTileID[1]][changeTileID[0]].tile = newTile;
}

void MakedMap::TileScroll(int scrollValue)
{
	int tileHalfSize = Tile::TILE_SIZE / 2;
	int move = scrollValue / 120;

	// �X�N���[���\
	if (m_drawBeginTile[1] + -move >= 0 && m_drawBeginTile[1] + -move < DRAW_TILE_NUM_Y)
	{
		m_drawBeginTile[1] += -move;

		// ���̍X�V
		std::vector<std::vector<OneTileData>>::iterator it1;
		for (it1 = m_tiles.begin(); it1 != m_tiles.end(); it1++)
		{
			std::vector<OneTileData> ::iterator it2;
			for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
			{
				// �^�C�������炷
				Vector2 pos = (*it2).tile->getPos();
				(*it2).tile->setPosition(Vector2(pos.x, pos.y + Tile::TILE_SIZE * move));
				(*it2).glids.setPosition(Vector2(pos.x, pos.y + Tile::TILE_SIZE * move));

			}
		}
	}
}

/// <summary>
/// �}�b�v�̃��Z�b�g
/// </summary>
void MakedMap::mapReset()
{
	std::vector<std::vector<OneTileData>>::iterator it1;
	for (it1 = m_tiles.begin(); it1 != m_tiles.end() + DRAW_TILE_NUM_X; it1++)
	{
		std::vector<OneTileData> ::iterator it2;
		for (it2 = (*it1).begin(); it2 != (*it1).end() + DRAW_TILE_NUM_Y; it2++)
		{
			Vector2 pos = (*it2).tile->getPos();

			(*it2).tile->initialize(0, pos);
		}
	}
}

/// <summary>
/// �}�b�v�T�C�Y��ύX����
/// </summary>
/// <param name="sizeX">�ύX��̃T�C�Y(��)</param>
/// <param name="sizeY">�ύX��̃T�C�Y(�c)</param>
void MakedMap::mapReSize(int sizeX, int sizeY)
{
	// �c�T�C�Y���������Ȃ�ꍇ
	if (m_mapNum[1] > sizeY)
	{
		// ����ȏ㏬�����Ȃ�Ȃ��ꍇ�͂����I���
		if (m_mapNum[1] <= 1)return;

		for (m_mapNum[1]; m_mapNum[1] > sizeY; m_mapNum[1]--)
		{
			mapReSizeOneLine(m_mapNum[1]-1, 0);
			m_tiles.pop_back();
		}
	}

	// ���ׂẴp�^�[���̋��ʏ���
	{// ���Ƃ��Ƃ�������̒�����ύX
		for (int i = 0; i < m_mapNum[1]; i++)
		{
			mapReSizeOneLine(i, sizeX);
		}
		m_mapNum[0] = sizeX;
	}

	// �c�T�C�Y���傫���Ȃ�ꍇ
	if (m_mapNum[1] < sizeY)
	{
		mapReSizeSomeLine(sizeY);
	}

	m_mapNum[0] = sizeX; m_mapNum[1] = sizeY;
}

/// <summary>
/// �}�b�v�̃T�C�Y�ύX(�P��)
/// </summary>
/// <param name="changeLine">�T�C�Y�ύX�����ԍ�</param>
/// <param name="size">�ύX��̃T�C�Y</param>
void MakedMap::mapReSizeOneLine(int changeLine, int size)
{
	// �������Ȃ�Ȃ炷���I���
	if (m_mapNum[0] == size)return;

	// �������Ȃ�ꍇ
	if (m_mapNum[0] > size)
	{
		// ����ȏ㏬�����Ȃ�Ȃ��ꍇ�͂����I���
		if (m_mapNum[0] <= 1)return;

		for (int i = m_mapNum[0]; i > size; i--)
		{
			// �Ō�����폜
			delete m_tiles[changeLine][i-1].tile;
			m_tiles[changeLine].pop_back();
		}
	}

	// �傫���Ȃ�ꍇ
	else
	{
		for (int i = m_mapNum[0]; i < size; i++)
		{
			// �ʒu��ݒ�
			Vector2 glidPos =
				Vector2((i*Tile::TILE_SIZE) - 195.0f, ((changeLine - m_drawBeginTile[1]) * Tile::TILE_SIZE) - 270.0f) + m_screenPos;
			
			// ���₷
			m_tiles[changeLine].push_back(createTileData(glidPos));
		}
	}
}

/// <summary>
/// �}�b�v���P�ʂŃT�C�Y�ύX
/// </summary>
/// <param name="size">�ύX��̃T�C�Y</param>
void MakedMap::mapReSizeSomeLine(int size)
{
	// �ς��Ȃ��ꍇ�͂����I���
	if (m_mapNum[1] == size)return;

	// �������Ȃ�ꍇ
	if (m_mapNum[1] > size)
	{

	}

	// �傫���Ȃ�ꍇ
	if (m_mapNum[1] < size)
	{
		// �ǉ������
		std::vector<OneTileData> newTileLine;

		for ( m_mapNum[1]; m_mapNum[1] < size; m_mapNum[1]++)
		{// ��񑝂₷
			for (int i = 0; i < m_mapNum[0]; i++)
			{
				// �ʒu��ݒ�
				Vector2 glidPos =
					Vector2((i*Tile::TILE_SIZE) - 195.0f, ((m_mapNum[1] - m_drawBeginTile[1]) * Tile::TILE_SIZE) - 270.0f) + m_screenPos;

				// ���₷
				newTileLine.push_back(createTileData(glidPos));
			}
		}

		// �ł������ǉ�
		m_tiles.push_back(newTileLine);
	}
}


/// <summary>
/// �^�C������̃f�[�^�����
/// </summary>
/// <param name="pos">�����ʒu</param>
/// <returns>������^�C��</returns>
MakedMap::OneTileData MakedMap::createTileData(DirectX::SimpleMath::Vector2 pos)
{
	// ���₷�f�[�^
	OneTileData oneTile;

	// �O���b�h
	oneTile.glids.initialize(L"Resources/TileFlame.png", pos);

	// �^�C��
	Tile* tile = new Tile;
	tile->initialize(0, pos);
	oneTile.tile = tile;

	return oneTile;
}
