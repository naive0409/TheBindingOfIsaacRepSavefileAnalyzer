#pragma once
#include "Parser.h"
#include <map>

u8 Parser::readU8()
{
	u8 res = 0;
	/*	for (int i = 0; i < 1; i++)
		{*/
		// res += (*it++) << 8 * i;
	res += *((this->iter)++);
	//}
	return res;
}

u16 Parser::readU16()
{
	u16 res = 0;
	for (int i = 0; i < 2; i++)
	{
		res += *((this->iter)++) << 8 * i;
	}
	return res;
}

u32 Parser::readU32()
{
	u32 res = 0;
	for (int i = 0; i < 4; i++)
	{
		res += *((this->iter)++) << 8 * i;
	}
	return res;
}

u32 Parser::getU32(
	//vector<u8>::iterator iter, 
	int offset
)
{
	u32 res = 0;
	for (int i = 0; i < 4; i++)
	{
		vector<u8>::iterator temp_it = this->iter + offset + i;
		//cout << static_cast<u16>(*(temp_it)) << ',';
		res += *(temp_it) << 8 * i;
	}
	//cout << endl;
	return res;
}

void Parser::parse(vector<u8>& unparsedData) {
	//int savedata; //JSON
	string preleading = "";
	u32 checksum = 0;
	vector<bool> achis;
	map<string, u32> counter;
	vector<u32> counter_data;
	vector<bool> collectibles;
	vector<bool> challenges;
	vector<u32>	cutscene;
	vector<u32>	level;
	map<string, vector<u32>> bestiary;

	//std::vector<u8> v = { 73,83,65,65,67,78,71,83,65,86,69,48,57,82,32,32,93,150,51,254 };

	this->iter = unparsedData.begin();

	for (int i = 0; i < 16; i++)
	{
		preleading += *((this->iter)++);
		//cout << *(iter + i) << ',';
	}


	if (preleading != "ISAACNGSAVE09R  ") {
		cout << "您的存档格式不受支持，只支持忏悔(Rep)的存档";
		return;
	}

	checksum = readU32();


	int block_count = 0;
	while (block_count < 11) {
		block_count++;
		u32 block_type = readU32();
		u32 block_size = readU32();
		u32 extra_number = readU32();

		switch (block_type) {
		case 1:
		{
			u32 achi_count = extra_number;
			for (u32 i = 0; i < block_size; i++)
			{
				if (i < achi_count) achis.push_back(readU8() > 0);
			}
			break;
		}
		case 2:
		{
			//iter++;

			counter["momkills"] = getU32(4);
			counter["death"] = getU32(0x28);
			counter["beststreak"] = getU32(0x5c);

			for (u32 i = 0; i < block_size; i += 4)
			{
				counter_data.push_back(getU32(i));
			}
			this->iter += block_size;

			break;
		}
		case 4:
		{
			for (u32 i = 0; i < extra_number; i++)
			{
				collectibles.push_back(readU8() > 0);

			}
			break;
		}
		case 7:
		{
			for (u32 i = 0; i < extra_number; i++)
			{
				challenges.push_back(readU8() > 0);
			}
			break;
		}
		case 8:
		{
			for (u32 i = 0; i < extra_number; i++)
			{
				cutscene.push_back(readU32());
			}
			break;
		}
		case 3:
		{
			for (u32 i = 0; i < extra_number; i++)
			{
				level.push_back(readU32());
			}
			break;
		}
		case 9:
		{
			this->iter += block_size;
			break;
		}
		case 5:
		case 6:
		case 10:
		{
			this->iter += extra_number;
			break;
		}
		case 11:
		{
			u32 type, size;
			u8 SubType, Variant;
			u16 value, Type;
			for (u32 i = 0; i < 4; i++) {
				type = readU32();
				size = readU32() / 4 ;
				for (u32 j = 0; j < size; j++)
				{
					SubType = readU8();
					Variant = readU8();
					Type = readU8();
					Type += readU8() << 8;
					Type >>= 4;
					value = readU16();
					string key = to_string(Type) + '.' + to_string(Variant);

					if (bestiary.find(key) == bestiary.end())
					{
						vector<u32> temp(4);
						bestiary[key] = temp;
					}
					bestiary[key][static_cast<std::vector<std::_Vbase, std::_Vb_val<std::allocator<bool>>::_Alvbase>::size_type>(type) - 1] += value;
					readU16();
				}
			}
			break;

		}
		default:
			break;
		};

	}

	this->parsedObject.preleading = preleading;
	this->parsedObject.checksum = checksum;
	this->parsedObject.achis = achis;
	this->parsedObject.counter = counter;
	this->parsedObject.counter_data = counter_data;
	this->parsedObject.collectibles = collectibles;
	this->parsedObject.challenges = challenges;
	this->parsedObject.cutscene = cutscene;
	this->parsedObject.level = level;
	this->parsedObject.bestiary = bestiary;

}

