class Solution(object):
    def countBits(self, n):
        
        ans = (n + 1) * [0]
        for i in range(0, n + 1):
            ans[i] = ans[i // 2]  + (i % 2)
        return ans
        






ss = Solution()


print(ss.countBits(2))
print(ss.countBits(5))