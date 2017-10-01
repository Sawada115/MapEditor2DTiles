//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapInPut.h
//!
//! @brief  マップ読み込みクラス
//!
//! @date   日付　2017/10/01
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

// ヘッダーファイルのインクルード==============================================
#include <Windows.h>
#include <Commdlg.h>
#include "UI_Buttan.h"
#include "MakedMap.h"

// クラスの宣言
class MapInPut :public UI_Buttan
{
	// 静的変数の宣言
private:
	static const int BUTTON_SIZE_X;		// ボタンの横幅
	static const int BUTTON_SIZE_Y;		// ボタンの縦幅
public:
	// コンストラクタ
	MapInPut();
	// デストラクタ
	~MapInPut();

	// 初期化処理
	void Initialize(DirectX::SimpleMath::Vector2 buttonPos);

	// ボタンが押されたら呼ぶ処理
	void toActivate();

	// 出力ボタン処理
	bool isPressed(int posX, int posY);

	// 開くファイルを設定
	bool SetOpenFilePath();

	struct TileData
	{
		int imageType;			// 画像番号
		bool isColision;		// 当たり判定
	};

	// マップデータの読み込み
	void InPutCsv(MakedMap* map);

private:
	Obj2d m_outPutButton;			// 出力ボタン画像

	OPENFILENAME     m_ofn;						// ダイアログ用構造体
	TCHAR            m_folderPath[MAX_PATH];	// 初期フォルダ位置
	TCHAR            m_filePath[MAX_PATH];		// 選択したファイル位置
	TCHAR            m_fileName[MAX_PATH];		// ファイル名
};


