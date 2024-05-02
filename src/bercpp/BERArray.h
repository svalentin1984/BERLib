#pragma once


#include "BaseBER.h"
#include "BaseBERType.h"
#include "BaseBER.h"
#include <stdint.h>
#include <list>
#include <string>

namespace BER
{
	class BERArray : public BaseBERType< list<Ber*> >
	{
	public:
		using BaseBERType< list<Ber*> >::Encode;
		using BaseBERType< list<Ber*> >::Size;
		virtual uint32_t Size(list<Ber*> *value);
		virtual BasicBuffer* Encode(list<Ber*> *value);
		virtual list<Ber*>* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERArray();
		virtual string toString();
	};
}
