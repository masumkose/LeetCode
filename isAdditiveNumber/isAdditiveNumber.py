"""306.
 Additive Number
An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

Example 1:

Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199
"""



class Solution(object):
    def backtrack(self, num1, num2, num):
        if not num:
            return True
        if num1 + num2 > 0 and num[0] == 0:
            return False
        for i in range(1, len(num) + 1):
            # print(f'num1 = {num1}, num2 = {num2}, next = {int(num[:i])}, rest {num[i:]}')
            if num1 + num2 == int(num[:i]) and self.backtrack(num2, num1 + num2, num[i:]) == True:
                return True
        
        return False

    def isAdditiveNumber(self, num):
        n = len(num)
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                if i > 1 and num[0] == '0':
                    break
                if j - i > 1 and num[i] == '0':
                    continue
                if self.backtrack(int(num[:i]), int(num[i:j]), num[j:]) == True:
                    return True
        return False
        

ss = Solution()


print(ss.isAdditiveNumber("1203")) 
# print(ss.isAdditiveNumber("112358")) 
# print(ss.isAdditiveNumber("000")) 
# print(ss.isAdditiveNumber("199100199"))