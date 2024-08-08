

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
};




int main()
{
	Solution ss;

	vector<vector<int>> intervals = 
	{
		{1,3},
		{2,6},
		{8,10},
		{15,18}
	};

	vector<vector<int>> intervals2 = 
	{
		{1,4},
		{4,5}
	};




	print_nested_container(ss.merge(intervals2));
	print_nested_container(ss.merge(intervals));




	return (0);
}
