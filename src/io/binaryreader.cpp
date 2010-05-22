#include "binaryreader.h"

BinaryReader::BinaryReader(uint8_t *&source, uint32_t length)
	: position(0), length(length)
{
	data = source;
}

BinaryReader::BinaryReader(std::vector<uint8_t> &source)
	: position(0), length(source.size())
{
	data = new uint8_t[length];
	memcpy(data, &source[0], length);
}

BinaryReader::~BinaryReader()
{
	delete [] data;
}

bool BinaryReader::Seek(int32_t offset, SeekOrigin origin)
{
	uint32_t new_pos;

	if (origin == START) new_pos = offset;
	if (origin == CURRENT) new_pos = position + offset;
	if (origin == END) new_pos = length - offset - 1;

	if (new_pos >= length)
	{
		return false;
	}

	position = new_pos;

	return true;
}

void * BinaryReader::ReadBytes(size_t size, size_t count)
{
	size_t offset = size * count;

	if (offset >= length)
	{
		return NULL;
	}

	position += offset;

	return &data[position - offset];
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