
import heapq
from collections import Counter

class Solution:

    def frequencySort(self, nums):
        c = Counter(nums)
        cS = sorted(c.items(), key = lambda x :(x[1], -x[0]))
        ans = []
        for n, freq in cS:
            ans += freq * [n]
        return ans

    
    def frequencySort_alternative(self, nums):
        c = Counter(nums)
        heap = []
        for n, freq in c.items():
            heapq.heappush(heap, (freq, -n))
        ans = []
        while heap:
            top = heapq.heappop(heap)
            ans += (top[0] * [-top[1]])
    
        return ans 






nums = [[1,1,2,2,2,3], [2,3,1,3,2], [-1,1,-6,4,5,-6,1,4,1], [1,5,0,5]]
ss = Solution()

for n in nums:
    print(ss.frequencySort(n))
    print(ss.frequencySort_alternative(n))