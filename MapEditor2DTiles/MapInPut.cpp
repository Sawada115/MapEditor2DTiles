//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   MapInPut.cpp
//!
//! @brief  マップ読み込みクラス
//!
//! @date   日付　2017/10/01
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダーファイルのインクルード==============================================
#include "pch.h"
#include "MapInPut.h"
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
const int MapInPut::BUTTON_SIZE_X = 75;
const int MapInPut::BUTTON_SIZE_Y = 25;



//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] サイズ
//!
//! @return 存在しない
//----------------------------------------------------------------------
MapInPut::MapInPut()
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
MapInPut::~MapInPut()
{
}



//----------------------------------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] ボタン座標
//!
//! @return なし
//----------------------------------------------------------------------
void MapInPut::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{
	UI_Buttan::initialize(L"Resources/InPutButton.png", buttonPos);

	// ダイアログ設定
	GetCurrentDirectory(MAX_PATH, m_folderPath);
	memset(&m_ofn, 0, sizeof(OPENFILENAME));
	memset(m_filePath, NULL, MAX_PATH);
	memset(m_fileName, NULL, MAX_PATH);

	m_ofn.lStructSize = sizeof(OPENFILENAME);
	m_ofn.hwndOwner = NULL;
	m_ofn.lpstrInitialDir = m_folderPath;       // 初期フォルダ位置
	m_ofn.lpstrFile = m_filePath;				// 選択ファイル格納
	m_ofn.nMaxFile = MAX_PATH;
	m_ofn.lpstrFilter = TEXT("CSV(カンマ区切り)(*.csv)\0*.csv");
	m_ofn.lpstrTitle = TEXT("ファイルを開く");
	m_ofn.Flags = OFN_FILEMUSTEXIST;
	m_ofn.lpstrFileTitle = m_fileName;			// 入力ファイル名
	m_ofn.nMaxFileTitle = MAX_PATH;
}

/// <summary>
/// ボタンを押したときの処理
/// </summary>
void MapInPut::toActivate()
{

}



//----------------------------------------------------------------------
//! @brief マップを読み込む
//!
//! @param[in] 読み込んだデータを受け取る変数
//!
//! @return 設定できたか
//----------------------------------------------------------------------
void MapInPut::InPutCsv(MakedMap* map)
{
	// ファイルを開く
	m_ofn;
	ifstream ifs(m_ofn.lpstrFile);
	string str;
	int i = 0;

	Vector2 mapSize;

	if (ifs)
	{
		string token;

		// マップサイズの読み込み
		if (getline(ifs, str))
		{
			istringstream stream(str);
			getline(stream, token, ',');
			mapSize.x = atoi(token.c_str());
			getline(stream, token, ',');
			mapSize.y = atoi(token.c_str());
			map->mapReSize(mapSize.x, mapSize.y);
		}

		vector<TileData> tileData;
		tileData.resize(mapSize.x*mapSize.y);

		// タイルデータの読み込み
		while (getline(ifs, str))
		{
			istringstream stream(str);
			while (getline(stream, token, ','))
			{
				int num = atoi(token.c_str());
				tileData[i].imageType = num / 10 - 1;
				tileData[i].isColision = num % 10;
				i++;
			}
		}

		for (int i = 0; i < (int)tileData.size(); i++)
		{
			int tileID[2] = { i / mapSize.y,i % (int)mapSize.y };
			Tile* tile = new Tile();
			tile->initialize(tileData[i].imageType);
			tile->setColision(tileData[i].isColision);
			map->changTile(tileID, tile);
		}
	}
}



//----------------------------------------------------------------------
//! @brief 出力ボタン処理
//!
//! @param[in] 座標X 座標Y
//!
//! @return なし
//----------------------------------------------------------------------
bool MapInPut::isPressed(int posX, int posY)
{
	if (UI_Buttan::isPressed(posX, posY))
	{
		return true;
	}
	return false;
}



//----------------------------------------------------------------------
//! @brief 開くファイル設定
//!
//! @param[in] なし
//!
//! @return 設定できたか
//----------------------------------------------------------------------
bool MapInPut::SetOpenFilePath()
{
	// ダイアログを開く
	bool result = GetOpenFileName(&m_ofn);
	
	// フォルダ位置を元に戻す
	SetCurrentDirectory(m_folderPath);
	return result;
}
