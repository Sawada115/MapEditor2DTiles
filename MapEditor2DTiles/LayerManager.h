//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.h
//!
//! @brief  ���C���[�}�l�[�W���[�N���X
//!
//! @date   ���t�@2017/09/28
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include <vector>
#include "Obj2d.h"

// �N���X�̐錾
class LayerManager
{
	// �ÓI�ϐ��̐錾
private:
	static const int BUTTON_SIZE_X;		// �{�^���̉���
	static const int BUTTON_SIZE_Y;		// �{�^���̏c��
	static const int LAYER_MAX_NUM;			// ���C���[�̐�
public:
	// �R���X�g���N�^
	LayerManager();
	// �f�X�g���N�^
	~LayerManager();

	// ����������
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);
	// �`�揈��
	void Draw();

	// �{�^������
	bool PressedButton(int posX, int posY);
	int GetSelectLayer() { return m_selectLayer; }

	void LayerDelete();
private:
	std::vector<Obj2d> m_layerButton;			// ���C���[�{�^���摜
	int m_layerNum;								// ���C���[�̐�
	int m_selectLayer;							// �I�𒆂̃��C���[�ԍ�
};
