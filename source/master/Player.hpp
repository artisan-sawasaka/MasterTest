#pragma once

#include <string>
#include "utility/StreamReader.hpp"

namespace MasterData
{
class PlayerData
{
public :
    float speed;
    int credit;
    int xpos;
    int ypos;

    void Load(StreamReader& reader)
    {
        speed = reader.ReadFloat();
        credit = reader.ReadInt();
        xpos = reader.ReadInt();
        ypos = reader.ReadInt();
    }
};
}
