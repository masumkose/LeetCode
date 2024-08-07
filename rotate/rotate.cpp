

#include "../include/include.hpp"

class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int size = matrix.size();
		int temp = 0;

		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < size; ++i)
		{
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> matrix = 
	{
		{5, 1, 9, 11}, 
		{2, 4, 8, 10}, 
		{13, 3, 6, 7}, 
		{15, 14, 12, 16}
	};

	vector<vector<int>> matrix2 = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	ss.rotate(matrix);
	ss.rotate(matrix2);

	print_nested_container(matrix);
	printf("---------------------\n");
	print_nested_container(matrix2);


	return (0);
}
