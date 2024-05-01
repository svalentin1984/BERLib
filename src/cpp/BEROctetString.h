#pragma once

#include "BaseBERType.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <string>
using namespace std;


namespace BER
{
	class BEROctetString : public BaseBERType< BasicBuffer >
	{
	public:
		using BaseBERType< BasicBuffer >::Encode;
		using BaseBERType< BasicBuffer >::Size;
		virtual uint32_t Size(BasicBuffer *value);
		virtual BasicBuffer* Encode(BasicBuffer *value);
		virtual BasicBuffer* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BEROctetString();
		virtual string toString();
		static BEROctetString* EncodeString(const char *string, uint32_t length);
		static BEROctetString* EncodeString(const char *string);
		static BEROctetString* EncodeString(string str);
	};

}
