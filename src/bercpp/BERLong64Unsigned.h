#pragma once

#include "BaseBERType.h"
#include "BasicBuffer.h"

#include <stdint.h>
#include <list>

using namespace std;

namespace BER
{
	class BERLong64Unsigned : public BaseBERType<uint64_t>
	{
	public:
		using BaseBERType<uint64_t>::Encode;
		using BaseBERType<uint64_t>::Size;
		virtual uint32_t Size(uint64_t *value);
		virtual BasicBuffer* Encode(uint64_t *value);
		virtual uint64_t* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERLong64Unsigned();
		virtual string toString();
	};
}
