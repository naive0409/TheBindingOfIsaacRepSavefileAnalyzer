#pragma once
#include "FileReader.h"

FileReader::FileReader()
{

}

void FileReader::readSaveFile(const char dir[])
{
	ifstream inputFile(dir, ios::binary); // 打开二进制文件
	if (!inputFile) {
		cout << "无法打开文件" << endl;
		return;
	}

	// 读取文件内容并存储在vector<u8>中
	char byte;
	while (inputFile.read(&byte, sizeof(u8))) {
		this->savedata.push_back(static_cast<u8>(byte));
	}

	inputFile.close(); // 关闭文件
}

void FileReader::viewSavedata(unsigned int previewNum)
{
	vector<u8>::iterator it = this->savedata.begin();
	cout << "preview savedata:" << endl;
	if (!previewNum)
	{
		for (; it != this->savedata.end(); it++) {
			cout << static_cast<u16>(*it) << ',';
		}
	}
	else {
		for (int i = 0; i != previewNum; i++,it++) {
			cout << static_cast<u16>(*it) << ',';
		}
	}
		cout << endl;
}
