class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        left = [0]*len(nums)
        right = [0]*len(nums)

        for i in range(len(nums)):
            if i == 0:
                left[i] = 1
            else:
                left[i] = left[i-1]*nums[i-1]

        for i in range(len(nums)-1, -1, -1):
            if i == len(nums) - 1:
                right[i] = 1
            else:
                right[i] = right[i+1]*nums[i+1]
        result = []
        for i in range(len(nums)):
            result.append(left[i]*right[i])
        return result
        