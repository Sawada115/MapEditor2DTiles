//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include <SimpleMath.h>
#include <Mouse.h>
#include <SpriteFont.h>
#include "MakedMap.h"
#include "ColisionCheckButtan.h"
#include "Tile.h"
#include "TileManager.h"
#include "StatusTile.h"
#include "MapOutPut.h"
#include "LayerManager.h"
#include "MapInPut.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

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

	//Obj2d backImage1;	// �����̔w�i�摜
	Obj2d m_backGround3;	// �E���p���b�g�̔w�i�摜

	// �}�E�X
	DirectX::Mouse::State m_mouse;
	std::unique_ptr<DirectX::Mouse::ButtonStateTracker> m_mouseTracker;

	// �����̃}�b�v
	std::vector<MakedMap> m_map;
	// �R���W�����`�F�b�N�{�^��
	UI_Buttan m_clisionCheckButtan;
	// �}�b�v�T�C�Y�ύX�{�^��


	//�E��̑I���^�C��
	StatusTile m_status;

	TileManager m_tileManager;			// �^�C���}�l�[�W���[
	MapOutPut m_outputButton;			// �o�̓{�^��
	MapInPut m_inputButton;				// �ǂݍ��݃{�^��
	LayerManager m_layerManager;		// ���C���[�}�l�[�W���[

	int m_oldScrollWheelValue;			// �O�t���[���}�E�X�z�C�[���l

	DirectX::SpriteBatch* m_spriteBatch;
	DirectX::SpriteFont*	m_spriteFont;
};