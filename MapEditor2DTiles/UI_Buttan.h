/// <summary>
/// 概要　 ボタンの
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"

class UI_ButtanBase : public Obj2d
{
public:
	UI_ButtanBase(DirectX::SimpleMath::Vector2 size);
	virtual ~UI_ButtanBase();

	// 初期化処理
	virtual void initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos);
	// ボタンが押されたかを、判定する
	virtual bool isPressed(int posX, int posY);

	// ボタンが押されたら呼ぶ処理
	virtual void toActivate() = 0;

private:
	const int BUTTON_SIZE_X;		// ボタンの横幅
	const int BUTTON_SIZE_Y;		// ボタンの縦幅
};

