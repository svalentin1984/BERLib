#pragma once

#include <list>
#include <stdint.h>
#include <string>

using namespace std;

#include "BasicBuffer.h"
using namespace BER;

namespace BER
{
	class Ber
	{
	public:
		virtual BasicBuffer* Encode() = 0;
		virtual BasicBuffer* Encode(void *value) = 0;
		virtual uint32_t Size() = 0;
		virtual uint32_t Size(void *value) = 0;
		virtual string toString() = 0;

		virtual void *DecodeData(BasicBuffer &buffer, uint32_t &index) = 0;

		virtual ~Ber() {/* cout << "calling ber destructor\n";*/ }


	};
}


