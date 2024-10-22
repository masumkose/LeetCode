

#include "../include/include.hpp"

class Solution
{
public:
	void gameOfLife(vector<vector<int>> &board)
	{
		if (board.empty() || board[0].empty()) return;
		int len = board.size();
		int len2 = board[0].size();
		vector<vector<int>> liveOnes(len, vector<int>(len2, 0));
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				liveOnes[i][j] =	(i + 1 < len ? board[i + 1][j] : 0) +
									(i - 1 >= 0 ? board[i - 1][j] : 0) +
									(i + 1 < len && j + 1 < len2 ? board[i + 1][j + 1] : 0) +
									(i - 1 >= 0 && j - 1 >= 0 ? board[i - 1][j - 1] : 0) +
									(i + 1 < len && j - 1 >= 0 ? board[i + 1][j - 1] : 0) +
									(i - 1 >= 0 && j + 1 < len2 ? board[i - 1][j + 1] : 0) +
									(j - 1 >= 0 ? board[i][j - 1] : 0) +
									(j + 1 < len2 ? board[i][j + 1] : 0);
			}
		}
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (board[i][j])
				{
					if (liveOnes[i][j] < 2)
						board[i][j] = 0;
					else if (liveOnes[i][j] > 3)
						board[i][j] = 0;
				}
				else if (liveOnes[i][j] == 3)
				{
					board[i][j] = 1;
				}
			}
		}
=
	}
};

int main()
{
	Solution ss;
	vector<vector<vector<int>>> matrix =
		{{{0,1,0}, {0,0,1}, {1, 1, 1}, {0,0,0}},
		 {{1,1},{1,0}}};
	print_nested_container(matrix[0]);
	ss.gameOfLife(matrix[0]);
	print_nested_container(matrix[0]);
	print_nested_container(matrix[1]);
	ss.gameOfLife(matrix[1]);
	print_nested_container(matrix[1]);

	return (0);
}
