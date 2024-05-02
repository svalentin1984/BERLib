#pragma once

#include "BaseBER.h"
#include <stdint.h>
#include "BasicBuffer.h"
#include <list>
using namespace std;

namespace BER
{
	//! \brief A generic template extending the Ber general type.
	//! \details This generic template allows the implementation of each type of BER. It defines the actual data types that will store the values of the BER Types,
	//! This template extends the Ber generic type and thus it re-defines the method accordingly.
	//!	It also provides a generic implementation where possible.
	//! This template should not be directly used by the programmer. The programmer should use the Ber class instead
	//! \tparam BaseType This template parameters holds the actual BER Type class implementing it
	template <class BaseType> class BaseBERType : public Ber
	{
	public:
		//! Holds the actual payload value of the BER Type
		BaseType *Value;

		virtual BasicBuffer* Encode();		
		virtual BasicBuffer* Encode(void *value);

		virtual uint32_t Size();
		virtual uint32_t Size(void *value);

		virtual void* DecodeData(BasicBuffer &buffer, uint32_t &index);

		virtual BasicBuffer* Encode(BaseType *value) = 0;
		virtual uint32_t Size(BaseType *value) = 0;
		virtual BaseType* Decode(BasicBuffer &buffer, uint32_t &index) = 0;
		virtual string toString() = 0;

		virtual ~BaseBERType();
	};


}
