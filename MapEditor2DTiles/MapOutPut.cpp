//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapOutOut.cpp
//!
//! @brief  マップ出力クラス
//!
//! @date   日付　2017/10/01
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダーファイルのインクルード==============================================
#include "pch.h"
#include "MapOutPut.h"
#include <iostream> 
#include <string>
#include <fstream>  
#include <sstream>  
#include <WinBase.h>
#include <tchar.h>

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// 静的変数の初期化
const int MapOutPut::BUTTON_SIZE_X = 75;
const int MapOutPut::BUTTON_SIZE_Y = 25;



//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] サイズ
//!
//! @return 存在しない
//----------------------------------------------------------------------
MapOutPut::MapOutPut()
	:UI_Buttan(Vector2(BUTTON_SIZE_X, BUTTON_SIZE_Y))
{

}



//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] 存在しない
//!
//! @return 存在しない
//----------------------------------------------------------------------
MapOutPut::~MapOutPut()
{
}



//----------------------------------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] ボタン座標
//!
//! @return なし
//----------------------------------------------------------------------
void MapOutPut::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{
	UI_Buttan::initialize(L"Resources/OutPutButton.png", buttonPos);

	// ダイアログ設定
	GetCurrentDirectory(MAX_PATH, m_folderPath);
	memset(&m_ofn, 0, sizeof(OPENFILENAME));
	memset(m_filePath,NULL, MAX_PATH);
	memset(m_fileName, NULL, MAX_PATH);

	m_ofn.lStructSize = sizeof(OPENFILENAME);
	m_ofn.hwndOwner = NULL;
	m_ofn.lpstrInitialDir = m_folderPath;       // 初期フォルダ位置
	m_ofn.lpstrFile = m_filePath;				// 選択ファイル格納
	m_ofn.nMaxFile = MAX_PATH;
	m_ofn.lpstrFilter = TEXT("CSV(カンマ区切り)(*.csv)\0*.csv");
	m_ofn.lpstrTitle = TEXT("名前を付けて保存");
	m_ofn.Flags = OFN_FILEMUSTEXIST;
	m_ofn.lpstrFileTitle = m_fileName;			// 入力ファイル名
	m_ofn.nMaxFileTitle = MAX_PATH;
}

/// <summary>
/// ボタンを押したときの処理
/// </summary>
void MapOutPut::toActivate()
{

}






//----------------------------------------------------------------------
//! @brief タイルデータを出力
//!
//! @param[in] レイヤー番号 出力データ マップの横幅
//!
//! @return なし
//----------------------------------------------------------------------
void MapOutPut::OutPutCsv(int layerNum,std::vector<Tile*> tileData,Vector2 mapSize)
{
	// ファイル名の作成 (入力したファイル名＋Layer＋レイヤー番号＋.csv)
	TCHAR layeNum[MAX_PATH];
	TCHAR filePath[MAX_PATH];
	wsprintf(layeNum, TEXT("%d"), layerNum);
	memset(filePath, NULL, MAX_PATH);

	wcscat(filePath, m_filePath);
	wcscat(filePath, _T("Layer"));
	wcscat(filePath, layeNum);
	wcscat(filePath, _T(".csv"));

	// ファイルを開く
	ofstream ofs(filePath);
	
	if (ofs)
	{
		// マップの縦幅・横幅を出力
		ofs << mapSize.x << "," << mapSize.y << endl;

		int count = 0;
		for (auto itr = tileData.begin(); itr != tileData.end(); itr++)
		{
			count++;
			// データをまとめる
			int data = ((*itr)->getNum() + 1) * 10 + (int)(*itr)->getColision();
			// データの書き出し
			ofs << data << ",";
			// 改行する
			if (count >= mapSize.y)
			{
				count = 0;
				ofs << endl;
			}
		}
	}
	return;
}



//----------------------------------------------------------------------
//! @brief 出力ボタン処理
//!
//! @param[in] 座標X 座標Y
//!
//! @return なし
//----------------------------------------------------------------------
bool MapOutPut::isPressed(int posX, int posY )
{
	if (UI_Buttan::isPressed(posX, posY))
	{
		return true;
	}
	return false;
}



//----------------------------------------------------------------------
//! @brief 保存先を設定
//!
//! @param[in] なし
//!
//! @return 設定できたか
//----------------------------------------------------------------------
bool MapOutPut::SetSaveFilePath()
{	
	// ダイアログを開く
	bool result = GetSaveFileName(&m_ofn);
	// フォルダ位置を元に戻す
	SetCurrentDirectory(m_folderPath);
	return result;
}