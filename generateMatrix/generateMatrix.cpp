

#include "../include/include.hpp"


class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> matrix(n, vector<int>(n, 0));  

		int left = 0;
		int right = n - 1;

		int top = 0;
		int bot = n - 1;

		int m = 1;

		while (top <= bot && left <= right)
		{
			for (int i = left; i < right + 1; i++)
			{
				matrix[top][i] = m++;
			}
			top += 1;
			for (int i = top; i < bot + 1; i++)
			{
				matrix[i][right] = m++;
			}
			right -= 1;
			if (top <= bot)
			{
				for (int i = right; i > left - 1; i--)
				{
					matrix[bot][i] = m++;
				}
				bot -= 1;
			}
			if (left <= right)
			{
				for (int i = bot; i > top - 1; i--)
				{
					matrix[i][left] = m++;
				}
				left += 1;
			}
		}
		return (matrix);
	}
};

int main()
{
	Solution ss;

	print_nested_container(ss.generateMatrix(1));

	return (0);
}
