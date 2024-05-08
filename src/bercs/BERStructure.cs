using System;
using System.Collections.Generic;
using System.Text;

using BER.Exceptions;

namespace BER
{
    public class BERStructure : BaseBERType<List<IBaseBERType>>
    {
        #region Overrides of BaseBERType<List<IBaseBERType>>

		//! Method that encodes the value of this BERStructure into a Byte List containing the encoding of the BERStructure as well as all the component object
		//! \return A Byte List containing the encoded raw bytes of this BERStructure	
        public override List<byte> Encode(List<IBaseBERType> value)
        {
            var list = new List<Byte> {(byte) BERCodes.Structure, (byte) value.Count};
            foreach (var baseBERType in value)
                list.AddRange(baseBERType.Encode());
            return list;
        }
		//! Method that decodes a List of Bytes into this BERStructure object. This method will decode all the objectes contained in the BERStructure
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override List<IBaseBERType> Decode(List<byte> buffer)
        {
            if (buffer[0] != (int) BERCodes.Structure)
                throw new BERTypeDecodeIncorrectTag();

            var length = buffer[1];
            var berList = new List<IBaseBERType>(length);
            buffer.RemoveRange(0, 2);
            for (var i = 0; i < length; i++)
            {
                var ber = BERFactory.Create(buffer[0]);
                ber.Decode(buffer);
                berList.Add(ber);
            }
            return berList;
        }
		//! Method that provides a String representation of this BERStructure. The string representation will also contain the representations of all the BER Types contained by this BERStructure
		//! \return The string representation of this BERStructure
        public override string AsString()
        {
            StringBuilder str = new StringBuilder();
            foreach (IBaseBERType b in Value)
            {
                str.Append(", ");
                str.Append(b.AsString());
            }

            String result = str.ToString();
            if (!result.StartsWith(", ")) return "{" + result + "}";
            else return "{" + result.Substring(2) + "}";
        }

        #endregion
    }
}
