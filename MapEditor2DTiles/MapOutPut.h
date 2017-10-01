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
#include "UI_Button.h"
#include "MakedMap.h"

// �N���X�̐錾
class MapOutPut:public UI_Button
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

	// �{�^���������ꂽ��Ăԏ���
	void toActivate();

	// �o�̓{�^������
	bool isPressed(int posX, int posY);

	// �^�C���f�[�^���o��
	void OutPutCsv(int layerNum ,std::vector<Tile*> tileData, DirectX::SimpleMath::Vector2 mapSize);

	struct TileData
	{
		int imageType;			// �摜�ԍ�
		bool isColision;		// �����蔻��
	};

	// �}�b�v�f�[�^�̓ǂݍ���
	std::vector<TileData> InPutCsv(std::string fileName);

private:
	Obj2d m_outPutButton;			// �o�̓{�^���摜
};

