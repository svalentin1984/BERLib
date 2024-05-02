using System;
using System.Collections.Generic;
using System.Text;

using BER.Exceptions;

namespace BER
{
    public class BERArray : BaseBERType<List<IBaseBERType>>
    {
        #region Overrides of BaseBERType<List<IBaseBERType>>

        public static bool PartialDecode = false;

        protected Exception error = null;
        public Exception Exception
        {
            get { return error; }
        }

        public override List<byte> Encode(List<IBaseBERType> value)
        {
            var list = new List<Byte> { (byte)BERCodes.Array, (byte)value.Count };
            foreach (var baseBERType in value)
                list.AddRange(baseBERType.Encode());
            return list;
        }

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
