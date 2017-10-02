/// <summary>
/// 概要　 制作マップ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include "MakedMap.h"

using namespace DirectX::SimpleMath;

// 描画するタイルの数
const int MakedMap::DRAW_TILE_NUM_X = 14;
const int MakedMap::DRAW_TILE_NUM_Y = 17;


MakedMap::MakedMap()
{
}


MakedMap::~MakedMap()
{
	// タイル情報をデリート
	std::vector<std::vector<OneTileData>>::iterator it1;
	for (it1 = m_tiles.begin(); it1 != m_tiles.end(); it1++)
	{
		std::vector<OneTileData> ::iterator it2;
		for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
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
	m_mapNum[0] = DRAW_TILE_NUM_X;
	m_mapNum[1] = DRAW_TILE_NUM_Y;

	// 描画の左上のタイル
	m_drawBeginTile[0] = 0;
	m_drawBeginTile[1] = 0;

	// マップ情報の初期化
	m_tiles.resize(m_mapNum[1]);	// 縦の長さを設定
	for (int i = 0; i < m_mapNum[1]; i++)
	{
		m_tiles[i].resize(m_mapNum[0]);// 横の長さの設定

		for (int j = 0; j < m_mapNum[0]; j++)
		{
			// 位置を設定
			Vector2 glidPos = Vector2( (j*Tile::TILE_SIZE) - 195.0f,  (i*Tile::TILE_SIZE) - 270.0f) + m_screenPos;

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

	//std::vector<std::vector<OneTileData>>::iterator it1;
	//for (it1 = m_tiles.begin() + m_drawBeginTile[0]; it1 != m_tiles.end() + DRAW_TILE_NUM_X; it1++)
	//{
	//	std::vector<OneTileData> ::iterator it2;
	//	for (it2 = (*it1).begin() + m_drawBeginTile[0]; it2 != (*it1).end() + DRAW_TILE_NUM_Y; it2++)
	//	{
	//		// タイル画像
	//		(*it2).tile->draw();
	//		// グリッド
	//		(*it2).glids.draw();
	//	}
	//}

	// 縦ループ
	for (int i = m_drawBeginTile[1]; i < m_drawBeginTile[0] + DRAW_TILE_NUM_Y; i++)
	{
		// サイズが小さい場合は途中でループを抜ける
		if (i >= m_tiles.size())break;

		// 横ループ
		for (int j = m_drawBeginTile[0]; j < m_drawBeginTile[1] + DRAW_TILE_NUM_X; j++)
		{
			// サイズが小さい場合は途中でループを抜ける
			if (j >= m_tiles[i].size())break;

			// 描画する
			m_tiles[i][j].tile->draw();
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
	int i = m_tiles[0].size();
	while (beginPos.x < clickPos.x && beginPos.x + i*Tile::TILE_SIZE > clickPos.x)
	{
		i--;
	}
	// マップ外ならすぐ終わり、
	if (i >= m_tiles[0].size() || i < 0)
	{
		return;
	}
	clickedTileID[0] = i;

	// クリックされた位置を探す(縦)
	i = m_tiles.size();
	while (beginPos.y < clickPos.y && beginPos.y + i*Tile::TILE_SIZE > clickPos.y)
	{
		i--;
	}
	if (i >= m_tiles.size() || i < 0)
	{
		return;
	}
	clickedTileID[1] = i;

	// 選択したタイルを変更する
	changTile(clickedTileID, newTile);
}


/// <summary>
/// /// <summary>
/// タイルデータの取得
/// </summary>
/// <returns>全タイルデータ</returns>
std::vector<Tile*> MakedMap::GetAllTileData()
{
	std::vector<Tile*> tileData;

	// マップサイズの取得
	Vector2 size((int)m_tiles[0].size(), (int)m_tiles.size());
	int dataNum = size.x * size.y;

	// タイルデータを取り出す
	tileData.resize(dataNum);
	for (int i = 0; i < dataNum; i++)
		tileData[i] = m_tiles[i % (int)size.y][i / (int)size.y].tile;

	return tileData;
}

/// <summary>
/// マップサイズの取得
/// </summary>
/// <returns>マップサイズ</returns>
DirectX::SimpleMath::Vector2 MakedMap::GetMapSize()
{
	// マップサイズの取得
	Vector2 size((int)m_tiles[0].size(), (int)m_tiles.size());
	return size;
}

/// <summary>
/// 選択したタイルを変更する
/// </summary>
/// <param name="changeTileID">変更するタイルの番号</param>
/// <param name="newTile">新しいタイル</param>
void MakedMap::changTile(int changeTileID[2], Tile* newTile)
{
	newTile->setPosition(m_tiles[changeTileID[1]][changeTileID[0]].tile->getPos());

	// 新しいタイルをセット
	m_tiles[changeTileID[1]][changeTileID[0]].tile = newTile;
}

void MakedMap::TileScroll(int scrollValue)
{
	int tileHalfSize = Tile::TILE_SIZE / 2;
	int move = scrollValue / 120;

	// スクロール可能
	if (m_drawBeginTile[1] + -move >= 0 && m_drawBeginTile[1] + -move < DRAW_TILE_NUM_Y)
	{
		m_drawBeginTile[1] += -move;

		// 情報の更新
		std::vector<std::vector<OneTileData>>::iterator it1;
		for (it1 = m_tiles.begin(); it1 != m_tiles.end(); it1++)
		{
			std::vector<OneTileData> ::iterator it2;
			for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
			{
				// タイルをずらす
				Vector2 pos = (*it2).tile->getPos();
				(*it2).tile->setPosition(Vector2(pos.x, pos.y + Tile::TILE_SIZE * move));
				(*it2).glids.setPosition(Vector2(pos.x, pos.y + Tile::TILE_SIZE * move));

			}
		}
	}
}

/// <summary>
/// マップのリセット
/// </summary>
void MakedMap::mapReset()
{
	std::vector<std::vector<OneTileData>>::iterator it1;
	for (it1 = m_tiles.begin(); it1 != m_tiles.end() + DRAW_TILE_NUM_X; it1++)
	{
		std::vector<OneTileData> ::iterator it2;
		for (it2 = (*it1).begin(); it2 != (*it1).end() + DRAW_TILE_NUM_Y; it2++)
		{
			Vector2 pos = (*it2).tile->getPos();

			(*it2).tile->initialize(0, pos);
		}
	}
}

/// <summary>
/// マップサイズを変更する
/// </summary>
/// <param name="sizeX">変更後のサイズ(横)</param>
/// <param name="sizeY">変更後のサイズ(縦)</param>
void MakedMap::mapReSize(int sizeX, int sizeY)
{
	// 縦サイズが小さくなる場合
	if (m_mapNum[1] > sizeY)
	{
		// これ以上小さくならない場合はすぐ終わり
		if (m_mapNum[1] <= 1)return;

		for (m_mapNum[1]; m_mapNum[1] > sizeY; m_mapNum[1]--)
		{
			mapReSizeOneLine(m_mapNum[1]-1, 0);
			m_tiles.pop_back();
		}
	}

	// すべてのパターンの共通処理
	{// もともとあった列の長さを変更
		for (int i = 0; i < m_mapNum[1]; i++)
		{
			mapReSizeOneLine(i, sizeX);
		}
		m_mapNum[0] = sizeX;
	}

	// 縦サイズが大きくなる場合
	if (m_mapNum[1] < sizeY)
	{
		mapReSizeSomeLine(sizeY);
	}

	m_mapNum[0] = sizeX; m_mapNum[1] = sizeY;
}

/// <summary>
/// マップのサイズ変更(１列分)
/// </summary>
/// <param name="changeLine">サイズ変更する列番号</param>
/// <param name="size">変更後のサイズ</param>
void MakedMap::mapReSizeOneLine(int changeLine, int size)
{
	// 同じ数ならならすぐ終わり
	if (m_mapNum[0] == size)return;

	// 小さくなる場合
	if (m_mapNum[0] > size)
	{
		// これ以上小さくならない場合はすぐ終わり
		if (m_mapNum[0] <= 1)return;

		for (int i = m_mapNum[0]; i > size; i--)
		{
			// 最後尾を削除
			delete m_tiles[changeLine][i-1].tile;
			m_tiles[changeLine].pop_back();
		}
	}

	// 大きくなる場合
	else
	{
		for (int i = m_mapNum[0]; i < size; i++)
		{
			// 位置を設定
			Vector2 glidPos =
				Vector2((i*Tile::TILE_SIZE) - 195.0f, ((changeLine - m_drawBeginTile[1]) * Tile::TILE_SIZE) - 270.0f) + m_screenPos;
			
			// 増やす
			m_tiles[changeLine].push_back(createTileData(glidPos));
		}
	}
}

/// <summary>
/// マップを列単位でサイズ変更
/// </summary>
/// <param name="size">変更後のサイズ</param>
void MakedMap::mapReSizeSomeLine(int size)
{
	// 変わらない場合はすぐ終わり
	if (m_mapNum[1] == size)return;

	// 小さくなる場合
	if (m_mapNum[1] > size)
	{

	}

	// 大きくなる場合
	if (m_mapNum[1] < size)
	{
		// 追加する列
		std::vector<OneTileData> newTileLine;

		for ( m_mapNum[1]; m_mapNum[1] < size; m_mapNum[1]++)
		{// 一列増やす
			for (int i = 0; i < m_mapNum[0]; i++)
			{
				// 位置を設定
				Vector2 glidPos =
					Vector2((i*Tile::TILE_SIZE) - 195.0f, ((m_mapNum[1] - m_drawBeginTile[1]) * Tile::TILE_SIZE) - 270.0f) + m_screenPos;

				// 増やす
				newTileLine.push_back(createTileData(glidPos));
			}
		}

		// できた列を追加
		m_tiles.push_back(newTileLine);
	}
}


/// <summary>
/// タイル一つ分のデータを作る
/// </summary>
/// <param name="pos">初期位置</param>
/// <returns>作ったタイル</returns>
MakedMap::OneTileData MakedMap::createTileData(DirectX::SimpleMath::Vector2 pos)
{
	// 増やすデータ
	OneTileData oneTile;

	// グリッド
	oneTile.glids.initialize(L"Resources/TileFlame.png", pos);

	// タイル
	Tile* tile = new Tile;
	tile->initialize(0, pos);
	oneTile.tile = tile;

	return oneTile;
}
