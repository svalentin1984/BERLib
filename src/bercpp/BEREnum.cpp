#include "BERCodes.h"
#include "BEREnum.h"
#include "BERException/BERExceptions.h"
#include "BasicBuffer.h"
#include <list>
#include <string>
#include <sstream>

using namespace std;


namespace BER
{
	uint32_t BEREnum::Size(uint8_t *value)
	{
		return 2;
	}

	BasicBuffer* BEREnum::Encode(uint8_t *value)
	{
		BasicBuffer *v = new BasicBuffer(Size(value));
		v->PushBack(BER::Enum);
		v->PushBack(*value);
		return v;
	}

	uint8_t* BEREnum::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Enum)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint8_t *temp = new uint8_t(buffer.Get(index++));
		return temp;
	}

	BEREnum::~BEREnum()
	{
		DELETE(this->Value);
	}
	string BEREnum::toString()
	{
		ostringstream oss;
		oss << "{BEREnum: " << (uint32_t)(*Value) << "}" ;
		return oss.str();
	}
}
