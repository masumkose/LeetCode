

#include "../include/include.hpp"

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int n = s.length();
		vector<int> dp(n, 0);
		int res = 0;

		for (int i = 1; i < n; i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					if (i >= 2)
						dp[i] = dp[i - 2] + 2;
					else
						dp[i] = 2;
				}
				else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
				{
					if (i - dp[i - 1] >= 2)
						dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
					else
						dp[i] = dp[i - 1] + 2;
				}
			}
			res = max(res, dp[i]);
		}
		return (res);
	}
};

int main()
{
	Solution ss;

	vector<string> s =
	{
		"(()",
		")()())",
		"(((())()))",
		""
	};

	for (auto str : s)
	{
		cout << ss.longestValidParentheses(str) << '\n';
	}

	return (0);
}
