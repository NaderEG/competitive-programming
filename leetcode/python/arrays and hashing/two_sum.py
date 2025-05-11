class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        indexed_list = list(enumerate(nums))
        sorted_pairs = sorted(indexed_list, key=lambda x: x[1])

        sorted_indices = [index for index, value in sorted_pairs]
        sorted_values = [value for index, value in sorted_pairs]

        i = 0
        j = len(nums)-1
        indexes = (0, 0)
        while(j>i):
            if sorted_values[i] + sorted_values[j] > target:
                j-=1
            elif sorted_values[i] + sorted_values[j] < target:
                i+=1
            else:
                indexes = (i, j)
                break

        return [sorted_indices[i], sorted_indices[j]]