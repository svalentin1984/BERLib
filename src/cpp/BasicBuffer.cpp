#include "BasicBuffer.h"
#include "BERException/BasicBufferException.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>

namespace BER
{
	BasicBuffer::BasicBuffer(const uint32_t size)
	{
		bufferSize = size + 0;
		maxIndex = -1;
		buffer = new uint8_t[bufferSize];
		bzero(buffer, bufferSize);
	}

	BasicBuffer::~BasicBuffer()
	{
		delete[] buffer;
	}

	void BasicBuffer::Put(const uint32_t index, const uint8_t byte)
	{
		if(index >= bufferSize)
		{
			throw BasicBufferException();
		}
		else
		{
			writeAtIndex(index, byte);
		}
	}

	uint8_t BasicBuffer::Get(const uint32_t index) const
	{
		if(index > (uint32_t)maxIndex)
		{
			throw BasicBufferException();
		}

		return buffer[index];
	}

	void BasicBuffer::PushFront(const uint8_t byte)
	{
		if(true == IsFull())
		{
			throw BasicBufferException();
		}
		else
		{
			if(false == IsEmpty())
			{
				int16_t index = maxIndex;

				while( -1 != index )
				{
					writeAtIndex( uint32_t(index + 1), buffer[index] );
					index--;
				}
			}
			writeAtIndex(0, byte);
		}
	}

	void BasicBuffer::PushBack(const uint8_t byte)
	{
		if(true == IsFull())
		{
			throw BasicBufferException();
		}
		else
		{
			writeAtIndex( uint32_t(maxIndex + 1), byte );
		}
	}


	void BasicBuffer::writeAtIndex(const uint32_t index, const uint8_t byte)
	{
		buffer[index] = byte;

		if( int32_t(index) > maxIndex )
		{
			maxIndex = int32_t(index);
		}
	}

	void BasicBuffer::Erase(const uint32_t index)
	{
		if (((int64_t)index > maxIndex) | (maxIndex < 0))
		{
			throw BasicBufferException();
		}
		for (int64_t i = index; i < maxIndex; i++)
		{
			buffer[i] = buffer[i + 1];
		}
		maxIndex -= 1;
	}

	bool BasicBuffer::IsEmpty(void)
	{
		bool ret = false;

		if(-1 == maxIndex)
		{
			ret = true;
		}

		return ret;
	}

	bool BasicBuffer::IsFull(void)
	{
		bool ret = false;

		if(maxIndex == int32_t(bufferSize - 1))
		{
			ret = true;
		}

		return ret;
	}

	uint32_t BasicBuffer::Size()
	{
		return maxIndex + 1;
	}

	uint8_t *BasicBuffer::GetBufferAddress()
	{
		return buffer;
	}

	void BasicBuffer::Clear(void)
	{
		bzero(buffer, bufferSize);
		maxIndex = -1;
	}

	string BasicBuffer::BufferToString(uint8_t* buffer, uint32_t size)
	{
		uint32_t i = 0;
		ostringstream oss;
		for (i = 0; i < size; i++)
		{
			oss << hex << setfill('0') << setw(2) << (uint32_t)buffer[i];
		}
		return oss.str();
	}

	string BasicBuffer::BasicBufferToString(BasicBuffer* buffer)
	{
		return BufferToString(buffer->GetBufferAddress(), buffer->Size());
	}
}
