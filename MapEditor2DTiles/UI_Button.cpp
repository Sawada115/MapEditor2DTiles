#include "pch.h"
#include "UI_Button.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="size">ボタンのサイズ</param>
UI_Button::UI_Button(DirectX::SimpleMath::Vector2 size)
	:BUTTON_SIZE_X(size.x)
	,BUTTON_SIZE_Y(size.y)
{

}


UI_Button::~UI_Button()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="buttonPos">初期位置</param>
void UI_Button::initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos, const wchar_t* pressedImageFileName)
{
	// 画像をセッティング
	Obj2d::initialize(imageFileName, buttonPos);

	// 最初は押されていない
	m_isPressed = false;

	// マウストラッカー
	m_mouseTracker = std::make_unique<DirectX::Mouse::ButtonStateTracker>();
}

/// <summary>
/// 更新
/// </summary>
void UI_Button::upDate(DirectX::Mouse::State mouse)
{
	// マウス情報を取得
	m_mouseTracker->Update(mouse);

	// 左クリックしたら
	if (mouse.leftButton && isPressed(mouse.x,mouse.y))
	{

		// 押されたよ
		m_isPressed = true;
	}
	else
	{
		// 押されてないよ
		m_isPressed = false;
	}
	// 左クリック(トラッカー)
	if (m_mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::PRESSED)
	{

	}
}

/// <summary>
/// 描画
/// </summary>
void UI_Button::draw()
{
	// 押されているなら色を暗くする
	if (m_isPressed)this->setColer(DirectX::Colors::Gray);
	else this->setColer(DirectX::Colors::White);

	Obj2d::draw();


}

/// <summary>
/// ボタンが押されたかの判定
/// </summary>
/// <param name="posX">マウスの位置(横)</param>
/// <param name="posY">マウスの位置(縦)</param>
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
		// 押されたとき関数を呼ぶ
		toActivate();

		m_isPressed = true;

		return true;
	}
	m_isPressed = false;

	return false;
}

/// <summary>
/// ボタンが押された際の処理
/// </summary>
/// <param name="posX">マウスの位置(横)</param>
/// <param name="posY">マウスの位置(縦)</param>
/// <param name="func">押されたときに呼ぶ処理</param>
void UI_Button::pressed(int posX, int posY, void(*func)())
{
	// ボタンが押されたら
	if (isPressed(posX, posY))
	{
		// 引数の関数を呼ぶ
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
	// ボタンが押されたら
	if (isPressed(posX, posY))
	{
		// 引数の関数を呼ぶ
		func();
	}

}
