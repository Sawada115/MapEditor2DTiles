/// <summary>
/// 概要　 タイル一枚
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "Obj2d.h"

// ----- タイルのベース --------------------------------------------------------------------------------
class TileBase : public Obj2d
{
public:
	TileBase();
	virtual ~TileBase();

	// 初期化
	void initialize(int imageType, DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// ゲット・セット
	bool getColision() { return m_isColision; };						// 当たるか
	void setColision(bool isColision) { m_isColision = isColision; };	//		どうか
	int getNum() { return m_num; };						// 画像ID
	void setNum(int num) { m_num = num; };

	// m_isColisionを変更
	bool changheColision();

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
	static TileData m_datas[180];


protected:
	// あたりをとるかどうか
	bool m_isColision;

	int m_num;

};



// ----- エディターで使うタイル -------------------------------------------------------------------------
class Tile:public TileBase
{
public:
	Tile();
	virtual ~Tile();

	// 初期化
	void initialize(int imageType ,DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// 描画
	void draw();

	// ゲット・セット
	std::wstring getName() { return m_name; };					// 名
	void setName(std::wstring newName) { m_name = newName; };	// 前

	// コリジョンチェックフラグをセットする
	static void setClisionCheck(bool check) { m_isCheckedColision = check; };
	static void changheClisionCheck();


private:

	// 名前
	std::wstring m_name;

	// コリジョンが働いているかを見た目で確認するか
	static bool m_isCheckedColision;
};

