/// <summary>
/// 概要　 制作マップ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include "MakedMap.h"

using namespace DirectX::SimpleMath;

MakedMap::MakedMap()
{
}


MakedMap::~MakedMap()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="pos">初期位置</param>
void MakedMap::initialize(Vector2 pos)
{
	// 背景画像の初期化
	Obj2d::initialize(L"Resources/BackImage1.png", pos);

	// マップサイズの初期化
	GLID_V = 14;
	GLID_H = 19;

	// マップ情報の初期化
	m_tiles.resize(GLID_V);	// 縦の長さを設定
	for (int i = 0; i < GLID_V; i++)
	{
		m_tiles[i].resize(GLID_H);// 横の長さの設定

		for (int j = 0; j < GLID_H; j++)
		{
			// 位置を設定
			Vector2 glidPos = Vector2( (i*Tile::TILE_SIZE) - 195.0f,  (j*Tile::TILE_SIZE) - 270.0f) + m_screenPos;

			// グリッドとタイル画像の
			m_tiles[i][j].glids.initialize(L"Resources/TileFlame.png", glidPos);
			m_tiles[i][j].tile.initialize(0, 0,glidPos);
		}
	}

	// 何も選択していない状態
	m_choiceTile[0] = 999;
	m_choiceTile[1] = 999;

}

/// <summary>
/// 描画
/// </summary>
void MakedMap::draw()
{
	// 背景画像
	Obj2d::draw();

	for (int i = 0; i < GLID_V; i++)
	{
		for (int j = 0; j < GLID_H; j++)
		{
			// タイル画像
			m_tiles[i][j].tile.draw();
			// グリッド
			m_tiles[i][j].glids.draw();
		}
	}
}

/// <summary>
/// クリックされたとき
/// </summary>
/// <param name="newTile">タイルの情報</param>
/// <param name="pos">クリック座標</param>
void MakedMap::beClicked(Tile* newTile, DirectX::SimpleMath::Vector2 clickPos)
{
	// 一番左上の座標
	DirectX::SimpleMath::Vector2 beginPos = m_screenPos - Vector2(210.0f, 285.0f);

	// クリックされたタイルの位置(V,H)
	int clickedTileID[2];

	// クリックされた位置を探す(横)
	int i = m_tiles.size();
	while (beginPos.x < clickPos.x && beginPos.x + i*Tile::TILE_SIZE > clickPos.x)
	{

		i--;
	}

	clickedTileID[0] = i;

	// クリックされた位置を探す(縦)
	i = m_tiles[0].size();
	while (beginPos.y < clickPos.y && beginPos.y + i*Tile::TILE_SIZE > clickPos.y)
	{
		i--;
	}
	clickedTileID[1] = i;

	// 
}
