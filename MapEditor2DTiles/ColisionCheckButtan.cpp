/// <summary>
/// �T�v�@ �^�C���̃R���W�����`�F�b�N�̃I���I�t��؂�ւ���{�^��
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include "ColisionCheckButtan.h"

// ���O��Ԃ̊J��
using namespace DirectX::SimpleMath;

// �ÓI�ϐ��̏�����
const int ColisionCheckButtan::BUTTON_SIZE_X = 150;
const int ColisionCheckButtan::BUTTON_SIZE_Y = 50;


ColisionCheckButtan::ColisionCheckButtan()
{
}


ColisionCheckButtan::~ColisionCheckButtan()
{
}

void ColisionCheckButtan::initialize(DirectX::SimpleMath::Vector2 pos)
{
	Obj2d::initialize(L"Resources/OutPutButton.png", pos);
	setColer(DirectX::Colors::Blue);
	//setScale(DirectX::XMFLOAT2(0.5f,0.5f));
}

bool ColisionCheckButtan::PressedButton(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);

	Vector2 buttonPos = this->getPos();

	if (buttonPos.x + buttonHalfSize.x >= posX &&
		buttonPos.x - buttonHalfSize.x <= posX &&
		buttonPos.y + buttonHalfSize.y >= posY &&
		buttonPos.y - buttonHalfSize.y <= posY)
	{
		return true;
	}
	return false;
}
