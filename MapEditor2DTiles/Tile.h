/// <summary>
/// �T�v�@ �^�C���ꖇ
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"

class Tile:public Obj2d
{
public:
	Tile();
	virtual ~Tile();
	//Tile operator=(const Tile& tile);// �R�s�[�R���X�g���N�^

	// ������
	void initialize(int imageType,int imageID ,DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// �Q�b�g�E�Z�b�g
	bool getColision() { return m_isColision; };						// �����邩
	void setColision(bool isColision) { m_isColision = isColision; };	//		�ǂ���
	std::wstring getName() { return m_name; };					// ��
	void setName(std::wstring newName) { m_name = newName; };	// �O


	// m_isColision��ύX
	bool changheColision();

	// �^�C���T�C�Y(�c������)
	const static float TILE_SIZE;

	// �^�C���ɕK�v�ȃf�[�^
	struct TileData
	{
		// ��������Ƃ邩�ǂ���
		bool isColision;

		// �g�p����摜�̃t�@�C����
		const std::wstring fileNames;
	};


	// ID���ƂɕK�v�ȃf�[�^
	static TileData m_datas[5];

private:

	// ���O
	std::wstring m_name;
	// ��������Ƃ邩�ǂ���
	bool m_isColision;
};

