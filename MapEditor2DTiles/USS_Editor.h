/// <summary>
/// 概要　 USS_Editorで作ったステージを使用するためのヘッダ
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include<string>
#include<fstream>				

//void importData(std::string filename)
//{
//	std::ifstream ifs(filename);
//	std::string str;
//
//	int i;
//	if (!ifs)
//	{
//		for (i = 0; i < MAX_BACK_BALL; i++)
//		{
//			g_map[i / 20][i % 20] = 4;
//		}
//		return;
//	}
//
//	i = 0;
//	while (getline(ifs, str))
//	{
//		std::string token;
//		istringstream stream(str);
//
//		// １行のうち、文字列とコンマを分割する
//		while (getline(stream, token, ','))
//		{
//			// 全て文字列として読み込まれるため数値は変換が必要
//			g_map[i / 20][i % 20] = atoi(token.c_str());
//			i++;
//		}
//	}
//}
