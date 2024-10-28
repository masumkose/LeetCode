

#include "../include/include.hpp"

class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		int red = 0;
		int white = 0;
		int blue = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			switch (nums[i])
			{
			case 0:
				red++;
				break;
			case 1:
				white++;
				break;
			case 2:
				blue++;
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < red; i++)
			nums[i] = 0;
		for (int i = red; i < white + red; i++)
			nums[i] = 1;
		for (int i = white + red; i < nums.size(); i++)
			nums[i] = 2;
	}
};

int main()
{
	Solution ss;

	vector<int> colors = {2,0,2,1,1,0};

	ss.sortColors(colors);
	print_container(colors);

	return (0);
}
