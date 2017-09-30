#include "pch.h"
#include "UI_Buttan.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="size">ボタンのサイズ</param>
UI_Buttan::UI_Buttan(DirectX::SimpleMath::Vector2 size)
	:BUTTON_SIZE_X(size.x)
	,BUTTON_SIZE_Y(size.y)
{

}


UI_Buttan::~UI_Buttan()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="buttonPos">初期位置</param>
void UI_Buttan::initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos)
{
	Obj2d::initialize(imageFileName, buttonPos);
}

/// <summary>
/// ボタンが押されたかの判定
/// </summary>
/// <param name="posX">マウスの位置(横)</param>
/// <param name="posY">マウスの位置(縦)</param>
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
		// 押されたとき関数を呼ぶ
		toActivate();

		return true;
	}
	return false;
}

/// <summary>
/// ボタンが押された際の処理
/// </summary>
/// <param name="posX">マウスの位置(横)</param>
/// <param name="posY">マウスの位置(縦)</param>
/// <param name="func">押されたときに呼ぶ処理</param>
void UI_Buttan::pressed(int posX, int posY, void(*func)())
{
	// ボタンが押されたら
	if (isPressed(posX, posY))
	{
		// 引数の関数を呼ぶ
		func();
	}
	
}

/// <summary>
/// ゲームクラスのメンバー関数を使う用の
/// ボタンが押された際の処理
/// </summary>
/// <param name="posX">マウスの位置(横)</param>
/// <param name="posY">マウスの位置(縦)</param>
/// <param name="func">押されたときに呼ぶ処理</param>
/// <param name="Game">ゲームクラスのアドレス</param>
void UI_Buttan::pressed(int posX, int posY, void(Game::*func)(), Game* Game)
{
	// ボタンが押されたら
	if (isPressed(posX, posY))
	{
		// 引数の関数を呼ぶ
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
	// ボタンが押されたら
	if (isPressed(posX, posY))
	{
		// 引数の関数を呼ぶ
		func();
	}

}
