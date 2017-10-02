/// <summary>
/// �T�v�@ �X�N���[���o�[
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include "UI_ScrollBar.h"

// ���O��Ԃ��J��
using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// ���[���̏����T�C�Y(�c������)
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
/// ������
/// </summary>
/// <param name="imageFileName">�ǂݍ��މ摜�̃t�@�C����</param>
/// <param name="railImageFileName">���[�������̃t�@�C����</param>
/// <param name="barPos">�����ʒu</param>
/// <param name="stage">���i�K�Ȃ̂�</param>
void UI_ScrollBar::initialize(	const wchar_t * imageFileName,
								const wchar_t* railImageFileName,
								bool isVertical,
								Vector2 barPos,
								int stage)
{
	UI_Button::initialize(imageFileName, barPos);

	// ���[�������̏�����
	m_railImage = new Obj2d;
	m_railImage->initialize(railImageFileName, barPos);

	// ���i�K�œ�����
	m_stage = stage;
	// ���A���i�K�ڂ�
	m_stageNow = 0;

	// �c������
	m_isVertical = isVertical;

	// �ŏ��̓h���b�O���Ă��Ȃ�
	m_dragStart = false;

	// �ʒu�v�Z
	barSizeCalc();
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="m_mouse">�}�E�X���</param>
void UI_ScrollBar::upDate(DirectX::Mouse::State mouse)
{
	UI_Button::upDate(mouse);

	// �h���b�O���n��
	if (m_mouseTracker->leftButton == Mouse::ButtonStateTracker::ButtonState::PRESSED)
	{
		if (m_isPressed)
		{
			m_dragStart = true;
		}

	}
	
	// �h���b�O��
	if (m_dragStart && mouse.leftButton)
	{
		// �o�[�̈ʒu��ς���
		setBarPositionFromMousePosition(mouse);
	}
	else
	{
		m_dragStart = false;
	}

	// �}�E�X�����L��
	m_oldMouse = mouse;
}

/// <summary>
/// �X�P�[���̕ύX
/// </summary>
/// <param name="scale"></param>
void UI_ScrollBar::setScale(XMFLOAT2 scale)
{
	// ���[��
	m_railImage->setScale(scale);

	// �{�̂̃T�C�Y�̕ύX
	barSizeCalc();
}

/// <summary>
///	�o�[�̑傫�����v�Z����
/// </summary>
void UI_ScrollBar::barSizeCalc()
{
	// �o�[�̑傫��
	XMFLOAT2 barScale = XMFLOAT2( m_railImage->getScale().x, m_railImage->getScale().y);

	// �c����
	if (m_isVertical)
	{
		barScale.y /= m_stage;
	}	
	// ������
	else
	{
		barScale.x /= m_stage;
	}

	// �Z�b�g����
	Obj2d::setScale(barScale);

	BUTTON_SIZE_X = this->getScale().x * DEFOULT_RAIL_SIZE;
	BUTTON_SIZE_Y = this->getScale().y * DEFOULT_RAIL_SIZE;

	barPositionCalc();
}

/// <summary>
/// �o�[�̈ʒu�̌v�Z
/// </summary>
void UI_ScrollBar::barPositionCalc()
{
	// �c�̏ꍇ
	if (m_isVertical)
	{
		m_railLengh = m_railImage->getScale().y * DEFOULT_RAIL_SIZE;
	}
	// ���̏ꍇ
	else
	{
		m_railLengh = m_railImage->getScale().x * DEFOULT_RAIL_SIZE;
	}

	// 1���������̒���
	m_railOneStageLengh = m_railLengh / m_stage;

	// �ꏊ���Z�o
	XMFLOAT2 position = m_railImage->getPos();
	// �c�̏ꍇ
	if (m_isVertical)
	{
		position.y -= m_railLengh / 2;
		m_leftUpPosition = position;// ����̒��_
		position.y += m_stageNow * m_railOneStageLengh + m_railOneStageLengh / 2;
	}
	// ���̏ꍇ
	else
	{
		position.x -= m_railLengh / 2;
		m_leftUpPosition = position;// ����̒��_
		position.x += m_stageNow * m_railOneStageLengh + m_railOneStageLengh / 2;
	}
	
	Obj2d::setPosition(position);
}

/// <summary>
/// �}�E�X��񂩂�o�[�̈ʒu��ς���
/// </summary>
/// <param name="mouse">�}�E�X���</param>
void UI_ScrollBar::setBarPositionFromMousePosition(DirectX::Mouse::State mouse)
{
	int i = m_stage;

	// �c����
	if (m_isVertical)
	{
		// �N���b�N���ꂽ�ʒu��T��(�c)
		while (m_leftUpPosition.y < mouse.y && m_leftUpPosition.y + i*m_railOneStageLengh > mouse.y)
		{
			i--;
		}
	}
	// ������
	else
	{
		// �N���b�N���ꂽ�ʒu��T��(��)
		while (m_leftUpPosition.x < mouse.x && m_leftUpPosition.x + i*m_railOneStageLengh > mouse.x)
		{
			i--;
		}
	}

	// �}�b�v�O�Ȃ炷���I���A
	if (i >= m_stage || i < 0)
	{
		return;
	}

	// �N���b�N�ʒu��ݒ�
	m_stageNow = i;

	// �ʒu��ݒ肵�Ȃ���
	barPositionCalc();

}
