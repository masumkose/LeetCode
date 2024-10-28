

#include "../include/include.hpp"

class Solution
{
public:
	int atMostNGivenDigitSet(vector<string> &digits, int n)
	{
		string n_str = to_string(n);
		int dignum = log10(n + 1);
		int size = digits.size();
		int total = 0;
		for (int i = 0; i < dignum; i++)
		{
			total += pow(size, i + 1);
		}
		for (auto &digit : digits)
		{
			for (auto ch : n_str)
			{

			}
		}




		return (total);
	}
};

int main()
{
	Solution ss;

	vector<vector<string>> digits = {{"1", "3", "5", "7"},
		{"5", "7", "8"}};
	vector<int> n = {100, 59};
	int i = 0;
	for (auto digit : digits)
		cout << ss.atMostNGivenDigitSet(digit, n[i++]) << '\n';


	return (0);
}
