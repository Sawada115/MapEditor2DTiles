/// <summary>
/// �T�v�@ �^�C���̃R���W�����`�F�b�N�̃I���I�t��؂�ւ���{�^��
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "UI_Buttan.h"
#include "Tile.h"


class ColisionCheckButtan : public UI_Buttan
{
public:
	ColisionCheckButtan();
	virtual ~ColisionCheckButtan();

	// ������
	virtual void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2());

	// �{�^�����������
	void toActivate();
};

