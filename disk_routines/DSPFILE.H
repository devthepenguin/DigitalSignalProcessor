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
};