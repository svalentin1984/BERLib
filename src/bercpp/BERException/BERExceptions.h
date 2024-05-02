#pragma once

#include "BaseException.h"
namespace BER
{
	//! \brief A general exception for the whole BER implementation extending the BaseException exception class
	//! \details This class extends the BaseException class and is meant to provide a basic exception class for the whole BER implementation
	class BERException : public BaseException
	{
	public:
		//! Empty constructor. All the messages are initialized to empty string but with the idMessage parameter in BaseException initialized to string \a "BERException"
		BERException();
		//! Constructor providing a mean to specify a custom message of the exception.
		//! \param message The custom message of the exception
		BERException(char *message);
		//! Constructor providing a mean to specify a custom message and an additional message of the exception.
		//! \param message The custom message of the exception
		//! \param additionalMessage The additional message of the exception		
		BERException(char *message, char *additionalMessage);
	};
	//! \brief A BER dedicated exception extending BERException class signaling an incorrect BER Tag
	//! \details This class extends the BERException class and is meant to signal the error when an incorrect BER Tag was found. 
	//! This exception may be thrown by any Decode method when an incorrect BER Tag was found during the decode process.
	class BERTypeIncorrectTag : public BERException
	{
	public:
		//! Empty constructor. All the messages are initialized to empty string but with the message parameter in BERException initialized to string \a "BERTypeIncorrectTag"
		BERTypeIncorrectTag();
		//! Constructor providing a mean to specify an additional custom for the exception.
		//! \param message The additional custom message of the exception				
		BERTypeIncorrectTag(char *message);
	};
	//! \brief A BER dedicated exception extending BERException class signaling an unrecognized BER Type was found
	//! \details This class extends the BERException class and is meant to signal the error when an unrecognized BER Type was found. 
	//! This exception may be thrown by the CreateBER method when an unsupported BER Tag was found during the Factory process.
	class BERTypeUnrecognized :	public BERException
	{
	public:
		//! Empty constructor. All the messages are initialized to empty string but with the message parameter in BERException initialized to string \a "BERTypeUnrecognized"
		BERTypeUnrecognized();
		//! Constructor providing a mean to specify an additional custom for the exception.
		//! \param message The additional custom message of the exception				
		BERTypeUnrecognized(char *message);
	};
}
