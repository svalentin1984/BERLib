using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERNullData : BaseBERType<int?>
    {
        #region Overrides of BaseBERType<int?>
		//! Method that encodes the value of this BERNullData into a Byte List
		//! \return A Byte List containing the encoded raw bytes of this BERNullData	
        public override List<byte> Encode(int? value)
        {
            return new List<byte>(1) {(byte) BERCodes.NullData};
        }
		//! Method that decodes a List of Bytes into this BERNullData object
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override int? Decode(List<byte> buffer)
        {
            if (buffer[0] != (int) BERCodes.NullData)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            buffer.RemoveRange(0, 1);
            return null;
        }
		//! Method that provides a String representation of this BERNullData
		//! \return The string representation of this BERNullData
        public override string AsString()
        {
            return "null";
        }

        #endregion
    }
}
