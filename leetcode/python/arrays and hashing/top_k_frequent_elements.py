class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        m = {}
        for i in nums:
            if i in m:
                m[i] += 1
            else:
                m[i] = 1

        return [key for key, value in sorted(m.items(), key=lambda x: x[1], reverse=True)[:k]]