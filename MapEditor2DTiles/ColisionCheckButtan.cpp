/// <summary>
/// 概要　 タイルのコリジョンチェックのオンオフを切り替えるボタン
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include "ColisionCheckButtan.h"

// 名前空間の開放
using namespace DirectX::SimpleMath;

ColisionCheckButtan::ColisionCheckButtan()
	:UI_ButtanBase(Vector2(150,50))
{

}


ColisionCheckButtan::~ColisionCheckButtan()
{
}

void ColisionCheckButtan::initialize(DirectX::SimpleMath::Vector2 pos)
{
	Obj2d::initialize(L"Resources/OutPutButton.png", pos);
	setColer(DirectX::Colors::Blue);
}

void ColisionCheckButtan::toActivate()
{
	Tile::changheClisionCheck();
}