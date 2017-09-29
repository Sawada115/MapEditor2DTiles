//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.cpp
//!
//! @brief  �N���A�{�^���N���X
//!
//! @date   ���t�@2017/09/29
//!
//! @author ����Җ� ����
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�[�t�@�C���̃C���N���[�h==============================================
#include "pch.h"
#include "ClearBotton.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// �ÓI�ϐ��̏�����
const int ClearBotton::BUTTON_SIZE_X = 75;
const int ClearBotton::BUTTON_SIZE_Y = 25;


//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
ClearBotton::ClearBotton()
{
}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//!
//! @param[in] ���݂��Ȃ�
//!
//! @return ���݂��Ȃ�
//----------------------------------------------------------------------
ClearBotton::~ClearBotton()
{
}



//----------------------------------------------------------------------
//! @brief ����������
//!
//! @param[in] �{�^�����W
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void ClearBotton::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{

	m_ClearBotton_ON.initialize(L"Resources/LayerClearButtanON.png", buttonPos);
	m_ClearBotton_OFF.initialize(L"Resources/LayerClearButtanOFF.png", buttonPos);

	m_ClearFlag = 1;
}



//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void ClearBotton::Draw()
{

	if (m_ClearFlag)
	{
		m_ClearBotton_ON.draw();
	}
	else
	{
		m_ClearBotton_OFF.draw();
	}
}



//----------------------------------------------------------------------
//! @brief �{�^������
//!
//! @param[in] ���WX ���WY
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
bool ClearBotton::PressedButton(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);
	Vector2 buttonPos = m_ClearBotton_ON.getPos();

	if (buttonPos.x + buttonHalfSize.x >= posX &&
		buttonPos.x - buttonHalfSize.x <= posX &&
		buttonPos.y + buttonHalfSize.y >= posY &&
		buttonPos.y - buttonHalfSize.y <= posY)
	{
		if (m_ClearFlag)
		{
			m_ClearFlag = 0;
		}
		else
		{
			m_ClearFlag = 1;
		}
		return true;
	}
	return false;
}

int ClearBotton::Get_ClearFlag()
{
	return m_ClearFlag;
}