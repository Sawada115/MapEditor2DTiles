//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapOutPut.h
//!
//! @brief  �}�b�v�o�̓N���X
//!
//! @date   ���t�@2017/09/27
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include "MakedMap.h"

// �N���X�̐錾
class MapOutPut
{
	// �ÓI�ϐ��̐錾
private:
	static const int BUTTON_SIZE_X;		// �{�^���̉���
	static const int BUTTON_SIZE_Y;		// �{�^���̏c��
public:
	// �R���X�g���N�^
	MapOutPut();
	// �f�X�g���N�^
	~MapOutPut();

	// ����������
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);
	// �`�揈��
	void Draw();

	// �^�C���f�[�^���o��
	void OutPutCsv(int layerNum ,std::vector<Tile*> tileData, DirectX::SimpleMath::Vector2 mapSize);

	struct TileData
	{
		int imageType;			// �摜�ԍ�
		bool isColision;		// �����蔻��
	};

	// �}�b�v�f�[�^�̓ǂݍ���
	std::vector<TileData> InPutCsv(std::string fileName);

	// �o�̓{�^������
	bool PressedButton(int posX, int posY);
private:
	Obj2d m_outPutButton;			// �o�̓{�^���摜
};

