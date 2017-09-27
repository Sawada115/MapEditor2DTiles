/// <summary>
/// �T�v�@ ����}�b�v
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"
#include <vector>
#include "Tile.h"

class MakedMap : public Obj2d
{
public:
	MakedMap();
	virtual ~MakedMap();

	// ������
	void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2(235.5f, 300.0f));
	// �`��
	void draw();

private:
	// �^�C������̃f�[�^
	struct OneTileData
	{
		Obj2d glids;	// �O���b�h���摜
		Tile tile;
	};

	int GLID_H;
	int GLID_V;
	std::vector<std::vector<OneTileData>> m_tiles;// �^�C������
};

