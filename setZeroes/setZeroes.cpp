

#include "../include/include.hpp"

class Solution
{
public:

	void setZeroes(vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty()) return;
		int len = matrix.size();
		int len2 = matrix[0].size();
		vector<bool> cols (len2,false);
		vector<bool> rows (len, false);
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (matrix[i][j] == 0)
				{
					cols[j] = true;
					rows[i] = true;
				}
			}
		}
	
		for (int i = 0; i < len; i++)
		{
			if (rows[i])
			{
				for (int j = 0; j < len2; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}
	
		for (int i = 0; i < len2; i++)
		{
			if (cols[i])
			{
				for (int j = 0; j < len; j++)
				{
					matrix[j][i] = 0;
				}
			}
		}

	}
};

int main()
{
	Solution ss;
	vector<vector<vector<int>>> matrix =
		{{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
		 {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}};
	//ss.setZeroes(matrix[0]);
	ss.setZeroes(matrix[1]);
	//print_nested_container(matrix[0]);
	print_nested_container(matrix[1]);

	return (0);
}
