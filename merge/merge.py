class Solution(object):
    def merge(self, nums1, m, nums2, n):
        while m > 0 and n > 0:
            if nums1[m - 1] > nums2[n - 1]:
                nums1[m + n - 1] = nums1[m - 1]
                m -= 1
            else:
                nums1[m + n - 1] = nums2[n - 1]
                n -= 1
        while n > 0:
            nums1[n - 1] = nums2[n - 1]
            n -= 1

            


ss = Solution()
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
ss.merge(nums1, 3, nums2, 3)
print(nums1)

