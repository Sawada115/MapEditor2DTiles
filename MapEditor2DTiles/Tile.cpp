/// <summary>
/// 概要　 タイル一枚
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include <string>
#include "Tile.h"

// クラス定数
Tile::TileData Tile::m_datas[5] = {	{ true,L"None" },
									{ false,L"Grass" },
									{ false,L"RoadA" },
									{ true,L"RoadB" },
									{ true,L"Tree" }};

// タイルサイズ
const float Tile::TILE_SIZE = 30.0f;


Tile::Tile()
{
}


Tile::~Tile()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="imageType">使用する画像のタイプの番号(Grass等)</param>
/// <param name="imageID">使用する画像タイプのID</param>
/// <param name="pos">初期位置</param>
void Tile::initialize(int imageType, int imageID, DirectX::SimpleMath::Vector2 pos)
{
	// 画像のファイル名を作る
	std::wstring fileName = m_datas[imageType].fileNames;

	// NONEの場合はimageIDをつけない
	if (imageID != 0)
	{
		fileName += std::to_wstring(imageID);
	}

	// 名前を保存
	m_name = fileName.c_str();

	fileName = L"Resources/" + fileName;
	fileName += L".png";

	// 型変換
	const wchar_t* imgName = fileName.c_str();

	// 基底クラスの初期化
	Obj2d::initialize(imgName);

	// 判定を設定
	m_isColision = m_datas[imageType].isColision;

	// 初期位置設定
	m_screenPos = pos;
}

/// <summary>
/// m_isColisionを変更
/// </summary>
/// <returns>変更後の判定</returns>
bool Tile::changheColision()
{
	if (m_isColision) 
	{
		m_isColision = false;
	}
	else
	{
		m_isColision = true;
	}

	return m_isColision;
}
