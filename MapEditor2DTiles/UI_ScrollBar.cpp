/// <summary>
/// 概要　 スクロールバー
/// 作成者 GS1 04 牛山航平
/// </summary>

/* －－ ヘッダーのインクルード －－－－ */
#include "pch.h"
#include "UI_ScrollBar.h"

// 名前空間を開放
using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// レールの初期サイズ(縦横共通)
const float UI_ScrollBar::DEFOULT_RAIL_SIZE = 15.0f;


UI_ScrollBar::UI_ScrollBar()
	:UI_Button(Vector2(1.0f,1.0f))
	,m_railImage(nullptr)
{
	
}


UI_ScrollBar::~UI_ScrollBar()
{
	if (m_railImage != nullptr)delete m_railImage;
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="imageFileName">読み込む画像のファイル名</param>
/// <param name="railImageFileName">レール部分のファイル名</param>
/// <param name="barPos">初期位置</param>
/// <param name="stage">何段階なのか</param>
void UI_ScrollBar::initialize(	const wchar_t * imageFileName,
								const wchar_t* railImageFileName,
								bool isVertical,
								Vector2 barPos,
								int stage)
{
	UI_Button::initialize(imageFileName, barPos);

	// レール部分の初期化
	m_railImage = new Obj2d;
	m_railImage->initialize(railImageFileName, barPos);

	// 何段階で動くか
	m_stage = stage;
	// 今、何段階目か
	m_stageNow = 0;

	// 縦か横か
	m_isVertical = isVertical;

	// 最初はドラッグしていない
	m_dragStart = false;

	// 位置計算
	barSizeCalc();
}

/// <summary>
/// 更新
/// </summary>
/// <param name="m_mouse">マウス情報</param>
void UI_ScrollBar::upDate(DirectX::Mouse::State mouse)
{
	UI_Button::upDate(mouse);

	// ドラッグし始め
	if (m_mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::PRESSED)
	{
		if (m_isPressed)
		{
			m_dragStart = true;
		}

	}
	
	// ドラッグ中
	if (m_dragStart && mouse.leftButton)
	{
		// バーの位置を変える
		setBarPositionFromMousePosition(mouse);
	}
	else
	{
		m_dragStart = false;
	}

	// マウス情報を記憶
	m_oldMouse = mouse;
}

/// <summary>
/// スケールの変更
/// </summary>
/// <param name="scale"></param>
void UI_ScrollBar::setScale(XMFLOAT2 scale)
{
	// レール
	m_railImage->setScale(scale);

	// 本体のサイズの変更
	barSizeCalc();
}

/// <summary>
///	バーの大きさを計算する
/// </summary>
void UI_ScrollBar::barSizeCalc()
{
	// バーの大きさ
	XMFLOAT2 barScale = XMFLOAT2( m_railImage->getScale().x, m_railImage->getScale().y);

	// 縦向き
	if (m_isVertical)
	{
		barScale.y /= m_stage;
	}	
	// 横向き
	else
	{
		barScale.x /= m_stage;
	}

	// セットする
	Obj2d::setScale(barScale);

	BUTTON_SIZE_X = this->getScale().x * DEFOULT_RAIL_SIZE;
	BUTTON_SIZE_Y = this->getScale().y * DEFOULT_RAIL_SIZE;

	barPositionCalc();
}

/// <summary>
/// バーの位置の計算
/// </summary>
void UI_ScrollBar::barPositionCalc()
{
	// 縦の場合
	if (m_isVertical)
	{
		m_railLengh = m_railImage->getScale().y * DEFOULT_RAIL_SIZE;
	}
	// 横の場合
	else
	{
		m_railLengh = m_railImage->getScale().x * DEFOULT_RAIL_SIZE;
	}

	// 1メモリ分の長さ
	m_railOneStageLengh = m_railLengh / m_stage;

	// 場所を算出
	XMFLOAT2 position = m_railImage->getPos();
	// 縦の場合
	if (m_isVertical)
	{
		position.y -= m_railLengh / 2;
		m_leftUpPosition = position;// 左上の頂点
		position.y += m_stageNow * m_railOneStageLengh + m_railOneStageLengh / 2;
	}
	// 横の場合
	else
	{
		position.x -= m_railLengh / 2;
		m_leftUpPosition = position;// 左上の頂点
		position.x += m_stageNow * m_railOneStageLengh + m_railOneStageLengh / 2;
	}
	
	Obj2d::setPosition(position);
}

/// <summary>
/// マウス情報からバーの位置を変える
/// </summary>
/// <param name="mouse">マウス情報</param>
void UI_ScrollBar::setBarPositionFromMousePosition(DirectX::Mouse::State mouse)
{
	int i = m_stage;

	// 縦向き
	if (m_isVertical)
	{
		// クリックされた位置を探す(縦)
		while (m_leftUpPosition.y < mouse.y && m_leftUpPosition.y + i*m_railOneStageLengh > mouse.y)
		{
			i--;
		}
	}
	// 横向き
	else
	{
		// クリックされた位置を探す(横)
		while (m_leftUpPosition.x < mouse.x && m_leftUpPosition.x + i*m_railOneStageLengh > mouse.x)
		{
			i--;
		}
	}

	// マップ外ならすぐ終わり、
	if (i >= m_stage || i < 0)
	{
		return;
	}

	// クリック位置を設定
	m_stageNow = i;

	// 位置を設定しなおす
	barPositionCalc();

}
