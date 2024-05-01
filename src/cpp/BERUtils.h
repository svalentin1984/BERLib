#pragma once

#include <list>
#include <stdint.h>
using namespace std;

#include "BasicBuffer.h"

namespace BER
{
	class BERUtils
	{
		public:
		virtual void Dummy() = 0;
		virtual ~BERUtils();
		public:
		static BasicBuffer* DecodeFlagList(BasicBuffer *flagList, uint32_t count);
		static BasicBuffer* EncodeFlagList(BasicBuffer *bitList);
		static list<uint8_t> *EncodeLength(uint32_t length);
		static uint32_t DecodeLength(BasicBuffer &buffer, uint32_t &index);
	};
		
}	
