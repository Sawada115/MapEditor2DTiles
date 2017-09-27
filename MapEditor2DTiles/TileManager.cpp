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
const int TileManager::TILE_TYPE_NUM = 27;
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
	Vector2 tilePos = m_palletTiles[0].getPos();
	for (int i = 0; i < PALLET_SIZE_X*PALLET_SIZE_Y; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_X));
		if (i == m_selectTile)
		{
			m_selectGrid.setPosition(pos);
			m_selectGrid.draw();
		}
		else
		{
			m_grid.setPosition(pos);
			m_grid.draw();
		}
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

	for (int i = 0; i < (int)m_palletTiles.size(); i++)
	{
		Vector2 tilePos = m_palletTiles[i].getPos();

		if (tilePos.x + tileHalfSize >= posX &&
			tilePos.x - tileHalfSize <= posX &&
			tilePos.y + tileHalfSize >= posY &&
			tilePos.y - tileHalfSize <= posY)
		{
			m_selectTile = i;
		}
	}
}



//----------------------------------------------------------------------
//! @brief 選択中のタイルを取得
//!
//! @param[in] 
//!
//! @return 
//----------------------------------------------------------------------
Tile* TileManager::GetSelectTile()
{
	Tile* tile = new Tile();
	int num = m_palletTiles[m_selectTile].getNum();

	tile->initialize(num);

	return tile;
}
