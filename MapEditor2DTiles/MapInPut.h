//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapInPut.h
//!
//! @brief  �}�b�v�ǂݍ��݃N���X
//!
//! @date   ���t�@2017/10/01
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include <Windows.h>
#include <Commdlg.h>
#include "UI_Buttan.h"
#include "MakedMap.h"

// �N���X�̐錾
class MapInPut :public UI_Buttan
{
	// �ÓI�ϐ��̐錾
private:
	static const int BUTTON_SIZE_X;		// �{�^���̉���
	static const int BUTTON_SIZE_Y;		// �{�^���̏c��
public:
	// �R���X�g���N�^
	MapInPut();
	// �f�X�g���N�^
	~MapInPut();

	// ����������
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);

	// �{�^���������ꂽ��Ăԏ���
	void toActivate();

	// �o�̓{�^������
	bool isPressed(int posX, int posY);

	// �J���t�@�C����ݒ�
	bool SetOpenFilePath();

	struct TileData
	{
		int imageType;			// �摜�ԍ�
		bool isColision;		// �����蔻��
	};

	// �}�b�v�f�[�^�̓ǂݍ���
	void InPutCsv(MakedMap* map);

private:
	Obj2d m_outPutButton;			// �o�̓{�^���摜

	OPENFILENAME     m_ofn;						// �_�C�A���O�p�\����
	TCHAR            m_folderPath[MAX_PATH];	// �����t�H���_�ʒu
	TCHAR            m_filePath[MAX_PATH];		// �I�������t�@�C���ʒu
	TCHAR            m_fileName[MAX_PATH];		// �t�@�C����
};


