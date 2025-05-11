from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def k_works(piles, h, k):
            count = 0
            for p in piles:
                count += math.ceil(p / k)
            return count <= h

        max_k = max(piles)
        min_k = 1
        
        l, r = min_k, max_k
        while l < r:
            m = (l + r) // 2
            if k_works(piles, h, m):
                r = m
            else:
                l = m + 1
        return l