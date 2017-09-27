/// <summary>
/// 概要　 タイル一枚
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"

class Tile:public Obj2d
{
public:
	Tile();
	virtual ~Tile();
	//Tile operator=(const Tile& tile);// コピーコンストラクタ

	// 初期化
	void initialize(int imageType,int imageID ,DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// ゲット・セット
	bool getColision() { return m_isColision; };						// 当たるか
	bool setColision(bool isColision) { m_isColision = isColision; };	//		どうか
	std::wstring getName() { return m_name; };					// 名
	bool setName(std::wstring newName) { m_name = newName; };	// 前


	// m_isColisionを変更
	bool changheColision();

	// タイルサイズ(縦横共通)
	const static float TILE_SIZE;

private:

	// タイルに必要なデータ
	struct TileData
	{
		// あたりをとるかどうか
		bool isColision;

		// 使用する画像のファイル名
		const std::wstring fileNames;
	};

	// 名前
	std::wstring m_name;
	// IDごとに必要なデータ
	static TileData m_datas[5];
	// あたりをとるかどうか
	bool m_isColision;
};

