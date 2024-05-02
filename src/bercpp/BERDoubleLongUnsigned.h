#pragma once
#include "BaseBERType.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
using namespace std;

namespace BER
{

	class BERDoubleLongUnsigned : public BaseBERType<uint32_t>
	{
	public:
		using BaseBERType<uint32_t>::Encode;
		using BaseBERType<uint32_t>::Size;

		virtual uint32_t Size(uint32_t *value);
		virtual BasicBuffer* Encode(uint32_t *value);
		virtual uint32_t* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERDoubleLongUnsigned();
		virtual string toString();
	};

}
