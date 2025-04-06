
class Solution:
    def encode(self, strs):
        code = ""
        for s in strs:
            code += str(len(s)) + "#" + s
        return code



    def decode(self, s):
        res = []
        i = 0

        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            leng = int(s[i:j])
            res.append(s[j + 1 : j + 1 + leng])
            i = j + 1 + leng

        return res




ss = Solution()

print(ss.decode(ss.encode(["neet","code","love","you"])))
print(ss.decode(ss.encode(["we","say",":","yes"])))
