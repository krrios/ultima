#ifndef ULTIMA_BINARYREADER_H_
#define ULTIMA_BINARYREADER_H_

#include "../ultima.h"
#include <vector>

class BinaryReader
{
	public:

		enum SeekOrigin
		{
			START,
			CURRENT,
			END
		};

		BinaryReader(uint8_t *&source, uint32_t length);

		BinaryReader(std::vector<uint8_t> &source);

		~BinaryReader();

		bool Seek(int32_t offset, SeekOrigin origin = CURRENT);

		void * ReadBytes(size_t size, size_t count);

		template<typename T>
		T * ReadTs(size_t count)
		{
			return reinterpret_cast<T *>(ReadBytes(sizeof(T), count));
		}

		uint8_t ReadUint8();

		uint16_t ReadUint16();

		uint32_t ReadUint32();

		uint64_t ReadUint64();

		int8_t ReadInt8();

		int16_t ReadInt16();

		int32_t ReadInt32();

		int64_t ReadInt64();

	private:

		template<typename T>
		T ReadT()
		{
			void *ptr = ReadBytes(sizeof(T), 1);

			if (ptr == NULL)
			{
				return T();
			}

			return *reinterpret_cast<T *>(ptr);
		}

		uint32_t position;

		uint32_t length;

		uint8_t *data;
};

#endif