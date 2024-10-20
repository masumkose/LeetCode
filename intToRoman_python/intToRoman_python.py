




class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        size = len(s)
        for i in range(size):
            if s[i] == 'D':
                num += 500
            elif s[i] == 'L':
                num += 50
            elif s[i] == 'V':
                num += 5
            elif s[i] == 'M':
                num += 1000
            elif s[i] == 'C':
                if i != size - 1 and (s[i + 1] == 'D' or s[i + 1] == 'M'):
                    num -= 100
                else:
                    num += 100
            elif s[i] == 'X':
                if i != size - 1 and (s[i + 1] == 'L' or s[i + 1] == 'C'):
                    num -= 10
                else:
                    num += 10
            elif s[i] == 'I':
                if i != size - 1 and (s[i + 1] == 'V' or s[i + 1] == 'X'):
                    num -= 1
                else:
                    num += 1
        return num



