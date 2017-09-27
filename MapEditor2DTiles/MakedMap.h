/// <summary>
/// 概要　 制作マップ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"
#include <vector>
#include <SimpleMath.h>
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

	// クリックされたとき
	void beClicked(Tile* newTile, DirectX::SimpleMath::Vector2 clickPos);

	// マップのサイズを変更する
	//void setMapSize(int size[2]) {};

private:
	// 選択したタイルを変更する
	void changTile(int changeTileID[2],Tile* newTile);

	// タイル一つ分のデータ
	struct OneTileData
	{
		Obj2d glids;	// グリッド線画像
		Tile* tile;		// タイル画像
	};


	int m_mapNum;	// グリッドの
	int GLID_V; //		サイズ
	std::vector<std::vector<OneTileData>> m_tiles;// タイルたち

	// 現在選択中のタイル
	int m_choiceTile[2];
};

