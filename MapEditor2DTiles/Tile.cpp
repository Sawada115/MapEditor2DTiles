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
	std::wstring fileName = L"Resources/" + m_datas[imageType].fileNames+ std::to_wstring(imageID);

	// NONE�̏ꍇ��imageID�����Ȃ�
	if (imageID == 0)
	{
		fileName += std::to_wstring(imageID);
	}
	fileName += L".png";
	const wchar_t* imgName = fileName.c_str();

	// ���N���X�̏�����
	Obj2d::initialize(imgName);

	// �����ݒ�
	m_isColision = m_datas[imageType].isColision;
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
