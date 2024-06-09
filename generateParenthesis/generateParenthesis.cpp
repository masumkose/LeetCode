#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void backtrack(vector<string> &result, string current_combination, int open_count, int close_count, int n)
{
	if (current_combination.length() == 2 * n)
	{
		result.push_back(current_combination);
		return;
	}

	if (open_count < n)
	{
		backtrack(result, current_combination + "(", open_count + 1, close_count, n);
	}

	if (close_count < open_count)
	{
		backtrack(result, current_combination + ")", open_count, close_count + 1, n);
	}

}

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> res;
		backtrack(res, "", 0, 0, n);
		return (res);
	}
};


int main()
{
	Solution s;
	vector<string> ans = s.generateParenthesis(3);

	for (auto an : ans)
	{
		cout << an << '\n';
	}
	return (0);
}