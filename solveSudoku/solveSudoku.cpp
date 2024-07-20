
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
	vector<vector<int>> valid;
	vector<vector<char>>::iterator it;

	bool sudoku_check(vector<vector<int>> &board, int row, int col, int num)
	{
		for (int x = 0; x < 9; x++)
		{
			if (board[row][x] == num)
				return false;
		}

		for (int x = 0; x < 9; x++)
		{
			if (board[x][col] == num)
				return false;
		}

		int startRow = row - row % 3;
		int startCol = col - col % 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[startRow + i][startCol + j] == num)
					return false;
			}
		}
		return true;
	}

	bool bbd(vector<vector<int>> &board, int row, int col)
	{
		if (row == 9)
			return true;

		if (col == 9)
			return (bbd(board, row + 1, 0));

		if (board[row][col] != 0)
			return (bbd(board, row, col + 1));

		for (int num = 1; num <= 9; num++)
		{
			if (sudoku_check(board, row, col, num))
			{
				board[row][col] = num;
				if (bbd(board, row, col + 1))
					return (true);
				board[row][col] = 0;
			}
		}
		return (false);
	}

	void fill_valid(vector<vector<char>> &board)
	{
		valid.resize(9, vector<int>(9, 0));
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == '.')
					valid[i][j] = 0;
				else
					valid[i][j] = board[i][j] - '0'; // Convert char to int
			}
		}
	}

	void print_vector(const vector<vector<int>> &board)
	{
		for (const auto &row : board)
		{
			for (size_t i = 0; i < row.size(); i++)
			{
				if (i != 0)
					cout << ", ";
				cout << row[i];
			}
			cout << endl;
		}
	}

	void get_sol(vector<vector<char>> &board)
	{
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[i].size(); j++)
			{
				board[i][j] = valid[i][j] + '0';
			}
		}
	}


public:
	Solution() : valid(9, vector<int>(9)) {}
	bool solveSudoku(vector<vector<char>> &board)
	{
		fill_valid(board);

			print_vector(valid);
			cout << '\n';
		if (bbd(valid, 0, 0))
		{
			print_vector(valid);
			get_sol(board);
			return true;
		}
		get_sol(board);
		return false;
	}
};

int main()
{
	vector<vector<char>> board_1 = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};


	Solution sl;
	if (sl.solveSudoku(board_1))
		cout << "TRUE\n";
	else
		cout << "FALSE\n";

	return (0);
}
