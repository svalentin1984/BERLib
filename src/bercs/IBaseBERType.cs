using System;
using System.Collections.Generic;

namespace BER
{
    /// <summary>
    /// Weak type ber type generalization
    /// </summary>
    public interface IBaseBERType
    {			
        List<Byte> Encode();
        List<Byte> Encode(object value);
        object Decode(List<Byte> buffer);   
        string AsString();
    }
}