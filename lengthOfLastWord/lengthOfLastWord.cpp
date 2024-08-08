

#include "../include/include.hpp"

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int len = s.length() - 1;

		while (len >= 0 && s[len] && isspace(s[len]))
			len--;
		int i = 0;
		while (len >= 0 && s[len])
		{
			if (isalpha(s[len]))
				i++;
			else
				break ;
			len--;
		}


		return (i);
	}
};

int main()
{
	Solution ss;
	string s = "   fly me   to   the moon  ";
	string s2 = "Hello World";
	string s3 = "a";


	cout << ss.lengthOfLastWord(s) << '\n';
	cout << ss.lengthOfLastWord(s2) << '\n';
	cout << ss.lengthOfLastWord(s3) << '\n';

	return (0);
}
