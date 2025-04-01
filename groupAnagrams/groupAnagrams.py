class Solution:
    def groupAnagrams(self, strs):
        Map = {}

        for s in strs:
            sorted_s = "".join(sorted(s))
            Map[sorted_s] = Map.get(sorted_s,[]) + [s]

        res = []
        for key, value in Map.items():
            res.append(value)

        return res




ss = Solution()

print(ss.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))