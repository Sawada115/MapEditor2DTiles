/// <summary>
/// 概要　 選択中のチップ表示
/// 作成者 GS1 14　菅野 悠二 
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"
#include "string.h"
#include "Tile.h"

class StatusTile : public Obj2d
{
public:
	StatusTile();
	virtual ~StatusTile();

	// 初期化
	void initialize(DirectX::SimpleMath::Vector2 BackImage_pos, 
		DirectX::SimpleMath::Vector2 Tile_Pos, 
		DirectX::SimpleMath::Vector2 Collision_Pos);

	// タイルデータの取得
	void TileChange(Tile* tile);		//選択中のタイルデータの取得

	void CollisionChange(int posX, int posY, Tile* tile);

	void GetCollision(Tile* tile);	//選択中のタイルデータのCollision取得


	// 描画
	void draw();

private:
	Obj2d m_backImage;			//背景
	Obj2d m_Collison_ON;	//あたり判定の状態表示ON
	Obj2d m_Collison_OFF;	//あたり判定の状態表示OFF

	std::wstring tile_name;					//選択中のタイルの名前

	Tile m_Tile;							//選択中のタイル
	DirectX::SimpleMath::Vector2 name_Pos;	//選択中のタイルの名前の表示座標

};
