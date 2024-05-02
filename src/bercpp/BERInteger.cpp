#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERInteger.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <sstream>
using namespace std;


namespace BER
{
	uint32_t BERInteger::Size(int8_t *value)
	{
		return 2;
	}

	BasicBuffer* BERInteger::Encode(int8_t *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::Integer);
		result->PushBack((uint8_t)(*value));
		return result;
	}

	int8_t* BERInteger::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Integer)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		int8_t *temp = new int8_t(buffer.Get(index++));
		return temp;
	}

	BERInteger::~BERInteger()
	{
		DELETE(this->Value);
	}

	string BERInteger::toString()
	{
		ostringstream oss;
		oss << "{BERInteger: " << (int32_t)(*Value) << "}" ;
		return oss.str();
	}

}
