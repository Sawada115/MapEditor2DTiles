#include "pch.h"
#include "UI_Buttan.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="size">�{�^���̃T�C�Y</param>
UI_Buttan::UI_Buttan(DirectX::SimpleMath::Vector2 size)
	:BUTTON_SIZE_X(size.x)
	,BUTTON_SIZE_Y(size.y)
{

}


UI_Buttan::~UI_Buttan()
{
}

/// <summary>
/// ������
/// </summary>
/// <param name="buttonPos">�����ʒu</param>
void UI_Buttan::initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos)
{
	Obj2d::initialize(imageFileName, buttonPos);
}

/// <summary>
/// �{�^���������ꂽ���̔���
/// </summary>
/// <param name="posX">�}�E�X�̈ʒu(��)</param>
/// <param name="posY">�}�E�X�̈ʒu(�c)</param>
/// <returns></returns>
bool UI_Buttan::isPressed(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);

	Vector2 buttonPos = getPos();

	if (buttonPos.x + buttonHalfSize.x >= posX &&
		buttonPos.x - buttonHalfSize.x <= posX &&
		buttonPos.y + buttonHalfSize.y >= posY &&
		buttonPos.y - buttonHalfSize.y <= posY)
	{
		// �����ꂽ�Ƃ��֐����Ă�
		toActivate();

		return true;
	}
	return false;
}

/// <summary>
/// �{�^���������ꂽ�ۂ̏���
/// </summary>
/// <param name="posX">�}�E�X�̈ʒu(��)</param>
/// <param name="posY">�}�E�X�̈ʒu(�c)</param>
/// <param name="func">�����ꂽ�Ƃ��ɌĂԏ���</param>
void UI_Buttan::pressed(int posX, int posY, void(*func)())
{
	// �{�^���������ꂽ��
	if (isPressed(posX, posY))
	{
		// �����̊֐����Ă�
		func();
	}
	
}

/// <summary>
/// �Q�[���N���X�̃����o�[�֐����g���p��
/// �{�^���������ꂽ�ۂ̏���
/// </summary>
/// <param name="posX">�}�E�X�̈ʒu(��)</param>
/// <param name="posY">�}�E�X�̈ʒu(�c)</param>
/// <param name="func">�����ꂽ�Ƃ��ɌĂԏ���</param>
/// <param name="Game">�Q�[���N���X�̃A�h���X</param>
void UI_Buttan::pressed(int posX, int posY, void(Game::*func)(), Game* Game)
{
	// �{�^���������ꂽ��
	if (isPressed(posX, posY))
	{
		// �����̊֐����Ă�
		(Game->*func)();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <param name="func"></param>
/// <param name="Game"></param>
void UI_Buttan::presse(int posX, int posY, const std::function<void(void)>& func)
{
	// �{�^���������ꂽ��
	if (isPressed(posX, posY))
	{
		// �����̊֐����Ă�
		func();
	}

}
