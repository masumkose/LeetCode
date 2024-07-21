
#include "../include/include.hpp"

class Solution
{
private:
	string special(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return ("0");
		if (num1 == "1")
			return (num2);
		if (num2 == "1")
			return (num1);
		return ("");
	}

public:
	string multiply(string num1, string num2)
	{
		string res = special(num1, num2);
		if (!res.empty())
			return (res);

		int len1 = num1.size();
		int len2 = num2.size();
		vector<int> result(len1 + len2, 0);
		for (int i = len1 - 1; i >= 0; --i)
		{
			for (int j = len2 - 1; j >= 0; --j)
			{
				int mult = (num1[i] - '0') * (num2[j] - '0');
				int p1 = i + j + 1;
				int p2 = i + j;

				result[p1] += mult % 10;
				if (result[p1] > 9)
				{
					result[p2] += result[p1] / 10;
					result[p1] = result[p1] % 10;
				}
				result[p2] += mult / 10;
			}
		}

		string resultStr;
		for (int num : result)
		{
			if (!(resultStr.empty() && num == 0))
			{
				resultStr.push_back(num + '0');
			}
		}
		return (resultStr);
	}
};

int main()
{
	// string num1 = "2", num2 = "3";
	// string num1 = "123", num2 = "456";
	string num1 = "123456789", num2 = "987654321";

	Solution ss;

	cout << ss.multiply(num1, num2) << '\n';

	return (0);
}
