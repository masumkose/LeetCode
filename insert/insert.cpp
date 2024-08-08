

#include "../include/include.hpp"

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		vector<vector<int>> res;

		for (auto &in : intervals)
		{
			sort(in.begin(), in.end());
		}
		sort(intervals.begin(), intervals.end());

		int index = 0;
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (res.back()[1] >= intervals[i][0])
			{
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
			else
			{
				res.push_back(intervals[i]);
				index++;
			}
		}
		return (res);
	}

	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		intervals.push_back(newInterval);
		return (merge(intervals));
	}
};

int main()
{
	Solution ss;



	vector<int> newInterval = {2,5};
	vector<vector<int>> intervals =
		{
			{1, 3},
			{6, 9}
		};



	vector<int> newInterval2 = {4,8};
	vector<vector<int>> intervals2 =
		{
			{1, 2},
			{3, 5},
			{6, 7},
			{8, 10},
			{12, 16}
		};

	print_nested_container(ss.insert(intervals, newInterval));
	print_nested_container(ss.insert(intervals2, newInterval2));

	return (0);
}
