using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERBoolean : BaseBERType<bool>
    {
        public override List<byte> Encode(bool value)
        {
            return new List<byte> {(byte) BERCodes.Boolean, Convert.ToByte(value)};
        }

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

        public override string AsString()
        {
            if (Value) return "T";
            else return "F";
        }

    }
}
