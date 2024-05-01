#pragma once

#include "BasicBuffer.h"
#include "BaseBERType.h"
#include <stdint.h>

namespace BER
{
	class BERNullData : public BaseBERType<uint8_t>
	{
	public:
		using BaseBERType<uint8_t>::Encode;
		using BaseBERType<uint8_t>::Size;
		virtual BasicBuffer* Encode(uint8_t *value);

		virtual uint32_t Size(uint8_t *value);
		
		virtual uint8_t * Decode(BasicBuffer &buffer, uint32_t &index);
		virtual string toString();
	};

}

