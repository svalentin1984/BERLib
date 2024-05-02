using System;
using System.Collections.Generic;
using System.Text;

using BER.Exceptions;

namespace BER
{
    public class BERStructure : BaseBERType<List<IBaseBERType>>
    {
        #region Overrides of BaseBERType<List<IBaseBERType>>

        public override List<byte> Encode(List<IBaseBERType> value)
        {
            var list = new List<Byte> {(byte) BERCodes.Structure, (byte) value.Count};
            foreach (var baseBERType in value)
                list.AddRange(baseBERType.Encode());
            return list;
        }

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
