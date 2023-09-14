#pragma once

#include "FileReader.h"

void FileReader::readSaveFile(const char dir[])
{
	ifstream inputFile(dir, ios::binary); // 打开二进制文件
	if (!inputFile) {
		cout << "无法打开文件 " 
			<< dir << endl;
		return;
	}

	// 读取文件内容并存储在vector<u8>中
	char byte;
	while (inputFile.read(&byte, sizeof(u8))) {
		this->savedata.push_back(static_cast<u8>(byte));
	}

	inputFile.close(); // 关闭文件
}

vector<u8>& FileReader::getSavedata()
{
	//if(this->savedata != NULL)
		return (this->savedata);
	throw "savedata not found";
}
