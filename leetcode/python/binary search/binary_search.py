class Solution:
    def search(self, nums: List[int], target: int) -> int:
        r = len(nums)-1
        l = 0

        while True:
            if r - l <= 1:
                if nums[l] == target:
                    return l
                elif nums[r] == target:
                    return r
                else:
                    return -1
            pos = (r+l)//2
            if nums[pos] == target:
                return pos
            elif nums[pos] > target:
                r = pos
            else:
                l = pos