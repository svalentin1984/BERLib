#include "BERException/BERExceptions.h"
#include "BERLong.h"
#include "BERCodes.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <sstream>
using namespace std;

namespace BER
{
	uint32_t BERLong::Size(int16_t *value)
	{
		return 3;	
	}

	BasicBuffer* BERLong::Encode(int16_t *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::Long);
		for (int8_t i = 1; i >= 0; i--)
		{
			result->PushBack(((*value) >> (i * 8)) & 0xFF);
		}
		return result;
	}

	int16_t* BERLong::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Long)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		int16_t *temp = new int16_t(0);
		*temp |= buffer.Get(index++) << 8;
		*temp |= buffer.Get(index++);
		return temp;
	}
	BERLong::~BERLong()
	{
		DELETE(this->Value);
	}

	string BERLong::toString()
	{
		ostringstream oss;
		oss << "{BERLong: " << (uint32_t)(*Value) << "}" ;
		return oss.str();
	}
}
