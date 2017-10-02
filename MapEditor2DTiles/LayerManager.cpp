//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.cpp
//!
//! @brief  レイヤーマネージャークラス
//!
//! @date   日付　2017/09/28
//!
//! @author 制作者名 澤田
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダーファイルのインクルード==============================================
#include "pch.h"
#include "LayerManager.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// 静的変数の初期化
const int LayerManager::BUTTON_SIZE_X = 75;
const int LayerManager::BUTTON_SIZE_Y = 25;
const int LayerManager::LAYER_MAX_NUM = 5;


//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return 存在しない
//----------------------------------------------------------------------
LayerManager::LayerManager()
{
}



//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] 存在しない
//!
//! @return 存在しない
//----------------------------------------------------------------------
LayerManager::~LayerManager()
{
}



//----------------------------------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] ボタン座標
//!
//! @return なし
//----------------------------------------------------------------------
void LayerManager::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{
	m_layerNum = 1;
	m_layerButton.resize(LAYER_MAX_NUM);

	for (int i = 0; i < (int)m_layerButton.size(); i++)
		m_layerButton[i].initialize(L"Resources/LayerButton.png", buttonPos + Vector2(BUTTON_SIZE_X * i, 0));

	m_selectLayer = 0;
}



//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void LayerManager::Draw()
{
	int i;
	// レイヤー切り替えボタンの描画
	for (i = 0; i < m_layerNum; i++)
	{ 
		if (i == m_selectLayer)
			m_layerButton[i].setColer(Colors::White);
		else
			m_layerButton[i].setColer(Colors::Gray);
		m_layerButton[i].draw();
	}
	// レイヤー追加ボタンの描画
	if (i < LAYER_MAX_NUM)
	{
		m_layerButton[i].setColer(Colors::Gray);
		m_layerButton[i].draw();
	}
}



//----------------------------------------------------------------------
//! @brief ボタン処理
//!
//! @param[in] 座標X 座標Y
//!
//! @return なし
//----------------------------------------------------------------------
bool LayerManager::PressedButton(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);

	for (int i = 0; i < (int)m_layerButton.size(); i++)
	{
		Vector2 buttonPos = m_layerButton[i].getPos();

		if (buttonPos.x + buttonHalfSize.x >= posX &&
			buttonPos.x - buttonHalfSize.x <= posX &&
			buttonPos.y + buttonHalfSize.y >= posY &&
			buttonPos.y - buttonHalfSize.y <= posY)
		{
			if (m_layerNum >= i)
			{
				m_selectLayer = i;
			}
			if (m_layerNum == i && m_layerNum < LAYER_MAX_NUM)
			{
				m_layerNum++;
				return true;
			}
			return false;
		}
	}
	return false;
}



//----------------------------------------------------------------------
//! @brief レイヤーの削除
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void LayerManager::LayerDelete()
{
	if (m_selectLayer)
		m_selectLayer--;

	m_layerNum--;
}
