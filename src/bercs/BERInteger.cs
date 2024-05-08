using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERInteger : BaseBERType<SByte>
    {
        #region Overrides of BaseBERType<sbyte>
		//! Method that encodes the value of this BERInteger into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERInteger	
        public override List<byte> Encode(sbyte value)
        {
            return new List<byte>(2) {(byte) BERCodes.Integer, (byte) value};
        }
		//! Method that decodes a List of Bytes into this BERInteger object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override sbyte Decode(List<byte> buffer)
        {
            if (buffer[0] != (byte) BERCodes.Integer)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (sbyte) (buffer[1]);
            buffer.RemoveRange(0, 2);
            return result;
        }
		//! Method that provides a String representation of this BERInteger
		//! \return The string representation of this BERInteger
        public override string AsString()
        {
            return Value.ToString();
        }

        #endregion
    }
}
