#pragma once

#include <string>
#include <vector>
#include <map>
#include "master/Player.hpp"
#include "master/TitleImageList.hpp"
#include "master/TitleUI.hpp"

namespace MasterData
{
    extern PlayerData Player;
    extern std::map<std::string, TitleImageListData> TitleImageList;
    extern std::vector<TitleUIData> TitleUI;


    void Reload(const std::string& path);
}
