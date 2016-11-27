#pragma once

#include <string>
#include <vector>
#include <map>
#include "utility/FileUtility.hpp"
#include "utility/StreamReader.hpp"
#include "master/Player.hpp"
#include "master/TitleImageList.hpp"
#include "master/TitleUI.hpp"

namespace MasterData
{
    static PlayerData Player;
    static std::map<std::string, TitleImageListData> TitleImageList;
    static std::vector<TitleUIData> TitleUI;


    void Reload(const std::string& path)
    {
        std::vector<char> buffer;
	    StreamReader reader;

        buffer = File::ReadAllBytes(path + "/Player.dat");
        reader = StreamReader(buffer);
        Player.Load(reader);

        buffer = File::ReadAllBytes(path + "/TitleImageList.dat");
        reader = StreamReader(buffer);
        int length = reader.ReadInt();
        for (int i = 0; i < length; ++i) {
            auto key = reader.ReadStringNoSeek();
            TitleImageList[key].Load(reader);
        }

        buffer = File::ReadAllBytes(path + "/TitleUI.dat");
        reader = StreamReader(buffer);
        TitleUI.resize(reader.ReadInt());
        for (size_t i = 0; i < TitleUI.size(); ++i) {
            TitleUI[i].Load(reader);
        }

    }
}
