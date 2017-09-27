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
			Vector2 glidPos = Vector2(275.5f + (i*30.0f), 330.0f + (j*30.0f)) - m_screenPos;

			// グリッドとタイル画像の
			m_tiles[i][j].glids.initialize(L"Resources/TileFlame.png", glidPos);
			m_tiles[i][j].tile.initialize(0, 0,glidPos);
		}
	}
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
