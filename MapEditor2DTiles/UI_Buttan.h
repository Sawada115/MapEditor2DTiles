/// <summary>
/// �T�v�@ �{�^����
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"

class UI_ButtanBase : public Obj2d
{
public:
	UI_ButtanBase(DirectX::SimpleMath::Vector2 size);
	virtual ~UI_ButtanBase();

	// ����������
	virtual void initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos);
	// �{�^���������ꂽ�����A���肷��
	virtual bool isPressed(int posX, int posY);

	// �{�^���������ꂽ��Ăԏ���
	virtual void toActivate() = 0;

private:
	const int BUTTON_SIZE_X;		// �{�^���̉���
	const int BUTTON_SIZE_Y;		// �{�^���̏c��
};

