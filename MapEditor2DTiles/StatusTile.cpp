#include "pch.h"
#include "StatusTile.h"
#include "iostream"

using namespace DirectX::SimpleMath;
using namespace std;

StatusTile::StatusTile()
{
	
	

}


StatusTile::~StatusTile()
{
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="pos">初期位置</param>
void StatusTile::initialize(Vector2 pos)
{
	Obj2d::initialize(L"Resources/BackImage2.png", pos);

	m_Tile.initialize(0, Vector2(600.0f, 100.0f));

	
	Collision_Pos = Vector2(725.0, 215.0);

	m_Collison_ON.initialize(L"Resources/ON.png", Collision_Pos);
	m_Collison_OFF.initialize(L"Resources/OFF.png", Collision_Pos);
	

}


/// <summary>
/// 描画
/// </summary>
void StatusTile::draw()
{


	Obj2d::draw();

	m_Tile.draw();
	

	if (m_Tile.getColision())
	{
		m_Collison_ON.draw();
	}
	else
	{
		m_Collison_OFF.draw();
	}

	
	


}

// タイルデータの取得
void StatusTile::TileChange(Tile* tile)
{
	m_Tile.setNum(tile->getNum());
	m_Tile.initialize(m_Tile.getNum(), m_Tile.getPos());
	m_Tile.setColision(tile->getColision());
	tile_name = tile->getName();
}





void StatusTile::GetCollision(Tile* tile)
{
	m_Tile.setColision(tile->getColision());
}


void StatusTile::CollisionChange(int posX, int posY, Tile* tile)
{
	if (680.0f < posX && posX < 770.0f && 
		198.0f < posY && posY< 230.0f)
	{
		if (m_Tile.getColision() == true)
		{
			Tile::m_datas[tile->getNum()].isColision = false;
			tile->setColision(false);
			m_Tile.setColision(false);
		}
		else
		{
			Tile::m_datas[tile->getNum()].isColision = true;
			tile->setColision(true);
			m_Tile.setColision(true);
		}
	}
}