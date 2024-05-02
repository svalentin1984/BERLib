#pragma once

#include "BaseBER.h"
#include "BaseBERType.h"
#include "BERArray.h"
#include "BERBitString.h"
#include "BERBoolean.h"
#include "BERCodes.h"
#include "BERDoubleLongUnsigned.h"
#include "BEREnum.h"
#include "BERException/BERExceptions.h"
#include "BERFactory.h"
#include "BERInteger.h"
#include "BERLong.h"
#include "BERLong64Unsigned.h"
#include "BERLongUnsigned.h"
#include "BERNullData.h"
#include "BEROctetString.h"
#include "BERStructure.h"
#include "BERUnsigned.h"
#include "BERUtils.h"

namespace BER
{

typedef enum
{
	BERUnit_ActivePower_W = 27,
	BERUnit_ActiveEnergy_Wh = 30,
	BERUnit_ApparentEnergy_VAh = 31,
	BERUnit_ReactiveEnergy_varh = 32,
	BERUnit_Current_A = 33,
	BERUnit_Voltage_V = 35,
	BERUnit_NoUnit = 255,
}BERUnit;

}
