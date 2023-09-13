#pragma once
#include "FileReader.h"

FileReader::FileReader()
{

}

void FileReader::readSaveFile(const char dir[])
{
	ifstream inputFile(dir, ios::binary); // �򿪶������ļ�
	if (!inputFile) {
		cout << "�޷����ļ�" << endl;
		return;
	}

	// ��ȡ�ļ����ݲ��洢��vector<u8>��
	char byte;
	while (inputFile.read(&byte, sizeof(u8))) {
		this->savedata.push_back(static_cast<u8>(byte));
	}

	inputFile.close(); // �ر��ļ�
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
