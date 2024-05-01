#pragma once

#include "BaseBER.h"
#include <stdint.h>

#include <list>
using namespace std;

#include "BasicBuffer.h"

namespace BER
{
	template <class BaseType> class BaseBERType : public Ber
	{
	public:
		BaseType *Value;

		virtual BasicBuffer* Encode();		
		virtual BasicBuffer* Encode(void *value);

		virtual uint32_t Size();
		virtual uint32_t Size(void *value);

		virtual void* DecodeData(BasicBuffer &buffer, uint32_t &index);

		virtual BasicBuffer* Encode(BaseType *value) = 0;
		virtual uint32_t Size(BaseType *value) = 0;
		virtual BaseType* Decode(BasicBuffer &buffer, uint32_t &index) = 0;
		virtual string toString() = 0;

		virtual ~BaseBERType();
	};


}
