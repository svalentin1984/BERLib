using System;
using System.Collections.Generic;

namespace BER
{
    public abstract class BaseBERType<T> : IBaseBERType
    {
        public T Value { set; get; }
        public abstract List<Byte> Encode(T value);

        public abstract T Decode(List<Byte> buffer);

        #region IBaseBERType
        public virtual List<byte> Encode()
        {
            return Encode(Value);
        }

        public List<byte> Encode(object value)
        {
            return Encode((T)value);
        }

        object IBaseBERType.Decode(List<byte> buffer)
        {
            Value = Decode(buffer);
            return Value;
        }

        public virtual string AsString()
        {
            return "";
        }
        #endregion
    }
}
