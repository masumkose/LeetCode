

#include "../include/include.hpp"

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix)
	{
		vector<int> res;

		int left = 0;
		int right = matrix[0].size() - 1;

		int top = 0;
		int bot = matrix.size() - 1;

		while (top <= bot && left <= right)
		{
			for (int i = left; i < right + 1; i++)
			{
				res.push_back(matrix[top][i]);
			}
			top += 1;
			for (int i = top; i < bot + 1; i++)
			{
				res.push_back(matrix[i][right]);
			}
			right -= 1;
			if (top <= bot)
			{
				for (int i = right; i > left - 1; i--)
				{
					res.push_back(matrix[bot][i]);
				}
				bot -= 1;
			}
			if (left <= right)
			{
				for (int i = bot; i > top - 1; i--)
				{
					res.push_back(matrix[i][left]);
				}
				left += 1;
			}
		}
		return (res);
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> matrix = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	vector<vector<int>> matrix2 = 
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};



	print_container(ss.spiralOrder(matrix));
	print_container(ss.spiralOrder(matrix2));



	return (0);
}
