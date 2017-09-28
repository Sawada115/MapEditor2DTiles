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
const int MapOutPut::BUTTON_SIZE_X = 150;
const int MapOutPut::BUTTON_SIZE_Y = 50;



//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] サイズ
//!
//! @return 存在しない
//----------------------------------------------------------------------
MapOutPut::MapOutPut()
	:UI_ButtanBase(Vector2(150, 50))
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
	UI_ButtanBase::initialize(L"Resources/OutPutButton.png",buttonPos);
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
//! @param[in] 出力データ マップの横幅
//!
//! @return なし
//----------------------------------------------------------------------
void MapOutPut::OutPutCsv(std::vector<Tile*> tileData,int mapSizeX)
{
	// ファイルを開く
	ofstream ofs("MapData.csv");
	
	if (ofs)
	{
		int count = 0;
		for (auto itr = tileData.begin(); itr != tileData.end(); itr++)
		{
			count++;
			// データをまとめる
			int data = ((*itr)->getNum() + 1) * 10 + (int)(*itr)->getColision();
			// データの書き出し
			ofs << data << ",";
			// 改行する
			if (count >= mapSizeX)
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
bool MapOutPut::isPressed(int posX, int posY, std::vector<Tile*> tileData, int mapSizeX)
{
	if (UI_ButtanBase::isPressed(posX, posY))
	{
		OutPutCsv(tileData, mapSizeX);
		return true;
	}
	return false;

}
