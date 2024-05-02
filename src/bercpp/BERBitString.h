#pragma once

#include "BaseBERType.h"
#include <list>
#include "BasicBuffer.h"
using namespace std;

namespace BER
{
	class BERBitString : public BaseBERType< BasicBuffer >
	{
	public:
		using BaseBERType< BasicBuffer >::Encode;
		using BaseBERType< BasicBuffer >::Size;

		virtual uint32_t Size(BasicBuffer *value);
		virtual BasicBuffer* Encode(BasicBuffer *value);
		
		virtual BasicBuffer* Decode(BasicBuffer &buffer, uint32_t &index);

		virtual ~BERBitString();
		virtual string toString();
	};
}
