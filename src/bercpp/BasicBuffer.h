#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <string>
#define DELETE(x) 	delete x; x = NULL

using namespace std;
//! \namespace BER
//! \brief Contains general use classes
namespace BER
{
	//! \brief Modeling a byte linear buffer
	//!
	//! This class is used to implement a general linear byte buffer in C++. The reason for this implementation is the lack of such a data type in C++
	//!
	//! STL only contains the vector class (and other related classes) which give a significant memory overhead
	//! This implementation tends to imitate the vector class but with a lower memory footprint
	class BasicBuffer
	{
		private:
			uint8_t *buffer;			//!< Reference to the actual memory zone holding the buffer
			uint32_t bufferSize;		//!< Buffer maximum size
			int32_t maxIndex;			//!< Maximum index value

		private:
			//! \brief Private internal method which writes a byte received as parameter at the designated index
			//!
			//! \param index The values of the position index where the new byte has to be inserted in the buffer
			//! \param byte The actual data that has to be inserted in the buffer
			//! \return None
			void writeAtIndex(const uint32_t index, const uint8_t byte);

		public:
			//! \brief Initializes the internal memory zone with the size given as parameter
			//!
			//! The constructor not only initializes the internal variables but also dynamically allocates the memory zone
			//! holding the buffer with the size given as parameter.
			//! \param size The size of the buffer that will be allocated in order to store the data
			BasicBuffer(const uint32_t size);

			//! \brief Deallocates all the memory occupied by the object
			//!
			//! Frees the memory zone holding the buffer which was allocated by the constructor at the creation of an object
			~BasicBuffer();

			//! \brief Add a byte at the top (beginning) of the buffer
			//! \param byte The byte to be added
			//! \return None
			void PushFront(const uint8_t byte);

			//! \brief Add a byte at the bottom (end) of the buffer
			//! \param byte The byte to be added
			//! \return None
			void PushBack(const uint8_t byte);

			//! \brief Insert a byte at a specified index position
			//! \param index An integer specifying the position where the data should be inserted
			//! \param byte The byte to be added
			//! \return None
			void Put(const uint32_t index, const uint8_t byte);

			//! \brief Get the byte data stored at the specified index in the buffer. The whole buffer is not affected by this method.
			//! \param index An integer specifying the position from where the data is returned
			//! \return The data stored at the specified index without advancing the size (maximum index) value of the buffer.
			uint8_t Get(const uint32_t index) const;

			//! \brief Determines if the buffer is empty
			//! \return \b true if the buffer is empty
			//! \return \b false if the buffer is not empty
			bool IsEmpty(void);

			//! \brief Determines if the buffer is full
			//! \return \b true if the buffer is full
			//! \return \b false if the buffer is not full
			bool IsFull(void);

			//! \brief Erases the data at the specified index from the buffer.
			//!
			//! This method deletes the data from the buffer at the specified index. The new size of the buffer will be decremented by 1.
			//! \param index An unsigned integer specifying the index from which the data is removed from the buffer
			//! \return None
			void Erase(const uint32_t index);

			//! \brief Determines how many bytes are stored in the buffer.
			//!
			//! This method returns the current size of the actual data in the buffer. It shall not be considered to be similar to the maximum size of the buffer specified in the constructor
			//! \return An unsigned integer containing the number of bytes actually stored in the buffer
			uint32_t Size();

			//! \brief Returns a pointer to the actual memory zone containing the buffer
			//! \return The addreess of the actual memory zone containing the buffer (the address of the buffer)
			uint8_t *GetBufferAddress();

			//! \brief Clear the content of the buffer
			//!
			//! This method empties the buffer by deleting all its content. It does not deallocate the memory zone. After this call the call of Size() will return 0
			//! \return None
			void Clear(void);

			//! \brief Print a buffer to a string
			//!
			//! This method may be used to print to a string in hexadecimal format the content of the buffer given as parameter
			//! Be advised that this method is static and in consequence it will not act on an object of this class
			//! \param buffer A pointer to the buffer to be printed as string
			//! \param size The size of the buffer
			//! \return A string values containing the buffer in hexadecimal format
			static string BufferToString(uint8_t* buffer, uint32_t size);

			//! \brief Print a BasicBuffer object to a string
			//!
			//! This method may be used to print to a string in hexadecimal format the content of the BasicBuffer object given as parameter
			//! Be advised that this method is static and in consequence it will not act on an object of this class
			//! \param buffer A pointer to the BasicBuffer object to be printed as string
			//! \return A string values containing the buffer in hexadecimal format
		    static string BasicBufferToString(BasicBuffer* buffer);

	};
}








