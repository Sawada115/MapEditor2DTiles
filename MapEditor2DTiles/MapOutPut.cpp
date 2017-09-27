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

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return 存在しない
//----------------------------------------------------------------------
MapOutPut::MapOutPut()
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
