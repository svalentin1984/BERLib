using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERBoolean : BaseBERType<bool>
    {
		//! Method that encodes the value of this BERBoolean into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERBoolean				
        public override List<byte> Encode(bool value)
        {
            return new List<byte> {(byte) BERCodes.Boolean, Convert.ToByte(value)};
        }
		//! Method that decodes a List of Bytes into this BERBoolean object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override bool Decode(List<byte> buffer)
        {
            var index = 0;
            if (buffer[index++] != (int) BERCodes.Boolean)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            Value = Convert.ToBoolean(buffer[index++]);
            buffer.RemoveRange(0, index);
            return Value;
        }

		//! Method that provides a String representation of this BERBoolean
		//! \return The string representation of this BERBoolean
        public override string AsString()
        {
            if (Value) return "T";
            else return "F";
        }

    }
}
