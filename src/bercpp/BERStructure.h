#pragma once

#include <stdint.h>
#include <list>
using namespace std;

#include "BaseBERType.h"
#include "BaseBER.h"
#include "BasicBuffer.h"

namespace BER
{

	class BERStructure : public BaseBERType< list<Ber*> >
	{
	public:
		using BaseBERType< list<Ber*> >::Encode;
		using BaseBERType< list<Ber*> >::Size;
		virtual uint32_t Size(list<Ber*> *value);
		virtual BasicBuffer* Encode(list<Ber*> *value);
		virtual list<Ber*>* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERStructure();
		virtual string toString();
	};

}
