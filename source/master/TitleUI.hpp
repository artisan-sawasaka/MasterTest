#pragma once

#include <string>
#include "utility/StreamReader.hpp"

namespace MasterData
{
class TitleUIData
{
public :
    int id;
    std::string image;
    int x;
    int y;

    void Load(StreamReader& reader)
    {
        id = reader.ReadInt();
        image = reader.ReadString();
        x = reader.ReadInt();
        y = reader.ReadInt();
    }
};
}
