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
	{ false,L"None" },{ false,L"RoadToGrass (1)" },{ false,L"RoadToGrass (2)" },{ false,L"RoadToGrass (3)" },{ true,L"HoleToGrass (1)" },{ true,L"HoleToGrass (2)" },{ true,L"HoleToGrass (3)" },{ false,L"GrassToRoad (1)" },{ false,L"GrassToRoad (2)" },{ false,L"GrassToRoad (3)" },
									// -------  20  --------- //
	{ false,L"Grass1" },{ false,L"RoadToGrass (4)" },{ false,L"RoadToGrass (5)" },{ false,L"RoadToGrass (6)" },{ true,L"HoleToGrass (4)" },{ true,L"HoleToGrass (5)" },{ true,L"HoleToGrass (6)" },{ false,L"GrassToRoad (4)" },{ false,L"GrassToRoad (5)" },{ false,L"GrassToRoad (6)" },
									// -------  30  --------- //
	{ false,L"Grass2" },{ false,L"RoadToGrass (7)" },{ false,L"RoadToGrass (8)" },{ false,L"RoadToGrass (9)" },{ true,L"HoleToGrass (7)" },	{ true,L"HoleToGrass (8)" },{ true,L"HoleToGrass (9)" },{ false,L"GrassToRoad (7)" },{ false,L"GrassToRoad (8)" },{ false,L"GrassToRoad (9)" },
									// -------  40  --------- //
	{ false,L"RoadToHole (5)" },{ true,L"RoadToHole (1)" },{ true,L"RoadToHole (2)" },{ true,L"RoadToHole (3)" },{ true,L"GrassToHole (1)" },{ true,L"GrassToHole (2)" },{ true,L"GrassToHole (3)" },{ true,L"HoleToRoad (1)" },{ true,L"HoleToRoad (2)" },{ true,L"HoleToRoad (3)" },
									// -------  50  --------- //
	{ false,L"RoadToHole (5)" },{ true,L"RoadToHole (4)" },{ false,L"RoadToHole (5)" },{ true,L"RoadToHole (6)" },{ true,L"GrassToHole (4)" },{ false,L"GrassToHole (5)" },{ true,L"GrassToHole (6)" },{ true,L"HoleToRoad (4)" },{ true,L"HoleToRoad (5)" },{ true,L"HoleToRoad (6)" },
									// -------  60  --------- //
	{ false,L"RoadToHole (5)" },{ true,L"RoadToHole (7)" },{ true,L"RoadToHole (8)" },{ true,L"RoadToHole (9)" },{ true,L"GrassToHole (7)" },{ true,L"GrassToHole (8)" },{ true,L"GrassToHole (9)" },{ true,L"HoleToRoad (7)" },{ true,L"HoleToRoad (8)" },{ true,L"HoleToRoad (9)" },
									// -------  70  --------- //
	{ false,L"ReverToGrass (5)" },{ true,L"RoadToRever (1)" },{ true,L"RoadToRever (2)" },{ true,L"RoadToRever (3)" },{ true,L"ReverToGrass (1)" },{ true,L"ReverToGrass (2)" },{ true,L"ReverToGrass (3)" },{ true,L"GrassToRever1 (1)" },{ true,L"GrassToRever1 (2)" },{ true,L"GrassToRever1 (3)" },
									// -------  80  --------- //
	{ false,L"ReverToGrass (5)" },{ true,L"RoadToRever (4)" },{ false,L"RoadToRever (5)" },{ true,L"RoadToRever (6)" },{ true,L"ReverToGrass (4)" },{ true,L"ReverToGrass (5)" },{ true,L"ReverToGrass (6)" },{ true,L"GrassToRever1 (4)" },{ false,L"GrassToRever1 (5)" },{ true,L"GrassToRever1 (6)" },
									// -------  90  --------- //
	{ false,L"ReverToGrass (5)" },{ true,L"RoadToRever (7)" },{ true,L"RoadToRever (8)" },{ true,L"RoadToRever (9)" },{ true,L"ReverToGrass (7)" },{ true,L"ReverToGrass (8)" },{ true,L"ReverToGrass (9)" },{ true,L"GrassToRever1 (7)" },{ true,L"GrassToRever1 (8)" },{ true,L"GrassToRever1 (9)" },
									// -------  100  --------- //
	{ false,L"ReverToHole (5)" },{ true,L"ReverToHole (1)" },{ true,L"ReverToHole (2)" },{ true,L"ReverToHole (3)" },{ true,L"GrassToRever2 (1)" },{ true,L"GrassToRever2 (2)" },{ true,L"GrassToRever2 (3)" },{ true,L"HoleToRever (1)" },{ true,L"HoleToRever (2)" },{ true,L"HoleToRever (3)" },
									// -------  110  --------- //
	{ false,L"ReverToHole (5)" },{ true,L"ReverToHole (4)" },{ true,L"ReverToHole (5)" },{ true,L"ReverToHole (6)" },{ true,L"GrassToRever2 (4)" },{ false,L"GrassToRever2 (5)" },{ true,L"GrassToRever2 (6)" },{ true,L"HoleToRever (4)" },{ true,L"HoleToRever (5)" },{ true,L"HoleToRever (6)" },
									// -------  120  --------- //
	{ false,L"ReverToHole (5)" },{ true,L"ReverToHole (7)" },{ true,L"ReverToHole (8)" },{ true,L"ReverToHole (9)" },{ true,L"GrassToRever2 (7)" },{ true,L"GrassToRever2 (8)" },{ true,L"GrassToRever2 (9)" },{ true,L"HoleToRever (7)" },{ true,L"HoleToRever (8)" },{ true,L"HoleToRever (9)" },
									// -------  130  --------- //
	{ false,L"ReverToRoad (5)" },{ true,L"ReverToRoad (1)" },{ true,L"ReverToRoad (2)" },{ true,L"ReverToRoad (3)" },{ false,L"BridgeToRiverD(1)" },{ false,L"BridgeToRiverD(2)" },{ false,L"BridgeToRiverD(3)" },{ false,L"BridgeToRiverW(1)" },{ false,L"BridgeToRiverW(2)" },{ false,L"BridgeToRiverW(3)" },
									// -------  140  --------- //
	{ false,L"ReverToRoad (5)" },{ true,L"ReverToRoad (4)" },{ true,L"ReverToRoad (5)" },{ true,L"ReverToRoad (6)" },{ false,L"BridgeToRiverD(4)" },{ false,L"BridgeToRiverD(5)" },{ false,L"BridgeToRiverD(6)" },{ false,L"BridgeToRiverW(4)" },{ false,L"BridgeToRiverW(5)" },{ false,L"BridgeToRiverW(6)" },
									// -------  150  --------- //
	{ false,L"ReverToRoad (5)" },{ true,L"ReverToRoad (7)" },{ true,L"ReverToRoad (8)" },{ true,L"ReverToRoad (9)" },{ false,L"BridgeToRiverD(7)" },{ false,L"BridgeToRiverD(8)" },{ false,L"BridgeToRiverD(9)" },{ false,L"BridgeToRiverW(7)" },{ false,L"BridgeToRiverW(8)" },{ false,L"BridgeToRiverW(9)" },
									// -------  160  --------- //
	{ false,L"None" },{ false,L"BridgeToClearD(1)" },{ false,L"BridgeToClearD(2)" },{ false,L"BridgeToClearD(3)" },{ false,L"BridgeToClearW(1)" },{ false,L"BridgeToClearW(2)" },{ false,L"BridgeToClearW(3)" },{ true,L"Tree1" },{ true,L"Tree2" },{ false,L"Grass3" },
									// -------  170  --------- //
	{ false,L"None" },{ false,L"BridgeToClearD(4)" },{ false,L"BridgeToClearD(5)" },{ false,L"BridgeToClearD(6)" },{ false,L"BridgeToClearW(4)" },{ false,L"BridgeToClearW(5)" },{ false,L"BridgeToClearW(6)" },{ true,L"Tree3" },{ true,L"Tree4" },{ false,L"Grass3" },
									// -------  180  --------- //
	{ false,L"None" },{ false,L"BridgeToClearD(7)" },{ false,L"BridgeToClearD(8)" },{ false,L"BridgeToClearD(9)" },{ false,L"BridgeToClearW(7)" },{ false,L"BridgeToClearW(8)" },{ false,L"BridgeToClearW(9)" },{ false,L"Grass3" },{ false,L"Grass3" },{ false,L"Grass3" },
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
