using System;
using System.Collections.Generic;
using System.Text;

namespace BER
{
    public static class BERUtils
    {
        public static List<Byte> EncodeFlagList(List<Boolean> bitList)
        {
            var result = new List<Byte>();
            Byte mask = 0x80;
            Byte bitCount = 0;
            Byte tempByte = 0;
            for (var i = 0; i < bitList.Count; i++ )
            {
                if (bitList[i])
                {
                    tempByte |= mask;
                }
                mask = (byte)(mask >> 1);
                bitCount = (byte)(bitCount + 1);
                if ((bitCount == 8) || (i == (bitList.Count - 1)))
                {
                    result.Add(tempByte);
                    mask = 0x80;
                    tempByte = 0;
                    bitCount = 0;
                }
            }
            return result;
        }

        public static List<Boolean> DecodeFlagList(List<Byte> flagList, UInt16 flagCount)
        {
            var dst = new List<Boolean>(flagList.Count*8);
            foreach (var b in flagList)
            {
                for (var i = 7; (i >= 0) && (flagCount > 0); i--, flagCount--)
                {
                    dst.Add((((b >> i) & 1) != 0) ? true : false);
                }
            }
            return dst;
        }

        public static String BitStringToString(BERBitString bitstring)
        {
            return BitStringToString(bitstring.Value);
        }

        public static List<Byte> EncodeLength(UInt32 length)
        {
            var result = new List<byte>();
            Byte bytenr;
            if (length < 256)
            {
                bytenr = 1;
            }
            else
            {
                if (length < 65536)
                {
                    bytenr = 2;
                }
                else
                {
                    if (length < 16777216)
                    {
                        bytenr = 3;
                    }
                    else
                    {
                        bytenr = 4;
                    }
                }
            }
            if (bytenr == 1)
            {
                result.Add((byte) (length & 0xFF));
            }
            else
            {
                result.Add((byte) (0x80 | (bytenr & 0xF)));
                for (var i = (sbyte)(((sbyte)bytenr) - 1); i >= 0; i--)
                {
                    result.Add((byte) ((length >> (i*8)) & 0xFF));
                }
            }
            return result;
        }

        public static String BitStringToString(List<Boolean> bitstring)
        {
            var bd = new StringBuilder();
            UInt32 i = 0;
            if (bitstring == null)
            {
                return "";
            }
            bd.Append("BitString Value:\n");
            foreach (var b in bitstring)
            {
                bd.AppendFormat("{0} {1} \n", i++, b);
            }
            return bd.ToString();
        }

        public static Boolean LogicAndOnBooleanList(List<Boolean> bitString)
        {
            var result = true;
            foreach (var b in bitString)
            {
                result = result && b;
            }
            return result;
        }
    }
}
