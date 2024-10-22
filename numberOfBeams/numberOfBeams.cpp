

#include "../include/include.hpp"

class Solution
{
public:
	int numberOfBeams(vector<string> &bank)
	{
		vector<int> devices(bank.size(), 0);
		for (auto str : bank)
		{
			devices.push_back(std::count(str.begin(), str.end(), '1'));
		}
		int total = 0;
		int carp = 1;
		int prev = 0;
		for (auto &dev : devices)
		{
			total += dev * prev;
			if (dev != 0)
				prev = dev;
		}
		return total;
	}
};

int main()
{
	Solution ss;
	vector<vector<string>> bank =
		{
			{"011001", "000000", "010100", "001000"},
			{"000", "111", "000"}
		};

	for (auto b : bank)
		cout << ss.numberOfBeams(b) << '\n';

	return (0);
}
