using System;
using System.Collections.Generic;
using System.Text;

using BER.Exceptions;

namespace BER
{
    public class BERBitString : BaseBERType<List<Boolean>>
    {
        #region Overrides of BaseBERType<List<bool>>

        public override List<byte> Encode(List<bool> value)
        {
            var result = new List<Byte> { (byte)BERCodes.BitString };
            result.AddRange(BERUtils.EncodeLength((uint)value.Count));
            result.AddRange(BERUtils.EncodeFlagList(value));
            return result;
        }

        public override List<bool> Decode(List<byte> buffer)
        {
            var index = 0;
            if (buffer[index++] != (int)BERCodes.BitString)
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
            var byteCount = Convert.ToUInt16(Math.Ceiling((Double) length/8));
            var byteList = new List<Byte>((int)byteCount);
            for (i = 0; i < byteCount; i++)
            {
                byteList.Add(buffer[index++]);
            }
            buffer.RemoveRange(0, index);
            return BERUtils.DecodeFlagList(byteList, (ushort)length);
        }
        #endregion
        
        public override string AsString() { 
            StringBuilder result = new StringBuilder(Value.Count);
            foreach (bool b in Value)
                if (b) result.Append("1");
                else result.Append("0");
            return result.ToString();
        }
    }
}
