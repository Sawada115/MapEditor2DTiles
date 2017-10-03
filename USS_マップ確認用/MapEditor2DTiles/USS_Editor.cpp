/// <summary>
/// 概要　 USS_Editorで作ったステージを使用するための機能
/// 作成者 GS1 04 澤田
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include "USS_Editor.h"
#include <iostream> 
#include <string>
#include <fstream>  
#include <sstream>  

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;


// ----- マップ使用用クラス ------------------------------------------------------------------------------
USS_Explorer::USS_Explorer()
{
}

USS_Explorer::~USS_Explorer()
{
}

void USS_Explorer::Initialize(std::string fileName, int layerNum, DirectX::SimpleMath::Vector2 mapPos)
{
	m_map.resize(layerNum);
	m_scrollPower.resize(layerNum);
	for (int i = 0; i < layerNum; i++)
	{
		InPutCsv(i, fileName);

		for (int j = 0; j < (int)m_map[i].size(); j++)
			m_map[i][j].setPosition(Vector2(mapPos.x + Tile::TILE_SIZE * (j / (int)m_mapSize.y), mapPos.y + Tile::TILE_SIZE * (j % (int)m_mapSize.y)));

		m_scrollPower[i] = 1.0f;
	}
}

void USS_Explorer::Draw()
{
	for (auto itr = m_map.end()-1; itr != m_map.begin(); itr--)
		for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
			(*itr2).draw();
}

bool USS_Explorer::GetTileColision(DirectX::SimpleMath::Vector2 pos)
{
	Vector2 mapHalfSize(15, 15);
	for (auto itr = m_map.begin(); itr != m_map.end(); itr++)
	{
		for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
		{
			Vector2 mapPos = (*itr2).getPos();

			if (mapPos.x + mapHalfSize.x >= pos.x&&
				mapPos.x - mapHalfSize.x <= pos.x&&
				mapPos.y + mapHalfSize.y >= pos.y&&
				mapPos.y - mapHalfSize.y <= pos.y)
			{
				if ((itr2)->getNum())
					return (itr2)->getColision();
			}
		}
	}
	return false;
}

void USS_Explorer::MapScroll(DirectX::SimpleMath::Vector2 vec)
{
	int i = 0;
	for (auto itr = m_map.begin(); itr != m_map.end(); itr++)
	{
		Vector2 moveVec = vec * m_scrollPower[i];
		for (auto itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++)
		{
			Vector2 mapPos = (*itr2).getPos();
			(*itr2).setPosition(mapPos + moveVec);
		}
		i++;;
	}
}

void USS_Explorer::InPutCsv(int layer,std::string fileName)
{
	// ファイルを開く
	std::string filePath = fileName + "\\" + fileName + "Layer" + std::to_string(layer + 1) + ".csv";
	ifstream ifs(filePath);
	string str;
	int i = 0;

	if (ifs)
	{
		string token;

		// マップサイズの読み込み
		if (getline(ifs, str))
		{
			istringstream stream(str);
			getline(stream, token, ',');
			m_mapSize.x = atoi(token.c_str());
			getline(stream, token, ',');
			m_mapSize.y = atoi(token.c_str());
		}

		m_map[layer].resize(m_mapSize.x * m_mapSize.y);
		// タイルデータの読み込み
		while (getline(ifs, str))
		{
			istringstream stream(str);
			while (getline(stream, token, ','))
			{
				int num = atoi(token.c_str());
				m_map[layer][i].initialize(num / 10 - 1);
				m_map[layer][i].setColision(num % 10);
				i++;
			}
		}
	}
}