/// <summary>
/// �T�v�@ �X�N���[���o�[
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "UI_Button.h"


class UI_ScrollBar : public UI_Button
{
public:
	UI_ScrollBar();
	virtual ~UI_ScrollBar();

	// ������
	void initialize(const wchar_t* imageFileName, 
							const wchar_t* railImageFileName,
							bool isVertical,
							DirectX::SimpleMath::Vector2 barPos = DirectX::SimpleMath::Vector2(),
							int stage = 1);

	// �X�V
	void upDate(DirectX::Mouse::State mouse);

	// �`��
	void draw() { m_railImage->draw(); UI_Button::draw(); };

	// �Z�b�g
	void setScale(DirectX::XMFLOAT2 scale); // �X�P�[�����O
	void setPosition(DirectX::SimpleMath::Vector2 pos) { m_railImage->setPosition(pos); };	// �\���ʒu
	void setStage(int stage) { m_stage = stage; barSizeCalc(); };
	// �Q�b�g
	int getStageNow() { return m_stageNow; };
	bool getIsDrag() { return m_dragStart; };

	// �o�[�̑傫���̌v�Z
	void barSizeCalc();

private:
	// �o�[�̈ʒu�̌v�Z
	void barPositionCalc();
	// �}�E�X��񂩂�o�[�̈ʒu��ς���
	void setBarPositionFromMousePosition(DirectX::Mouse::State mouse);


	// ���[���̏����T�C�Y(�c������)
	static const float DEFOULT_RAIL_SIZE;



	// ���[�������̉摜
	Obj2d* m_railImage;
	DirectX::SimpleMath::Vector2 m_leftUpPosition;
	float m_railLengh;
	float m_railOneStageLengh;

	// ���i�K�œ�����
	int m_stage;
	// ���A���i�K�ڂ�
	int m_stageNow;

	// �c�����̃o�[���ۂ�
	bool m_isVertical;

	// �h���b�O�J�n�t���O
	bool m_dragStart;

	// 1�t���[���O�̃}�E�X���
	DirectX::Mouse::State m_oldMouse;

};

