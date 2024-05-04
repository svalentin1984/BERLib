#pragma once

#include <list>
#include <stdint.h>
#include <string>

using namespace std;

#include "BasicBuffer.h"

namespace BER
{
	//! \brief A general BER class used to define a generic BER type. 
	//! \details This class defines a generic BER data type that is extended by a template in order to generically implement all BER Types.
	//! This class is abstract and is only used to define a generic interface. This class represents the generic BER data type.

	class Ber
	{
	public:
		//! Method that encodes the value of the BER Type into a BasicBuffer
		//! \return A dynamically allocated BasicBuffer* containing the encoded BER Type
		virtual BasicBuffer* Encode() = 0;
		//! Method that encodes as the current BER Type the value provided as argument of the BER Type into a BasicBuffer
		//! \param value The value of the BER Type
		//! \return A dynamically allocated BasicBuffer* containing the encoded BER Type
		virtual BasicBuffer* Encode(void *value) = 0;
		//! Method that calculates the size in bytes of the encoded value of the BER Type into a BasicBuffer
		//! \return The size in bytes of the encoded BER Type
		virtual uint32_t Size() = 0;
		//! Method that calculates the size in bytes of the encoded value provided as argument of BER Type into a BasicBuffer
		//! \param value The value of the BER Type
		//! \return The size in bytes of the encoded BER Type
		virtual uint32_t Size(void *value) = 0;
		//! This method returns a string representation of the current BER Type
		//! \return The string representation of the current BER Type
		virtual string toString() = 0;
		//! Method that decodes a stream of bytes provided by a BasicBuffer into the calling BER Type
		//! \param[in] buffer The BasicBuffer object containing the raw data to be decoded
		//! \param[in,out] index The index in the buffer from where the decoding will start. After the decoding this parameter will hold the value of the new index in the buffer after the decoding has ended. 
		//! \return The payload of the decoded value
		virtual void *DecodeData(BasicBuffer &buffer, uint32_t &index) = 0;

		virtual ~Ber() {/* cout << "calling ber destructor\n";*/ }


	};
}


