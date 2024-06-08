#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution
{
public:
	bool isValid(string s)
	{
		unordered_map<char, char> matching_bracket =
		{
			{')', '('},
			{']', '['},
			{'}', '{'}
		};
		stack<char> stack;

		for (auto ch : s)
		{
			if (ch == '(' || ch == '[' || ch == '{')
			{
				stack.push(ch);
			}
			else if (ch == ')' || ch == ']' || ch == '}')
			{
				if (stack.empty() || stack.top() != matching_bracket[ch])
					return (false);
				stack.pop();
			}
		}	
		return (stack.empty());
	}
};



int main()
{

	Solution s;
	vector<string> tests;

	tests.push_back("()");
	tests.push_back("()[]{}");
	tests.push_back("(]");
	tests.push_back("]()[");
	tests.push_back("([)]");
	tests.push_back("{[]}");
	tests.push_back("{[()]}");
	for (auto test : tests)
	{
		if (s.isValid(test))
			cout << "true" << '\n';
		else
			cout << "false" << '\n';
	}

	return (0);
}