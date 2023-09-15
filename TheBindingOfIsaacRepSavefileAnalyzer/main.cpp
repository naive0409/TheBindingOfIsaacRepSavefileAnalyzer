#pragma once

#include "necessaryInclude.h"

#include "Analyzer.h"


int main(int argc, char** argv)
{
	BindingOfIsaacRepSavefileAnalyzer ana;

	ana.loadSavefile();
	ana.parse();

	ana.count();

	ana.test();
	
	return 0;
}