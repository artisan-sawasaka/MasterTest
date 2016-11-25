#include "stdafx.h"
#include "utility/FileUtility.hpp"
#include "utility/StreamReader.hpp"
#include "master/Mario.h"

int main()
{
	std::vector<MasterData::MarioData> datas;
	auto buffer = File::ReadAllBytes("data/master/Mario.dat");
	StreamReader reader(buffer);
	for (int i = 0; i < 3; ++i) {
		MasterData::MarioData data;
		data.Load(reader);
		datas.push_back(data);
	}
}
