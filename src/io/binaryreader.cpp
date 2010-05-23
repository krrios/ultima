#include "binaryreader.h"
#include <algorithm>

BinaryReader::BinaryReader(uint8_t *&source, uint32_t length)
	: position_(0)
{
	data_.resize(length);
	std::copy(source, source + length, data_.begin());
}

BinaryReader::BinaryReader(const std::vector<uint8_t> &source)
	: position_(0)
{
	data_.resize(source.size());
	std::copy(source.begin(), source.end(), data_.begin());
}

bool BinaryReader::Seek(int32_t offset, SeekOrigin origin)
{
	uint32_t new_pos;

	if (origin == START) new_pos = offset;
	if (origin == CURRENT) new_pos = position_ + offset;
	if (origin == END) new_pos = data_.size() - offset - 1;

	if (new_pos >= data_.size())
	{
		return false;
	}

	position_ = new_pos;

	return true;
}

void * BinaryReader::ReadBytes(size_t size, size_t count)
{
	size_t offset = size * count;

	if (offset >= data_.size())
	{
		return NULL;
	}

	position_ += offset;

	return &data_[position_ - offset];
}

uint8_t BinaryReader::ReadUint8()
{
	return ReadT<uint8_t>();
}

uint16_t BinaryReader::ReadUint16()
{
	return ReadT<uint16_t>();
}

uint32_t BinaryReader::ReadUint32()
{
	return ReadT<uint32_t>();
}

uint64_t BinaryReader::ReadUint64()
{
	return ReadT<uint64_t>();
}

int8_t BinaryReader::ReadInt8()
{
	return ReadT<int8_t>();
}

int16_t BinaryReader::ReadInt16()
{
	return ReadT<int16_t>();
}

int32_t BinaryReader::ReadInt32()
{
	return ReadT<int32_t>();
}

int64_t BinaryReader::ReadInt64()
{
	return ReadT<int64_t>();
}