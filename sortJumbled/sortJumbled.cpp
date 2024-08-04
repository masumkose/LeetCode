

#include "../include/include.hpp"

class Solution
{
public:
	vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
	{
		vector<int> res = {};
		map<float, int> mymap;

		for (int i = 0; i < nums.size(); i++)
		{
			int		num = nums[i];
			float	mynum = 0;
			int		m = 0;
			if (num == 0)
				mynum = mapping[0];
			while (num != 0)
			{
				mynum = mapping[num % 10] * pow(10, m) + mynum;
				num = num / 10;
				m++;
			}
			auto it = mymap.find(mynum);
			if (it == mymap.end())
				mymap.insert(pair<float, int>(mynum, nums[i]));
			else
				mymap.insert(pair<float, int>(mynum + 0.01, nums[i]));
		}

		for (const auto& element : mymap)
		{
			res.push_back(element.second);
		}

		return res;
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> nums = {{991,338,38}, {789,456,123}, {0,1,2,3,4,5,6,7,8,9}};
	vector<vector<int>> mapping = {{8,9,4,0,2,1,3,5,7,6}, {0,1,2,3,4,5,6,7,8,9}, {9,8,7,6,5,4,3,2,1,0}};

	//for (int i = 0; i < mapping.size(); i++)
	//{
	//	vector<int> result = ss.sortJumbled(mapping[i], nums[i]);
	//	print_container(result);
	//}

	vector<int> result = ss.sortJumbled(mapping[2], nums[2]);
	print_container(result);

	return (0);
}
