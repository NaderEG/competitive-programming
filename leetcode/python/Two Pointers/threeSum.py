class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()

        i = 0

        result = []

        for i in range(len(nums)-2):
            j = i+1
            k = len(nums)-1
            target = -1*nums[i]
            while(k>j):
                if nums[j] + nums[k] > target:
                    k-=1
                elif nums[j] + nums[k] < target:
                    j+=1
                else:
                    if [nums[i], nums[j], nums[k]] not in result:
                        result.append([nums[i], nums[j], nums[k]])
                    k-=1
                    j+=1


        return result
