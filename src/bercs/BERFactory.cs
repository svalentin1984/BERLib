using System;

namespace BER
{
    public class BERFactory
    {
        public static IBaseBERType Create(byte tag)
        {
            var berType = (BERCodes) tag;
            switch (berType)
            {
                case BERCodes.NullData:
                    return new BERNullData();
                case BERCodes.Array:
                    return new BERArray();
                case BERCodes.Boolean:
                    return new BERBoolean();
                case BERCodes.OctetString:
                    return new BEROctetString();
                case BERCodes.VisibleString:
                    return new BERVisibleString();
                case BERCodes.LongUnsigned:
                    return new BERLongUnsigned();
                case BERCodes.Unsigned:
                    return new BERUnsigned();
                case BERCodes.Structure:
                    return new BERStructure();
                case BERCodes.Enum:
                    return new BEREnum();
                case BERCodes.Integer:
                    return new BERInteger();
                case BERCodes.Long:
                    return new BERLong();
                case BERCodes.Long64Unsigned:
                    return new BERLong64Unsigned();
                case BERCodes.DoubleLongUnsigned:
                    return new BERDoubleLongUnsigned();
                case BERCodes.BitString:
                    return new BERBitString();
                default:
                    throw new NotImplementedException("unimplemented ber type");
            }
        }
    }
}
