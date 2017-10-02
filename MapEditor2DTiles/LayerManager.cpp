//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.cpp
//!
//! @brief  ���C���[�}�l�[�W���[�N���X
//!
//! @date   ���t�@2017/09/28
//!
//! @author ����Җ� �V�c
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include "pch.h"
#include "LayerManager.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// �ÓI�ϐ��̏�����
const int LayerManager::BUTTON_SIZE_X = 75;
const int LayerManager::BUTTON_SIZE_Y = 25;
const int LayerManager::LAYER_MAX_NUM = 5;


//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
LayerManager::LayerManager()
{
}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] ���݂��Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
LayerManager::~LayerManager()
{
}



//----------------------------------------------------------------------
//! @brief ����������
//!
//! @param[in] �{�^�����W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void LayerManager::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{
	m_layerNum = 1;
	m_layerButton.resize(LAYER_MAX_NUM);

	for (int i = 0; i < (int)m_layerButton.size(); i++)
		m_layerButton[i].initialize(L"Resources/LayerButton.png", buttonPos + Vector2(BUTTON_SIZE_X * i, 0));

	m_selectLayer = 0;
}



//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void LayerManager::Draw()
{
	int i;
	// ���C���[�؂�ւ��{�^���̕`��
	for (i = 0; i < m_layerNum; i++)
	{ 
		if (i == m_selectLayer)
			m_layerButton[i].setColer(Colors::White);
		else
			m_layerButton[i].setColer(Colors::Gray);
		m_layerButton[i].draw();
	}
	// ���C���[�ǉ��{�^���̕`��
	if (i < LAYER_MAX_NUM)
	{
		m_layerButton[i].setColer(Colors::Gray);
		m_layerButton[i].draw();
	}
}



//----------------------------------------------------------------------
//! @brief �{�^������
//!
//! @param[in] ���WX ���WY
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
bool LayerManager::PressedButton(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);

	for (int i = 0; i < (int)m_layerButton.size(); i++)
	{
		Vector2 buttonPos = m_layerButton[i].getPos();

		if (buttonPos.x + buttonHalfSize.x >= posX &&
			buttonPos.x - buttonHalfSize.x <= posX &&
			buttonPos.y + buttonHalfSize.y >= posY &&
			buttonPos.y - buttonHalfSize.y <= posY)
		{
			if (m_layerNum >= i)
			{
				m_selectLayer = i;
			}
			if (m_layerNum == i && m_layerNum < LAYER_MAX_NUM)
			{
				m_layerNum++;
				return true;
			}
			return false;
		}
	}
	return false;
}



//----------------------------------------------------------------------
//! @brief ���C���[�̍폜
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void LayerManager::LayerDelete()
{
	if (m_selectLayer)
		m_selectLayer--;

	m_layerNum--;
}
