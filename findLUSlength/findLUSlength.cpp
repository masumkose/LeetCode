

#include "../include/include.hpp"

class Solution {
public:

    int findLUSlength_I(string a, string b) {
        if (a == b)
            return -1;
        return (a.length() > b.length() ? a.length() : b.length());
    }
};

int main()
{
	Solution ss;

	return (0);
}
