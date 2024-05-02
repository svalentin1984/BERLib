#pragma once

#include "BaseBER.h"
#include "BERCodes.h"

namespace BER
{
	Ber* CreateBER(BERCodes tag);
}
