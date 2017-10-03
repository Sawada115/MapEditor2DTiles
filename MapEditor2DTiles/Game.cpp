//
// Game.cpp
//

#include "pch.h"
#include "Game.h"
// �e�X�g
#include <iostream>

extern void ExitGame();

using namespace DirectX;
using namespace DirectX::SimpleMath;

using Microsoft::WRL::ComPtr;

static std::unique_ptr<Mouse> s_mouse(new Mouse);

Game::Game() :
	m_window(0),
	m_outputWidth(800),
	m_outputHeight(600),
	m_featureLevel(D3D_FEATURE_LEVEL_9_1),
	m_outputButton(),
	m_collisionCheckButton(Vector2(75, 25)),
	m_inputButton(),
	m_mapResetButton(Vector2(75, 25)),
	m_layerDeleteButton(Vector2(75, 25))
{
	// �}�b�v�T�C�Y�ύX�{�^��
	for (int i = 0; i < 4; i++)
	{
		m_mapSizeChageButton[i] = nullptr;
	}

	// �}�b�v�̃X�N���[���o�[
	for (int i = 0; i < 2; i++)
	{
		m_mapScrollBar[i] = nullptr;
	}
}

Game::~Game()
{
	// �}�b�v�T�C�Y�ύX�{�^���̃����[�X
	for (int i = 0; i < 4; i++)
	{
		if (m_mapSizeChageButton[i] != nullptr)
		{
			delete m_mapSizeChageButton[i];
			m_mapSizeChageButton[i] = nullptr;
		}	
	}

	// �X�N���[���o�[�̃����[�X
	for (int i = 0; i < 2; i++)
	{
		if (m_mapScrollBar[i] != nullptr)
		{
			delete m_mapScrollBar[i];
			m_mapScrollBar[i] = nullptr;
		}
	}

	
}

// Initialize the Direct3D resources required to run.
void Game::Initialize(HWND window, int width, int height)
{
    m_window = window;
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    CreateDevice();

    CreateResources();

	// �}�E�X�g���b�J�[
	m_mouseTracker = std::make_unique<DirectX::Mouse::ButtonStateTracker>();

	// obj2D�̐ÓI�ϐ��̏�����(2D�摜�̏������͂�����艺�ɏ����Ă�������)
	Obj2d::staticInitialize(m_d3dContext, m_d3dDevice);

	//������
	m_spriteBatch = new SpriteBatch(m_d3dContext.Get());						// �X�v���C�g�\��
	m_spriteFont = new SpriteFont(m_d3dDevice.Get(), L"myfile.spritefont");		// �t�H���g�\��


	MakedMap* map = new MakedMap();
	map->initialize(DirectX::SimpleMath::Vector2(235.5f, 360.0f));
	m_map.push_back(map);

	m_layerManager.Initialize(DirectX::SimpleMath::Vector2(50.0f,60.0f));

	// �R���W�����`�F�b�N�{�^��
	m_collisionCheckButton.initialize(L"Resources/ColisionCheckButtanOn.png",DirectX::SimpleMath::Vector2(500.0f, 25.0f));
	// �}�b�v�T�C�Y�ύX�{�^��
	for (int i = 0; i < 4; i++)
	{
		m_mapSizeChageButton[i] = new UI_Button(Vector2(20,20));
	} 

	m_mapSizeChageButton[0]->initialize(L"Resources/MapSizePlus.png", Vector2(435.0f, 65.0f));
	m_mapSizeChageButton[1]->initialize(L"Resources/MapSizeMinus.png", Vector2(415.0f, 65.0f));
	m_mapSizeChageButton[2]->initialize(L"Resources/MapSizePlus.png", Vector2(15.0f, 580.0f));
	m_mapSizeChageButton[3]->initialize(L"Resources/MapSizeMinus.png", Vector2(15.0f, 560.0f));

	// �}�b�v�̃X�N���[���o�[
	// ��
	m_mapScrollBar[0] = new UI_ScrollBar;
	m_mapScrollBar[0]->initialize(L"Resources/ScrollBar.png", L"Resources/ScrollBarBack.png",false, Vector2(220.0f, 580.0f));
	m_mapScrollBar[0]->setScale(XMFLOAT2(19.5f, 1.0f));
	// �c
	m_mapScrollBar[1] = new UI_ScrollBar;
	m_mapScrollBar[1]->initialize(L"Resources/ScrollBar.png", L"Resources/ScrollBarBack.png", true, Vector2(435.0f, 315.0f));
	m_mapScrollBar[1]->setScale(XMFLOAT2(1.0f, 24.0f));

	// �N���A�[�{�^��
	m_ClearBotton.Initialize(Vector2(50.0f, 25.0f));

	//�@�E��̔w�i�摜�̏�����
	m_status.initialize(DirectX::SimpleMath::Vector2(630.0f, 183.0f),
						DirectX::SimpleMath::Vector2(680.0f, 185.0f),
						DirectX::SimpleMath::Vector2(680.0f, 235.0f));

	// TODO: Change the timer settings if you want something other than the default variable timestep mode.
	m_backGround3.initialize(L"Resources/BackImage3.png", DirectX::SimpleMath::Vector2(630.0f, 447.0f));
	
	m_tileManager.Initialize(DirectX::SimpleMath::Vector2(495.0f,340.0f));
	m_outputButton.Initialize(DirectX::SimpleMath::Vector2(700.0f, 25.0f));
	m_inputButton.Initialize(DirectX::SimpleMath::Vector2(600.0f, 25.0f));
	m_mapResetButton.initialize(L"Resources/MapResetButton.png", DirectX::SimpleMath::Vector2(150.0f, 25.0f));
	m_layerDeleteButton.initialize(L"Resources/LayerDeleteButton.png", DirectX::SimpleMath::Vector2(250.0f, 25.0f));

	m_oldScrollWheelValue = 0;

	// TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */
}

// Executes the basic game loop.
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    elapsedTime;

	// �}�E�X�����擾
	m_mouse = s_mouse->GetState();
	m_mouseTracker->Update(m_mouse);

	// �{�^���̍X�V
	m_collisionCheckButton.upDate(m_mouse);
	m_mapResetButton.upDate(m_mouse);
	m_layerDeleteButton.upDate(m_mouse);

	for (int i = 0; i < 4; i++)
	{
		m_mapSizeChageButton[i]->upDate(m_mouse);
	}
	// �X�N���[���o�[�̍X�V
	for (int i = 0; i < 2; i++)
	{
		m_mapScrollBar[i]->upDate(m_mouse);
	}
	for (auto itr = m_map.begin(); itr != m_map.end(); itr++)
		(*itr)->TileScroll(m_mapScrollBar[0]->getStageNow(), m_mapScrollBar[1]->getStageNow());



	// ���N���b�N������A���A�X�N���[���o�[���h���b�O���Ă��Ȃ����
	bool isScroll =  !(m_mapScrollBar[0]->getIsDrag() || m_mapScrollBar[1]->getIsDrag());
	if (m_mouse.leftButton && isScroll)
	{
		Tile* tile = new Tile();

		tile = m_tileManager.CopySelectTile();

		m_map[m_layerManager.GetSelectLayer()]->beClicked(tile, DirectX::SimpleMath::Vector2(m_mouse.x, m_mouse.y));
	}

	if (m_mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::PRESSED)
	{
		m_tileManager.TileSelect(m_mouse.x, m_mouse.y);
		/*m_status.TileChange(m_tileManager.GetSelectTile());
		m_status.CollisionChange(m_mouse.x, m_mouse.y);*/
		if (m_layerManager.PressedButton(m_mouse.x, m_mouse.y))
		{
			MakedMap* map = new MakedMap();
			map->initialize(DirectX::SimpleMath::Vector2(235.5f, 360.0f));
			map->mapReSize(m_map[0]->GetMapSize().x, m_map[0]->GetMapSize().y);
			m_map.push_back(map);
		}

		//�N���A�[�{�^������
		if (m_ClearBotton.PressedButton(m_mouse.x, m_mouse.y))
		{
			int num = m_layerManager.GetSelectLayer();
			if (num != (int)m_map.size() - 1)
				m_map[num]->setVisible(!m_map[num]->getVisible());
		}
	

		m_status.TileChange(m_tileManager.CopySelectTile());
		m_status.CollisionChange(m_mouse.x, m_mouse.y, m_tileManager.GetSelectTile());
		
		// �o�̓{�^����������
		if (m_outputButton.isPressed(m_mouse.x, m_mouse.y))
		{
			if (m_outputButton.SetSaveFilePath())
			{
				for (int i = 0; i < (int)m_map.size(); i++)
					m_outputButton.OutPutCsv(i + 1, m_map[i]->GetAllTileData(), m_map[i]->GetMapSize());
			}
		}

		// �ǂݍ��݃{�^����������
		if (m_inputButton.isPressed(m_mouse.x, m_mouse.y))
		{
			if (m_inputButton.SetOpenFilePath())
			{
				Tile* tile = new Tile();
				m_inputButton.InPutCsv(m_map[m_layerManager.GetSelectLayer()]);
			}
		}

		// �}�b�v�S�폜�{�^����������
		m_mapResetButton.pressed(m_mouse.x, m_mouse.y, [this]() {Game::MapReset(); });

		// ���C���[�폜�{�^����������
		m_layerDeleteButton.pressed(m_mouse.x, m_mouse.y, [this]() {Game::LayerDelete(); });

		// �R���W�����`�F�b�N�{�^������������
		m_collisionCheckButton.pressed(m_mouse.x, m_mouse.y, [this]() {Game::ChangeColisionCheck(); });

		// �}�b�v�T�C�Y�̕ύX
		m_mapSizeChageButton[0]->pressed(m_mouse.x, m_mouse.y, [this]() {Game::MapSizeChange( 1,  0); });
		m_mapSizeChageButton[1]->pressed(m_mouse.x, m_mouse.y, [this]() {Game::MapSizeChange(-1,  0); });
		m_mapSizeChageButton[2]->pressed(m_mouse.x, m_mouse.y, [this]() {Game::MapSizeChange( 0,  1); });
		m_mapSizeChageButton[3]->pressed(m_mouse.x, m_mouse.y, [this]() {Game::MapSizeChange( 0, -1); });


	}

	// �E�N���b�N������
	if (m_mouse.rightButton)
	{
		Tile* tile = new Tile();
		tile->initialize(0);

		m_map[m_layerManager.GetSelectLayer()]->beClicked(tile, DirectX::SimpleMath::Vector2(m_mouse.x, m_mouse.y));
	
	}

	// �}�E�X�z�C�[��
	if (m_mouse.scrollWheelValue != m_oldScrollWheelValue)
	{
		// �p���b�g�̃X�N���[��
		m_tileManager.TileScroll(m_mouse.x, m_mouse.y, m_mouse.scrollWheelValue - m_oldScrollWheelValue);

		// �}�b�v�̃X�N���[��
		for (int i = (int)m_map.size(); i > m_layerManager.GetSelectLayer(); i--)
			m_map[i - 1]->TileScroll(m_mouse.x, m_mouse.y, m_mouse.scrollWheelValue - m_oldScrollWheelValue);
	}
	m_oldScrollWheelValue = m_mouse.scrollWheelValue;

}

// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    Clear();

    // TODO: Add your rendering code here.

	// ���C���[�̕`��

	if (m_map[m_layerManager.GetSelectLayer()]->getVisible() == false)
	{
		for (int i = (int)m_map.size(); i > m_layerManager.GetSelectLayer(); i--)
			m_map[i - 1]->draw();
	}
	else
		m_map[m_layerManager.GetSelectLayer()]->draw();
	m_layerManager.Draw();

	// �R���W�����`�F�b�N�{�^��
	m_collisionCheckButton.draw();

	// �}�b�v�S�폜�{�^��
	m_mapResetButton.draw();
	// ���C���[�폜�{�^��
	m_layerDeleteButton.draw();

	// �}�b�v�T�C�Y�ύX�{�^��
	for (int i = 0; i < 4; i++)
	{
		m_mapSizeChageButton[i]->draw();
	}

	// �X�N���[���o�[
	m_mapScrollBar[0]->draw();
	m_mapScrollBar[1]->draw();

	// �N���A�[�{�^��
	bool visible = m_map[m_layerManager.GetSelectLayer()]->getVisible();
	m_ClearBotton.Set_ClearFlag(!visible);
	m_ClearBotton.Draw();

	m_status.draw();
	m_backGround3.draw();
	m_tileManager.Draw();
	m_outputButton.draw();
	m_inputButton.draw();

	// �����`��
	m_spriteBatch->Begin();

	// ���C���[�ԍ��̕`��
	for (int i = 0; i < (int)m_map.size(); i++)
	{
		wchar_t layerNum[2];
		_itow_s(i + 1, layerNum, 10);
		wchar_t layerName[10] = L"Layer";
		wcscat(layerName, layerNum);
		m_spriteFont->DrawString(m_spriteBatch, layerName, XMFLOAT2(15.0f, 45.0f) + Vector2(i * 75, 0), Colors::Black);
	}

	// �^�C�����擾
	std::wstring ws_name = m_tileManager.GetSelectTile()->getName();
	// wstring��wchar_t�ɕϊ�
	const wchar_t* wc_name = ws_name.c_str();

	m_spriteFont->DrawString(m_spriteBatch, wc_name, XMFLOAT2(630, 120.0f),Colors::Black);
	m_spriteFont->DrawString(m_spriteBatch, L"TileName", XMFLOAT2(480, 120.0f), Colors::Black);
	m_spriteFont->DrawString(m_spriteBatch, L"TileImage", XMFLOAT2(480, 170.0f), Colors::Black);
	m_spriteFont->DrawString(m_spriteBatch, L"Colision", XMFLOAT2(480, 220.0f), Colors::Black);

	m_spriteBatch->End();

Present();
}

/// <summary>
/// �R���W�����`�F�b�N�{�^�����������Ƃ��̏���
/// </summary>
void Game::ChangeColisionCheck()
{
	Tile::changeCollisionCheck();
}

void Game::MapSizeChange(int ChangeX, int ChangeY)
{
	for (auto itr = m_map.begin(); itr != m_map.end(); itr++)
	(*itr)->mapReSize((*itr)->GetMapSize().x + ChangeX, (*itr)->GetMapSize().y + ChangeY);

	// �X�N���[���̒i�K������(��)
	int scrollStageX = m_map[0]->GetMapSize().x - MakedMap::DRAW_TILE_NUM_X + 1;
	if (scrollStageX < 1)scrollStageX = 1;
	m_mapScrollBar[0]->setStage(scrollStageX);

	// �X�N���[���̒i�K������(��)
	int scrollStageY = m_map[0]->GetMapSize().y - MakedMap::DRAW_TILE_NUM_Y + 1;
	if (scrollStageY < 1)scrollStageY = 1;
	m_mapScrollBar[1]->setStage(scrollStageY);
}

void Game::MapReset()
{
	m_map[m_layerManager.GetSelectLayer()]->mapReset();
}

void Game::LayerDelete()
{
	if ((int)m_map.size() > 1)
	{
		int i = 0;
		for (auto itr = m_map.begin(); itr != m_map.end();)
		{
			if (i == m_layerManager.GetSelectLayer())
				itr = m_map.erase(itr);
			else
				itr++;
			i++;
		}
		m_layerManager.LayerDelete();
	}
}


// Helper method to clear the back buffers.
void Game::Clear()
{
    // Clear the views.
    m_d3dContext->ClearRenderTargetView(m_renderTargetView.Get(), Colors::CornflowerBlue);
    m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    m_d3dContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());

    // Set the viewport.
    CD3D11_VIEWPORT viewport(0.0f, 0.0f, static_cast<float>(m_outputWidth), static_cast<float>(m_outputHeight));
    m_d3dContext->RSSetViewports(1, &viewport);
}

// Presents the back buffer contents to the screen.
void Game::Present()
{
    // The first argument instructs DXGI to block until VSync, putting the application
    // to sleep until the next VSync. This ensures we don't waste any cycles rendering
    // frames that will never be displayed to the screen.
    HRESULT hr = m_swapChain->Present(1, 0);

    // If the device was reset we must completely reinitialize the renderer.
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
    {
        OnDeviceLost();
    }
    else
    {
        DX::ThrowIfFailed(hr);
    }
}

// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    CreateResources();

    // TODO: Game window is being resized.
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}

// These are the resources that depend on the device.
void Game::CreateDevice()
{
    UINT creationFlags = 0;

#ifdef _DEBUG
    creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    static const D3D_FEATURE_LEVEL featureLevels [] =
    {
        // TODO: Modify for supported Direct3D feature levels (see code below related to 11.1 fallback handling).
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_9_3,
        D3D_FEATURE_LEVEL_9_2,
        D3D_FEATURE_LEVEL_9_1,
    };

    // Create the DX11 API device object, and get a corresponding context.
    HRESULT hr = D3D11CreateDevice(
        nullptr,                                // specify nullptr to use the default adapter
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        creationFlags,
        featureLevels,
        _countof(featureLevels),
        D3D11_SDK_VERSION,
        m_d3dDevice.ReleaseAndGetAddressOf(),   // returns the Direct3D device created
        &m_featureLevel,                        // returns feature level of device created
        m_d3dContext.ReleaseAndGetAddressOf()   // returns the device immediate context
        );

    if (hr == E_INVALIDARG)
    {
        // DirectX 11.0 platforms will not recognize D3D_FEATURE_LEVEL_11_1 so we need to retry without it.
        hr = D3D11CreateDevice(nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            creationFlags,
            &featureLevels[1],
            _countof(featureLevels) - 1,
            D3D11_SDK_VERSION,
            m_d3dDevice.ReleaseAndGetAddressOf(),
            &m_featureLevel,
            m_d3dContext.ReleaseAndGetAddressOf()
            );
    }

    DX::ThrowIfFailed(hr);

#ifndef NDEBUG
    ComPtr<ID3D11Debug> d3dDebug;
    if (SUCCEEDED(m_d3dDevice.As(&d3dDebug)))
    {
        ComPtr<ID3D11InfoQueue> d3dInfoQueue;
        if (SUCCEEDED(d3dDebug.As(&d3dInfoQueue)))
        {
#ifdef _DEBUG
            d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_CORRUPTION, true);
            d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_ERROR, true);
#endif
            D3D11_MESSAGE_ID hide [] =
            {
                D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS,
                // TODO: Add more message IDs here as needed.
            };
            D3D11_INFO_QUEUE_FILTER filter = {};
            filter.DenyList.NumIDs = _countof(hide);
            filter.DenyList.pIDList = hide;
            d3dInfoQueue->AddStorageFilterEntries(&filter);
        }
    }
#endif

    // DirectX 11.1 if present
    if (SUCCEEDED(m_d3dDevice.As(&m_d3dDevice1)))
        (void)m_d3dContext.As(&m_d3dContext1);

    // TODO: Initialize device dependent objects here (independent of window size).
}

// Allocate all memory resources that change on a window SizeChanged event.
void Game::CreateResources()
{
    // Clear the previous window size specific context.
    ID3D11RenderTargetView* nullViews [] = { nullptr };
    m_d3dContext->OMSetRenderTargets(_countof(nullViews), nullViews, nullptr);
    m_renderTargetView.Reset();
    m_depthStencilView.Reset();
    m_d3dContext->Flush();

    UINT backBufferWidth = static_cast<UINT>(m_outputWidth);
    UINT backBufferHeight = static_cast<UINT>(m_outputHeight);
    DXGI_FORMAT backBufferFormat = DXGI_FORMAT_B8G8R8A8_UNORM;
    DXGI_FORMAT depthBufferFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
    UINT backBufferCount = 2;

    // If the swap chain already exists, resize it, otherwise create one.
    if (m_swapChain)
    {
        HRESULT hr = m_swapChain->ResizeBuffers(backBufferCount, backBufferWidth, backBufferHeight, backBufferFormat, 0);

        if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
        {
            // If the device was removed for any reason, a new device and swap chain will need to be created.
            OnDeviceLost();

            // Everything is set up now. Do not continue execution of this method. OnDeviceLost will reenter this method 
            // and correctly set up the new device.
            return;
        }
        else
        {
            DX::ThrowIfFailed(hr);
        }
    }
    else
    {
        // First, retrieve the underlying DXGI Device from the D3D Device.
        ComPtr<IDXGIDevice1> dxgiDevice;
        DX::ThrowIfFailed(m_d3dDevice.As(&dxgiDevice));

        // Identify the physical adapter (GPU or card) this device is running on.
        ComPtr<IDXGIAdapter> dxgiAdapter;
        DX::ThrowIfFailed(dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf()));

        // And obtain the factory object that created it.
        ComPtr<IDXGIFactory1> dxgiFactory;
        DX::ThrowIfFailed(dxgiAdapter->GetParent(IID_PPV_ARGS(dxgiFactory.GetAddressOf())));

        ComPtr<IDXGIFactory2> dxgiFactory2;
        if (SUCCEEDED(dxgiFactory.As(&dxgiFactory2)))
        {
            // DirectX 11.1 or later

            // Create a descriptor for the swap chain.
            DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };
            swapChainDesc.Width = backBufferWidth;
            swapChainDesc.Height = backBufferHeight;
            swapChainDesc.Format = backBufferFormat;
            swapChainDesc.SampleDesc.Count = 1;
            swapChainDesc.SampleDesc.Quality = 0;
            swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            swapChainDesc.BufferCount = backBufferCount;

            DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsSwapChainDesc = { 0 };
            fsSwapChainDesc.Windowed = TRUE;

            // Create a SwapChain from a Win32 window.
            DX::ThrowIfFailed(dxgiFactory2->CreateSwapChainForHwnd(
                m_d3dDevice.Get(),
                m_window,
                &swapChainDesc,
                &fsSwapChainDesc,
                nullptr,
                m_swapChain1.ReleaseAndGetAddressOf()
                ));

            DX::ThrowIfFailed(m_swapChain1.As(&m_swapChain));
        }
        else
        {
            DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
            swapChainDesc.BufferCount = backBufferCount;
            swapChainDesc.BufferDesc.Width = backBufferWidth;
            swapChainDesc.BufferDesc.Height = backBufferHeight;
            swapChainDesc.BufferDesc.Format = backBufferFormat;
            swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            swapChainDesc.OutputWindow = m_window;
            swapChainDesc.SampleDesc.Count = 1;
            swapChainDesc.SampleDesc.Quality = 0;
            swapChainDesc.Windowed = TRUE;

            DX::ThrowIfFailed(dxgiFactory->CreateSwapChain(m_d3dDevice.Get(), &swapChainDesc, m_swapChain.ReleaseAndGetAddressOf()));
        }

        // This template does not support exclusive fullscreen mode and prevents DXGI from responding to the ALT+ENTER shortcut.
        DX::ThrowIfFailed(dxgiFactory->MakeWindowAssociation(m_window, DXGI_MWA_NO_ALT_ENTER));
    }

    // Obtain the backbuffer for this window which will be the final 3D rendertarget.
    ComPtr<ID3D11Texture2D> backBuffer;
    DX::ThrowIfFailed(m_swapChain->GetBuffer(0, IID_PPV_ARGS(backBuffer.GetAddressOf())));

    // Create a view interface on the rendertarget to use on bind.
    DX::ThrowIfFailed(m_d3dDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, m_renderTargetView.ReleaseAndGetAddressOf()));

    // Allocate a 2-D surface as the depth/stencil buffer and
    // create a DepthStencil view on this surface to use on bind.
    CD3D11_TEXTURE2D_DESC depthStencilDesc(depthBufferFormat, backBufferWidth, backBufferHeight, 1, 1, D3D11_BIND_DEPTH_STENCIL);

    ComPtr<ID3D11Texture2D> depthStencil;
    DX::ThrowIfFailed(m_d3dDevice->CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf()));

    CD3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc(D3D11_DSV_DIMENSION_TEXTURE2D);
    DX::ThrowIfFailed(m_d3dDevice->CreateDepthStencilView(depthStencil.Get(), &depthStencilViewDesc, m_depthStencilView.ReleaseAndGetAddressOf()));

    // TODO: Initialize windows-size dependent objects here.
}

void Game::OnDeviceLost()
{
    // TODO: Add Direct3D resource cleanup here.

    m_depthStencilView.Reset();
    m_renderTargetView.Reset();
    m_swapChain1.Reset();
    m_swapChain.Reset();
    m_d3dContext1.Reset();
    m_d3dContext.Reset();
    m_d3dDevice1.Reset();
    m_d3dDevice.Reset();

    CreateDevice();

    CreateResources();
}

