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

	m_Tile.initialize(1, Vector2(600.0f, 100.0f));
	if (m_Tile.getColision() == true)
	{
		m_Collison_Status.initialize(L"Resources/ON.png", Collision_Pos);
	}
	else
	{
		m_Collison_Status.initialize(L"Resources/OFF.png", Collision_Pos);
	}
	Collision_Pos = Vector2(725.0, 215.0);

}


/// <summary>
/// 描画
/// </summary>
void StatusTile::draw()
{

	Obj2d::draw();

	m_Tile.draw();
	if (m_Tile.getColision() == true)
	{
		m_Collison_Status.initialize(L"Resources/ON.png", Collision_Pos);
	}
	else
	{
		m_Collison_Status.initialize(L"Resources/OFF.png", Collision_Pos);
	}
	m_Collison_Status.draw();

	
	


}

// タイルデータの取得
void StatusTile::TileChange(Tile* tile)
{
	m_Tile.setNum(tile->getNum());
	m_Tile.initialize(m_Tile.getNum(), m_Tile.getPos());
}


void StatusTile::GetCollision(Tile* tile)
{
	m_Tile.setColision(tile->getColision());
}

void StatusTile::CollisionChange(int posX, int posY)
{
	if (680.0f < posX && posX < 770.0f && 
		198.0f < posY && posY< 230.0f)
	{
		if (m_Tile.getColision() == true)
		{
			m_Tile.setColision(false);
		}
		else
		{
			m_Tile.setColision(true);
		}
	}
}