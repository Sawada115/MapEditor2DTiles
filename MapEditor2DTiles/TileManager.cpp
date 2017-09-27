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
const int TileManager::TILE_TYPE_NUM = 5;
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
	// タイルの種類とタイル数
	int tileID[TILE_TYPE_NUM] =
	{
		1,4,9,9,4
	};

	// タイルの合計数を求める
	int tileNum = 0;
	for (int i = 0; i < TILE_TYPE_NUM; i++)
		tileNum += tileID[i];

	m_palletTiles.resize(tileNum);

	// タイルの作成
	int count = 0;
	for (int i = 0; i < TILE_TYPE_NUM; i++)
	{
		for (int j = 0; j < tileID[i]; j++)
		{
			Vector2 pos(tilePos.x + TILE_SIZE * (count % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(count / PALLET_SIZE_Y));
			if (tileID[i] == 1)
				m_palletTiles[count].initialize(1, 1, pos);
			else
				m_palletTiles[count].initialize(i, j + 1, pos);
			count++;
		}
	}
	
	// 仮座標設定
	for (int i = 0; i < count; i++)
	{
		Vector2 pos(tilePos.x + TILE_SIZE * (i % PALLET_SIZE_X), tilePos.y + TILE_SIZE*(i / PALLET_SIZE_Y));
		m_palletTiles[i].setPosition(pos);
	}
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
	for (auto itr = m_palletTiles.begin(); itr != m_palletTiles.end(); itr++)
		(*itr).draw();
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

	for (auto itr = m_palletTiles.begin(); itr != m_palletTiles.end(); itr++)
	{
		Vector2 tilePos = (*itr).getPos();

		if (tilePos.x + tileHalfSize >= posX &&
			tilePos.x - tileHalfSize <= posX &&
			tilePos.y + tileHalfSize >= posY &&
			tilePos.y - tileHalfSize <= posY)
		{
			m_selectTile = 0;
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
Tile TileManager::GetSelectTile()
{
	return Tile();
}
