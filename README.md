# BERLib: A Basic Encoding Rules Implementation

This projects offers a BER (Basic Encoding Rules) implementation in three programming languages (C, C++, C#) that offers encoding and decoding of data types in order to be used in serialization and deserialization
processes in communication protocols. The implementation is consistent with the currently active
standards and it also offers a great degree of scalability enabling the programmer to adapt it according to
the needs of the project. BERLib is also highly documented and significant examples are provided for all the
programming languages used. Our work qualifies as an ideal solution for providing data encoding and decoding
in communication protocol design especially for Wireless Sensor Networks and Internet of Things.

## Repository structure

    .
    ├── src                     # Source files
    │   ├── berc                # Source files for the C implementation
    │   ├── bercpp              # Source files for the C++ implementation
    │   └── bercs               # Source files for the C# implementation    
    ├── exmples                 # Usage examples
    │   ├── example-berc        # Usage example for the C implementation
    │   ├── example-bercpp      # Usage example for the C++ implementation
    │   └── example-bercs       # Usage example for the C# implementation 
    ├── Doxyfile-berc           # Doxygen configuration file for generating the documentation for the C implementation
    ├── Doxyfile-berpp          # Doxygen configuration file for generating the documentation for the C++ implementation
    ├── Doxyfile-bercs          # Doxygen configuration file for generating the documentation for the C# implementation
    ├── LICENSE                 # License file
    └── README.md               # Readme file

## Usage examples

In the examples subdirectory there is an example for each type of implementation.

### Example for C implementation

The usage example for the C implementation may be found in ./examples/example-berc. It demonstrates the usage of the following BER Types: 
* BERUnsigned
* BERLong64Unsigned
* BEROctetString
* BERStructure

For each of these types a value is encoded into a raw byte buffer and is then deocded and printed to standard output

A simple makefile is present in order to easily compile the code.


### Example for C++ implementation

The usage example for the C++ implementation may be found in ./examples/example-bercpp. It demonstrates the usage of the following BER Types: 
* BERUnsigned
* BERLong64Unsigned
* BEROctetString
* BERBitString
* BERStructure
* BERArray
 

For each of these types a value is encoded into BasicBuffer object and is then deocded and printed to standard output.

A simple makefile is present in order to easily compile the code.

### Example for C# implementation

The usage example for the C implementation may be found in ./examples/example-bercs/example-berlibcs. This subdirectory contains a Microsoft Visual Studio Solution with 2 projects:

* BERLibCS - A Class Library project which includes the C# source files. The output of this project is BERLibCS.dll library
* example-berlibcs - A Console Appliation project which contains the actual examples and uses the BERLibCS.dll library
 

This examples demonstrates the usege of the following BER Types:
* BERUnsigned
* BERLong64Unsigned
* BEROctetString
* BERBitString
* BERStructure
* BERArray
 

For each of these types a value is encoded into List < Byte >  object and is then deocded and printed to standard output.

## Generating the documentation

In order to generate the Doxygen documentation, the Doxygen tools must be installed along with Graphiz in order to also obtain the class and call diagrams. A Doxygen configuration file is provided for each type of implementation

* Generate the documentation for the C implementaion.

```
doxygen Doxyfile-berc
```

* Generate the documentation for the C++ implementaion.
```
doxygen Doxyfile-bercpp
```

* Generate the documentation for the C# implementaion.
```
doxygen Doxyfile-bercs
```