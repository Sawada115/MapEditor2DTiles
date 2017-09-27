/// <summary>
/// �T�v�@ �^�C���ꖇ
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include <string>
#include "Tile.h"

// �N���X�萔
Tile::TileData Tile::m_datas[30] = {	{ true,L"None" },

										{ false,L"RoadA1" },
										{ false,L"RoadA2" },
										{ false,L"RoadA3" },

										{ true,L"RoadB1" },
										{ true,L"RoadB2" },
										{ true,L"RoadB3" },

										{ true,L"Tree1" },
										{ true,L"Tree2" },

										{ false,L"Grass1" },
										{ false,L"Grass2" },

										{ false,L"RoadA4" },
										{ false,L"RoadA5" },
										{ false,L"RoadA6" },

										{ true,L"RoadB4" },
										{ true,L"RoadB5" },
										{ true,L"RoadB6" },

										{ true,L"Tree3" },
										{ true,L"Tree4" },

										{ false,L"Grass3" },
										{ false,L"Grass4" },

										{ false,L"RoadA7" },
										{ false,L"RoadA8" },
										{ false,L"RoadA9" },

										{ true,L"RoadB7" },
										{ true,L"RoadB8" },
										{ true,L"RoadB9" },
};

// �^�C���T�C�Y
const float Tile::TILE_SIZE = 30.0f;


Tile::Tile()
{
}


Tile::~Tile()
{
}

/// <summary>
/// �R�s�[�R���X�g���N�^
/// </summary>
/// <param name="tile">�R�s�[��</param>
/// <returns>�V�����ł�������</returns>
Tile& Tile::operator=(const Tile& tile)
{
	Tile& tilee = Tile();
	tilee.m_isColision = tile.m_isColision;
	tilee.m_name = tile.m_name;


	std::wstring fileName = tilee.m_name;
	fileName = L"Resources/" + fileName;
	fileName += L".png";
	

	return Tile();
}

/// <summary>
/// ������
/// </summary>
/// <param name="imageType">�g�p����摜�̃^�C�v�̔ԍ�</param>
/// <param name="pos">�����ʒu</param>
void Tile::initialize(int imageType, DirectX::SimpleMath::Vector2 pos)
{
	m_num = imageType;


	// �摜�̃t�@�C���������
	std::wstring fileName = m_datas[imageType].fileNames;

	// ���O��ۑ�
	m_name = fileName;

	fileName = L"Resources/" + fileName;
	fileName += L".png";

	// �^�ϊ�
	const wchar_t* imgName = fileName.c_str();

	// ���N���X�̏�����
	Obj2d::initialize(imgName);

	// �����ݒ�
	m_isColision = m_datas[imageType].isColision;

	// �����ʒu�ݒ�
	m_screenPos = pos;
}

/// <summary>
/// m_isColision��ύX
/// </summary>
/// <returns>�ύX��̔���</returns>
bool Tile::changheColision()
{
	if (m_isColision) 
	{
		m_isColision = false;
	}
	else
	{
		m_isColision = true;
	}

	return m_isColision;
}
