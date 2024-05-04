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

		//! Encode this BER Type object into a raw BasicBuffer object
		//! \return A dynamically allocated BasicBuffer* object containing this encoded BER Type
		virtual BasicBuffer* Encode();		
		//! Encode this BER Type object into a raw BasicBuffer object with the value provided by the argument		
		//! \param value The value with will be used to encode this BER Type object
		//! \return A dynamically allocated BasicBuffer* object containing this encoded BER Type
		virtual BasicBuffer* Encode(void *value);

		//! Calculte the size in bytes of this BER Type encoded into a BasicBuffer object.
		//! This method does not actually encode this BER Type. It only provides the size of the encoding in bytes. 
		//! \return The size in bytes of this BER Type encoded into a BasicBuffer
		virtual uint32_t Size();

		//! Calculate the size in bytes of this BER Type encoded into a BasicBuffer object using the value given as argument.
		//! This method does not actually encode this BER Type.  It only provides the size of the encoding in bytes. 
		//! \param value The value of this BER Type that will be used to calculate the size of the encoding.
		//! \return The size in bytes of this BER Type encoded into a BasicBuffer.
		virtual uint32_t Size(void *value);

		//! Decodes the raw bytes provided using the BasicBuffer object into this BER Type
		//! \param[in] buffer The BasicBuffer object containg the raw bytes to be decoded
		//! \param[in,out] index The index in the buffer from where the decoding will start. After the decoding this parameter will hold the value of the new index in the buffer after the decoding has ended. 
		virtual void* DecodeData(BasicBuffer &buffer, uint32_t &index);


		//! Encodes this BER Type into a BasicBuffer object with the value provided as argument
		//! \param value THe value of this BER Type to be used in encoding. 
		//! \return A dynamically allocated BasicBuffer* object containing the result of the encoding
		virtual BasicBuffer* Encode(BaseType *value) = 0;
		
		//! Calculate the size in bytes of this BER Type encoded into a BasicBuffer object using the value given as argument.
		//! This method does not actually encode this BER Type.  It only provides the size of the encoding in bytes. 
		//! \param value The value of this BER Type that will be used to calculate the size of the encoding.
		//! \return The size in bytes of this BER Type encoded into a BasicBuffer.
		virtual uint32_t Size(BaseType *value) = 0;

		//! Decodes the raw bytes provided using the BasicBuffer object into this BER Type
		//! \param[in] buffer The BasicBuffer object containg the raw bytes to be decoded
		//! \param[in,out] index The index in the buffer from where the decoding will start. After the decoding this parameter will hold the value of the new index in the buffer after the decoding has ended. 
		virtual BaseType* Decode(BasicBuffer &buffer, uint32_t &index) = 0;
		
		//! Method that returns a string representation of the current BER Type
		//! \return The string representation of the current BER Type
		virtual string toString() = 0;

		virtual ~BaseBERType();
	};


}
