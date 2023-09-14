#pragma once

//#include "necessaryInclude.h"
//#include "AbstractInterface.h"

#include "ParsedObject.h"

class Parser : public AbstractInterface
{
public:
	Parser(){}
	void parse(vector<u8>& unparsedData);
	ParsedObject& getParsedData();
private:
	ParsedObject parsedObject;
	vector<u8>::iterator iter;

	u8 readU8();
	u16 readU16();
	u32 readU32();
	
	u32 getU32(const int offset = 0);

};
