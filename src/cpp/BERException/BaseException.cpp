#include "BaseException.h"
#include <string.h>
namespace BER
{

BaseException::BaseException()
{
	bzero(this->custom_message, EXCEPTION_CUSTOM_MESSAGE_LENGTH + 1);
	bzero(this->id_message, EXCEPTION_ID_MESSAGE_LENGTH + 1);
	bzero(this->final_message, EXCEPTION_FINAL_MESSAGE_LENGTH + 1);
	bzero(this->additional_message, EXCEPTION_ADDITIONAL_MESSAGE_LENGTH + 1);
}

BaseException::BaseException(char *idMessage)
{
	bzero(this->custom_message, EXCEPTION_CUSTOM_MESSAGE_LENGTH + 1);
	bzero(this->id_message, EXCEPTION_ID_MESSAGE_LENGTH + 1);
	bzero(this->final_message, EXCEPTION_FINAL_MESSAGE_LENGTH + 1);
	bzero(this->additional_message, EXCEPTION_ADDITIONAL_MESSAGE_LENGTH + 1);
	strncpy(this->id_message, idMessage, EXCEPTION_ID_MESSAGE_LENGTH);
	this->id_message[EXCEPTION_ID_MESSAGE_LENGTH] = 0;
}

BaseException::BaseException(char *idMessage, char *customMessage)
{
	bzero(this->custom_message, EXCEPTION_CUSTOM_MESSAGE_LENGTH + 1);
	bzero(this->id_message, EXCEPTION_ID_MESSAGE_LENGTH + 1);
	bzero(this->final_message, EXCEPTION_FINAL_MESSAGE_LENGTH + 1);
	bzero(this->additional_message, EXCEPTION_ADDITIONAL_MESSAGE_LENGTH + 1);

	strncpy(this->id_message, idMessage, EXCEPTION_ID_MESSAGE_LENGTH);
	this->id_message[EXCEPTION_ID_MESSAGE_LENGTH] = 0;
	strncpy(this->custom_message, customMessage, EXCEPTION_CUSTOM_MESSAGE_LENGTH);
	this->custom_message[EXCEPTION_CUSTOM_MESSAGE_LENGTH] = 0;
}

BaseException::BaseException(char *idMessage, char *customMessage, char *additionalMessage)
{
	bzero(this->custom_message, EXCEPTION_CUSTOM_MESSAGE_LENGTH + 1);
	bzero(this->id_message, EXCEPTION_ID_MESSAGE_LENGTH + 1);
	bzero(this->final_message, EXCEPTION_FINAL_MESSAGE_LENGTH + 1);
	bzero(this->additional_message, EXCEPTION_ADDITIONAL_MESSAGE_LENGTH + 1);

	strncpy(this->id_message, idMessage, EXCEPTION_ID_MESSAGE_LENGTH);
	this->id_message[EXCEPTION_ID_MESSAGE_LENGTH] = 0;
	strncpy(this->custom_message, customMessage, EXCEPTION_CUSTOM_MESSAGE_LENGTH);
	this->custom_message[EXCEPTION_CUSTOM_MESSAGE_LENGTH] = 0;
	strncpy(this->additional_message, additionalMessage, EXCEPTION_ADDITIONAL_MESSAGE_LENGTH);
	this->additional_message[EXCEPTION_ADDITIONAL_MESSAGE_LENGTH] = 0;
}

const char* BaseException::what() const throw()
{
	strcpy((char*)final_message, id_message);
	if (strlen(custom_message) > 0)
	{
		strcat((char*)final_message, ": ");
		strcat((char*)final_message, custom_message);
		if (strlen(additional_message) > 0)
		{
			strcat((char*)final_message, " - ");
			strcat((char*)final_message, additional_message);
		}
	}
	return final_message;
}



}
