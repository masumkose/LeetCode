
#include "../include/include.cpp"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string number;

        while (columnNumber > 0)
        {
            columnNumber--;
            char ch = (columnNumber % 26) + 'A';
            number.push_back(ch);
            columnNumber /= 26;
        }
        reverse(number.begin(), number.end());
        return number;
    }


    int titleToNumber(string columnTitle) {

        int number = 0;


        for (int i = 0; i < columnTitle.length(); i++)
        {
            number = (number * 26) + (columnTitle[i] - 'A');
            number++;
        }
        return number;
    }
};


int main() {


    Solution ss = Solution();

    vector<int> nums = {
        1,
        27,
        701
    };
    
    for (auto num : nums)
    {
        cout << (ss.convertToTitle(num)) << '\n';

    }

    vector<string> strs = {
        "A",
        "AB",
        "ZY"
    };
    
    for (auto str : strs)
    {
        cout << ss.titleToNumber(str) << '\n';
    }




    return 0;
}
