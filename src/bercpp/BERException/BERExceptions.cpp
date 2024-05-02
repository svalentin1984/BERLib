#include "BERExceptions.h"

namespace BER
{

BERException::BERException() : BaseException((char*)"BERException")
{

}

BERException::BERException(char *message) : BaseException((char*)"BERException" ,message)
{

}

BERException::BERException(char *message, char *additionalMessage) : BaseException((char*)"BERException" ,message, additionalMessage)
{

}



BERTypeIncorrectTag::BERTypeIncorrectTag() : BERException((char*)"BERTypeIncorrectTag")
{

}


BERTypeIncorrectTag::BERTypeIncorrectTag(char *message) : BERException((char*)"BERTypeIncorrectTag", message)
{

}

BERTypeUnrecognized::BERTypeUnrecognized() : BERException((char*)"BERTypeUnrecognized")
{

}

BERTypeUnrecognized::BERTypeUnrecognized(char *message) : BERException((char*)"BERTypeUnrecognized", message)
{

}

}
