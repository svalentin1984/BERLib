using System;
using System.Collections.Generic;
using System.Text;

using BER.Exceptions;

namespace BER
{
    public class BERVisibleString : BaseBERType<List<Byte>>
    {
        public override List<byte> Encode(List<byte> value)
        {
            var result = new List<Byte>(value.Count + 2) { (byte)BERCodes.VisibleString };
            if (value.Count <= 0x80)
            {
                result.Add((byte)value.Count);
            }
            else
            {
                result.Add(0x82);
                result.Add((byte)((value.Count >> 8) & 0xFF));
                result.Add((byte)(value.Count & 0xFF));
            }
            result.AddRange(value);
            return result;
        }

        public override List<byte> Decode(List<byte> buffer)
        {
            var index = 0;
            if (buffer[index++] != (int)BERCodes.VisibleString)
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
            var resultList = new List<Byte>((int)length);
            buffer.RemoveRange(0, index);
            i = 0;
            for (i = 0; i < length; i++)
            {
                resultList.Add(buffer[i]);
            }
            buffer.RemoveRange(0, i);

            return resultList;
        }

        public override string AsString()
        {
            StringBuilder str = new StringBuilder(Value.Count);
            foreach (byte b in Value) str.Append((char) b);
            return "'" + str.ToString() + "'";
        }

    }
}

