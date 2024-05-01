#include "BERDecode.h"
#include <iostream>
namespace BER {

Ber* BERDecode::Decode(BasicBuffer *basicBuffer)
{
	uint32_t index = 0;
	Ber* ber = NULL;

	ber = BER::CreateBER((BERCodes) (basicBuffer->GetBufferAddress()[0]) );

	ber->DecodeData(*basicBuffer, index);
	return ber;
}

}
