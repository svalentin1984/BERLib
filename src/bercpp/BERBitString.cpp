#include "BERBitString.h"
#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERUtils.h"
#include "BasicBuffer.h"
#include <sstream>
#include <stdint.h>
#include <list>
using namespace std;

namespace BER
{
	uint32_t BERBitString::Size(BasicBuffer *value)
	{
		uint32_t result = 0;
		list<uint8_t> *tempList = BERUtils::EncodeLength(value->Size());
		result += tempList->size();
		DELETE(tempList);
		result += value->Size() / 8;
		if ((value->Size() % 8) != 0)
		{
			result++;
		}
		return result + 1;
	}

	BasicBuffer* BERBitString::Encode(BasicBuffer *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		// encode the tag
		result->PushBack(BER::BitString);
		// encode the length
		list<uint8_t> *tempList = BERUtils::EncodeLength(value->Size());
		list<uint8_t>::iterator it = tempList->begin();
		while (it != tempList->end())
		{
			result->PushBack(*it++);
		}
		// encode the content
		DELETE(tempList);
		BasicBuffer *tempBasicBuffer = BERUtils::EncodeFlagList(value);
		//it = tempList->begin();
		
		//while (it != tempList->end())
		for (uint32_t i = 0; i < tempBasicBuffer->Size(); i++)
		{
			result->PushBack(tempBasicBuffer->Get(i));
		}
		DELETE(tempBasicBuffer);
		return result;
	}

	BasicBuffer* BERBitString::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		BasicBuffer* result = NULL;
		if (buffer.Get(index) != BER::BitString)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint32_t length = BERUtils::DecodeLength(buffer, index);
		uint16_t ByteCount = 0;
		if ((length % 8) == 0)
		{
			ByteCount = length / 8;
		}
		else
		{
			ByteCount = (length / 8) + 1;
		}
		BasicBuffer *byteList = new BasicBuffer(ByteCount);
		for (uint16_t i = 0; i < ByteCount; i++)
		{
			byteList->PushBack(buffer.Get(index++));
		}
		result = BERUtils::DecodeFlagList(byteList, length);
		DELETE(byteList);
		return result;
	}
	BERBitString::~BERBitString()
	{
		DELETE(this->Value);
	}

	string BERBitString::toString()
	{

		ostringstream oss;

		oss << "{BERArray: " << (uint32_t)Value->Size() << " ";
		for (uint32_t i = 0; i < Value->Size(); i++)
		{
			bool v = Value->Get(i);
			if (v)
			{
				oss << "T";
			}
			else
			{
				oss << "F";
			}

		}
		oss << "}";
		return oss.str();

	}

}
