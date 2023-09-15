#pragma once

#include "necessaryInclude.h"
#include "AbstractInterface.h"


class Statistic : public AbstractInterface
{
public:

	void countStats(ParsedObject& p)
	{
		// 道具收集
		this->itemsTodo = this->findPositions(p.collectibles);

		// 成就
		this->achievementsTodo = this->findPositions(p.achis);

		// 挑战
		this->challengesTodo = this->findPositions(p.challenges);

		// 计数器
		vector<u32> tmp;
		vector<u32>& c_data = p.counter_data;

		_Append(tmp, c_data, 0, 27);
		_Append(tmp, c_data, 111, 116);
		_Append(tmp, c_data, 158, 173);
		_Append(tmp, c_data, 194, 203);
		_Append(tmp, c_data, 385, 404);
		_Append(tmp, c_data, 491, 0);

		this->counters = tmp;

		// 概览
		this->overview.insert(
			p.counter.begin(),
			p.counter.end()
		);

		this->overview["items collected"] = static_cast<u32>(
			count(
			p.collectibles.begin(),
			p.collectibles.end(),
			true
		)
			);

		this->overview["achivements unlocked"] = static_cast<u32>(
			count(
			p.achis.begin(),
			p.achis.end(),
			true
		)
			);


		return;
	}

private:
	vector<u32> achievementsTodo;
	vector<u32> itemsTodo;
	vector<u32> challengesTodo;
	vector<u32> counters;
	map<string, u32> overview;

	vector<u32> findPositions(const vector<bool>& v, bool flag = false) {
		vector<u32> Positions;
		for (int i = 0; i < (v).size(); ++i) {
			if (v[i] == flag) {
				Positions.push_back(i);
			}
		}
		return Positions;
	}

	void _Append(
		vector<u32>& v, vector<u32>& c,
		int begin, int end, bool flag = true
	)
	{
		v.insert(
			v.end(),
			begin ? (c.begin() + begin) : c.begin(),
			end ? (c.begin() + end) : c.end()
		);
		if (flag)
		{
			v.push_back(0xFFFFFFFF);
		}

	}


};
