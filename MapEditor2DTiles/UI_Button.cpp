#include "pch.h"
#include "UI_Button.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="size">�{�^���̃T�C�Y</param>
UI_Button::UI_Button(DirectX::SimpleMath::Vector2 size)
	:BUTTON_SIZE_X(size.x)
	,BUTTON_SIZE_Y(size.y)
{

}


UI_Button::~UI_Button()
{
}

/// <summary>
/// ������
/// </summary>
/// <param name="buttonPos">�����ʒu</param>
void UI_Button::initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos, const wchar_t* pressedImageFileName)
{
	// �摜���Z�b�e�B���O
	Obj2d::initialize(imageFileName, buttonPos);

	// �ŏ��͉�����Ă��Ȃ�
	m_isPressed = false;

	// �}�E�X�g���b�J�[
	m_mouseTracker = std::make_unique<DirectX::Mouse::ButtonStateTracker>();
}

/// <summary>
/// �X�V
/// </summary>
void UI_Button::upDate(DirectX::Mouse::State mouse)
{
	// �}�E�X�����擾
	m_mouseTracker->Update(mouse);

	// ���N���b�N������
	if (mouse.leftButton && isPressed(mouse.x,mouse.y))
	{

		// �����ꂽ��
		m_isPressed = true;
	}
	else
	{
		// ������ĂȂ���
		m_isPressed = false;
	}
	// ���N���b�N(�g���b�J�[)
	if (m_mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::PRESSED)
	{

	}
}

/// <summary>
/// �`��
/// </summary>
void UI_Button::draw()
{
	// ������Ă���Ȃ�F���Â�����
	if (m_isPressed)this->setColer(DirectX::Colors::Gray);
	else this->setColer(DirectX::Colors::White);

	Obj2d::draw();


}

/// <summary>
/// �{�^���������ꂽ���̔���
/// </summary>
/// <param name="posX">�}�E�X�̈ʒu(��)</param>
/// <param name="posY">�}�E�X�̈ʒu(�c)</param>
/// <returns></returns>
bool UI_Button::isPressed(int posX, int posY)
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

		m_isPressed = true;

		return true;
	}
	m_isPressed = false;

	return false;
}

/// <summary>
/// �{�^���������ꂽ�ۂ̏���
/// </summary>
/// <param name="posX">�}�E�X�̈ʒu(��)</param>
/// <param name="posY">�}�E�X�̈ʒu(�c)</param>
/// <param name="func">�����ꂽ�Ƃ��ɌĂԏ���</param>
void UI_Button::pressed(int posX, int posY, void(*func)())
{
	// �{�^���������ꂽ��
	if (isPressed(posX, posY))
	{
		// �����̊֐����Ă�
		func();

		m_isPressed = true;
	}
	m_isPressed = false;
}

/// <summary>
/// 
/// </summary>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <param name="func"></param>
/// <param name="Game"></param>
void UI_Button::pressed(int posX, int posY, const std::function<void(void)>& func)
{
	// �{�^���������ꂽ��
	if (isPressed(posX, posY))
	{
		// �����̊֐����Ă�
		func();
	}

}
