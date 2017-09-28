/// <summary>
/// �T�v�@ �^�C���̃R���W�����`�F�b�N�̃I���I�t��؂�ւ���{�^��
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#include "pch.h"
#include "ColisionCheckButtan.h"

// ���O��Ԃ̊J��
using namespace DirectX::SimpleMath;

ColisionCheckButtan::ColisionCheckButtan()
	:UI_ButtanBase(Vector2(150,50))
{

}


ColisionCheckButtan::~ColisionCheckButtan()
{
}

void ColisionCheckButtan::initialize(DirectX::SimpleMath::Vector2 pos)
{
	Obj2d::initialize(L"Resources/OutPutButton.png", pos);
	setColer(DirectX::Colors::Blue);
}

void ColisionCheckButtan::toActivate()
{
	Tile::changheClisionCheck();
}