#pragma once

#include "necessaryInclude.h"
#include "AbstractInterface.h"

class ParsedObject : public AbstractInterface
{
public:
	ParsedObject(){}
	string preleading = "";
	u32 checksum = 0;
	vector<bool> achis;
	map<string, u32> counter;
	vector<u32> counter_data;
	vector<bool> collectibles;
	vector<bool> challenges;
	vector<u32>	cutscene;
	vector<u32>	level;
	map<string, vector<u32>> bestiary;
private:
};

