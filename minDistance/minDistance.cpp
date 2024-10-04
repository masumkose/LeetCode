

#include "../include/include.hpp"

class Solution
{
public:
	std::map<std::pair<int, int>, int> memo;

	int dp(const string &word1, const string &word2, int i, int j)
	{
		if (i == word1.size())
			return word2.size() - j;

		if (j == word2.size())
			return word1.size() - i;

		auto key = make_pair(i, j);
		if (memo.find(key) != memo.end())
			return (memo[key]);

		if (word1[i] == word2[j])
		{
			return memo[key] = dp(word1, word2, i + 1, j + 1);
		}
		else
		{
			int deleteOp =  1 + dp(word1, word2, i + 1, j);
			int insertOp =  1 + dp(word1, word2, i, j + 1);
			int replaceOp = 1 + dp(word1, word2, i + 1, j + 1);
	
			return memo[key] = min({deleteOp, insertOp, replaceOp});
		}
	}

	int minDistance(string word1, string word2)
	{
		return (dp(word1, word2, 0, 0));
	}
};

int main()
{
	Solution ss;

	cout << ss.minDistance("horse", "ros") << endl;

	 cout << ss.minDistance("intention", "execution") << endl;
	 cout << ss.minDistance("dinitrophenylhydrazine", "dinitrophenylhydrazine") << endl;

	return (0);
}
