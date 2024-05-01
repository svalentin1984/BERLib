#pragma once

#include <exception>

namespace BER
{
//! Length of the Custom Message of the exception
#define EXCEPTION_CUSTOM_MESSAGE_LENGTH		256
//! Length of the ID Message of the exception
#define EXCEPTION_ID_MESSAGE_LENGTH			64
//! Length of the Additional message within an exception
#define EXCEPTION_ADDITIONAL_MESSAGE_LENGTH	12
//! Length of the final concatenated message of the exception
#define EXCEPTION_FINAL_MESSAGE_LENGTH	EXCEPTION_ID_MESSAGE_LENGTH + EXCEPTION_CUSTOM_MESSAGE_LENGTH + EXCEPTION_ADDITIONAL_MESSAGE_LENGTH + 2 + 3


//! \brief A custom implementation of an exception class extending the std::standard exception class
//! \details This class extends the standard std::exception class and adds more message types to be transmitted to an exception
//! This class provides 4 messages that may be transmitted to an exception. The final message that is returned by the \ref what() method is the concatenation of all the messages
//! The additional messages added to this implementation are the following
//! - id_message - An identification message of the exception. This usually specifies a short identification text for the message. Example: "DateTime Exception". The maximum size of this message may be: EXCEPTION_ID_MESSAGE_LENGTH
//! - custom_message - A custom message for the exception. This message may be used to specify detailed information about the exception. Example: "Date is not correct.". The maximum size of this message may be: EXCEPTION_CUSTOM_MESSAGE_LENGTH
//! - additional_message - An extension to the custom message for the exception. This message may be used to further extend the details provided in the custom_message. Example: "Month out of range". The maximum size of this message may be: EXCEPTION_FINAL_MESSAGE_LENGTH
//!
//! The final message that shall be exported by the \ref what() method is the concatenation of the previous messages
//!
//! final_message = id_message + custom_message + additional_message
//!
//! Using the above examples the final_message should be:
//!
//! "DateTime Exception Date is not correct Month out of range"
//!
//! This class is provides protection for the strings and it should not throw exceptions itself
class BaseException: public std::exception
{
private:
	char custom_message[EXCEPTION_CUSTOM_MESSAGE_LENGTH + 1];
	char id_message[EXCEPTION_ID_MESSAGE_LENGTH + 1];
	char final_message[EXCEPTION_FINAL_MESSAGE_LENGTH + 1];
	char additional_message[EXCEPTION_ADDITIONAL_MESSAGE_LENGTH + 1];
public:
	//! Empty constructor. All the messages are initialized to empty strings
	BaseException();
	//! Constructor providing a mean to specify the idMessage. All the other messages are initialized to empty strings
	//! \param idMessage The ID message of the exception
	BaseException(char *idMessage);
	//! Constructor providing a mean to specify the idMessage and the custom_message. All the other messages are initialized to empty strings
	//! \param idMessage The ID message of the exception
	//! \param customMessage The custom message of the exception
	BaseException(char *idMessage, char *customMessage);
	//! Constructor providing a mean to specify all the messages of the exception.
	//! \param idMessage The ID message of the exception
	//! \param customMessage The custom message of the exception
	//! \param additionalMessage The additional message of the exception
	BaseException(char *idMessage, char *customMessage, char *additionalMessage);
	//! The overloaded version of the std::exception::what()
	//! This version of the what() method offers the final message exported by the exception by concatenating all the described above 3 message. The concatenation method is presented in the class description
	virtual const char* what() const throw();
};

}
