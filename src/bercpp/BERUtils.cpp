#include "BERUtils.h"
#include <stdint.h>

#include <list>
using namespace std;

#include "BasicBuffer.h"

namespace BER
{
	BasicBuffer* BERUtils::DecodeFlagList(BasicBuffer *flagList, uint32_t count)
	{
		BasicBuffer *result = new BasicBuffer(count);
		uint8_t temp = 0;
		for (uint32_t j = 0; j < flagList->Size(); j++)
		{
			temp = flagList->Get(j);
			for (int8_t i = 7; (i >= 0) && (count > 0); i--, count--)
			{
				result->PushBack((((temp >> i) & 1) != 0) ? true : false);
			}

		}
		return result;
	}

	BasicBuffer* BERUtils::EncodeFlagList(BasicBuffer *bitList)
	{
		
		// compute the number of bytes needed to encode the bit list
		uint16_t byteCount = bitList->Size() / 8;
		if ((bitList->Size() % 8) != 0)
		{
			byteCount = byteCount + 1;
		}
		//list<uint8_t> *result = new list<uint8_t>;
		BasicBuffer *result = new BasicBuffer(byteCount);
		uint8_t mask = 0x80;
		uint8_t bitcount = 0;
		uint8_t tempByte = 0;

		for (uint16_t i = 0; i < bitList->Size(); i++)
		{
			if (((bool)bitList->Get(i)) == true)
			{
				tempByte |= mask;
			}
			
			mask = mask >> 1;
			bitcount++;
			if ((bitcount == 8) || (i == bitList->Size() - 1))
			{
				result->PushBack(tempByte);
				mask = 0x80;
				tempByte = 0;
				bitcount = 0;
			}
		}
		//result->reverse();
		return result;
	}

	uint32_t BERUtils::DecodeLength(BasicBuffer &buffer, uint32_t &index)
	{
		uint32_t length = 0;
		uint8_t temp = buffer.Get(index++);
		if (temp <= 0x80)
		{
			length = temp;
		}
		else
		{
			for (uint8_t i = 0; i < (temp - 0x80); i++)
			{
				length = (length << 8) | buffer.Get(index);
				index++;
			}		
		}
		return length;
	}

	list<uint8_t>* BERUtils::EncodeLength(uint32_t length)
	{
		list<uint8_t> *result = new list<uint8_t>;
		uint8_t bytenr = 0;
		// find the number of bytes needed to encode the length
		if (length <= 0x80) // < 2^8
		{
			bytenr = 1;
		}
		else
		{
			if (length < 65536) // < 2^16
			{
				bytenr = 2;
			}
			else
			{
				if (length < 16777216) // < 2^24
				{
					bytenr = 3;
				}
				else
				{
					bytenr = 4; 
				}
			}
		}
		if (bytenr == 1)
		{
			// only one byte needed for length... encode it as it is
			result->push_back(length & 0xFF);
		}
		else
		{
			// more bytes needed for length... encoding the length of the length
			result->push_back(0x80 | (bytenr & 0xF));		
			for (int8_t i = bytenr - 1; i >= 0; i--)
			{
				result->push_back((length >> (i * 8)) & 0xFF);
			}
		}
		return result;
	}

}
