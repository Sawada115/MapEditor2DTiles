/// <summary>
/// �T�v�@ �{�^����
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"
#include <functional>
#include <Mouse.h>

class Game;

class UI_Button : public Obj2d
{
public:
	UI_Button(DirectX::SimpleMath::Vector2 size);
	virtual ~UI_Button();

	// ����������
	virtual void initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos, const wchar_t* pressedImageFileName = nullptr);

	// �X�V����
	virtual void upDate(DirectX::Mouse::State m_mouse);

	// �`��
	virtual void draw();

/* ---- �{�^�����������Ƃ��� ---- */
// ��x�ɏ������čs���ꍇ
	virtual void pressed(int posX, int posY, void(*func)());
	void UI_Button::pressed(int posX, int posY,const std::function<void(void)>& func);

// ����Ə����ŕ�����ꍇ
	// �{�^���������ꂽ�����A���肷��
	virtual bool isPressed(int posX, int posY);
	// �{�^���������ꂽ��Ăԏ���
	virtual void toActivate() { /*(���e�͌p����Œ�`)*/};

protected:
	int BUTTON_SIZE_X;		// �{�^���̉���
	int BUTTON_SIZE_Y;		// �{�^���̏c��

	// ������Ă����Ԃ��ǂ���
	bool m_isPressed;

	// �}�E�X�̏��
	DirectX::Mouse::State m_mouse;
	std::unique_ptr<DirectX::Mouse::ButtonStateTracker> m_mouseTracker;
};

