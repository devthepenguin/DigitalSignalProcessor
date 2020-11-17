#include <stdlib.h>
#include <stdio.h>

class DSPFile
{
private:
	// Data type 0-7 as defined above
	DSPFILETYPE m_type;

	// Size of each element
	unsigned char m_elementSize;

	// Number of records
	int m_numRecords;

	// Number of elements in each record
	int m_recLen;

	// Pointer to trailer text
	char* m_trailer;

	// File data
	fstream m_fs;
	bool m_readOnly;
	stream m_posBeginData;

	// Buffer for reading single elements
	BYTE* m_singleElement;

	// Helper Functions

	// Clear data
	void empty();
public:
	// Constructor and Destructor
	DSPFile();
	~DSPFile();

	// File operation

	static bool isFound(const char* name);
	bool hasData() { return((m_numRecords * m_recLen) != 0); }
	void openRead(const char* name);
	void openWrite(const char* name);
	void close();

	// Get file format
	DSPFILETYPE getType() { return m_type; }
	int getNumRecords() { return m_numRecords; }
	int getRecLen() { return m_recLen; }

	// Get and Set file contents
	void getTrailer(String& str);
	void setTrailer(const char* trailer);
	void seek(int len = 0, int rec = 0);

	/*
	* The first element in the structure defines the type of data in the data area.
	* Eleven types have been defined and represented by values from 0 to 10.
	* The C++ const statement is used in order to conveniently use these types
	* in other C++ functions as follows:
	*/

	typedef unsigned char DSPFILETYPE;
	// C DSP_FILE compatible types
	const DSPFILETYPE UNSIGNED_CHAR = 0;
	const DSPFILETYPE UNSIGNED_SHORT = 1;
	const DSPFILETYPE UNSIGNED_LONG = 2;
	const DSPFILETYPE FLOAT = 3;
	const DSPFILETYPE SIGNED_CHAR = 4;
	const DSPFILETYPE SIGNED_SHORT = 5;
	const DSPFILETYPE SIGNED_LONG = 6;
	const DSPFILETYPE DOUBLE = 7;

	// Define for additional data types (C++ DSPFile only)
	const DSPFILETYPE UNSIGNED_INT = 8;
	const DSPFILETYPE SIGNED_INT = 9;

	// Complex numbers
	const DSPFILETYPE COMPLEX = 10;

	// Unknown type
	const DSPFILETYPE UNKNOWN_TYPE = 0xFF;

};