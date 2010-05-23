#ifndef ULTIMA_INDEXFILE_H_
#define ULTIMA_INDEXFILE_H_

#include "../ultima.h"
#include <fstream>
#include <vector>

#ifdef WIN32
	#pragma pack(push, 1)
#endif

struct PACKED IndexEntry
{
	int32_t offset;
	int32_t length;
	int32_t extra;
};

#ifdef WIN32
	#pragma pack(pop)
#endif
	
class IndexFile
{
	public:

		IndexFile();

		~IndexFile();
		
		bool Open(const std::string &path);

		bool Close();
		
		IndexEntry * GetEntry(int id);

		int entry_count() const { return entries_.size(); }

	private:
		
		std::ifstream file_;
		
		std::vector<IndexEntry> entries_;
};

#endif