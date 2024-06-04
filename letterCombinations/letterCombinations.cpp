
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		if (digits.empty()) return {};
		map<string, string> keyboard = {{"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"}, {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}};
		vector<string> result = {""};
		for(auto digit : digits)
		{
			vector<string> temp;
			string letters = keyboard[string(1,digit)];
			for (auto ch : letters)
			{
				for (auto combination : result)
				{
					temp.push_back(combination + ch);
				}
			}
			result = temp;
		}
		return (result);
	}
};




int main()
{

	Solution ex;
	vector<string> result = ex.letterCombinations("23");


	for (auto it = result.begin(); it != result.end(); it++)
	{
		cout << *it << endl;
	}

}
