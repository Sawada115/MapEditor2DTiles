/// <summary>
/// 概要　 USS_Editorで作ったステージを使用するためのヘッダ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include<string>
#include<fstream>
#include "Tile.h"

// マップ使用用クラス
class USS_Explorer
{
public:
	USS_Explorer();
	~USS_Explorer();

	// マップのCSVデータを読み込む

	// マップを描画する

	// タイルとの当たり判定をとる

	// マップをスクロールする

private:

};

// 読み込む用タイルクラス
class LoadedTile
{
public:
	LoadedTile();
	~LoadedTile();

private:

};

