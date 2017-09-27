/// <summary>
/// 概要　 タイル一枚
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include <string>
#include "Tile.h"

// クラス定数
Tile::TileData Tile::m_datas[30] = {	{ true,L"None" },

										{ false,L"RoadA1" },
										{ false,L"RoadA2" },
										{ false,L"RoadA3" },

										{ true,L"RoadB1" },
										{ true,L"RoadB2" },
										{ true,L"RoadB3" },

										{ true,L"Tree1" },
										{ true,L"Tree2" },

										{ false,L"Grass1" },
										{ false,L"Grass2" },

										{ false,L"RoadA4" },
										{ false,L"RoadA5" },
										{ false,L"RoadA6" },

										{ true,L"RoadB4" },
										{ true,L"RoadB5" },
										{ true,L"RoadB6" },

										{ true,L"Tree3" },
										{ true,L"Tree4" },

										{ false,L"Grass3" },
										{ false,L"Grass4" },

										{ false,L"RoadA7" },
										{ false,L"RoadA8" },
										{ false,L"RoadA9" },

										{ true,L"RoadB7" },
										{ true,L"RoadB8" },
										{ true,L"RoadB9" },
};

// タイルサイズ
const float Tile::TILE_SIZE = 30.0f;


Tile::Tile()
{
}


Tile::~Tile()
{
}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="tile">コピー元</param>
/// <returns>新しくできたもの</returns>
Tile& Tile::operator=(const Tile& tile)
{
	Tile& tilee = Tile();
	tilee.m_isColision = tile.m_isColision;
	tilee.m_name = tile.m_name;


	std::wstring fileName = tilee.m_name;
	fileName = L"Resources/" + fileName;
	fileName += L".png";
	

	return Tile();
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="imageType">使用する画像のタイプの番号</param>
/// <param name="pos">初期位置</param>
void Tile::initialize(int imageType, DirectX::SimpleMath::Vector2 pos)
{
	m_num = imageType;


	// 画像のファイル名を作る
	std::wstring fileName = m_datas[imageType].fileNames;

	// 名前を保存
	m_name = fileName;

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
