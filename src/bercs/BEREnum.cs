using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BEREnum : BaseBERType<Byte>
    {
        #region Overrides of BaseBERType<byte>
		//! Method that encodes the value of this BEREnum into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BEREnum	
        public override List<byte> Encode(byte value)
        {
            return new List<byte>(2) { (byte)BERCodes.Enum, value };
        }
		//! Method that decodes a List of Bytes into this BEREnum object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override byte Decode(List<byte> buffer)
        {
            if (buffer[0] != (byte)BERCodes.Enum)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (buffer[1]);
            buffer.RemoveRange(0, 2);
            return result;
        }
		//! Method that provides a String representation of this BEREnum
		//! \return The string representation of this BEREnum
        public override string AsString()
        {
            return Value.ToString();
        }

        #endregion
    }
}
