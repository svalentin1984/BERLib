#pragma once

#include "BaseException.h"
namespace BER
{

	class BERException : public BaseException
	{
	public:
		BERException();
		BERException(char *message);
		BERException(char *message, char *additionalMessage);
	};

	class BERTypeIncorrectTag : public BERException
	{
	public:
		BERTypeIncorrectTag();
		BERTypeIncorrectTag(char *message);
	};

	class BERTypeUnrecognized :	public BERException
	{
	public:
		BERTypeUnrecognized();
		BERTypeUnrecognized(char *message);
	};
}
