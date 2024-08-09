

#include "../include/include.hpp"

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string ans;
		int sizea = a.size() - 1;
		int sizeb = b.size() - 1;

		while (sizea >= 0 && sizeb >= 0)
		{
			if (a[sizea] == '0')
				ans.insert(ans.begin(), b[sizeb]);
			else if (a[sizea] == '1')
			{
				if (b[sizeb] == '0')
				{
					ans.insert(ans.begin(), '1');
				}
				else
				{
					ans.insert(ans.begin(), '2');
				}
			}
			sizea--;
			sizeb--;
		}

		while (sizea >= 0)
		{
			ans.insert(ans.begin(), a[sizea]);
			sizea--;
		}

		while (sizeb >= 0)
		{
			ans.insert(ans.begin(), b[sizeb]);
			sizeb--;
		}

		for (int i = ans.size() - 1; i >= 0; --i)
		{
			if (ans[i] >= '2')
			{
				if (i == 0)
				{
					if (ans[i] == '2')
						ans[i] = '0';
					else
						(ans[i] = '1');
					ans.insert(ans.begin(), '1');
				}
				else
				{
					if (ans[i] == '2')
						ans[i] = '0';
					else
						(ans[i] = '1');
					ans[i - 1]++;
				}
			}
		}



		return (ans);
	}
};

int main()
{
	Solution ss;

	cout << ss.addBinary("11", "1") << '\n';
	cout << ss.addBinary("1010", "1011") << '\n';
	cout << ss.addBinary("1111", "1111") << '\n';

	return (0);
}
