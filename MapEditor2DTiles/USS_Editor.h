/// <summary>
/// �T�v�@ USS_Editor�ō�����X�e�[�W���g�p���邽�߂̃w�b�_
/// �쐬�� GS1 04 ���R�q��
/// </summary>

/* �|�| �w�b�_�[�̃C���N���[�h �|�|�|�| */
#pragma once
#include<string>
#include<fstream>				

//void importData(std::string filename)
//{
//	std::ifstream ifs(filename);
//	std::string str;
//
//	int i;
//	if (!ifs)
//	{
//		for (i = 0; i < MAX_BACK_BALL; i++)
//		{
//			g_map[i / 20][i % 20] = 4;
//		}
//		return;
//	}
//
//	i = 0;
//	while (getline(ifs, str))
//	{
//		std::string token;
//		istringstream stream(str);
//
//		// �P�s�̂����A������ƃR���}�𕪊�����
//		while (getline(stream, token, ','))
//		{
//			// �S�ĕ�����Ƃ��ēǂݍ��܂�邽�ߐ��l�͕ϊ����K�v
//			g_map[i / 20][i % 20] = atoi(token.c_str());
//			i++;
//		}
//	}
//}
