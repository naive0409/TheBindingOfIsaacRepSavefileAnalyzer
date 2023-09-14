#pragma once

//#include "necessaryInclude.h"
//#include "AbstractInterface.h"

#include "FileReader.h"
#include "Parser.h"
#include "Statistic.h"

class BindingOfIsaacRepSavefileAnalyzer : public AbstractInterface
{
private:
	FileReader fileReader;
	Parser parser;
	Statistic statistic;

public:
	BindingOfIsaacRepSavefileAnalyzer() {}

	void loadSavefile();
	void parse();
	void count()
	{
		//统计未完成的项目
		ParsedObject& p = this->getParsedData();
		this->statistic.countChallengesTodo(p);
		this->statistic.countAchievementsTodo(p);
		this->statistic.countItemsTodo(p);
	}

	vector<u8>& getUnparsedData();
	ParsedObject& getParsedData();

	virtual void test()
	{
		vector<u8>& v = this->getUnparsedData();
		ParsedObject& p = this->getParsedData();
		return;
	}

};

