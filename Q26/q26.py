from typing import List

#不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
#使用游标i, j同时移动 i为当前检索的位置 j为当前不重复的长度-1
#如果数组长度为0 或者为 1 则直接返回
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = len(nums)
        if l <= 1:
            return l
        j = 0
        for i in range(1, l):
            if nums[i] != nums[j]:
                j+=1
                nums[j] = nums[i]
            else:
                continue
        return (j+1)
#test
print("test:\n")
a = [1, 1, 2, 3, 3, 4, 5, 5, 5, 6]
print(a)
b = Solution.removeDuplicates(a,a)
print(a)
print(b)
a = [1]
print(a)
b = Solution.removeDuplicates(a,a)
print(a)
print(b)
a = [1, 1]
print(a)
b = Solution.removeDuplicates(a,a)
print(a)
print(b)
a = [1, 1, 1]
print(a)
b = Solution.removeDuplicates(a,a)
print(a)
print(b)
a = [1, 2, 3, 3]
print(a)
b = Solution.removeDuplicates(a,a)
print(a)
print(b)

