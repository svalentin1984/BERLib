using System;
using System.Collections.Generic;
using System.Text;

using BER.Exceptions;

namespace BER
{
    public class BERArray : BaseBERType<List<IBaseBERType>>
    {
        #region Overrides of BaseBERType<List<IBaseBERType>>

		//! This static parameter dictates the behavious of the Decode method. When this parameter is true and an exception was found the decoding process is stopped but the exception is not thrown to the calling process, thus a partial decode of the BERArray is returned. If this parameter is true, when an exception is caught the whole decoding process is terminated and the exception is thrown ahead.
        public static bool PartialDecode = false;


        protected Exception error = null;
        public Exception Exception
        {
            get { return error; }
        }


		//! Method that encodes the value of this BERArray into a Byte List containing the encoding of the BERArray as well as all the component objects
		//! \return A Byte List containing the encoded raw bytes of this BERArray	
        public override List<byte> Encode(List<IBaseBERType> value)
        {
            var list = new List<Byte> { (byte)BERCodes.Array, (byte)value.Count };
            foreach (var baseBERType in value)
                list.AddRange(baseBERType.Encode());
            return list;
        }

		//! Method that decodes a List of Bytes into this BERArray object. This method will decode all the objectes contained in the BERArray
		//! \return true The decoding process was succesfull
		//! \return true The decoding process was not succesfull
		//! \throws BERTypeDecodeIncorrectTag if an incompatible tag was found
        public override List<IBaseBERType> Decode(List<byte> buffer)
        {
            var index = 0;
            if (buffer[index++] != (int)BERCodes.Array)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var temp = buffer[index++];
            UInt32 length = 0;
            int i;
            if (temp <= 0x80)
            {
                length = temp;
            }
            else
            {
                var nbrLengthBytes = temp - 0x80;
                for (i = 0; i < nbrLengthBytes; i++)
                {
                    length = (length << 8) + buffer[index++];
                }
            }
            var berList = new List<IBaseBERType>((int)length);
            buffer.RemoveRange(0, index);
            for (i = 0; i < length; i++)
            {
                try
                {
                    var ber = BERFactory.Create(buffer[0]);
                    ber.Decode(buffer);
                    berList.Add(ber);
                }
                catch (Exception e)
                {
                    if (PartialDecode) error = e;
                    else throw;
                }
            }
            return berList;
        }

        #endregion
		//! Method that provides a String representation of this BERArray. The string representation will also contain the representations of all the BER Types contained by this BERArray
		//! \return The string representation of this BERArray
        public override string AsString()
        {
            StringBuilder str = new StringBuilder();
            foreach (IBaseBERType b in Value)
            {
                str.Append(", ");
                str.Append(b.AsString());
            }

            String result = str.ToString();
            if (!result.StartsWith(", ")) return "[" + result + "]";
            else return "[" + result.Substring(2) + "]";
        }

    }
}
