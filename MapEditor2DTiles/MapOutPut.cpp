//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   TileManager.cpp
//!
//! @brief  タイルマネージャークラス
//!
//! @date   日付　2017/09/27
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
	:UI_Buttan(Vector2(150, 50))
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
	UI_Buttan::initialize(L"Resources/OutPutButton.png",buttonPos);
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
void MapOutPut::OutPutCsv(HWND hWnd,int layerNum,std::vector<Tile*> tileData,Vector2 mapSize)
{
	//HWND hWnd = NULL;
	static OPENFILENAME     ofn;
	static TCHAR            szPath[MAX_PATH];	// 初期フォルダ位置
	static TCHAR            szFile[MAX_PATH];   // 選択したファイル名 Staticなので関数外でも生きているが，もっかい呼ぶと死ぬ。
	static TCHAR            szFileName[MAX_PATH];	// 初期フォルダ位置
	static char				szFname[MAX_PATH];  // 出力用のファイル名 charの方が扱いやすいことがある


	if (szPath[0] == TEXT('\0')) {
		GetCurrentDirectory(MAX_PATH, szPath);
	}
	if (ofn.lStructSize == 0) {
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrInitialDir = szPath;       // 初期フォルダ位置
		ofn.lpstrFile = szFile;				// 選択ファイル格納
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrFilter =
			TEXT("すべてのファイル(*.*)\0*.*\0");
		ofn.lpstrTitle = TEXT("ファイルを選択します。");
		ofn.Flags = OFN_FILEMUSTEXIST;
		ofn.lpstrFileTitle = szFileName;
		ofn.nMaxFileTitle = MAX_PATH;
	}
	if (GetSaveFileName(&ofn)) {
		MessageBox(hWnd, szFileName, TEXT("ファイルを開く"), MB_OK);
	}
	else {
		// cancelled
		//return "saved_image.bmp";
	}

	//// ファイルを開く
	//string fileName = "MapDate";
	//string layerName = "Layer" + std::to_string(layerNum);

	//ofstream ofs(fileName + layerName + ".csv");
	//
	//if (ofs)
	//{
	//	// マップの縦幅・横幅を出力
	//	ofs << mapSize.x << "," << mapSize.y << endl;

	//	int count = 0;
	//	for (auto itr = tileData.begin(); itr != tileData.end(); itr++)
	//	{
	//		count++;
	//		// データをまとめる
	//		int data = ((*itr)->getNum() + 1) * 10 + (int)(*itr)->getColision();
	//		// データの書き出し
	//		ofs << data << ",";
	//		// 改行する
	//		if (count >= mapSize.x)
	//		{
	//			count = 0;
	//			ofs << endl;
	//		}
	//	}
	//}
	//return;
}



vector<MapOutPut::TileData> MapOutPut::InPutCsv(std::string fileName)
{
	// ファイルを開く
	ifstream ifs(fileName + ".csv");
	string str;
	int i = 0;

	vector<TileData> tileData;

	if (ifs)
	{
		string token;
		Vector2 mapSize;

		// マップサイズの読み込み
		if (getline(ifs, str))
		{
			istringstream stream(str);
			getline(stream, token, ',');
			mapSize.x = atoi(token.c_str());
			getline(stream, token, ',');
			mapSize.y = atoi(token.c_str());
		}

		tileData.resize(mapSize.x * mapSize.y);
		// タイルデータの読み込み
		while (getline(ifs, str))
		{
			istringstream stream(str);
			while (getline(stream, token, ','))
			{
				int num = atoi(token.c_str());
				tileData[i].imageType = num / 10;
				tileData[i].isColision = num % 10;
				i++;
			}
		}
	}
	return tileData;
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
