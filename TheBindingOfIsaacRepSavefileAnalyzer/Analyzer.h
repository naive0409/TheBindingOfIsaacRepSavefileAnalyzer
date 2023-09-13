#pragma once

#include "myInclude.h"

#include "FileReader.h"
#include "Parser.h"

class Analyzer
{
public:
	
	FileReader fileReader;
	Parser parser;
	Analyzer() {
	}
	void test();
};
