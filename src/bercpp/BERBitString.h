#pragma once

#include "BaseBERType.h"
#include <list>
#include "BasicBuffer.h"
using namespace std;

namespace BER
{
	//! \brief Class implements a BERBitString type
	class BERBitString : public BaseBERType< BasicBuffer >
	{
	public:
		using BaseBERType< BasicBuffer >::Encode;
		using BaseBERType< BasicBuffer >::Size;
		//! Calculates the size in bytes of the encoding of this BERBitString with the value provided as argument
		//! This method only calculates the size thus it does not actually encode this BERBitString
		//! \param value The value of the BERBitString to be used when calculating the encoding size. This value is only used for this method and it does not override the value contained in this BERBitString
		//! \return The calculated size of encoding of this BERBitString
		virtual uint32_t Size(BasicBuffer *value);
		//! Encode this BERBitString object using the value provided as argument. The value of this BERBitString will not be overwritten by this argument.
		//! This method received the value for this BERBitString as a boolean buffer implemented as a BasicBuffer object.
		//! In order to encode this BERBitString with the received value, this method will call EncodeFlagList method to obtain the bitwise encoding of the boolean buffer.
		//! \param value The value to be used when encoding this BERBitString
		//! \return A dynamically allocated BasicBuffer* object containing the bytes representing the encoding of this BERBitString
		virtual BasicBuffer* Encode(BasicBuffer *value);
		//! Decode the raw byte buffer starting from the provided index into a BERBitString object value
		//! \param[in] buffer The BasicBuffer object containing containing the raw bytes to be decoded into this BERBitString object
		//! \param[in,out] index The index in the buffer from where the decoding process should start. After the decoding process, this value contains the index where the decoding process has ended.
		//! \return The decoded value of the BERBitString encoded in the buffer starting at position provided by index		
		virtual BasicBuffer* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BERBitString();
		//! Build a string representation of the value of this BERBitString 
		//! \return The string representation of the value of this BERBitString
		virtual string toString();
	};
}
