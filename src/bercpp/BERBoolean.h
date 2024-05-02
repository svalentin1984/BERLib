#pragma once
#include "BasicBuffer.h"
#include "BaseBERType.h"

#include <string>
using namespace std;

namespace BER
{
	class BERBoolean : public BaseBERType<bool>
	{
	public:

		using BaseBERType<bool>::Encode;
		using BaseBERType<bool>::Size;
		virtual uint32_t Size(bool *value);
		virtual BasicBuffer* Encode(bool *value);
		
		virtual bool * Decode(BasicBuffer &buffer, uint32_t &index);
		virtual string toString();
		virtual ~BERBoolean();
		
	};

}
