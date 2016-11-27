#pragma once

#include <vector>
#include <string>

class StreamReader
{
public:
	StreamReader() : buffer_(nullptr), offset_(0)
	{
	}

	StreamReader(std::vector<char>& buffer) : buffer_(&buffer), offset_(0)
	{
	}

	int ReadInt()
	{
		if (offset_ + sizeof(int) > buffer_->size()) return 0;
		auto ret = *(int*)&(*buffer_)[offset_];
		offset_ += sizeof(int);
		return ret;
	}

	int ReadIntNoSeek()
	{
		auto temp = offset_;
		auto ret = ReadInt();
		offset_ = temp;
		return ret;
	}

	float ReadFloat()
	{
		if (offset_ + sizeof(float) > buffer_->size()) return 0;
		auto ret = *(float*)&(*buffer_)[offset_];
		offset_ += sizeof(float);
		return ret;
	}

	std::string ReadString()
	{
		int len = ReadInt();
		std::string ret = std::string(&(*buffer_)[offset_], len);
		offset_ += ret.length();
		return ret;
	}

	std::string ReadStringNoSeek()
	{
		auto temp = offset_;
		auto ret = ReadString();
		offset_ = temp;
		return ret;
	}

private :
	std::vector<char>* buffer_;
	size_t offset_;
};
