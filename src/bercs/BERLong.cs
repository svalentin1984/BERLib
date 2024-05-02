using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERLong : BaseBERType<short>
    {
        #region Overrides of BaseBERType<ushort>

        public override List<byte> Encode(short value)
        {
            return new List<Byte>(3)
                           {
                               (byte) BERCodes.Long,
                               (byte) ((value >> 8) & 0xFF),
                               (byte) (value & 0xFF)
                           };
        }

        public override short Decode(List<byte> buffer)
        {
            if (buffer[0] != (short)BERCodes.Long)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (short)((buffer[1] << 8) | buffer[2]);
            buffer.RemoveRange(0, 3);
            return result;
        }

        public override string AsString()
        {
            return Value.ToString();
        }


        #endregion
    }
}
