#pragma once

#include "BaseBERType.h"
#include "BasicBuffer.h"
#include <stdint.h>
#include <list>
#include <string>
using namespace std;


namespace BER
{
	//! \brief Class implements a BEROctetString type
	class BEROctetString : public BaseBERType< BasicBuffer >
	{
	public:
		using BaseBERType< BasicBuffer >::Encode;
		using BaseBERType< BasicBuffer >::Size;
		//! Calculates the size in bytes of the encoding of this BEROctetString with the value provided as argument
		//! This method only calculates the size thus it does not actually encode this BEROctetString
		//! \param value The value of the BEROctetString to be used when calculating the encoding size. This value is only used for this method and it does not override the value contained in this BEROctetString
		//! \return The calculated size of encoding of this BEROctetString
		virtual uint32_t Size(BasicBuffer *value);
		//! Encode this BEROctetString object using the value provided as argument. The value of this BEROctetString will not be overwritten by this argument
		//! \param value The value to be used when encoding this BEROctetString
		//! \return A dynamically allocated BasicBuffer* object containing the bytes representing the encoding of this BEROctetString
		virtual BasicBuffer* Encode(BasicBuffer *value);
		//! Decode the raw byte buffer starting from the provided index into a BEROctetString object value
		//! \param[in] buffer The BasicBuffer object containing containing the raw bytes to be decoded into this BEROctetString object
		//! \param[in,out] index The index in the buffer from where the decoding process should start. After the decoding process, this value contains the index where the decoding process has ended.
		//! \return The decoded value of the BEROctetString encoded in the buffer starting at position provided by index		
		virtual BasicBuffer* Decode(BasicBuffer &buffer, uint32_t &index);
		virtual ~BEROctetString();
		//! Build a string representation of the value of this BEROctetString 
		//! \return The string representation of the value of this BEROctetString
		virtual string toString();
		//! A static method that can be used to encode a string represented as a null ('\0') terminated char array into a BEROctetString object
		//! \param string The char * null terminated string to be encoded into a BEROctetString object
		//! \param length The length of the char* null terminated string
		//! \return A dynamically allocated BEROctetString* containg the encoded string
		static BEROctetString* EncodeString(const char *string, uint32_t length);
		//! A static method that can be used to encode a string represented as a null ('\0') terminated char array into a BEROctetString object
		//! \param string The char * null terminated string to be encoded into a BEROctetString object
		//! \return A dynamically allocated BEROctetString* containg the encoded string		
		static BEROctetString* EncodeString(const char *string);
		//! A static method that can be used to encode a string represented as a string object into a BEROctetString object
		//! \param str The string object to be encoded into a BEROctetString object
		//! \return A dynamically allocated BEROctetString* containg the encoded string		
		static BEROctetString* EncodeString(string str);
	};

}
