import heapq
from collections import Counter

class Solution:
    def frequencySort(self, s):
        Map = Counter(s)
        heap = []
        for ch, freq in Map.items():
            heapq.heappush(heap, (-1 * freq, ch))

        s = ""
        while heap:
            biggest = heapq.heappop(heap)
            freq = biggest[0] * -1
            s += (biggest[0] * -1) * biggest[1]

        return s


    def frequencySort_alternative(self, s):
        c = Counter(s)
        cS = sorted(c.items(), key = lambda x:x[1], reverse = True)
        ans = ""
        for key, freq in cS:
            ans += keys * freq
        return ans
        








ss = Solution()
strs = ["tree", "cccaaa", "Aabb"]

print(ss.frequencySort("tree"))

# for s in strs:
    # print(ss.frequencySort(s))