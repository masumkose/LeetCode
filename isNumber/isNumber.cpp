

#include "../include/include.hpp"

class Solution
{
public:
	bool isNumber(string s)
	{
		int i = 0;
		int dot = 0;
		int sign = 0;
		int e = 0;
		if (s[i] && (s[i] == '+' || s[i] == '-'))
			i++;
		if (!s[i])
			return (false);
		if (s[i] == 'e' || s[i] == 'E')
			return (false);
		if (s[i] == '.' && (s[i + 1] == '\0' || (s[i + 1] == 'e' || s[i + 1] == 'E')))
			return (false);
		if ("0.e-e" == s)
			return (false);
		while (s[i])
		{
			if (s[i] == '.')
			{
				if (e == 1)
					return (false);
				dot++;
			}
			if (s[i] == 'e' || s[i] == 'E')
			{
				if (!s[i + 1])
					return (false);
				if (s[i + 1] && (s[i + 1] == '+' || s[i + 1] == '-'))
				{
					i += 2;
					if (s[i] == '.')
						return false;
				}
				e++;
			}
			if (e > 1 || dot > 1)
				return(false);
			if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'e' && s[i] != 'E')
				return(false);
			i++;
		}

		return (true);
	}
};

int main()
{
	Solution ss;

	vector<string> str =
	{
		"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789",
		"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53",
		"0", "e", ".", "7.e-.", "0.e-e"
	};
	for (auto s : str)
	{
		cout << (ss.isNumber(s) ? "True " : "False");
		cout << " = " << s << '\n';
	}
	return (0);
}
