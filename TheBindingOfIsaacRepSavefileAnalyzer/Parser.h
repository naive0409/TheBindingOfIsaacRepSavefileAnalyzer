#pragma once
#include "myInclude.h"
#include "ParsedObject.h"

class Parser
{
public:
	Parser()
	{

	}
	void parse(vector<u8>& unparsedData);
private:
	ParsedObject parsedObject;
	vector<u8>::iterator iter;

	u8 readU8();
	u16 readU16();
	u32 readU32();
	
	u32 getU32(//vector<u8>::iterator iter = iter, 
		int offset = 0
	);

	void hexPreview(int num = 40)
	{
		for (int i = 0; i < num; i++)
		{
			//cout << static_cast<u16>(*(iter + i)) << ',';
			cout
				//<< hex
				<< static_cast<u16>(*(iter + i))
				<< '(' << i << ')' << ',';
			if (!((i + 1) % 16)) cout << endl;
		}
		cout << endl;

	}
};
