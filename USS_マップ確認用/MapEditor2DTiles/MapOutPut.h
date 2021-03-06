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
#include "MakedMap.h"

// クラスの宣言
class MapOutPut
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
	// 描画処理
	void Draw();

	// タイルデータを出力
	void OutPutCsv(int layerNum ,std::vector<Tile*> tileData, DirectX::SimpleMath::Vector2 mapSize);

	struct TileData
	{
		int imageType;			// 画像番号
		bool isColision;		// 当たり判定
	};

	// マップデータの読み込み
	std::vector<TileData> InPutCsv(std::string fileName);

	// 出力ボタン処理
	bool PressedButton(int posX, int posY);
private:
	Obj2d m_outPutButton;			// 出力ボタン画像
};

