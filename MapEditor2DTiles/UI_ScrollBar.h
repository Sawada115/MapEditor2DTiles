/// <summary>
/// 概要　 スクロールバー
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#pragma once
#include "UI_Button.h"


class UI_ScrollBar : public UI_Button
{
public:
	UI_ScrollBar();
	virtual ~UI_ScrollBar();

	// 初期化
	void initialize(const wchar_t* imageFileName, 
							const wchar_t* railImageFileName,
							bool isVertical,
							DirectX::SimpleMath::Vector2 barPos = DirectX::SimpleMath::Vector2(),
							int stage = 1);

	// 更新
	void upDate(DirectX::Mouse::State mouse);

	// 描画
	void draw() { m_railImage->draw(); UI_Button::draw(); };

	// セット
	void setScale(DirectX::XMFLOAT2 scale); // スケーリング
	void setPosition(DirectX::SimpleMath::Vector2 pos) { m_railImage->setPosition(pos); };	// 表示位置
	void setStage(int stage) { m_stage = stage; barSizeCalc(); };
	// ゲット
	int getStageNow() { return m_stageNow; };
	bool getIsDrag() { return m_dragStart; };

	// バーの大きさの計算
	void barSizeCalc();

private:
	// バーの位置の計算
	void barPositionCalc();
	// マウス情報からバーの位置を変える
	void setBarPositionFromMousePosition(DirectX::Mouse::State mouse);


	// レールの初期サイズ(縦横共通)
	static const float DEFOULT_RAIL_SIZE;



	// レール部分の画像
	Obj2d* m_railImage;
	DirectX::SimpleMath::Vector2 m_leftUpPosition;
	float m_railLengh;
	float m_railOneStageLengh;

	// 何段階で動くか
	int m_stage;
	// 今、何段階目か
	int m_stageNow;

	// 縦向きのバーか否か
	bool m_isVertical;

	// ドラッグ開始フラグ
	bool m_dragStart;

	// 1フレーム前のマウス情報
	DirectX::Mouse::State m_oldMouse;

};

