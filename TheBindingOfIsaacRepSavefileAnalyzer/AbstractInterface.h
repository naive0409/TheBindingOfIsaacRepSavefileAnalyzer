#pragma once

//#include "necessaryInclude.h"

class AbstractInterface
{
public:
	virtual void test()
	{
		std::cout << "ABSTRACT TESTING" << endl;
	}
	virtual void overview()
	{
		std::cout << "ABSTRACT OVERVIEW" << endl;
	}
};
