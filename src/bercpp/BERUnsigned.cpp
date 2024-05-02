#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERUnsigned.h"
#include "BasicBuffer.h"
#include <list>
#include <sstream>
using namespace std;

namespace BER
{
	uint32_t BERUnsigned::Size(uint8_t *value)
	{
		return 2;
	}

	BasicBuffer* BERUnsigned::Encode(uint8_t *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));

		result->PushBack(BER::Unsigned);
		result->PushBack(*value);
		return result;
	}

	uint8_t* BERUnsigned::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Unsigned)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint8_t *temp = new uint8_t(buffer.Get(index++));
		return temp;
	}

	BERUnsigned::~BERUnsigned()
	{
		DELETE(this->Value);
	}

	string BERUnsigned::toString()
	{
		ostringstream oss;
		oss << "{BERUnsigned: " << (uint32_t)(*Value) << "}" ;
		return oss.str();
	}
}
