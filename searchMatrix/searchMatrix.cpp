

#include "../include/include.hpp"

class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int col_s = matrix.size();
		int row_s = matrix[0].size();
		for (auto row : matrix)
		{
			if (row[row_s - 1] < target)
				continue;
			for (auto col : row)
			{
				if (col == target)
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
	int target = 3;

	cout << ss.searchMatrix(matrix, 3) << '\n';
	cout << ss.searchMatrix(matrix, 13) << '\n';

	return (0);
}
