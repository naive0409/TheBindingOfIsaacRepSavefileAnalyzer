#pragma once

#include "Analyzer.h"
//#include "Parser.h"

void BindingOfIsaacRepSavefileAnalyzer::loadSavefile() {
	this->fileReader.readSaveFile();
}

void BindingOfIsaacRepSavefileAnalyzer::parse()
{
	this->parser.parse(this->getUnparsedData());
}

void BindingOfIsaacRepSavefileAnalyzer::count()
{
	this->statistic.count(this->getParsedData());

}

vector<u8>& BindingOfIsaacRepSavefileAnalyzer::getUnparsedData()
{
	return this->fileReader.getSavedata();
}

ParsedObject& BindingOfIsaacRepSavefileAnalyzer::getParsedData()
{
	return this->parser.getParsedData();
}

