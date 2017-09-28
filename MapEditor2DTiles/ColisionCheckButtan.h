/// <summary>
/// 概要　 タイルのコリジョンチェックのオンオフを切り替えるボタン
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"


class ColisionCheckButtan : public Obj2d
{
public:
	ColisionCheckButtan();
	virtual ~ColisionCheckButtan();

	// 初期化
	virtual void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// ボタンが押される
	bool ColisionCheckButtan::PressedButton(int posX, int posY);
private:
	static const int BUTTON_SIZE_X;		// ボタンの横幅
	static const int BUTTON_SIZE_Y;		// ボタンの縦幅

};

