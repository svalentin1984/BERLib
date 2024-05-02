#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERLong64Unsigned.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <sstream>
using namespace std;

namespace BER										
{
	uint32_t BERLong64Unsigned::Size(uint64_t *value)
	{
		return 9;
	}

	BasicBuffer* BERLong64Unsigned::Encode(uint64_t *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::Long64Unsigned);
		for (int8_t i = 7; i >= 0; i--)
		{
			result->PushBack(((*value) >> (i * 8)) & 0xFF);
		}
		return result;
	}

	uint64_t* BERLong64Unsigned::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Long64Unsigned)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint64_t *temp = new uint64_t(0);
		for (uint8_t i = 0; i < 8; i++)
		{
			*temp = (((*temp) << 8) | buffer.Get(index++));
		}
		return temp;
	}
	
	BERLong64Unsigned::~BERLong64Unsigned()
	{
		DELETE(this->Value);
	}

	string BERLong64Unsigned::toString()
	{
		ostringstream oss;
		oss << "{BERLong64Unsigned: " << (uint64_t)(*Value) << "}" ;
		return oss.str();
	}

}
