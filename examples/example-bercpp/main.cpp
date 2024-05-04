#include <iostream>
#include <ber.h>

using namespace std;
using namespace BER;

int main(void)
{
	Ber *decodedBer;
	BasicBuffer *encoded;
	//create and encode a BERUnsigned
	BERUnsigned *berUnsisgned = new BERUnsigned();
	berUnsisgned->Value = new uint8_t(100);
	cout << berUnsisgned->toString() << endl;
	encoded = berUnsisgned->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;
	// generically decode the previously encoded BER
	decodedBer = BERDecode::Decode(encoded);
	cout << "Decoded ber: " << decodedBer->toString().c_str() << endl;

	//testing if the decoded BER is a BERUnsigned
	if (typeid(*decodedBer) == typeid(BERUnsigned))
	{
		cout << "The encoded buffer contained a BERUnsigned" << endl;
		uint8_t value = *((BERUnsigned*)decodedBer)->Value;
		cout << "The value of the BERUnsigned is: " << (uint32_t)value << endl;
	}
	delete encoded;
	delete decodedBer;

	//create and encode a BERLong64Unsigned
	BERLong64Unsigned *berLong64unsigned = new BERLong64Unsigned();
	berLong64unsigned->Value = new uint64_t;
	*(berLong64unsigned->Value) = 11111111;
	cout << berLong64unsigned->toString() << endl;
	encoded = berLong64unsigned->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;
	// generically decode the previously encoded BER
	decodedBer = BERDecode::Decode(encoded);
	cout << "Decoded ber: " << decodedBer->toString().c_str() << endl;
	delete encoded;
	delete decodedBer;

	//create and encode a BEROctetString from an actual string
	BEROctetString *berOctetString = BEROctetString::EncodeString("MyString");
	cout << berOctetString->toString() << endl;
	encoded = berOctetString->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;
	// generically decode the previously encoded BER
	decodedBer = BERDecode::Decode(encoded);
	cout << "Decoded ber: " << decodedBer->toString().c_str() << endl;
	delete encoded;
	delete decodedBer;
	//create and encode a BEROctetString from raw data
	BEROctetString *berOctetString2 = new BEROctetString();
	berOctetString2->Value = new BasicBuffer(5);
	berOctetString2->Value->PushBack(0x99);
	berOctetString2->Value->PushBack(0xAA);
	berOctetString2->Value->PushBack(0xBB);
	berOctetString2->Value->PushBack(0xCC);
	berOctetString2->Value->PushBack(0xDD);
	cout << berOctetString2->toString() << endl;
	encoded = berOctetString2->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;
	// generically decode the previously encoded BER
	decodedBer = BERDecode::Decode(encoded);
	cout << "Decoded ber: " << decodedBer->toString().c_str() << endl;
	delete encoded;
	delete decodedBer;

	//create and encode a BERBitString
	BERBitString *berBitString = new BERBitString();
	berBitString->Value = new BasicBuffer(5);
	berBitString->Value->PushBack(true);
	berBitString->Value->PushBack(false);
	berBitString->Value->PushBack(false);
	berBitString->Value->PushBack(true);
	berBitString->Value->PushBack(true);
	cout << berBitString->toString() << endl;
	encoded = berBitString->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;
	// generically decode the previously encoded BER
	decodedBer = BERDecode::Decode(encoded);
	cout << "Decoded ber: " << decodedBer->toString().c_str() << endl;
	delete encoded;
	delete decodedBer;

	//create and encode a BERStructure using the previously defined types as structure members
	BERStructure *berStructure = new BERStructure();
	berStructure->Value = new list<Ber*>();
	berStructure->Value->push_back(berUnsisgned);
	berStructure->Value->push_back(berLong64unsigned);
	berStructure->Value->push_back(berOctetString);
	berStructure->Value->push_back(berOctetString2);
	berStructure->Value->push_back(berBitString);
	cout << berStructure->toString() << endl;
	encoded = berStructure->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;

	//create and encode a BERArray having 2 of the above defined structures
	BERArray *berArray = new BERArray();
	berArray->Value = new list<Ber*>();
	berArray->Value->push_back(berStructure);
	//	berArray->Value->push_back(berStructure);
	cout << berArray->toString() << endl;
	encoded = berArray->Encode();
	cout << "Encoded data: " << BasicBuffer::BasicBufferToString(encoded) << endl;
	// generically decode the previously encoded BER
	decodedBer = BERDecode::Decode(encoded);
	cout << "Decoded ber: " << decodedBer->toString().c_str() << endl;
	delete encoded;
	delete decodedBer;

		delete berArray;


	return 0;
}
