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
			if (candidates[i] > target)
				continue;
			combination.push_back(candidates[i]);
			backtrack(candidates, target - candidates[i], i, combination, res);
			combination.pop_back();
		}
	
	}

public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int>> res;

		candidates.erase(
			remove_if(candidates.begin(), candidates.end(),
					  [target](int x)
					  { return x > target; }),
			candidates.end());

		vector<int> combination;
		backtrack(candidates, target, 0, combination, res);
		return (res);
	}
};

int main()
{
	Solution ss;
	vector<int> candidates = {2, 3, 6, 14, 7};
	print_dvector(ss.combinationSum(candidates, 7));

	return (0);
}
