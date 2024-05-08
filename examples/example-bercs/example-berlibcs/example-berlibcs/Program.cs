using BER;
using BER.Exceptions;
using System.Text;

class Program
{
    static void printByteBuffer(List<byte> bytes)
    {
        foreach (byte b in bytes) 
        {   
            Console.Write("{0:X}", b);
        }
        Console.WriteLine();
    }
    static void Main(string[] args)
    {
        List < Byte> encodedBer;
        
        BERUnsigned berUnsigned = new BERUnsigned();
        berUnsigned.Value = 100;
        encodedBer = berUnsigned.Encode();
        printByteBuffer(encodedBer);

        var ber = BERFactory.Create(encodedBer[0]);
        ber.Decode(encodedBer);
        Console.WriteLine(ber.ToString() + " " + ber.AsString());
        
        BERLong64Unsigned berLong64 = new BERLong64Unsigned();
        berLong64.Value = 0x11223344AABBCCDD;
        encodedBer = berLong64.Encode();
        printByteBuffer(encodedBer);

        ber = BERFactory.Create(encodedBer[0]);
        ber.Decode(encodedBer);
        Console.WriteLine(ber.ToString() + " " + ber.AsString());

        BERBitString berBitString = new BERBitString();
        berBitString.Value = new List<bool>();
        berBitString.Value.Add(true);
        berBitString.Value.Add(false);
        berBitString.Value.Add(false);
        berBitString.Value.Add(true);
        berBitString.Value.Add(true);
        encodedBer = berBitString.Encode();
        printByteBuffer(encodedBer);
        ber = BERFactory.Create(encodedBer[0]);
        ber.Decode(encodedBer);
        Console.WriteLine(ber.ToString() + " " + ber.AsString());

        String s = "Hello";
        BEROctetString berString = new BEROctetString();                
        byte[] array = Encoding.ASCII.GetBytes(s);
        berString.Value = new List<byte>(array);
        encodedBer = berString.Encode();
        printByteBuffer(encodedBer);
        ber = BERFactory.Create(encodedBer[0]);
        ber.Decode(encodedBer);
        Console.WriteLine(ber.ToString() + " " + ber.AsString());

        BERStructure berStructure = new BERStructure();
        berStructure.Value = new List<IBaseBERType>();
        berStructure.Value.Add(berUnsigned);
        berStructure.Value.Add(berLong64);
        berStructure.Value.Add(berBitString);
        berStructure.Value.Add(berString);
        encodedBer = berStructure.Encode();
        printByteBuffer(encodedBer);

        ber = BERFactory.Create(encodedBer[0]);
        ber.Decode(encodedBer);
        Console.WriteLine(ber.ToString() + " " + ber.AsString());





    }
}
