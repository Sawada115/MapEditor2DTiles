#include "pch.h"
#include "UI_Buttan.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="size">ボタンのサイズ</param>
UI_ButtanBase::UI_ButtanBase(DirectX::SimpleMath::Vector2 size)
	:BUTTON_SIZE_X(size.x)
	,BUTTON_SIZE_Y(size.y)
{

}


UI_ButtanBase::~UI_ButtanBase()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="buttonPos">初期位置</param>
void UI_ButtanBase::initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos)
{
	Obj2d::initialize(imageFileName, buttonPos);
}

/// <summary>
/// ボタンが押されたかの判定
/// </summary>
/// <param name="posX">マウスの位置(横)</param>
/// <param name="posY">マウスの位置(縦)</param>
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
		// 押されたとき関数を呼ぶ
		toActivate();

		return true;
	}
	return false;
}
