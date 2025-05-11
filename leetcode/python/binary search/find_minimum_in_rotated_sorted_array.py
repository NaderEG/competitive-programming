class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            m = l + ((r - l) // 2)
            if r-l <= 1:
                return min(nums[l], nums[r])
            if nums[m] < nums[r]:
                r = m
            elif nums[m] > nums[l]:
                l = m