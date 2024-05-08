using System;

namespace BER
{
    public class BERFactory
    {
		//! Based on the Factory Method pattern, this method creates a BER Type based on the value of BER Tag provided as argument
		//! \param tag The value of the BER Tag which will decide the type of the new BER to be created. This value must be one of the values in BERCodes
		//! \return The newly created BER Object
		//! \throws NotImplementedException if the provided tag is not found in BERCodes or not implemented yet
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
