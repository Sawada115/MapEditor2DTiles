/// <summary>
/// 概要　 タイルのコリジョンチェックのオンオフを切り替えるボタン
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include "ColisionCheckButtan.h"

// 名前空間の開放
using namespace DirectX::SimpleMath;

// 静的変数の初期化
const int ColisionCheckButtan::BUTTON_SIZE_X = 150;
const int ColisionCheckButtan::BUTTON_SIZE_Y = 50;


ColisionCheckButtan::ColisionCheckButtan()
{
}


ColisionCheckButtan::~ColisionCheckButtan()
{
}

void ColisionCheckButtan::initialize(DirectX::SimpleMath::Vector2 pos)
{
	Obj2d::initialize(L"Resources/OutPutButton.png", pos);
	setColer(DirectX::Colors::Blue);
	//setScale(DirectX::XMFLOAT2(0.5f,0.5f));
}

bool ColisionCheckButtan::PressedButton(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);

	Vector2 buttonPos = this->getPos();

	if (buttonPos.x + buttonHalfSize.x >= posX &&
		buttonPos.x - buttonHalfSize.x <= posX &&
		buttonPos.y + buttonHalfSize.y >= posY &&
		buttonPos.y - buttonHalfSize.y <= posY)
	{
		return true;
	}
	return false;
}
