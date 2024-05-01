#pragma once

#include "BasicBuffer.h"
#include "BaseBERType.h"
#include <stdint.h>
#include <list>

namespace BER
{
	class BERLongUnsigned : public BaseBERType<uint16_t>
	{
	public:
		using BaseBERType<uint16_t>::Encode;
		using BaseBERType<uint16_t>::Size;
		virtual uint32_t Size(uint16_t *value);
		virtual BasicBuffer* Encode(uint16_t *value);
		virtual uint16_t* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERLongUnsigned();
		virtual string toString();
	};

}
