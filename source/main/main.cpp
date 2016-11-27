#include "stdafx.h"
#include "utility/FileUtility.hpp"
#include "utility/StreamReader.hpp"
#include "master/MasterData.hpp"

void TitleImageListPrint()
{
	for (auto it = MasterData::TitleImageList.begin(); it != MasterData::TitleImageList.end(); ++it) {
		auto& info = it->second;
		printf("Name:%-10s Path:%-10s X:%3d Y:%3d W:%3d H%3d\n", info.name.c_str(), info.path.c_str(), info.x, info.y, info.w, info.h);
	}
}

void TitleUIPrint()
{
	for (size_t i = 0; i < MasterData::TitleUI.size(); ++i) {
		auto& info = MasterData::TitleUI[i];
		printf("ID:%2d Image:%-10s X:%3d Y:%3d\n", info.id, info.image.c_str(), info.x, info.y);
	}
}

void PlayerPrint()
{
	auto player = MasterData::Player;
	printf("Speed:%2f Credit:%d X:%3d Y:%3d\n", player.speed, player.credit, player.xpos, player.ypos);
}

int main()
{
	std::function<void()> funcs[] = {
		TitleImageListPrint,
		TitleUIPrint,
		PlayerPrint,
	};

	int c = 0;
	while (true) {
		printf("1:TitleImageList 2:TitleUI 3:Player\n");
		c = getchar();
		getchar();
		if (c == EOF) break;
		c -= '0' + 1;
		if (0 <= c && c <= 2) {
			MasterData::Reload("data/master");
			printf("--------------------------------------------------------\n");
			funcs[c]();
			printf("--------------------------------------------------------\n");
		}
	}
}
