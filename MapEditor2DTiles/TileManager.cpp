//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   TileManager.cpp
//!
//! @brief  タイルマネージャークラス
//!
//! @date   日付　2017/09/27
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダーファイルのインクルード==============================================
#include "pch.h"
#include "TileManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

// 静的変数の初期化
const int TileManager::TILE_TYPE_NUM = 72;
const int TileManager::TILE_SIZE = 30;
const int TileManager::PALLET_SIZE_X = 10;
const int TileManager::PALLET_SIZE_Y = 8;

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return 存在しない
//----------------------------------------------------------------------
TileManager::TileManager()
{
}



//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] 存在しない
//!
//! @return 存在しない
//----------------------------------------------------------------------
TileManager::~TileManager()
{
}



//----------------------------------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] 1番目のタイル座標
//!
//! @return なし
//----------------------------------------------------------------------
void TileManager::Initialize(Vector2 tilePos)
{
	m_palletTiles.resize(TILE_TYPE_NUM);

	// タイルの作成
	for (int i = 0; i < TILE_TYPE_NUM; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_X));
		m_palletTiles[i].initialize(i, pos);
	}

	m_grid.initialize(L"Resources/TileFlame.png");
	m_selectGrid.initialize(L"Resources/TileFlameRed.png");
	m_selectTile = 0;
	m_drawStartTile = 0;
}



//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void TileManager::Draw()
{
	// タイルの描画
	for (auto itr = m_palletTiles.begin(); itr != m_palletTiles.end(); itr++)
		(*itr).draw();

	// グリッドの描画
	Vector2 tilePos = m_palletTiles[m_drawStartTile].getPos();
	for (int i = 0; i < PALLET_SIZE_X*PALLET_SIZE_Y; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_X));
			m_grid.setPosition(pos);
			m_grid.draw();
	}

	// 選択中枠の描画
	if (m_palletTiles[m_selectTile].getVisible())
	{
		m_selectGrid.setPosition(m_palletTiles[m_selectTile].getPos());
		m_selectGrid.draw();
	}
}



//----------------------------------------------------------------------
//! @brief カーソル位置のタイルを選択する
//!
//! @param[in] 座標X 座標Y
//!
//! @return なし
//----------------------------------------------------------------------
void TileManager::TileSelect(int posX, int posY)
{
	int tileHalfSize = TILE_SIZE / 2;

	int tile = GetHitTile(posX, posY);
	if (tile != -1)
		m_selectTile = tile;
}



//----------------------------------------------------------------------
//! @brief 選択中のタイルを取得
//!
//! @param[in] 
//!
//! @return 
//----------------------------------------------------------------------
Tile* TileManager::CopySelectTile()
{
	Tile* tile = new Tile();
	int num = m_palletTiles[m_selectTile].getNum();

	tile->initialize(num);

	return tile;
}

Tile* TileManager::GetSelectTile()
{
	return &m_palletTiles[m_selectTile] ;
}



//----------------------------------------------------------------------
//! @brief パレットタイルのスクロール
//!
//! @param[in] 座標X 座標Y
//!
//! @return なし
//----------------------------------------------------------------------
void TileManager::TileScroll(int posX, int posY, int scrollValue)
{
	int tileHalfSize = TILE_SIZE / 2;
	int move = -scrollValue / 120;
	
	Vector2 tilePos = m_palletTiles[m_drawStartTile].getPos() - Vector2(tileHalfSize);

	// パレットのタイルに触れている
	if (tilePos.x <= posX &&
		tilePos.x + TILE_SIZE * PALLET_SIZE_X >= posX &&
		tilePos.y <= posY &&
		tilePos.y + TILE_SIZE * PALLET_SIZE_Y >= posY)
	{
		// スクロール可能
		if (m_drawStartTile + -move * 10 >= 0 && m_drawStartTile + -move * 10 < TILE_TYPE_NUM)
		{
			m_drawStartTile += -move * 10;

			// タイルをずらす
			for (int i = 0; i < (int)m_palletTiles.size(); i++)
			{
				Vector2 pos = m_palletTiles[i].getPos();
				m_palletTiles[i].setPosition(Vector2(pos.x, pos.y + TILE_SIZE * move));

				if (m_drawStartTile > i)
					m_palletTiles[i].setVisible(false);
				else
					m_palletTiles[i].setVisible(true);
			}
		}
	}
}



//----------------------------------------------------------------------
//! @brief 座標地点にあるタイルを取得
//!
//! @param[in] 座標X 座標Y
//!
//! @return タイル番号 ない場合は-1
//----------------------------------------------------------------------
int TileManager::GetHitTile(int posX, int posY)
{
	int tileHalfSize = TILE_SIZE / 2;

	for (int i = 0; i < (int)m_palletTiles.size(); i++)
	{
		if (m_palletTiles[i].getVisible())
		{
			Vector2 tilePos = m_palletTiles[i].getPos();

			if (tilePos.x + tileHalfSize >= posX &&
				tilePos.x - tileHalfSize <= posX &&
				tilePos.y + tileHalfSize >= posY &&
				tilePos.y - tileHalfSize <= posY)
			{
				return i;
			}
		}
	}
	return -1;
}
