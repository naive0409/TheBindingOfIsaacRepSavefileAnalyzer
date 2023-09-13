#pragma once

#include "myInclude.h"


class FileReader
{
public:
	//char* savefileDir = NULL;
	FileReader();
	vector<u8> savedata;
	void readSaveFile(const char dir[] = DEFAULT_SAVEFILE_DIR);
	void viewSavedata(unsigned int previewNum = 40);
	

};

