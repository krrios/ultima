#include "indexfile.h"

IndexFile::IndexFile()
	: file_()
{
}

IndexFile::~IndexFile()
{
	Close();
}

bool IndexFile::Open(const std::string &path)
{
	file_.open(path, std::ios::binary | std::ios::in | std::ios::ate);

	if (file_.is_open() == false)
	{
		return false;
	}
	
	entries_.resize(static_cast<size_t>(file_.tellg() / sizeof(IndexEntry)));

	file_.seekg(0, std::ios::beg);
	file_.read(reinterpret_cast<char *>(&entries_[0]), entries_.size() * sizeof(IndexEntry));

	return true;
}

bool IndexFile::Close()
{
	if (file_.is_open())
	{
		file_.close();
		return true;
	}

	return false;
}

IndexEntry * IndexFile::GetEntry(int id)
{
	if (id < 0 || id >= entry_count())
	{
		return NULL;
	}

	return &entries_[id];
}