//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   LayerManager.cpp
//!
//! @brief  クリアボタンクラス
//!
//! @date   日付　2017/09/29
//!
//! @author 制作者名 菅野
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダーファイルのインクルード==============================================
#include "pch.h"
#include "ClearBotton.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// 静的変数の初期化
const int ClearBotton::BUTTON_SIZE_X = 75;
const int ClearBotton::BUTTON_SIZE_Y = 25;


//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//!
//! @return 存在しない
//----------------------------------------------------------------------
ClearBotton::ClearBotton()
{
}



//----------------------------------------------------------------------
//! @brief デストラクタ
//!
//! @param[in] 存在しない
//!
//! @return 存在しない
//----------------------------------------------------------------------
ClearBotton::~ClearBotton()
{
}



//----------------------------------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] ボタン座標
//!
//! @return なし
//----------------------------------------------------------------------
void ClearBotton::Initialize(DirectX::SimpleMath::Vector2 buttonPos)
{

	m_ClearBotton_ON.initialize(L"Resources/LayerClearButtanON.png", buttonPos);
	m_ClearBotton_OFF.initialize(L"Resources/LayerClearButtanOFF.png", buttonPos);

	m_ClearFlag = 1;
}



//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void ClearBotton::Draw()
{

	if (m_ClearFlag)
	{
		m_ClearBotton_ON.draw();
	}
	else
	{
		m_ClearBotton_OFF.draw();
	}
}



//----------------------------------------------------------------------
//! @brief ボタン処理
//!
//! @param[in] 座標X 座標Y
//!
//! @return なし
//----------------------------------------------------------------------
bool ClearBotton::PressedButton(int posX, int posY)
{
	Vector2 buttonHalfSize(BUTTON_SIZE_X / 2, BUTTON_SIZE_Y / 2);
	Vector2 buttonPos = m_ClearBotton_ON.getPos();

	if (buttonPos.x + buttonHalfSize.x >= posX &&
		buttonPos.x - buttonHalfSize.x <= posX &&
		buttonPos.y + buttonHalfSize.y >= posY &&
		buttonPos.y - buttonHalfSize.y <= posY)
	{
		if (m_ClearFlag)
		{
			m_ClearFlag = 0;
		}
		else
		{
			m_ClearFlag = 1;
		}
		return true;
	}
	return false;
}

int ClearBotton::Get_ClearFlag()
{
	return m_ClearFlag;
}