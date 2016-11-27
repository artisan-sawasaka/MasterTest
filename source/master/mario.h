#pragma once

/*!
 * @brief マスターデータの個別構造体
 */
struct MarioInfo
{
	char name[80];
	int x;
	int y;
};

/*!
 * @brief マスターデータの大本の構造体
 */
struct Mario
{
	MarioInfo* Infos;
	int size;
};

/*!
 * @brief 再読み込み
 */
void ReloadMario(const char* path);

/*!
 * @brief マリオマスターの変数
 */
extern Mario MasterMario;
