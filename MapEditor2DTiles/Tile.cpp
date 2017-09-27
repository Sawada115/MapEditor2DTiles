/// <summary>
/// �T�v�@ �^�C���ꖇ
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include <string>
#include "Tile.h"

// �N���X�萔
Tile::TileData Tile::m_datas[5] = {	{ true,L"None" },
									{ false,L"Grass" },
									{ false,L"RoadA" },
									{ true,L"RoadB" },
									{ true,L"Tree" }};

// �^�C���T�C�Y
const float Tile::TILE_SIZE = 30.0f;


Tile::Tile()
{
}


Tile::~Tile()
{
}

/// <summary>
/// ������
/// </summary>
/// <param name="imageType">�g�p����摜�̃^�C�v�̔ԍ�(Grass��)</param>
/// <param name="imageID">�g�p����摜�^�C�v��ID</param>
/// <param name="pos">�����ʒu</param>
void Tile::initialize(int imageType, int imageID, DirectX::SimpleMath::Vector2 pos)
{
	// �摜�̃t�@�C���������
	std::wstring fileName = m_datas[imageType].fileNames;

	// NONE�̏ꍇ��imageID�����Ȃ�
	if (imageID != 0)
	{
		fileName += std::to_wstring(imageID);
	}

	// ���O��ۑ�
	m_name = fileName.c_str();

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
