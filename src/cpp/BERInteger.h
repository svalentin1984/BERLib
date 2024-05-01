#pragma once

#include "BasicBuffer.h"
#include "BaseBERType.h"
#include <stdint.h>

namespace BER
{
	class BERInteger : public BaseBERType<int8_t>
	{
	public:
		using BaseBERType<int8_t>::Encode;
		using BaseBERType<int8_t>::Size;
		virtual uint32_t Size(int8_t *value);
		virtual BasicBuffer* Encode(int8_t *value);
		virtual int8_t* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERInteger();
		virtual string toString();
	};

}
