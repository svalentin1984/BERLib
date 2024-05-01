#include "BERArray.h"
#include "BERBitString.h"
#include "BERBoolean.h"
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

namespace BER
{
	Ber* CreateBER(BERCodes tag)
	{
		switch (tag)
		{
		case NullData:
			{
				return new BERNullData();
			}
		case Unsigned:
			{
				return new BERUnsigned();
			}
		case BitString:
			{
				return new BERBitString();
			}
		case DoubleLongUnsigned:
			{
				return new BERDoubleLongUnsigned();
			}
		case Integer:
			{
				return new BERInteger();
			}
		case Long64Unsigned:
			{
				return new BERLong64Unsigned();
			}
		case Long:
			{
				return new BERLong();
			}
		case LongUnsigned:
			{
				return new BERLongUnsigned();
			}
		case OctetString:
			{
				return new BEROctetString();
			}
		case Enum:
			{
				return new BEREnum();
			}
		case Structure:
			{
				return new BERStructure();
			}
		case Array:
			{		
				return new BERArray();
			}
		case Boolean:
			{
				return new BERBoolean();
			}
		default:
			{
				throw BERTypeUnrecognized();
			}
		}

	}
}
