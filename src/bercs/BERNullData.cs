using System.Collections.Generic;

using BER.Exceptions;

namespace BER
{
    public class BERNullData : BaseBERType<int?>
    {
        #region Overrides of BaseBERType<int?>

        public override List<byte> Encode(int? value)
        {
            return new List<byte>(1) {(byte) BERCodes.NullData};
        }

        public override int? Decode(List<byte> buffer)
        {
            if (buffer[0] != (int) BERCodes.NullData)
            {
                throw new BERTypeDecodeIncorrectTag();
            }
            buffer.RemoveRange(0, 1);
            return null;
        }

        public override string AsString()
        {
            return "null";
        }

        #endregion
    }
}
