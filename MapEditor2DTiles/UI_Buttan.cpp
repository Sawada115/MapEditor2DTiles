#include "pch.h"
#include "UI_Buttan.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="size">�{�^���̃T�C�Y</param>
UI_ButtanBase::UI_ButtanBase(DirectX::SimpleMath::Vector2 size)
	:BUTTON_SIZE_X(size.x)
	,BUTTON_SIZE_Y(size.y)
{

}


UI_ButtanBase::~UI_ButtanBase()
{
}

/// <summary>
/// ������
/// </summary>
/// <param name="buttonPos">�����ʒu</param>
void UI_ButtanBase::initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos)
{
	Obj2d::initialize(imageFileName, buttonPos);
}

/// <summary>
/// �{�^���������ꂽ���̔���
/// </summary>
/// <param name="posX">�}�E�X�̈ʒu(��)</param>
/// <param name="posY">�}�E�X�̈ʒu(�c)</param>
/// <returns></returns>
bool UI_ButtanBase::isPressed(int posX, int posY)
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
