#pragma once

#include "Analyzer.h"
//#include "Parser.h"

void BindingOfIsaacRepSavefileAnalyzer::loadSavefile() {
	this->fileReader.readSaveFile();
}

void BindingOfIsaacRepSavefileAnalyzer::parse()
{
	vector<u8>& savedata = this->fileReader.getSavedata();
	this->parser.parse(savedata);
}

vector<u8>& BindingOfIsaacRepSavefileAnalyzer::getUnparsedData()
{
	return this->fileReader.getSavedata();
}

ParsedObject& BindingOfIsaacRepSavefileAnalyzer::getParsedData()
{
	return this->parser.getParsedData();
}




//void BindingOfIsaacRepSavefileAnalyzer::test()
//{
//	cout << "testing" << endl;
//}
