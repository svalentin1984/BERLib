#pragma once

#include "BaseException.h"

namespace BER
{
//! \brief A general exception for the BasicBuffer class extending the BaseException exception class
//! \details This class extends the BaseException class and is meant to provide a basic exception class for the BasicBuffer class
class BasicBufferException: public BaseException
{
public:
	//! Empty constructor. All the messages are initialized to empty string but with the idMessage parameter in BaseException initialized to string "BasicBufferException"
	BasicBufferException();
	//! Constructor providing a mean to specify a custom message of the exception.
	//! \param message The custom message of the exception
	BasicBufferException(char *message);
	//! Constructor providing a mean to specify a custom message and an additional message of the exception.
	//! \param message The custom message of the exception
	//! \param additionalMessage The additional message of the exception
	BasicBufferException(char *message, char *additionalMessage);
};

}

