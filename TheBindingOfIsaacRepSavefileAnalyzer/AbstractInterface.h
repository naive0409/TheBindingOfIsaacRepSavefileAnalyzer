#pragma once

//#include "necessaryInclude.h"

class AbstractInterface
{
public:
	virtual void test()
	{
		cout << "ABSTRACT TESTING" << endl;
	}
	virtual void overview()
	{
		cout << "ABSTRACT OVERVIEW" << endl;
	}
};
