

class Solution:
    def isPalindrome(self, s):

        start = 0
        end = len(s) - 1

        while start < end:

            while start < end and not self.isalphanum(s[start]):
                start += 1
            while start < end and not self.isalphanum(s[end]):
                end -= 1
            if s[start].lower() == s[end].lower():
                start += 1
                end -= 1
            else:
                return False

        return True

    def isalphanum(self, c):
        return (ord('A') <= ord(c) <= ord('Z') or
                ord('a') <= ord(c) <= ord('z') or
                ord('0') <= ord(c) <= ord('9'))

        






ss = Solution()


print(ss.isPalindrome("A man, a plan, a canal: Panama"))

