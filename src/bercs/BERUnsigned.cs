using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERUnsigned : BaseBERType<Byte>
    {
        #region Overrides of BaseBERType<byte>
		//! Method that encodes the value of this BERUnsigned into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERUnsigned	
        public override List<byte> Encode(byte value)
        {
            return new List<byte>(2) { (byte)BERCodes.Unsigned, value };
        }
		//! Method that decodes a List of Bytes into this BERUnsigned object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override byte Decode(List<byte> buffer)
        {
            if (buffer[0] != (int)BERCodes.Unsigned)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (buffer[1]);
            buffer.RemoveRange(0, 2);
            return result;
        }
		//! Method that provides a String representation of this BERUnsigned
		//! \return The string representation of this BERUnsigned
        public override string AsString()
        {
            return Value.ToString();
        }


        #endregion
    }
}
