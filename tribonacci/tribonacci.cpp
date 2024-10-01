

#include "../include/include.hpp"

class Solution
{
public:
	int tribonacci(int n)
	{
		switch (n)
		{
		case 0:
			return (0);
			break;
		case 1:
			return (1);
			break;
		case 2:
			return (1);
			break;
		default:
			break;
		}
		vector<int> res(n + 1, 0);

		res[0] = 0;
		res[1] = 1;
		res[2] = 1;

		for (int i = 3; i <= n; i++)
		{
			res[i] = res[i - 1] + res[i - 2] + res[i - 3];
		}
		return (res[n]);
	}
};

int main()
{
	Solution ss;


	cout << ss.tribonacci(6) << '\n';

	return (0);
}
