/// <summary>
/// �T�v�@ �^�C���̃R���W�����`�F�b�N�̃I���I�t��؂�ւ���{�^��
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"


class ColisionCheckButtan : public Obj2d
{
public:
	ColisionCheckButtan();
	virtual ~ColisionCheckButtan();

	// ������
	virtual void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// �{�^�����������
	bool ColisionCheckButtan::PressedButton(int posX, int posY);
private:
	static const int BUTTON_SIZE_X;		// �{�^���̉���
	static const int BUTTON_SIZE_Y;		// �{�^���̏c��

};

