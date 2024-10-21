

from typing import List, Tuple


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i = haystack.index(needle)
        print(i)
        return i


def main():
    ss = Solution()
    print(ss.strStr("leetcode", "leeto"))


if __name__ == "__main__":
    main()
