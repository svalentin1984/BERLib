#pragma once

#include <list>
#include <stdint.h>
using namespace std;

#include "BasicBuffer.h"

namespace BER
{
	//! \brief An abstract class containing static helper methods required by the BER implementation
	class BERUtils
	{
		public:
		virtual void Dummy() = 0;
		virtual ~BERUtils();
		public:
		//! Decodes the flags encoded according to a BERBitString in a bitwise manner into a boolean byte array both implemented using a BasicBuffer
		//! \param flagList The flagList in bitwise implementation to be decoded into a boolean byte buffer
		//! \param count The number of flags contained encoded into the flagList
		//! \return A dynamically allocated BasicBuffer* object containing the decoded bitwise flags into a boolean buffer array
		static BasicBuffer* DecodeFlagList(BasicBuffer *flagList, uint32_t count);
		//! Encodes a flag list provided in a boolean buffer into a bitwise format according to a BERBitString.
		//! \param bitList The flag list contained in a BasicBuffer object as a boolean buffer
		//! \return A dynamically allocated BasicBuffer* object containing the encoded flags in bitwise format.		
		static BasicBuffer* EncodeFlagList(BasicBuffer *bitList);
		//! Encodes a length value into a format according to the Basic Encoding Rules
		//! \param length The value of the length to be encoded
		//! \return A dynamically allocated list containing the raw bytes of the encoded length
		static list<uint8_t> *EncodeLength(uint32_t length);
		//! Decode a length value encoded according to the Basic Encoding Rules
		//! \param[in] buffer The BasicBuffer object containing the encoded length value
		//! \param[in,out] index The index in the buffer from where the decoding process should start. After the decoding process, this value contains the index where the decoding process has ended.
		static uint32_t DecodeLength(BasicBuffer &buffer, uint32_t &index);
	};
		
}	
