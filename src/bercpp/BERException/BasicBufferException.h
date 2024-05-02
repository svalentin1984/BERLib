#pragma once

#include "BaseException.h"

namespace BER
{

class BasicBufferException: public BaseException
{
public:
	BasicBufferException();
	BasicBufferException(char *message);
	BasicBufferException(char *message, char *additionalMessage);
};

}

