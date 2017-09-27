/// <summary>
/// 概要　 制作マップ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"
#include <vector>
#include "Tile.h"

class MakedMap : public Obj2d
{
public:
	MakedMap();
	virtual ~MakedMap();

	// 初期化
	void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2(235.5f, 300.0f));
	// 描画
	void draw();

private:
	// タイル一つ分のデータ
	struct OneTileData
	{
		Obj2d glids;	// グリッド線画像
		Tile tile;
	};

	int GLID_H;
	int GLID_V;
	std::vector<std::vector<OneTileData>> m_tiles;// タイルたち
};

