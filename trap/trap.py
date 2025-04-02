class Solution:
    def trap(self, height):
        area = 0        
        l, r = 0, len(height) - 1
        max_l, max_r = 0, 0

        while l < r:

            if height[l] <= height[r]:
                if max_l > height[l]:
                    area += max_l - height[l]
                else:
                    max_l = height[l]
                l += 1
            else:
                if max_r > height[r]:
                    area += max_r - height[r]
                else:
                    max_r = height[r]
                r -= 1
        return area






ss = Solution()

print(ss.trap([0,1,0,2,1,0,1,3,2,1,2,1]))