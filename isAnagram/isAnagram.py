class Solution:
    def isAnagram(self,s,t):
        if len(s) != len(t):
            return False

        my_dic = {}

        for ch in s:
            my_dic[ch] = my_dic.get(ch,0) + 1

        for ch in t:
            if ch not in my_dic or my_dic[ch] == 0:
                return False
            my_dic[ch] -= 1
        return True





ss = Solution()

print(ss.isAnagram("anagram", "nagaram"))
print(ss.isAnagram("rat", "car"))