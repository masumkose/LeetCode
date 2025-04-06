class Solution:
    def maxArea(self, height):

        l, r = 0, len(height) - 1 
        maxArea = 0

        while l < r:
            current = min(height[l], height[r]) * (r - l)
            if (height[l] > height[r]):
                r -= 1
            else:
                l += 1

            maxArea = max(current, maxArea)


        return maxArea







ss = Solution()

print(ss.maxArea([1,8,6,2,5,4,8,3,7]))