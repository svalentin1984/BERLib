using System;
using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERInteger : BaseBERType<SByte>
    {
        #region Overrides of BaseBERType<sbyte>

        public override List<byte> Encode(sbyte value)
        {
            return new List<byte>(2) {(byte) BERCodes.Integer, (byte) value};
        }

        public override sbyte Decode(List<byte> buffer)
        {
            if (buffer[0] != (byte) BERCodes.Integer)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            var result = (sbyte) (buffer[1]);
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
