/// <summary>
/// 概要　 ボタンの
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
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

	// 初期化処理
	virtual void initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos, const wchar_t* pressedImageFileName = nullptr);

	// 更新処理
	virtual void upDate(DirectX::Mouse::State m_mouse);

	// 描画
	virtual void draw();

/* ---- ボタンを押したときに ---- */
// 一度に処理して行う場合
	virtual void pressed(int posX, int posY, void(*func)());
	void UI_Button::pressed(int posX, int posY,const std::function<void(void)>& func);

// 判定と処理で分ける場合
	// ボタンが押されたかを、判定する
	virtual bool isPressed(int posX, int posY);
	// ボタンが押されたら呼ぶ処理
	virtual void toActivate() { /*(内容は継承先で定義)*/};

protected:
	int BUTTON_SIZE_X;		// ボタンの横幅
	int BUTTON_SIZE_Y;		// ボタンの縦幅

	// 押されている状態かどうか
	bool m_isPressed;

	// マウスの情報
	DirectX::Mouse::State m_mouse;
	std::unique_ptr<DirectX::Mouse::ButtonStateTracker> m_mouseTracker;
};

