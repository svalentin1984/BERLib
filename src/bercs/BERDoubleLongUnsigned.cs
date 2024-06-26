﻿using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERDoubleLongUnsigned : BaseBERType<UInt32>
    {
        #region Overrides of BaseBERType<uint>
		//! Method that encodes the value of this BERDoubleLongUnsigned into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERDoubleLongUnsigned	
        public override List<byte> Encode(uint value)
        {
            var result = new List<byte> {(Byte) BERCodes.DoubleLongUnsigned};
            for (SByte i = 3; i >= 0; i--)
            {
                result.Add((Byte) ((value >> (i * 8)) & 0xFF));
            }
            return result;
        }
		//! Method that decodes a List of Bytes into this BERDoubleLongUnsigned object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override uint Decode(List<byte> buffer)
        {
            if (buffer[0] != (int) BERCodes.DoubleLongUnsigned)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (UInt32) ((buffer[1] << 24) | (buffer[2] << 16) | (buffer[3] << 8) | buffer[4]);
            buffer.RemoveRange(0, 5);
            return result;
        }

        #endregion
		//! Method that provides a String representation of this BERDoubleLongUnsigned
		//! \return The string representation of this BERDoubleLongUnsigned
        public override string AsString()
        {
            return Value.ToString();
        }

    }
}
