#pragma once

namespace BER
{
	typedef enum
	{
		NullData = 0,
        Array = 1,
        Structure = 2,
        Boolean = 3,
        BitString = 4,
        DoubleLong = 5,
        DoubleLongUnsigned = 6,
        OctetString = 9,
        VisibleString = 10,
        BCD = 13,
        Integer = 15,
        Long = 16,
        Unsigned = 17,
        LongUnsigned = 18,
        CompactArray = 19,
        Long64 = 20,
        Long64Unsigned = 21,
        Enum = 22,
        Float32 = 23,
        FLoat64 = 24,
        BERDateTime = 25,
        Date = 26,
        Time = 27
	}BERCodes;
}						 
