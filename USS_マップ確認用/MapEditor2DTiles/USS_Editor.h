/// <summary>
/// �T�v�@ USS_Editor�ō�����X�e�[�W���g�p���邽�߂̃w�b�_
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include <vector>
#include "Tile.h"


// �}�b�v�g�p�p�N���X
class USS_Explorer
{
public:
	USS_Explorer();
	~USS_Explorer();

	struct TileData
	{
		int imageType;			// �摜�ԍ�
		bool isColision;		// �����蔻��
	};

	// ����������
	void Initialize(std::string fileName, int layerNum, DirectX::SimpleMath::Vector2 mapPos);

	// �}�b�v��CSV�f�[�^��ǂݍ���
	void InPutCsv(int layer, std::string fileName);

	// �}�b�v��`�悷��
	void Draw();

	// �^�C���Ƃ̓����蔻����Ƃ�
	bool GetTileColision(DirectX::SimpleMath::Vector2 pos);

	// �}�b�v���X�N���[������
	void MapScroll(DirectX::SimpleMath::Vector2 vec);

	void SetScrollPower(int layer ,float power) { m_scrollPower[layer] = power; };

private:
	std::vector<std::vector<TileBase>> m_map;	// �}�b�v
	DirectX::SimpleMath::Vector2 m_mapSize;		// �}�b�v�̑傫��
	std::vector<float> m_scrollPower;			// �X�N���[���{��
};



