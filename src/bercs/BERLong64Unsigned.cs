using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERLong64Unsigned : BaseBERType<UInt64>
    {
        #region Overrides of BaseBERType<ulong>

        public override List<byte> Encode(ulong value)
        {
            var result = new List<byte> { (Byte)BERCodes.Long64Unsigned };
            for (SByte i = 7; i >= 0; i--)
            {
                result.Add((Byte)((value >> (i * 8)) & 0xFF));
            }
            return result;
        }

        public override ulong Decode(List<byte> buffer)
        {
            var index = 0;
            UInt64 result = 0;
            if (buffer[index++] != (byte) BERCodes.Long64Unsigned)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            for (var i = 0; i < 8; i++)
            {
                result = (result << 8) | buffer[index++];
            }
            buffer.RemoveRange(0, 9);
            return result;
        }

        public override string AsString()
        {
            return Value.ToString();
        }

        #endregion
    }
}
