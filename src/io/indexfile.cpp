#include "indexfile.h"

IndexFile::IndexFile()
	: file(NULL)
{
}

IndexFile::~IndexFile()
{
	Close();
}

bool IndexFile::Open(const char *path)
{
	file = fopen(path, "rb");

	if (file == NULL)
	{
		return false;
	}

	fseek(file, 0, SEEK_END);
	entries.resize(ftell(file) / 12);
	fseek(file, 0, SEEK_SET);

	fread(&entries[0], sizeof(IndexEntry), entries.size(), file);

	return true;
}

bool IndexFile::Close()
{
	if (file != NULL && fclose(file) != 0)
	{
		return false;
	}

	file = NULL;

	return true;
}

IndexEntry * IndexFile::GetEntry(int id)
{
	if (id < 0 || id >= count())
	{
		return NULL;
	}

	return &entries[id];
}