//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   TileManager.h
//!
//! @brief  タイルマネージャークラス
//!
//! @date   日付　2017/09/27
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

// ヘッダーファイルのインクルード==============================================
#include "Tile.h"
#include <vector>


// クラスの宣言
class TileManager
{
	// 静的変数の宣言
private:
	static const int TILE_TYPE_NUM;		// タイルの種類数
	static const int TILE_SIZE;			// タイルのサイズ
	static const int PALLET_SIZE_X;		// パレットの横幅
	static const int PALLET_SIZE_Y;		// パレットの縦幅

public:
	// コンストラクタ
	TileManager();
	// デストラクタ
	~TileManager();

	// 初期化処理
	void Initialize(DirectX::SimpleMath::Vector2 tile1Pos);
	// 描画処理
	void Draw();

	// カーソル位置のタイルを選択
	void TileSelect(int posX, int posY);
	// 選択中のタイルを取得
	Tile* GetSelectTile();
private:
	std::vector<Tile> m_palletTiles;			// パレット上のタイル
	Obj2d m_grid;								// グリッド画像
	Obj2d m_selectGrid;							// 選択中パネルのグリッド画像
	int m_selectTile;							// 選択中のタイル
};

