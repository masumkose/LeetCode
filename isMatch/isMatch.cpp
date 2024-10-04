#include "../include/include.hpp"

class Solution
{
public:
	vector<vector<int>> memo;

	bool dp (int i, int j, string &s, string &p)
	{
		if (memo[i][j] != -1)
			return memo[i][j];
		
		if (j == p.size())
			return memo[i][j] = (i == s.size());
		
		bool match = (i < s.size() && p[j] == s[i] || p[j] == '?');

		if (p[j] == '*')
		{
			memo[i][j] = dp(i,j + 1, s, p) || (i < s.size() && dp(i + 1, j, s, p));
		}
		else
		{
			memo[i][j] = match && dp(i + 1, j + 1, s, p);
		}
		return (memo[i][j]);
	}

	bool isMatch(string s, string p)
	{
		memo = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
		return (dp(0, 0, s, p));
	}
};

int main()
{
	Solution ss;

	cout << ss.isMatch("aa", "a") << endl;
	cout << ss.isMatch("aa", "*") << endl;
	cout << ss.isMatch("cb", "?b") << endl;
	cout << ss.isMatch("adceb", "*a*b") << endl;

	return (0);
}