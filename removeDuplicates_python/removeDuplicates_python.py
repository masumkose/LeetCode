
from typing import List, Tuple

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        write_index = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[write_index] = nums[i]
                write_index += 1
        return (write_index)






def main():
    solution = Solution()
    nums = [0,0,1,1,1,2,2,3,3,4]
    k = solution.removeDuplicates(nums)
    print(f"number of unique elements: {k}")
    print(f"unique elements: {nums}")

if __name__ == "__main__":
    main()