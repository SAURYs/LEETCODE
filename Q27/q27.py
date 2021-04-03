from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        l = len(nums)
        j = 0
        for i in range(l):
            if nums[i] != val:
                nums[j] = nums[i]
                j+=1
        return j
#test
nums = [0,1,2,3,4,2,1,3]
print(nums)
val = 2
print("val: ", val)
l = Solution.removeElement(nums, nums, val)
print("l: ", l)
print(nums)


