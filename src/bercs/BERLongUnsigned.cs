using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERLongUnsigned : BaseBERType<UInt16>
    {
        #region Overrides of BaseBERType<ushort>

        public override List<byte> Encode(ushort value)
        {
            return new List<Byte>(3)
                           {
                               (byte) BERCodes.LongUnsigned,
                               (byte) ((value >> 8) & 0xFF),
                               (byte) (value & 0xFF)
                           };
        }

        public override ushort Decode(List<byte> buffer)
        {
            if (buffer[0] != (int) BERCodes.LongUnsigned)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (ushort) ((buffer[1] << 8) | buffer[2]);
            buffer.RemoveRange(0,3);
            return result;
        }

        public override string AsString()
        {
            return Value.ToString();
        }


        #endregion
    }
}
