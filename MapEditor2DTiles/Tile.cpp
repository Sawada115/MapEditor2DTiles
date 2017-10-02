/// <summary>
/// 概要　 タイル一枚
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include <string>
#include "Tile.h"

// ----- タイルのベース --------------------------------------------------------------------------------
TileBase::TileData TileBase::m_datas[180] = {	
									// -------  10  --------- //
	{ false,L"None" },{ false,L"RoadA1" },{ false,L"RoadA2" },{ false,L"RoadA3" },{ true,L"RoadB1" },{ true,L"RoadB2" },{ true,L"RoadB3" },{ false,L"RoadC1" },{ false,L"RoadC2" },{ false,L"RoadC3" },
									// -------  20  --------- //
	{ false,L"Grass1" },{ false,L"RoadA4" },{ false,L"RoadA5" },{ false,L"RoadA6" },{ true,L"RoadB4" },{ true,L"RoadB5" },{ true,L"RoadB6" },{ false,L"RoadC4" },{ false,L"RoadC5" },{ false,L"RoadC6" },
									// -------  30  --------- //
	{ false,L"Grass2" },{ false,L"RoadA7" },{ false,L"RoadA8" },{ false,L"RoadA9" },{ true,L"RoadB7" },	{ true,L"RoadB8" },{ true,L"RoadB9" },{ false,L"RoadC7" },{ false,L"RoadC8" },{ false,L"RoadC9" },
									// -------  40  --------- //
	{ false,L"Grass3" },{ true,L"RoadD1" },{ true,L"RoadD2" },{ true,L"RoadD3" },{ true,L"RoadE1" },{ true,L"RoadE2" },{ true,L"RoadE3" },{ true,L"RoadF1" },{ true,L"RoadF2" },{ true,L"RoadF3" },
									// -------  50  --------- //
	{ false,L"Grass4" },{ true,L"RoadD4" },{ false,L"RoadD5" },{ true,L"RoadD6" },{ true,L"RoadE4" },{ false,L"RoadE5" },{ true,L"RoadE6" },{ true,L"RoadF4" },{ true,L"RoadF5" },{ true,L"RoadF6" },
									// -------  60  --------- //
	{ false,L"None" },{ true,L"RoadD7" },{ true,L"RoadD8" },{ true,L"RoadD9" },{ true,L"RoadE7" },{ true,L"RoadE8" },{ true,L"RoadE9" },{ true,L"RoadF7" },{ true,L"RoadF8" },{ true,L"RoadF9" },
									// -------  70  --------- //
	{ false,L"None" },{ true,L"RoadG1" },{ true,L"RoadG2" },{ true,L"RoadG3" },{ true,L"RoadH1" },{ true,L"RoadH2" },{ true,L"RoadH3" },{ true,L"RoadI1" },{ true,L"RoadI2" },{ true,L"RoadI3" },
									// -------  80  --------- //
	{ false,L"None" },{ true,L"RoadG4" },{ false,L"RoadG5" },{ true,L"RoadG6" },{ true,L"RoadH4" },{ true,L"RoadH5" },{ true,L"RoadH6" },{ true,L"RoadI4" },{ false,L"RoadI5" },{ true,L"RoadI6" },
									// -------  90  --------- //
	{ false,L"None" },{ true,L"RoadG7" },{ true,L"RoadG8" },{ true,L"RoadG9" },{ true,L"RoadH7" },{ true,L"RoadH8" },{ true,L"RoadH9" },{ true,L"RoadI7" },{ true,L"RoadI8" },{ true,L"RoadI9" },
									// -------  100  --------- //
	{ false,L"None" },{ true,L"RoadJ1" },{ true,L"RoadJ2" },{ true,L"RoadJ3" },{ true,L"RoadK1" },{ true,L"RoadK2" },{ true,L"RoadK3" },{ true,L"RoadL1" },{ true,L"RoadL2" },{ true,L"RoadL3" },
									// -------  110  --------- //
	{ false,L"None" },{ true,L"RoadJ4" },{ true,L"RoadJ5" },{ true,L"RoadJ6" },{ true,L"RoadK4" },{ false,L"RoadK5" },{ true,L"RoadK6" },{ true,L"RoadL4" },{ true,L"RoadL5" },{ true,L"RoadL6" },
									// -------  120  --------- //
	{ false,L"None" },{ true,L"RoadJ7" },{ true,L"RoadJ8" },{ true,L"RoadJ9" },{ true,L"RoadK7" },{ true,L"RoadK8" },{ true,L"RoadK9" },{ true,L"RoadL7" },{ true,L"RoadL8" },{ true,L"RoadL9" },
									// -------  130  --------- //
	{ false,L"None" },{ true,L"RoadM1" },{ true,L"RoadM2" },{ true,L"RoadM3" },{ false,L"BridgeA1" },{ false,L"BridgeA2" },{ false,L"BridgeA3" },{ false,L"BridgeB1" },{ false,L"BridgeB2" },{ false,L"BridgeB3" },
									// -------  140  --------- //
	{ false,L"None" },{ true,L"RoadM4" },{ true,L"RoadM5" },{ true,L"RoadM6" },{ false,L"BridgeA4" },{ false,L"BridgeA5" },{ false,L"BridgeA6" },{ false,L"BridgeB4" },{ false,L"BridgeB5" },{ false,L"BridgeB6" },
									// -------  150  --------- //
	{ false,L"None" },{ true,L"RoadM7" },{ true,L"RoadM8" },{ true,L"RoadM9" },{ false,L"BridgeA7" },{ false,L"BridgeA8" },{ false,L"BridgeA9" },{ false,L"BridgeB7" },{ false,L"BridgeB8" },{ false,L"BridgeB9" },
									// -------  160  --------- //
	{ false,L"None" },{ false,L"BridgeC1" },{ false,L"BridgeC2" },{ false,L"BridgeC3" },{ false,L"BridgeD1" },{ false,L"BridgeD2" },{ false,L"BridgeD3" },{ true,L"Tree1" },{ true,L"Tree2" },{ false,L"None" },
									// -------  170  --------- //
	{ false,L"None" },{ false,L"BridgeC4" },{ false,L"BridgeC5" },{ false,L"BridgeC6" },{ false,L"BridgeD4" },{ false,L"BridgeD5" },{ false,L"BridgeD6" },{ true,L"Tree3" },{ true,L"Tree4" },{ false,L"None" },
									// -------  180  --------- //
	{ false,L"None" },{ false,L"BridgeC7" },{ false,L"BridgeC8" },{ false,L"BridgeC9" },{ false,L"BridgeD7" },{ false,L"BridgeD8" },{ false,L"BridgeD9" },{ false,L"None" },{ false,L"None" },{ false,L"None" },
};


TileBase::TileBase()
{
}

TileBase::~TileBase()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="imageType">使用する画像のタイプの番号</param>
/// <param name="pos">初期位置</param>
void TileBase::initialize(int imageType, DirectX::SimpleMath::Vector2 pos)
{
	m_num = imageType;


	// 画像のファイル名を作る
	std::wstring fileName = m_datas[imageType].fileNames;

	fileName = L"Resources/Tiles/" + fileName;
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
bool TileBase::changheColision()
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


// ----- エディターで使うタイル -------------------------------------------------------------------------
// タイルサイズ
const float Tile::TILE_SIZE = 30.0f;

// 最初はチェックしない
bool Tile::m_isCheckedColision = false;


Tile::Tile()
{
}


Tile::~Tile()
{
}


/// <summary>
/// 初期化
/// </summary>
/// <param name="imageType">使用する画像のタイプの番号</param>
/// <param name="pos">初期位置</param>
void Tile::initialize(int imageType, DirectX::SimpleMath::Vector2 pos)
{
	TileBase::m_num = imageType;


	// 画像のファイル名を作る
	std::wstring fileName = TileBase::m_datas[imageType].fileNames;

	// 名前を保存
	m_name = fileName;

	fileName = L"Resources/Tiles/" + fileName;
	fileName += L".png";

	// 型変換
	const wchar_t* imgName = fileName.c_str();

	// 基底クラスの初期化
	Obj2d::initialize(imgName);

	// 判定を設定
	m_isColision = TileBase::m_datas[imageType].isColision;

	// 初期位置設定
	m_screenPos = pos;

}


/// <summary>
/// 描画
/// </summary>
void Tile::draw()
{
	if (m_isColision && m_isCheckedColision)
	{
		this->setColer(DirectX::Colors::Red);
	}
	else
	{
		this->setColer(DirectX::Colors::White);
	}

	Obj2d::draw();
}


void Tile::changeCollisionCheck()
{
	if (m_isCheckedColision)
	{
		m_isCheckedColision = false;
	}
	else
	{
		m_isCheckedColision = true;
	}
}
