#pragma once

/*!
 * @brief �}�X�^�[�f�[�^�̌ʍ\����
 */
struct MarioInfo
{
	char name[80];
	int x;
	int y;
};

/*!
 * @brief �}�X�^�[�f�[�^�̑�{�̍\����
 */
struct Mario
{
	MarioInfo* Infos;
	int size;
};

/*!
 * @brief �ēǂݍ���
 */
void ReloadMario(const char* path);

/*!
 * @brief �}���I�}�X�^�[�̕ϐ�
 */
extern Mario MasterMario;
