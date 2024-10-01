

#include "../include/include.hpp"

class Solution
{
public:
	int fib(int n)
	{
		switch (n)
		{
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		
		default:
			break;
		}
		vector<int> v(n + 1, 0);
		v[0] = 0;
		v[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			v[i] = v[i - 1] + v[i - 2];
		}
		return (v[n]);
	}
};

int main()
{
	Solution ss;

	cout << ss.fib(6) << '\n';

	return (0);
}
