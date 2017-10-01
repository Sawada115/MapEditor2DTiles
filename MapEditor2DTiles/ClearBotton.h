//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.h
//!
//! @brief  �N���A�{�^���N���X
//!
//! @date   ���t�@2017/09/29
//!
//! @author ����Җ� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include <vector>
#include "Obj2d.h"

// �N���X�̐錾
class ClearBotton
{
	// �ÓI�ϐ��̐錾
private:
	static const int BUTTON_SIZE_X;		// �{�^���̉���
	static const int BUTTON_SIZE_Y;		// �{�^���̏c��

public:
	// �R���X�g���N�^
	ClearBotton();
	// �f�X�g���N�^
	~ClearBotton();

	// ����������
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);
	// �`�揈��
	void Draw();

	// �{�^������
	bool PressedButton(int posX, int posY);
	// �{�^���̏�Ԏ擾
	int Get_ClearFlag();

private:
	//�{�^��
	Obj2d m_ClearBotton_ON;
	Obj2d m_ClearBotton_OFF;

	//���߂��邩�ǂ���
	int m_ClearFlag;
};