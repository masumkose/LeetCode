# class NumArray(object):

#     def __init__(self, nums):
#         self.nums = nums
#         self.prefix()

#     def prefix(self):
#         for i in range(1, len(self.nums)):
#             self.nums[i] += self.nums[i - 1]
        

#     def sumRange(self, left, right):
#         if left == 0:
#             return self.nums[left]
#         return self.nums[right] - self.nums[left] 

class NumArray(object):

    def __init__(self, nums):
        self.update_nums = nums
        self.prefix()

    def prefix(self):
        self.nums = self.update_nums
        for i in range(1, len(self.nums)):
            self.nums[i] += self.nums[i - 1]
        

    def update(self, index, val):
        self.update_nums[index] = val
        self.prefix()
        

    def sumRange(self, left, right):
        if left == 0:
            return self.nums[right]
        return self.nums[right] - self.nums[left]
        


# Your NumArray object will be instantiated and called as such:

numArray = NumArray([9,8])
numArray.update(0,3)
print(numArray.sumRange(1, 1))
print(numArray.sumRange(0, 1))
numArray.update(1, -3)
print(numArray.sumRange(0, 1))
