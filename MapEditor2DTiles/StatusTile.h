/// <summary>
/// �T�v�@ �I�𒆂̃`�b�v�\��
/// �쐬�� GS1 14�@���� �I�� 
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include "Obj2d.h"
#include "string.h"
#include "Tile.h"


class StatusTile : public Obj2d
{
public:
	StatusTile();
	virtual ~StatusTile();

	// ������
	void initialize(DirectX::SimpleMath::Vector2 pos = DirectX::SimpleMath::Vector2(630.0f, 150.0f));

	// �^�C���f�[�^�̎擾
	void TileChange(Tile* tile);		//�I�𒆂̃^�C���f�[�^�̎擾

	void Get_Collision(Tile tile);	//�I�𒆂̃^�C���f�[�^��Collision�擾

	void CollisionChange(int posX, int posY);

	// �`��
	void draw();

private:
	Obj2d m_backImage;			//�w�i
	Obj2d m_Collison_Status;	//�����蔻��̏�ԕ\��

	DirectX::SimpleMath::Vector2 Tile_Pos;	//�I�𒆂̃^�C���̖��O�̕\�����W

	Tile m_Tile;							//�I�𒆂̃^�C��
	DirectX::SimpleMath::Vector2 name_Pos;	//�I�𒆂̃^�C���̖��O�̕\�����W

	DirectX::SimpleMath::Vector2 Collision_Pos;	//�����蔻��̕\�����W
};
