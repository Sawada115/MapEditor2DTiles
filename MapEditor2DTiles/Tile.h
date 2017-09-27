/// <summary>
/// 概要　 タイル一枚
/// 作成者 GS1 04 牛山航平
/// </summary>

/* −− ヘッダーのインクルード −−−− */
#pragma once
#include "Obj2d.h"

class Tile:public Obj2d
{
public:
	Tile();
	virtual ~Tile();
	Tile& operator=(const Tile& tile);// コピーコンストラクタ

	// 初期化
	void initialize(int imageType ,DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// ゲット・セット
	bool getColision() { return m_isColision; };						// 当たるか
	void setColision(bool isColision) { m_isColision = isColision; };	//		どうか
	std::wstring getName() { return m_name; };					// 名
	void setName(std::wstring newName) { m_name = newName; };	// 前
	int getNum() { return m_num; };						// 画像ID


	// m_isColisionを変更
	bool changheColision();

	// タイルサイズ(縦横共通)
	const static float TILE_SIZE;

	// タイルに必要なデータ
	struct TileData
	{
		// あたりをとるかどうか
		bool isColision;

		// 使用する画像のファイル名
		const std::wstring fileNames;
	};


	// IDごとに必要なデータ
	static TileData m_datas[30];

private:

	// 名前
	std::wstring m_name;
	// あたりをとるかどうか
	bool m_isColision;

	int m_num;
};

