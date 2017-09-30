/// <summary>
/// �T�v�@ �{�^����
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"
#include <functional>

class Game;

class UI_Buttan : public Obj2d
{
public:
	UI_Buttan(DirectX::SimpleMath::Vector2 size);
	virtual ~UI_Buttan();

	// ����������
	virtual void initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos);

/* ---- �{�^�����������Ƃ��� ---- */
// ��x�ɏ������čs���ꍇ
	virtual void pressed(int posX, int posY, void(*func)());
	virtual void pressed(int posX, int posY, void(Game::*func)(),Game* Game);
	void UI_Buttan::presse(int posX, int posY,const std::function<void(void)>& func);

// ����Ə����ŕ�����ꍇ
	// �{�^���������ꂽ�����A���肷��
	virtual bool isPressed(int posX, int posY);
	// �{�^���������ꂽ��Ăԏ���
	virtual void toActivate() { /*(���e�͌p����Œ�`)*/};

private:
	const int BUTTON_SIZE_X;		// �{�^���̉���
	const int BUTTON_SIZE_Y;		// �{�^���̏c��
};

