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

	// ������
	void initialize(int imageType,int imageID ,DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// �Q�b�g�E�Z�b�g
	bool getColision() { return m_isColision; };						// �����邩
	bool setColision(bool newColision) { m_isColision = newColision; }; //		�ǂ���


	// m_isColision��ύX
	bool changheColision();

private:

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
	// ��������Ƃ邩�ǂ���
	bool m_isColision;

};

