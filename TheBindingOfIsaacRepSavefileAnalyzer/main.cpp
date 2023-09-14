#pragma once

#include "necessaryInclude.h"

#include "Analyzer.h"

int main()
{
	BindingOfIsaacRepSavefileAnalyzer ana;

	ana.loadSavefile();
	ana.parse();

	ana.test();
	
	
	return 0;
}