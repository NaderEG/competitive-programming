class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        nums = [element for row in matrix for element in row]
        l, r = 0, len(nums) - 1

        while l <= r:
            m = l + ((r - l) // 2)
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                return True
        return False