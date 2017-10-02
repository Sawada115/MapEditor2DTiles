//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.h
//!
//! @brief  レイヤーマネージャークラス
//!
//! @date   日付　2017/09/28
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

// ヘッダーファイルのインクルード==============================================
#include <vector>
#include "Obj2d.h"

// クラスの宣言
class LayerManager
{
	// 静的変数の宣言
private:
	static const int BUTTON_SIZE_X;		// ボタンの横幅
	static const int BUTTON_SIZE_Y;		// ボタンの縦幅
	static const int LAYER_MAX_NUM;			// レイヤーの数
public:
	// コンストラクタ
	LayerManager();
	// デストラクタ
	~LayerManager();

	// 初期化処理
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);
	// 描画処理
	void Draw();

	// ボタン処理
	bool PressedButton(int posX, int posY);
	int GetSelectLayer() { return m_selectLayer; }

	void LayerDelete();
private:
	std::vector<Obj2d> m_layerButton;			// レイヤーボタン画像
	int m_layerNum;								// レイヤーの数
	int m_selectLayer;							// 選択中のレイヤー番号
};
