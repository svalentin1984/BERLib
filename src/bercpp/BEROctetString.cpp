#include <list>
#include <ctype.h>
#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BasicBuffer.h"
#include "BEROctetString.h"
#include "BERUtils.h"
#include <stdint.h>
#include <iomanip>
#include <string.h>

#include <list>
#include <sstream>
using namespace std;

namespace BER
{
	uint32_t BEROctetString::Size(BasicBuffer *value)
	{
		uint32_t result = 0;
		list<uint8_t> *temp = BERUtils::EncodeLength(value->Size());
		result += temp->size();
		DELETE(temp);
		result += value->Size();
		return result + 1;
	}

	BasicBuffer* BEROctetString::Encode(BasicBuffer *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::OctetString);
		list<uint8_t> *temp = BERUtils::EncodeLength(value->Size());
		list<uint8_t>::iterator it = temp->begin();
		while (it != temp->end())
		{
			result->PushBack(*it++);
		}
		for (uint16_t i = 0; i < value->Size(); i++)
		{
			result->PushBack(value->Get(i));
		}
		DELETE(temp);
		return result;
	}

	BasicBuffer* BEROctetString::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::OctetString)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint32_t length = BERUtils::DecodeLength(buffer, index);
		BasicBuffer *result = new BasicBuffer(length);
		for (uint16_t i = 0; i < length; i++)
		{
			result->PushBack(buffer.Get(index++));
		}
		return result;
	}
	
	BEROctetString::~BEROctetString()
	{
		DELETE(this->Value);
	}

	string BEROctetString::toString()
	{
		ostringstream oss;
		oss << "{BEROctetString: ";
		for (uint32_t i = 0; i < Value->Size(); i++)
		{
			uint8_t ch = Value->Get(i);
			oss << " 0x";
			oss << setfill('0') << setw(2) << hex << uppercase << (uint32_t)ch;
			oss << " ";
		}
		oss << "}";
		return oss.str();
	}

	BEROctetString* BEROctetString::EncodeString(const char *str, uint32_t length)
	{
		BEROctetString *result = new BEROctetString();
		result->Value = new BasicBuffer(length);
		for (uint32_t i = 0; i < length; i++)
		{
			result->Value->PushBack(str[i]);
		}
		return result;
	}

	BEROctetString* BEROctetString::EncodeString(const char *str)
	{
		return EncodeString(str, strlen(str));
	}

	BEROctetString* BEROctetString::EncodeString(string str)
	{
		return EncodeString(str.c_str(), str.size());
	}
}
