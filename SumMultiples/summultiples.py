class Solution(object):
    def sumOfMultiples(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        for i in range(n + 1):
            if i % 3 == 0 or i % 5 == 0 or i % 7 == 0:
                sum += i
        return sum




ss = Solution()
print(ss.sumOfMultiples(7))
print(ss.sumOfMultiples(10))
print(ss.sumOfMultiples(9))