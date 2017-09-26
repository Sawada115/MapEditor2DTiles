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
	Obj2d::initialize(L"Resources/BackImage1.png", pos);

	// グリッド線の初期化
	GLID_V = 14;
	GLID_H = 19;
	for (int i = 0; i < GLID_V; i++)
	{
		for (int j = 0; j < GLID_H; j++)
		{
			Vector2 glidPos = Vector2(275.5f + (i*30.0f), 330.0f + (j*30.0f)) - m_screenPos;

			m_glids[i][j].initialize(L"Resources/TileFlame.png", glidPos);
		}
	}
}

/// <summary>
/// 描画
/// </summary>
void MakedMap::draw()
{
	Obj2d::draw();

	for (int i = 0; i < GLID_V; i++)
	{
		for (int j = 0; j < GLID_H; j++)
		{
			m_glids[i][j].draw();
		}
	}
}
