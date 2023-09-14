#pragma once

//#include "necessaryInclude.h"
//#include "AbstractInterface.h"

#include "FileReader.h"
#include "Parser.h"

class BindingOfIsaacRepSavefileAnalyzer : public AbstractInterface
{
private:
	FileReader fileReader;
	Parser parser;

public:
	BindingOfIsaacRepSavefileAnalyzer() {}

	void loadSavefile();
	void parse();

	vector<u8>& getUnparsedData();
	ParsedObject& getParsedData();

	virtual void test()
	{
		vector<u8>& v = this->getUnparsedData();
		ParsedObject& p = this->getParsedData();
		return;
	}

};


