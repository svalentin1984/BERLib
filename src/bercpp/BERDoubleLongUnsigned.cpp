#include "BERCodes.h"
#include "BERDoubleLongUnsigned.h"
#include "BERException/BERExceptions.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <sstream>
using namespace std;

namespace BER
{
	uint32_t BERDoubleLongUnsigned::Size(uint32_t *value)
	{
		return 5;
	}

	BasicBuffer* BERDoubleLongUnsigned::Encode(uint32_t *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::DoubleLongUnsigned);
		for (int8_t i = 3; i >= 0; i--)
		{
			result->PushBack(((*value) >> (i * 8)) & 0xFF);
		}
		return result;
	}

	uint32_t* BERDoubleLongUnsigned::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::DoubleLongUnsigned)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint32_t *temp = new uint32_t(0);
		*temp |= buffer.Get(index++) << 24;
		*temp |= buffer.Get(index++) << 16;
		*temp |= buffer.Get(index++) <<  8;
		*temp |= buffer.Get(index++);
		return temp;
	}

	BERDoubleLongUnsigned::~BERDoubleLongUnsigned()
	{
		DELETE(this->Value);
	}

	string BERDoubleLongUnsigned::toString()
	{
		ostringstream oss;
		oss << "{BERDoubleLongUnsigned: " << (uint32_t)(*Value) << "}" ;
		return oss.str();
	}
}
