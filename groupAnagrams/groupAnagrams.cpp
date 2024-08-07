

#include "../include/include.hpp"


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>>	res;
		unordered_map<string, vector<string>> anagMap;

		for (auto str : strs)
		{
			string sorted = str;
			sort(sorted.begin(), sorted.end());
			anagMap[sorted].push_back(str); 
		}

		for (auto &pair : anagMap)
		{
			res.push_back(pair.second);
		}

		return (res);
	}

};


int main()
{
	Solution ss;
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};


	print_nested_container(ss.groupAnagrams(strs));
	return (0);
}
