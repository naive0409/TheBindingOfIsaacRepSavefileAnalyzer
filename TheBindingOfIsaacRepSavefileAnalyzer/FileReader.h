#pragma once

#include "necessaryInclude.h"
#include "AbstractInterface.h"

#include "defaults.h"

const unsigned int DEFAULT_PREVIEW_NUM = 40;

class FileReader : public AbstractInterface
{
public:
	FileReader();
	void readSaveFile(const char dir[] = DEFAULT_SAVEFILE_DIR);
	//void viewSavedata(const unsigned int previewNum = DEFAULT_PREVIEW_NUM);
	char* generateSavefileDir();
	vector<u8>& getSavedata();
private:
	vector<u8> savedata;

};

