/// <summary>
/// �T�v�@ ����}�b�v
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"
#include <vector>
#include <SimpleMath.h>
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

	// �N���b�N���ꂽ�Ƃ�
	void beClicked(Tile* newTile, DirectX::SimpleMath::Vector2 clickPos);

	// �}�b�v�̃T�C�Y��ύX����
	//void setMapSize(int size[2]) {};

private:
	// �I�������^�C����ύX����
	void changTile(int changeTileID[2],Tile* newTile);

	// �^�C������̃f�[�^
	struct OneTileData
	{
		Obj2d glids;	// �O���b�h���摜
		Tile* tile;		// �^�C���摜
	};


	int m_mapNum;	// �O���b�h��
	int GLID_V; //		�T�C�Y
	std::vector<std::vector<OneTileData>> m_tiles;// �^�C������

	// ���ݑI�𒆂̃^�C��
	int m_choiceTile[2];
};

