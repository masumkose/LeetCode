
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
	vector<vector<int>> valid;

	bool sudoku_check(vector<vector<int>> &board, int row, int col, int num)
	{
		for (int x = 0; x < 9; x++)
		{
			if (x == col)
				continue;
			if (board[row][x] == num)
				return false;
		}

		for (int x = 0; x < 9; x++)
		{
			if (x == row)
				continue;
			if (board[x][col] == num)
				return false;
		}

		int startRow = row - row % 3;
		int startCol = col - col % 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (startRow + i == row && startCol + j == col)
					continue;
				if (board[startRow + i][startCol + j] == num)
					return false;
			}
		}
		return true;
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
					valid[i][j] = board[i][j] - '0';
			}
		}
	}


public:
	Solution() : valid(9, vector<int>(9)) {}
	bool isValidSudoku(vector<vector<char>> &board)
	{
		fill_valid(board);

		for (size_t i = 0; i < valid.size(); i++)
		{
			for (size_t j = 0; j < valid[i].size(); j++)
			{
				if (valid[i][j] == 0)
					continue ;
				if (sudoku_check(valid, i, j, valid[i][j]) == false)
					return false;
			}
		}
		return true;
	}
};

int main()
{

	vector<vector<char>> board_2 = {
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	vector<vector<char>> board_1 = {
		{'.', '8', '7', '6', '5', '4', '3', '2', '1'},
		{'2', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'3', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'4', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'5', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'6', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'7', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'8', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'9', '.', '.', '.', '.', '.', '.', '.', '.'}};

	Solution sl;
	if (sl.isValidSudoku(board_1))
	{
		cout << "board_1 = ";
		cout << "TRUE\n";
	}
	else
	{
		cout << "board_1 = ";
		cout << "FALSE\n";
	}

	//cout << "board_2 = ";
	//if (sl.isValidSudoku(board_2))
	//	cout << "TRUE\n";
	//else
	//	cout << "FALSE\n";

	return (0);
}
