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
	// タイル情報をデリート
	std::vector<std::vector<OneTileData>>::iterator it1;
	for (it1 = m_tiles.begin(); it1 < m_tiles.end(); it1++)
	{
		std::vector<OneTileData> ::iterator it2;
		for (it2 = (*it1).begin(); it2 < (*it1).end(); it2++)
		{
			delete (*it2).tile;
		}
	}

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
	m_mapNum = 19;

	// マップ情報の初期化
	m_tiles.resize(GLID_V);	// 縦の長さを設定
	for (int i = 0; i < GLID_V; i++)
	{
		m_tiles[i].resize(m_mapNum);// 横の長さの設定

		for (int j = 0; j < m_mapNum; j++)
		{
			// 位置を設定
			Vector2 glidPos = Vector2( (i*Tile::TILE_SIZE) - 195.0f,  (j*Tile::TILE_SIZE) - 270.0f) + m_screenPos;

			// グリッドとタイル画像の
			m_tiles[i][j].glids.initialize(L"Resources/TileFlame.png", glidPos);
			m_tiles[i][j].tile = new Tile();
			m_tiles[i][j].tile->initialize(0,glidPos);
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
		for (int j = 0; j < m_mapNum; j++)
		{
			// タイル画像
			m_tiles[i][j].tile->draw();
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
	if (i >= m_tiles.size() || i < 0)
	{
		return;
	}
	clickedTileID[0] = i;

	// クリックされた位置を探す(縦)
	i = m_tiles[0].size();
	while (beginPos.y < clickPos.y && beginPos.y + i*Tile::TILE_SIZE > clickPos.y)
	{
		i--;
	}
	if (i >= m_tiles[0].size() || i < 0)
	{
		return;
	}
	clickedTileID[1] = i;

	// 選択したタイルを変更する
	changTile(clickedTileID, newTile);
}

/// <summary>
/// 選択したタイルを変更する
/// </summary>
/// <param name="changeTileID">変更するタイルの番号</param>
/// <param name="newTile">新しいタイル</param>
void MakedMap::changTile(int changeTileID[2], Tile* newTile)
{
	newTile->setPosition(m_tiles[changeTileID[0]][changeTileID[1]].tile->getPos());

	// 新しいタイルをセット
	m_tiles[changeTileID[0]][changeTileID[1]].tile = newTile;
}
