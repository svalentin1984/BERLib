#include "BaseBER.h"
#include "BERArray.h"
#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERFactory.h"
#include "BERUtils.h"

#include "BERFactory.h"
#include "BERUtils.h"
#include <stdint.h>

#include <sstream>
#include "BasicBuffer.h"
#include "BERException/BasicBufferException.h"

namespace BER
{
	uint32_t BERArray::Size(list<Ber*> *value)
	{
		uint32_t result = 0;
		list<uint8_t> *temp = BERUtils::EncodeLength(value->size());
		result += temp->size();
		DELETE(temp);
		list<Ber*>::iterator p = value->begin();	
		while (p != value->end())
		{
			result += (*p++)->Size();			
		}		
		return result + 1;
	}

	BasicBuffer* BERArray::Encode(list<Ber*> *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::Array);

		list<uint8_t> *temp = BERUtils::EncodeLength(value->size());
		list<uint8_t>::iterator it = temp->begin();
		while (it != temp->end())
		{
			result->PushBack(*it++);
		}
		DELETE(temp);

		list<Ber*>::iterator p = value->begin();	
		BasicBuffer *tempBuffer;
		while (p != value->end())
		{
			tempBuffer = (*p)->Encode();
			for (uint32_t i = 0; i < tempBuffer->Size(); i++)
			{
				result->PushBack(tempBuffer->Get(i));
			}

			DELETE(tempBuffer);
			p++;
		}
		return result;
	}

	list<Ber*>* BERArray::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Array)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		//uint8_t temp = buffer.Get(index++);
		uint32_t length = BERUtils::DecodeLength(buffer, index);
		list<Ber*> *result = new list<Ber*>();
		Ber *b;
		for (uint32_t i = 0; i < length; i++)
		{
			try
			{
				b = BER::CreateBER((BERCodes)(buffer.Get(index)));
				b->DecodeData(buffer, index);
				result->push_back(b);
			}
			catch (BasicBufferException &ex)
			{
				return result;
			}
			catch (BaseException &ex)
			{
				throw;
			}
			catch (exception &ex)
			{
				throw;
			}
		}
		return result;
	}

	BERArray::~BERArray()
	{
		Ber *temp;
		list<Ber*>::iterator it = ((list<Ber*>*)Value)->begin();
		while (it != ((list<Ber*>*)Value)->end())
		{
			temp = (Ber*)(*it);
			delete temp;
			it++;
		}
	}

	string BERArray::toString()
	{

		ostringstream oss;
		oss << "{BERArray: " << (uint32_t)Value->size() << " ";
		list<Ber*>::iterator p = Value->begin();
		while (p != Value->end())
		{
			Ber *element = *p;
			oss << element->toString();
			p++;
		}
		oss << "}";
		return oss.str();

	}
}
