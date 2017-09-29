/// <summary>
/// �T�v�@ �^�C���ꖇ
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"

// ----- �^�C���̃x�[�X --------------------------------------------------------------------------------
class TileBase : public Obj2d
{
public:
	TileBase();
	virtual ~TileBase();

	// ������
	void initialize(int imageType, DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// �Q�b�g�E�Z�b�g
	bool getColision() { return m_isColision; };						// �����邩
	void setColision(bool isColision) { m_isColision = isColision; };	//		�ǂ���
	int getNum() { return m_num; };						// �摜ID
	void setNum(int num) { m_num = num; };

	// m_isColision��ύX
	bool changheColision();

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
	static TileData m_datas[180];


protected:
	// ��������Ƃ邩�ǂ���
	bool m_isColision;

	int m_num;

};



// ----- �G�f�B�^�[�Ŏg���^�C�� -------------------------------------------------------------------------
class Tile:public TileBase
{
public:
	Tile();
	virtual ~Tile();

	// ������
	void initialize(int imageType ,DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// �`��
	void draw();

	// �Q�b�g�E�Z�b�g
	std::wstring getName() { return m_name; };					// ��
	void setName(std::wstring newName) { m_name = newName; };	// �O

	// �R���W�����`�F�b�N�t���O���Z�b�g����
	static void setClisionCheck(bool check) { m_isCheckedColision = check; };
	static void changheClisionCheck();


private:

	// ���O
	std::wstring m_name;

	// �R���W�����������Ă��邩�������ڂŊm�F���邩
	static bool m_isCheckedColision;
};

