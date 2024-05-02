using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERUnsigned : BaseBERType<Byte>
    {
        #region Overrides of BaseBERType<byte>

        public override List<byte> Encode(byte value)
        {
            return new List<byte>(2) { (byte)BERCodes.Unsigned, value };
        }

        public override byte Decode(List<byte> buffer)
        {
            if (buffer[0] != (int)BERCodes.Unsigned)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (buffer[1]);
            buffer.RemoveRange(0, 2);
            return result;
        }

        public override string AsString()
        {
            return Value.ToString();
        }


        #endregion
    }
}
