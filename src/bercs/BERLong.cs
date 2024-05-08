using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERLong : BaseBERType<short>
    {
        #region Overrides of BaseBERType<ushort>
		//! Method that encodes the value of this BERLong into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERLong	
        public override List<byte> Encode(short value)
        {
            return new List<Byte>(3)
                           {
                               (byte) BERCodes.Long,
                               (byte) ((value >> 8) & 0xFF),
                               (byte) (value & 0xFF)
                           };
        }
		//! Method that decodes a List of Bytes into this BERLong object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override short Decode(List<byte> buffer)
        {
            if (buffer[0] != (short)BERCodes.Long)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (short)((buffer[1] << 8) | buffer[2]);
            buffer.RemoveRange(0, 3);
            return result;
        }
		//! Method that provides a String representation of this BERLong
		//! \return The string representation of this BERLong
        public override string AsString()
        {
            return Value.ToString();
        }


        #endregion
    }
}
