#include "BasicBufferException.h"

namespace BER
{

BasicBufferException::BasicBufferException() : BaseException((char*)"BasicBufferException")
{

}

BasicBufferException::BasicBufferException(char *message) : BaseException((char*)"BasicBufferException" ,message)
{

}

BasicBufferException::BasicBufferException(char *message, char *additionalMessage) : BaseException((char*)"BasicBufferException" ,message, additionalMessage)
{

}

}
