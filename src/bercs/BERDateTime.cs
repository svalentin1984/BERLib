using System;
using System.Collections.Generic;
using System.Data;

namespace BER
{
    public class BERDateTime : BaseBERType<DateTime>
    {
        #region Overrides of BaseBERType<DateTime>

        public override List<byte> Encode(DateTime value)
        {
            throw new NotImplementedException();
        }

        public override DateTime Decode(List<byte> buffer)
        {
            throw new NotImplementedException();
        }

        public override string AsString()
        {
            return "#" + Value.ToString() + "#";
        }

        #endregion
    }
}
