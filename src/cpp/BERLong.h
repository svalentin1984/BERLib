#pragma once

#include "BasicBuffer.h"
#include "BaseBERType.h"
#include <stdint.h>
#include <list>

namespace BER
{
	class BERLong : public BaseBERType<int16_t>
	{
	public:
		using BaseBERType<int16_t>::Encode;
		using BaseBERType<int16_t>::Size;
		virtual uint32_t Size(int16_t *value);
		virtual BasicBuffer* Encode(int16_t *value);
		virtual int16_t* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERLong();
		virtual string toString();
	};

}
