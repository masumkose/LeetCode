

#include "../include/include.hpp"

class Solution
{
public:
	vector<int> plusOne(vector<int> &digits)
	{
		int val;

		digits[digits.size() - 1] += 1;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			if (digits[i] == 10)
			{
				if (i == 0)
				{
					digits[i] = 0;
					digits.insert(digits.begin(), 1);
				}
				else
				{
					digits[i] = 0;
					digits[i - 1]++;
				}
			}
		}
	return (digits);
	}
};


int main()
{

	Solution ss;

	vector<vector<int>> digits =
		{
			{1, 2, 3},
			{4, 3, 2, 1},
			{9}};

	for (auto digit : digits)
	{
		print_container(ss.plusOne(digit));
	}

	return (0);
}
