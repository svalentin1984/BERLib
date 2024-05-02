#pragma once

#include "BasicBuffer.h"
#include "BaseBERType.h"
#include "ber.h"
#include <stdint.h>
namespace BER {



class BERDecode {
public:
	static Ber* Decode(BasicBuffer *basicBuffer);
};

}

