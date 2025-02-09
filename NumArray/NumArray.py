class NumArray(object):

    def __init__(self, nums):
        self.nums = nums
        self.prefix()

    def prefix(self):
        for i in range(1, len(self.nums)):
            self.nums[i] += self.nums[i - 1]
        

    def sumRange(self, left, right):
        if left == 0:
            return self.nums[left]
        return self.nums[right] - self.nums[left] 



# Your NumArray object will be instantiated and called as such:

numArray = NumArray([-2, 0, 3, -5, 2, -1]);
print(numArray.sumRange(0, 2))
print(numArray.sumRange(2, 5))
print(numArray.sumRange(0, 5))
