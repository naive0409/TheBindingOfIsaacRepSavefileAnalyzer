#pragma once
#include "myInclude.h"

class Parser
{
public:
	Parser()
	{

	}
	vector<u8>::iterator iter;

	u8 read_uint8()
	{
		u8 res = 0;
		/*	for (int i = 0; i < 1; i++)
			{*/
			//res += (*it++) << 8 * i;
		res += *((this->iter)++);
		//}
		return res;
	}

	u16 read_uint16()
	{
		u16 res = 0;
		for (int i = 0; i < 2; i++)
		{
			res += *((this->iter)++) << 8 * i;
		}
		return res;
	}

	u32 read_uint32()
	{
		u32 res = 0;
		for (int i = 0; i < 4; i++)
		{
			res += *((this->iter)++) << 8 * i;
		}
		return res;
	}

	void parse(vector<u8>& unparsedData) {
		int savedata; //JSON
		string preleading = "";
		u32 checksum = 0;
		vector<bool> achis;
		vector<u32> counter_data;

		//std::vector<u8> v = { 73,83,65,65,67,78,71,83,65,86,69,48,57,82,32,32,93,150,51,254 };

		this->iter = unparsedData.begin();

		for (int i = 0; i < 16; i++)
		{
			preleading += *((this->iter)++);
			//cout << *(iter + i) << ',';
		}

		cout << preleading << endl;

		if (preleading != "ISAACNGSAVE09R  ") {
			cout << "您的存档格式不受支持，只支持忏悔(Rep)的存档";
			return;
		}

		checksum = read_uint32();
		cout << checksum << endl;


		int block_count = 0;
		while (block_count < 11) {
			block_count++;
			u32 block_type	 = read_uint32();
			u32 block_size	 = read_uint32();
			u32 extra_number = read_uint32();

			switch (block_type) {
			case 1:
			case 2:
			case 4:
			case 7:
			case 8:
			case 3:
			case 9:
			case 5:
			case 6:
			case 10:
			case 11:
			default:

			}


		}

	}


};
