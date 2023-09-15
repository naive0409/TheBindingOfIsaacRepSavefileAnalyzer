#pragma once

//#include "necessaryInclude.h"
//#include "AbstractInterface.h"

#include "FileReader.h"
#include "Parser.h"
#include "Statistic.h"
#include "Displayer.h"

class BindingOfIsaacRepSavefileAnalyzer : public AbstractInterface
{
private:
	FileReader fileReader;
	Parser parser;
	Statistic statistic;
	Displayer displayer;

public:
	BindingOfIsaacRepSavefileAnalyzer() {}

	void loadSavefile();
	void parse();
	void count();


	vector<u8>& getUnparsedData();
	ParsedObject& getParsedData();

	virtual void test()
	{
		vector<u8>& v = this->getUnparsedData();
		ParsedObject& p = this->getParsedData();
		return;
	}

};

