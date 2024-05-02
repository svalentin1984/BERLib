#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERNullData.h"
#include <stdint.h>
#include "BasicBuffer.h"
#include <list>
#include <sstream>
using namespace std;

namespace BER
{
	uint32_t BERNullData::Size(uint8_t *value)
	{
		return 1;
	}

	BasicBuffer* BERNullData::Encode(uint8_t *value)
	{
		BasicBuffer *v = new BasicBuffer(Size(value));
		v->PushBack(NullData);
		return v;
	}

	uint8_t* BERNullData::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != NullData)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		return NULL;
	}

	string BERNullData::toString()
	{
		ostringstream oss;
		oss << "{BERNullData}";
		return oss.str();
	}
}
