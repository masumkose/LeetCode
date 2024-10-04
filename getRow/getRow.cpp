

#include "../include/include.hpp"

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		if (rowIndex == 0) return {1};
		vector<int> row;
		vector<vector<int>> res;


		for (int i = 0; i < rowIndex + 1; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
					row.push_back(1);
				else if (j == i)
					row.push_back(1);
				else
					row.push_back(res[i - 1][j] + res[i - 1][j - 1]);
			}
			res.push_back(row);
			row.clear();
		}

		return res[rowIndex];
	}
};

int main()
{
	Solution ss;

	vector<int> nums = {0, 1, 2, 3, 4, 5, 6}; //, 1, 3, 6};

	for (auto num : nums)
	{
		print_container(ss.getRow(num));
	}

	return (0);
}