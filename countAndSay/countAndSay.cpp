

#include "../include.hpp"

class Solution
{
private:
	string rle_str(string rle)
	{
		string new_str;
		for(int i = 0; i < rle.length(); i++)
		{
			char c = rle[i];
			int n = 0;
			while (i < rle.length() && c == rle[i])
			{
				i++;
				n++;
			}
			i--;
			new_str.push_back(n + '0');
			new_str.push_back(c);
		}
		return (new_str);
	}

public:
	string countAndSay(int n)
	{
		string rle = "1";
		while (n != 1)
		{
			rle = rle_str(rle);
			n--;
		}
		return (rle);
	}
};




int main()
{
	Solution sl;

	cout << sl.countAndSay(4) << endl;

	return (0);
}