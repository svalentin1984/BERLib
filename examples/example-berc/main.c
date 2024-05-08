#include <stdio.h>
#include <ber.h>
#include <string.h>
#include <stdlib.h>

void PrintBuffer(uint8_t *buffer, uint32_t length)
{
  int i = 0;
  for (i = 0; i < length; i++)
    {
      printf ("%02X", buffer[i]);
    }
  printf ("\n");
}

int main(void)
{
  uint8_t encodedBuffer[256];
  uint32_t encodedBufferIndex = 0;
  uint32_t decodedBufferIndex = 0;
  uint32_t printIndex = 0;
  uint8_t value8 = 0;
  uint64_t value64 = 0;
  uint16_t value16 = 0;
  //create and encode a BERUnsigned
  encodedBufferIndex = 0;
  printIndex = 0;
  BERUnsignedEncode(100, encodedBuffer, &encodedBufferIndex);
  BERPrintEncodedBufferAsBer(encodedBuffer, &printIndex, encodedBufferIndex);
  printf ("\n");
  printf ("Encoded data:");
  PrintBuffer(encodedBuffer, encodedBufferIndex);
  //decode BERUnsigned
  decodedBufferIndex = 0;
  if (BERUnsignedDecode(&value8, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
    {
      printf ("Decoded value %hhu\n", value8);
    }
  else
    {
      fprintf (stderr, "Decode error\n");
      exit(-1);
    }

  //create and encode a BERLong64Unsigned
  encodedBufferIndex = 0;
  printIndex = 0;
  BERLong64UnsignedEncode(0x11223344AABBCCDD, encodedBuffer, &encodedBufferIndex);
  BERPrintEncodedBufferAsBer(encodedBuffer, &printIndex, encodedBufferIndex);
  printf ("\n");
  printf ("Encoded data:");
  PrintBuffer(encodedBuffer, encodedBufferIndex); 
  // decode BERLong64unsigned
  decodedBufferIndex = 0;
  if (BERLong64UnsignedDecode(&value64, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
    {
      printf ("Decoded value %lX\n", value64);
    }
  else
    {
      fprintf (stderr,"Decode error\n");
      exit(-1);
    }
  //create and encode a BEROctetString
  encodedBufferIndex = 0;
  printIndex = 0;
  char octetStringValue[] = "MyStringValue";
  char octetStringDecoded[128];
  uint32_t octetStringDecodedSize = 0;
  BEROctetStringEncode((uint8_t*)octetStringValue, strlen(octetStringValue), encodedBuffer, &encodedBufferIndex);
  BERPrintEncodedBufferAsBer(encodedBuffer, &printIndex, encodedBufferIndex);
  printf ("\n");
  printf ("Encoded data:");
  PrintBuffer(encodedBuffer, encodedBufferIndex); 
  decodedBufferIndex = 0;
  //decode BEROctetString
  if (BEROctetStringDecode((uint8_t *)octetStringDecoded, &octetStringDecodedSize, 127, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
     {
       octetStringDecoded[octetStringDecodedSize] = 0;
       printf ("Decoded value %s\n", octetStringDecoded);
     }
  else
    {
      fprintf (stderr, "Decode error\n");
    }   
  //create and encode a BERStructure
  encodedBufferIndex = 0;
  printIndex = 0;
  BERStructureEncode(3, encodedBuffer, &encodedBufferIndex);
  BERUnsignedEncode(100, encodedBuffer, &encodedBufferIndex);
  BERLong64UnsignedEncode(0x11223344AABBCCDD, encodedBuffer, &encodedBufferIndex);
  BEROctetStringEncode((uint8_t*)octetStringValue, strlen(octetStringValue), encodedBuffer, &encodedBufferIndex);
  BERPrintEncodedBufferAsBer(encodedBuffer, &printIndex, encodedBufferIndex);
  printf ("\n");
  printf ("Encoded data:");
  PrintBuffer(encodedBuffer, encodedBufferIndex);  
  // decode BERStructure
  decodedBufferIndex = 0;
  if (BERStructureDecode(&value16, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
    {
      printf ("BERStructure - size: %d\n", value16);
    }
  else
    {
      fprintf(stderr, "Decode error\n");
      exit(-1);
    }
  if (BERUnsignedDecode(&value8, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
    {
      printf ("    BERUnsigned Decoded value %hhu\n", value8);
    }
  else
    {
      fprintf (stderr, "Decode error\n");
      exit(-1);
    }
  if (BERLong64UnsignedDecode(&value64, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
    {
      printf ("    BERLong64Unsigned Decoded value %lX\n", value64);
    }
  else
    {
      fprintf (stderr,"Decode error\n");
      exit(-1);
    }
  if (BEROctetStringDecode((uint8_t *)octetStringDecoded, &octetStringDecodedSize, 127, encodedBuffer, &decodedBufferIndex, encodedBufferIndex) == true)
    {
      octetStringDecoded[octetStringDecodedSize] = 0;
      printf ("    BEROctetString Decoded value %s\n", octetStringDecoded);
    }
  else
    {
      fprintf (stderr, "Decode error\n");
    }   
  
  return 0;
}
