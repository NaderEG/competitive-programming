class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #base case
        if len(nums) <= 1:
            return nums[0]

        if len(nums) == 2:
            return max(nums[0], nums[1])
        
        dp_list = [nums[0], max(nums[0], nums[1]) ]

        #dp step
        for i in range(2, len(nums)):
            dp_list.append(max(dp_list[i-1], nums[i]+dp_list[i-2]))
        return dp_list[-1]