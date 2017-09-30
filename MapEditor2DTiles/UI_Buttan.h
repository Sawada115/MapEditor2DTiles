/// <summary>
/// 概要　 ボタンの
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"
#include <functional>

class Game;

class UI_Buttan : public Obj2d
{
public:
	UI_Buttan(DirectX::SimpleMath::Vector2 size);
	virtual ~UI_Buttan();

	// 初期化処理
	virtual void initialize(const wchar_t* imageFileName, DirectX::SimpleMath::Vector2 buttonPos);

/* ---- ボタンを押したときに ---- */
// 一度に処理して行う場合
	virtual void pressed(int posX, int posY, void(*func)());
	virtual void pressed(int posX, int posY, void(Game::*func)(),Game* Game);
	void UI_Buttan::presse(int posX, int posY,const std::function<void(void)>& func);

// 判定と処理で分ける場合
	// ボタンが押されたかを、判定する
	virtual bool isPressed(int posX, int posY);
	// ボタンが押されたら呼ぶ処理
	virtual void toActivate() { /*(内容は継承先で定義)*/};

private:
	const int BUTTON_SIZE_X;		// ボタンの横幅
	const int BUTTON_SIZE_Y;		// ボタンの縦幅
};

