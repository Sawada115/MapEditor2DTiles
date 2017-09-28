//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapOutPut.h
//!
//! @brief  マップ出力クラス
//!
//! @date   日付　2017/09/27
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

// ヘッダーファイルのインクルード==============================================
#include "UI_Buttan.h"
#include "MakedMap.h"

// クラスの宣言
class MapOutPut:public UI_ButtanBase
{
	// 静的変数の宣言
private:
	static const int BUTTON_SIZE_X;		// ボタンの横幅
	static const int BUTTON_SIZE_Y;		// ボタンの縦幅
public:
	// コンストラクタ
	MapOutPut();
	// デストラクタ
	~MapOutPut();

	// 初期化処理
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);

	// ボタンが押されたら呼ぶ処理
	void toActivate();

	// タイルデータを出力
	void OutPutCsv(std::vector<Tile*> tileData,int mapSizeX);
	// 出力ボタン処理
	bool isPressed(int posX, int posY, std::vector<Tile*> tileData, int mapSizeX);
private:
	Obj2d m_outPutButton;			// 出力ボタン画像
};

