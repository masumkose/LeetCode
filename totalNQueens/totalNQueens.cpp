
#include "../include/include.hpp"


class Solution
{
public:
	bool isValid(vector<string> &map, int row, int col, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (map[row][i] == 'Q')
				return false;
			if (map[i][col] == 'Q')
				return false;
		}

		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		{
			if (map[i][j] == 'Q')
				return false;
		}

		for (int i = row, j = col; i < n && j < n; i++, j++)
		{
			if (map[i][j] == 'Q')
				return false;
		}

		for (int i = row, j = col; i >= 0 && j < n; i--, j++)
		{
			if (map[i][j] == 'Q')
				return false;
		}

		for (int i = row, j = col; i < n && j >= 0; i++, j--)
		{
			if (map[i][j] == 'Q')
				return false;
		}

		return (true);
	}

	void back_track(vector<vector<string>> &res, vector<string> &map, int row, int col, int n)
	{
		if (row == n)
		{
			res.push_back(map);
			return;
		}
		for (int col = 0; col < n; col++)
		{
			if (isValid(map, row, col, n))
			{
				map[row][col] = 'Q';
				back_track(res, map, row + 1, col, n);
				map[row][col] = '.';
			}
		}
	}

	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		vector<string> map(n, string(n, '.'));
		back_track(res, map, 0, 0, n);
		return (res);
	}

	int totalNQueens(int n)
	{
		return (solveNQueens(n).size());
	}
};




int main()
{
	Solution ss;

	cout << ss.totalNQueens(4) << '\n';
	return (0);
}
