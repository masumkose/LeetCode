import heapq
from collections import Counter


class Solution:
    def topKFrequent(self, nums, k):
        freq_map = Counter(nums)

        heap = []

        for num, freq in freq_map.items():
            heapq.heappush(heap, (freq, num))

            if len(heap) > k:
                heapq.heappop(heap)

        return [num for freq, num in heap]






ss = Solution()

print(ss.topKFrequent([1,1,1,2,2,3], 2))

print(ss.topKFrequent([1], 1))
print(ss.topKFrequent([1,2], 2))