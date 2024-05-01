#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERLongUnsigned.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <sstream>
using namespace std;

namespace BER
{
	uint32_t BERLongUnsigned::Size(uint16_t *value)
	{
		return 3;
	}

	BasicBuffer* BERLongUnsigned::Encode(uint16_t *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		
		result->PushBack(BER::LongUnsigned);
		for (int8_t i = 1; i >= 0; i--)
		{
			result->PushBack(((*value) >> (i * 8)) & 0xFF);
		}
		return result;
	}

	uint16_t* BERLongUnsigned::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::LongUnsigned)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint16_t *temp = new uint16_t(0);
		*temp |= buffer.Get(index++) << 8;
		*temp |= buffer.Get(index++);
		return temp;
	}

	BERLongUnsigned::~BERLongUnsigned()
	{
		DELETE(this->Value);
	}

	string BERLongUnsigned::toString()
	{
		ostringstream oss;
		oss << "{BERLongUnsigned: " << (uint32_t)(*Value) << "}" ;
		return oss.str();
	}
}
