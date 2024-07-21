#include "../include.hpp"

void print_vector(const vector<int> &board)
{
	for (const auto num : board)
	{
		cout << num << ", ";
	}
	cout << endl;
}

void print_dvector(const vector<vector<int>> &board)
{
	for (const auto row : board)
	{
		print_vector(row);
	}
}

class Solution
{
	void backtrack(const vector<int> &candidates, int target, int start, vector<int> &combination, vector<vector<int>> &res)
	{
		if (target == 0)
		{
			res.push_back(combination);
			return;
		}
		for (int i = start; i < candidates.size(); ++i)
		{
			if (i > start && candidates[i] == candidates[i - 1])
				continue ;
			if (candidates[i] > target)
				break ;
			combination.push_back(candidates[i]);
			backtrack(candidates, target - candidates[i], i + 1, combination, res);
			combination.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> combination;

		sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0, combination, res);
		return (res);
	}
};

int main()
{
	Solution ss;
	vector<int> candidates = {2,5,2,1,2};
	print_dvector(ss.combinationSum2(candidates, 5));

	return (0);
}
