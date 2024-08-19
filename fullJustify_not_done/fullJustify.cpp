

#include "../include/include.hpp"

class Solution
{
public:
	vector<string> fullJustify(vector<string> &words, int maxWidth)
	{
		vector<string> res;
		string str;
		int leng = 0;
		for(auto word : words)
		{
			leng += str.length();
			if (leng <= maxWidth)
				str += word;
			else
			{
				res.push_back(str);
				leng = 0;
				str.clear();
			}
			cout << leng << '\n';
			str += " ";
		}



		return res;
	}
};

int main()
{
	Solution ss;
	vector<string> words = {"What","must","be","acknowledgment","shall","be"};

	print_container(ss.fullJustify(words, 16));

	return (0);
}
