#include "BaseBERType.h"
#include <stdint.h>
#include "BasicBuffer.h"
#include <list>
using namespace std;


namespace BER
{
	template class BaseBERType<uint8_t>;
	template class BaseBERType<int8_t>;
	template class BaseBERType< list<bool> >;
	template class BaseBERType<bool>;
	template class BaseBERType<uint64_t>;
	template class BaseBERType<uint32_t>;
	template class BaseBERType<uint16_t>;
	template class BaseBERType<int16_t>;
	template class BaseBERType< list<uint8_t> >;
	template class BaseBERType< BasicBuffer >;
	template class BaseBERType< list<Ber*> >;

	template <class BaseType> BasicBuffer* BaseBERType<BaseType>::Encode()
	{
		return Encode(this->Value);
	}

	template <class BaseType> BasicBuffer* BaseBERType<BaseType>::Encode(void *value)
	{
		return Encode((BaseType*)value);
	}

	template <class BaseType> uint32_t BaseBERType<BaseType>::Size()
	{
		return Size(this->Value);
	}


	template <class BaseType> uint32_t BaseBERType<BaseType>::Size(void *value)
	{
		return Size((BaseType*)value);
	}

	template <class BaseType> void* BaseBERType<BaseType>::DecodeData(BasicBuffer &buffer, uint32_t &index)
	{
		this->Value = Decode(buffer, index);
		return Value;
	}	

	template <class BaseType> BaseBERType<BaseType>::~BaseBERType()
	{
		if (Value != NULL)
		{
			DELETE(this->Value);
		}
	}

}

