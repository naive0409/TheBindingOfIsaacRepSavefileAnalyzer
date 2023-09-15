#pragma once

#include "necessaryInclude.h"
#include "AbstractInterface.h"


class Statistic : public AbstractInterface
{
public:

	void count(ParsedObject& p)
	{
		this->itemsTodo = this->findFalsePositions(p.collectibles);
		this->achievementsTodo = this->findFalsePositions(p.achis);
		this->challengesTodo = this->findFalsePositions(p.challenges);

		vector<u32> tmp;
		vector<u32>& c_data = p.counter_data;

		addToEnd(tmp, c_data, 0, 27);
		addToEnd(tmp, c_data, 111, 116);
		addToEnd(tmp, c_data, 158, 173);
		addToEnd(tmp, c_data, 194, 203);
		addToEnd(tmp, c_data, 385, 404);
		addToEnd(tmp, c_data, 491, 0);

		this->counters = tmp;


		// 概览
		return;
	}


private:
	vector<u32> achievementsTodo;
	vector<u32> itemsTodo;
	vector<u32> challengesTodo;
	vector<u32> counters;
	map<string, u32> overview;

	vector<u32> findTruePositions(const vector<bool>& v) {
		vector<u32> Positions;
		for (int i = 0; i < (v).size(); ++i) {
			if ((v[i])) {
				Positions.push_back(i);
			}
		}
		return Positions;
	}

	vector<u32> findFalsePositions(const vector<bool>& v) {
		vector<u32> Positions;
		for (int i = 0; i < (v).size(); ++i) {
			if (!(v[i])) {
				Positions.push_back(i);
			}
		}
		return Positions;
	}

	void addToEnd(vector<u32>& v, vector<u32>& c,
		int begin, int end, bool flag = true)
	{
		v.insert(v.end(),
			begin ? (c.begin() + begin) : c.begin(),
			end ? (c.begin() + end) : c.end()
		);
		if (flag)
		{
			v.push_back(0xFFFFFFFF);
		}

	}


};
