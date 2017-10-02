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
void StatusTile::initialize(Vector2 BackImage_pos, Vector2 Tile_Pos, Vector2 Collision_Pos)
{
	Obj2d::initialize(L"Resources/BackImage2.png", BackImage_pos);

	m_Tile.initialize(0, Tile_Pos);

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
	Vector2 pos = m_Collison_ON.getPos();

	if (pos.x - 45 < posX && posX < pos.x + 45 &&
		pos.y - 15 < posY && posY < pos.y + 15)
	{
		if (m_Tile.getColision() == true)
		{
			TileBase::m_datas[tile->getNum()].isColision = false;
			tile->setColision(false);
			m_Tile.setColision(false);
		}
		else
		{
			TileBase::m_datas[tile->getNum()].isColision = true;
			tile->setColision(true);
			m_Tile.setColision(true);
		}
	}
}