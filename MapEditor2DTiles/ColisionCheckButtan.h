/// <summary>
/// 概要　 タイルのコリジョンチェックのオンオフを切り替えるボタン
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "UI_Buttan.h"
#include "Tile.h"


class ColisionCheckButtan : public UI_Buttan
{
public:
	ColisionCheckButtan();
	virtual ~ColisionCheckButtan();

	// 初期化
	virtual void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// ボタンが押される
	void toActivate();
};

