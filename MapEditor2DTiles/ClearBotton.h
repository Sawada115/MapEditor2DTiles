//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.h
//!
//! @brief  クリアボタンクラス
//!
//! @date   日付　2017/09/29
//!
//! @author 制作者名 菅野
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

// ヘッダーファイルのインクルード==============================================
#include <vector>
#include "Obj2d.h"

// クラスの宣言
class ClearBotton
{
	// 静的変数の宣言
private:
	static const int BUTTON_SIZE_X;		// ボタンの横幅
	static const int BUTTON_SIZE_Y;		// ボタンの縦幅

public:
	// コンストラクタ
	ClearBotton();
	// デストラクタ
	~ClearBotton();

	// 初期化処理
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);
	// 描画処理
	void Draw();

	// ボタン処理
	bool PressedButton(int posX, int posY);
	// ボタンの状態取得
	int Get_ClearFlag();

private:
	//ボタン
	Obj2d m_ClearBotton_ON;
	Obj2d m_ClearBotton_OFF;

	//透過するかどうか
	int m_ClearFlag;
};