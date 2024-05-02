#include "BERBoolean.h"
#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include <list>
#include <string>
#include <sstream>
using namespace std;

#include "BasicBuffer.h"

namespace BER
{
	uint32_t BERBoolean::Size(bool *value)
	{
		return 2;
	}

	BasicBuffer* BERBoolean::Encode(bool *value)
	{
		BasicBuffer *v = new BasicBuffer(Size(value));
		v->PushBack(BER::Boolean);
		v->PushBack(*value);
		return v;
	}

	bool* BERBoolean::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Boolean)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		bool *temp = new bool( (buffer.Get(index++) != 0) ? true : false);
		return temp;
	}

	BERBoolean::~BERBoolean()
	{
		DELETE(this->Value);
	}

	string BERBoolean::toString()
	{
		ostringstream oss;
		oss << "{BERBoolean: ";
		if ( *Value == true)
		{
			oss << "True}";
		}
		else
		{
			oss << "False}";
		}
		return oss.str();
	}
}
