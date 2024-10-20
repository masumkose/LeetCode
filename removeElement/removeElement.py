

from typing import List, Tuple



class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if not nums:
            return 0
        write_index = 0
        for i in range(0, len(nums)):
            if nums[i] != val:
                nums[write_index] = nums[i]
                write_index += 1
        return write_index

def main():
    ss = Solution()
    nums = [3,2,2,3]
    val = 3
    print(ss.removeElement(nums, val))
    print(nums)


if __name__ == "__main__":
    main()
