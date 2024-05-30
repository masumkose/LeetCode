#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

int operation(int a, int b, string c)
{
	if (c == "+")
		return b + a;
	else if (c == "*")
		return b * a;
	else if (c == "/")
		return b / a;
	else if (c == "-")
		return b - a;
	else
		return (INT_MIN);
}


class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> stk;
		vector<string>::iterator it;
		int a,b;

		for (it = tokens.begin(); it != tokens.end(); it++)
		{
			if (*it == "+" || *it == "-" || *it == "*" || *it == "/")
			{
				a = stk.top();
				stk.pop();
				b = stk.top();
				stk.pop();
				stk.push(operation(a , b, *it));
			}
			else
				stk.push(atoi(it->c_str()));
		}
		return (stk.top());
	}
};


int main()
{
	Solution s;
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");

	std::cout << s.evalRPN(tokens) << std::endl;

}