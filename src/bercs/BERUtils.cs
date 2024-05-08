using System;
using System.Collections.Generic;
using System.Text;

namespace BER
{
    public static class BERUtils
    {
		//! Encodes a flag list provided as a boolean List into a bitwise format according to a BERBitString.
		//! \param bitList The flag list 
		//! \return A byte list containing the encoded flags in bitwise format.			
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
		//! Decodes the flags encoded according to a BERBitString in a bitwise manner into a boolean byte list 
		//! \param flagList The flagList in bitwise implementation to be decoded into a boolean byte list
		//! \param count The number of flags contained encoded into the flagList
		//! \return A byte list containing containing the decoded bitwise flags into a boolean list
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
		//! Encodes a length value into a format according to the Basic Encoding Rules
		//! \param length The value of the length to be encoded
		//! \return A byte list containing the raw bytes of the encoded length
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
		//! Provides a string representation of a Boolean List as a sequence of 0s and 1s
		//! \param bitstring The Boolean List to be represented as a string
		//! \return The string representing the Boolean List
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
