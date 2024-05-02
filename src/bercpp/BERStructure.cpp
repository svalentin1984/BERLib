#include "BaseBER.h"
#include "BERCodes.h"
#include "BERException/BERExceptions.h"
#include "BERFactory.h"
#include "BERStructure.h"
#include "BERUtils.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <sstream>
#include <string>
#include <list>
using namespace std;

namespace BER
{
	uint32_t BERStructure::Size(list<Ber*> *value)
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

	BasicBuffer* BERStructure::Encode(list<Ber*> *value)
	{
		BasicBuffer *result = new BasicBuffer(Size(value));
		result->PushBack(BER::Structure);

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

	list<Ber*>* BERStructure::Decode(BasicBuffer &buffer, uint32_t &index)
	{
		if (buffer.Get(index) != BER::Structure)
		{
			throw BERTypeIncorrectTag();
		}
		index++;
		uint8_t length = buffer.Get(index++);
		list<Ber*> *result = new list<Ber*>();
		Ber *b;
		for (uint32_t i = 0; i < length; i++)
		{
			b = BER::CreateBER((BERCodes)(buffer.Get(index)));
			b->DecodeData(buffer, index);
			result->push_back(b);
		}
		return result;
	}

	BERStructure::~BERStructure()
	{
		Ber *temp;
		list<Ber*>::iterator it = ((list<Ber*>*)Value)->begin();
		while (it != ((list<Ber*>*)Value)->end())
		{
			temp = (Ber*)(*it);
			delete temp;
			it++;
		}
		((list<Ber*>*)Value)->clear();
	}

	string BERStructure::toString()
	{
		ostringstream oss;
		oss << "{BERStructure: " << (uint32_t)Value->size() << " ";
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

