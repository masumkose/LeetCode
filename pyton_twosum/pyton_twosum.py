

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = {}
        for i, num in enumerate(nums):
            hash_table[num] = i

        for i, num in enumerate(nums):
            middle = target - num
            if middle in hash_table and hash_table[middle] != i:
                return [i, hash_table[middle]]
        return []








def main():
    solution = Solution()
    
    # Test cases
    test_cases = [
        ([2, 7, 11, 15], 9, [0, 1]),  # Simple case
        ([3, 2, 4], 6, [1, 2]),       # Multiple solutions, but should return the first valid one
        ([3, 3], 6, [0, 1]),          # Two identical numbers
        ([1, 2, 3, 4, 5], 10, []),    # No solution
        ([0, 4, 3, 0], 0, [0, 3]),    # Zero sum with zeros
    ]

    # Run and check test cases
    for i, (nums, target, expected) in enumerate(test_cases):
        result = solution.twoSum(nums, target)
        print(f"Test case {i + 1}: nums = {nums}, target = {target}")
        print(f"Expected: {expected}, Got: {result}")
        print("Pass" if result == expected else "Fail")
        print()

if __name__ == "__main__":
    main()
