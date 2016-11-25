#pragma once

#include <string>
#include "utility/StreamReader.hpp"

namespace MasterData
{
class MarioData
{
public :
    int id;
    std::string name;
    std::string path;
    int x;
    int y;

    void Load(StreamReader& reader)
    {
        id = reader.ReadInt();
        name = reader.ReadString();
        path = reader.ReadString();
        x = reader.ReadInt();
        y = reader.ReadInt();
    }
};
}
