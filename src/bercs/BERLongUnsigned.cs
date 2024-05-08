using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
		//! Method that encodes the value of this BERLongUnsigned into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERLongUnsigned	
		public class BERLongUnsigned : BaseBERType<UInt16>
		{
        #region Overrides of BaseBERType<ushort>

        public override List<byte> Encode(ushort value)
        {
            return new List<Byte>(3)
                           {
                               (byte) BERCodes.LongUnsigned,
                               (byte) ((value >> 8) & 0xFF),
                               (byte) (value & 0xFF)
                           };
        }
		//! Method that decodes a List of Bytes into this BERLongUnsigned object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override ushort Decode(List<byte> buffer)
        {
            if (buffer[0] != (int) BERCodes.LongUnsigned)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (ushort) ((buffer[1] << 8) | buffer[2]);
            buffer.RemoveRange(0,3);
            return result;
        }
		//! Method that provides a String representation of this BERLongUnsigned
		//! \return The string representation of this BERLongUnsigned
        public override string AsString()
        {
            return Value.ToString();
        }


        #endregion
    }
}
