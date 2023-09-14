#pragma once

#include "FileReader.h"

void FileReader::readSaveFile(const char dir[])
{
	ifstream inputFile(dir, ios::binary); // �򿪶������ļ�
	if (!inputFile) {
		cout << "�޷����ļ� " 
			<< dir << endl;
		return;
	}

	// ��ȡ�ļ����ݲ��洢��vector<u8>��
	char byte;
	while (inputFile.read(&byte, sizeof(u8))) {
		this->savedata.push_back(static_cast<u8>(byte));
	}

	inputFile.close(); // �ر��ļ�
}

vector<u8>& FileReader::getSavedata()
{
	//if(this->savedata != NULL)
		return (this->savedata);
	throw "savedata not found";
}
