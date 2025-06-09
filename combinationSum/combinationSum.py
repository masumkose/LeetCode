
from typing import List, Optional
import collections



class Solution:
    def combinationSum_anothersolution(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        
        def dfs(i, curr, total):
            if total == target:
                res.append(curr.copy())
                return
            if i >= len(candidates) or total > target:
                return
            
            curr.append(candidates[i])
            dfs(i, curr, total + candidates[i])
            curr.pop()
            dfs(i + 1, curr, total)
    
        dfs(0, [], 0)
        return res

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        curr = []

        def dfs(i, total):
            if total > target:
                return
            if total == target:
                res.append(curr.copy())
                return
            for n in range(i, len(candidates)):
                curr.append(candidates[n])
                dfs(n, total + candidates[n])
                curr.pop()
        dfs(0, 0)
        return res



candidates = [2,3,6,7]
target = 7

ss = Solution()


print(ss.combinationSum(candidates, target))
print(ss.combinationSum_anothersolution(candidates, target))




