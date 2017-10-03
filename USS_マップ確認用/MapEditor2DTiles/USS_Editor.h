/// <summary>
/// 概要　 USS_Editorで作ったステージを使用するためのヘッダ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include <vector>
#include "Tile.h"


// マップ使用用クラス
class USS_Explorer
{
public:
	USS_Explorer();
	~USS_Explorer();

	struct TileData
	{
		int imageType;			// 画像番号
		bool isColision;		// 当たり判定
	};

	// 初期化処理
	void Initialize(std::string fileName, int layerNum, DirectX::SimpleMath::Vector2 mapPos);

	// マップのCSVデータを読み込む
	void InPutCsv(int layer, std::string fileName);

	// マップを描画する
	void Draw();

	// タイルとの当たり判定をとる
	bool GetTileColision(DirectX::SimpleMath::Vector2 pos);

	// マップをスクロールする
	void MapScroll(DirectX::SimpleMath::Vector2 vec);

	void SetScrollPower(int layer ,float power) { m_scrollPower[layer] = power; };

private:
	std::vector<std::vector<TileBase>> m_map;	// マップ
	DirectX::SimpleMath::Vector2 m_mapSize;		// マップの大きさ
	std::vector<float> m_scrollPower;			// スクロール倍率
};



