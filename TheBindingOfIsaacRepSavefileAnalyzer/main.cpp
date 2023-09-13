#pragma once

#include "myInclude.h"

#include "Analyzer.h"

int main()
{
	Analyzer analyzer;
	analyzer.fileReader.readSaveFile();
	//analyzer.fileReader.viewSavedata();
	vector<u8>& savedata = analyzer.fileReader.savedata;
	analyzer.parser.parse(savedata);
	
	return 0;
}