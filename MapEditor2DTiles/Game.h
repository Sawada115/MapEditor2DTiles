//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include <SimpleMath.h>
#include <Mouse.h>
#include <SpriteFont.h>
#include "MakedMap.h"
#include "UI_Button.h"
#include "UI_ScrollBar.h"
#include "Tile.h"
#include "TileManager.h"
#include "StatusTile.h"
#include "MapOutPut.h"
#include "LayerManager.h"
#include "MapInPut.h"
#include "ClearBotton.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();
	~Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

	// コリジョンチェックをするかどうかを入れ替える
	void ChangeColisionCheck();

	void MapSizeChange(int ChangeX, int ChangeY);

	void MapReset();

	void LayerDelete();
private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();


    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	//Obj2d backImage1;	// 左側の背景画像
	Obj2d m_backGround3;	// 右下パレットの背景画像

	// マウス
	DirectX::Mouse::State m_mouse;
	std::unique_ptr<DirectX::Mouse::ButtonStateTracker> m_mouseTracker;

	// 左側のマップ
	std::vector<MakedMap*> m_map;
	// コリジョンチェックボタン
	UI_Button m_collisionCheckButton;
	// マップサイズ変更ボタン
	UI_Button* m_mapSizeChageButton[4];
	// マップのスクロールバー
	UI_ScrollBar* m_mapScrollBar[2];
	//レイヤーの透過処理の変更ボタン
	ClearBotton m_ClearBotton;
	// マップ全削除ボタン
	UI_Button m_mapResetButton;
	// レイヤー削除ボタン
	UI_Button m_layerDeleteButton;

	//右上の選択タイル
	StatusTile m_status;

	TileManager m_tileManager;			// タイルマネージャー
	MapOutPut m_outputButton;			// 出力ボタン
	MapInPut m_inputButton;				// 読み込みボタン
	LayerManager m_layerManager;		// レイヤーマネージャー

	int m_oldScrollWheelValue;			// 前フレームマウスホイール値

	DirectX::SpriteBatch* m_spriteBatch;
	DirectX::SpriteFont*	m_spriteFont;
};