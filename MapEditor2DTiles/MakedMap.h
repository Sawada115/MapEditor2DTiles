/// <summary>
/// 概要　 制作マップ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* −− ヘッダーのインクルード −−−− */
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

	// タイル一つ分のデータ
	struct OneTileData
	{
		Obj2d glids;	// グリッド線画像
		Tile* tile;		// タイル画像
	};

	static const int DRAW_TILE_NUM_X;
	static const int DRAW_TILE_NUM_Y;

	// 初期化
	void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2(235.5f, 300.0f));
	// 描画
	void draw();

	// クリックされたとき
	void beClicked(Tile* newTile, DirectX::SimpleMath::Vector2 clickPos);


	// タイルデータの取得
	std::vector<Tile*> GetAllTileData();
	// マップサイズの取得
	DirectX::SimpleMath::Vector2 GetMapSize();
	
	// マップサイズを変更する
	void mapReSize(int sizeX,int sizeY);

	// 選択したタイルを変更する
	void changTile(int changeTileID[2],Tile* newTile);

	// スクロール
	void TileScroll(int posX, int posY,int scrollValue);
	void TileScroll(int beginX,int beginY);

	// マップをリセット
	void mapReset();

private:

	int m_mapNum[2];	// マップのサイズ
	std::vector<std::vector<OneTileData>> m_tiles;// タイルたち

	// 背景画像のサイズ
	static const DirectX::SimpleMath::Vector2 BACK_SIZE;

	// 描画するタイルの一番左上
	int m_drawBeginTile[2];

	// 現在選択中のタイル
	int m_choiceTile[2];

	// マップの横一列分のサイズ変更
	void mapReSizeOneLine(int changeLine,int size);
	// マップの列単位でのサイズ変更
	void mapReSizeSomeLine(int size);
	// タイル一つ分のデータを作る
	OneTileData createTileData(DirectX::SimpleMath::Vector2 pos);
};

